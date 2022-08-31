#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define mp make_pair
typedef pair<int,int> pii;
typedef long long ll;
typedef double ld;
typedef vector<int> vi;
#define fi first
#define se second
#define fe first
#define FO(x) {freopen(#x".in","r",stdin);freopen(#x".out","w",stdout);}
#define Edg int M=0,fst[SZ],vb[SZ],nxt[SZ];void ad_de(int a,int b){++M;nxt[M]=fst[a];fst[a]=M;vb[M]=b;}void adde(int a,int b){ad_de(a,b);ad_de(b,a);}
#define Edgc int M=0,fst[SZ],vb[SZ],nxt[SZ],vc[SZ];void ad_de(int a,int b,int c){++M;nxt[M]=fst[a];fst[a]=M;vb[M]=b;vc[M]=c;}void adde(int a,int b,int c){ad_de(a,b,c);ad_de(b,a,c);}
#define es(x,e) (int e=fst[x];e;e=nxt[e])
#define esb(x,e,b) (int e=fst[x],b=vb[e];e;e=nxt[e],b=vb[e])
#define SZ 666666

//#define SELF

int n,p[SZ],u[SZ],v;
vector<int> pos;

#ifndef SELF
bool qry(vector<int> v)
{
	if(v.size()==1) return 1;
	set<int> sb;
	for(auto c:v)
		assert(c>=1&&c<=n),
		sb.insert(c);
	assert(sb.size()==v.size());
	cout<<"? "<<v.size();
	for(auto t:v) cout<<" "<<t;
	cout<<endl;
	int o; cin>>o;
	return o;
}
#else
int reala[SZ],num_qry;
bool qry(vector<int> v)
{
	if(v.size()==1) return 1;
	set<int> sb; ++num_qry;
	for(auto c:v)
		assert(c>=1&&c<=n),
		sb.insert(c);
	assert(sb.size()==v.size()&&v.size()!=0);
	int ss=0;
	for(auto c:v) ss+=reala[c];
	return ss%v.size()==0;
}
#endif
void report()
{
	if(p[1]>n/2)
		for(int i=1;i<=n;++i)
			p[i]=n+1-p[i];
	cout<<"!";
	for(int i=1;i<=n;++i)
		cout<<" "<<p[i];
	cout<<endl;
	#ifdef SELF
	cerr<<"num_qry"<<num_qry<<"\n";
	for(int i=1;i<=n;++i)
		assert(p[i]==reala[i]);
	#endif
	exit(0);
}
void chk(int u)
{
	if(n<=u)
		report();
}
void examine(int w)
{
	assert((int)pos.size()>=w);
	vector<int> uu; int tot=0;
	for(int i=1;i<=w;++i)
		uu.pb(i),tot+=i;
	tot%=w;
	for(int i=1;i<=n;++i)
		if(!p[i])
		{
//			cout<<"HELLO GOTTA CHECK"<<i<<" WITH "<<w<<"\n";
//			for(auto t:pos) cout<<t<<",";
//			cout<<"\n";
			vector<int> sk;
			for(auto x:uu)
			{
				//(tot-x+p[i])%w=0?
				//u[i]%v=0
				bool pos=0;
				for(int g=u[i];g<=n;g+=v)
					if((tot-x+g)%w==0) pos=1;
				if(pos) sk.pb(x);
			}
			random_shuffle(sk.begin(),sk.end());
			while(sk.size()>1)
			{
				int t=sk.back();
				vi tmp;
				for(auto w:uu)
					if(w!=t) tmp.pb(pos[w-1]);
				tmp.pb(i);
//				for(auto t:tmp)
//					cout<<t<<",";
//				cout<<"|qrY"<<t<<"\n";
				if(qry(tmp)) break;
				sk.pop_back();
			}
//			cout<<"x + "<<tot-sk.back()<<"  %"<<w<<"=0\n";
//			cout<<"cur:%"<<v<<"="<<u[i]<<"\n";
			//w|tot-x+g
			while((u[i]+tot-sk.back())%w!=0)
				u[i]+=v;
		}
	v=v/__gcd(v,w)*w;//lcm(v,w);
}
int main()
{
	cin>>n;
	#ifdef SELF
	for(int i=1;i<=n;++i)
		reala[i]=i;
	random_shuffle(reala+1,reala+1+n);
	if(reala[1]>n/2)
		for(int i=1;i<=n;++i)
			reala[i]=n+1-reala[i];
//		cin>>reala[i];
	#endif
	vi o;
	for(int i=1;i<=n;++i)
	{
		vi s;
		for(int j=1;j<=n;++j)
			if(i!=j) s.pb(j);
		if(qry(s)) o.pb(i);
	}
	p[o[0]]=1;
	p[o[1]]=n;
	for(int i=1;i<=n;++i)
	{
		if(p[i])
		{
			u[i]=p[i]&1;
			continue;
		}
		vi s{o[0],i};
		u[i]=(qry(s));
	}
	pos.pb(o[0]); v=2;
	chk(2);
	#define pos(a,q) (p[a]==0&&(u[a]-(q))%v==0)
	int p2,pn1;
	for(int i=1;i<=n;++i)
	{
		if(pos(i,2))
		{
			vi s;
			for(int j=1;j<=n;++j)
				if(i!=j&&!p[j]) s.pb(j);
			if(qry(s)) p2=i;
		}
		if(pos(i,n-1))
		{
			vi s;
			for(int j=1;j<=n;++j)
				if(i!=j&&!p[j]) s.pb(j);
			if(qry(s)) pn1=i;
		}
	}
	p[p2]=2; p[pn1]=n-1; pos.pb(p2);
	chk(4);
	int p3,pn2;
	for(int i=1;i<=n;++i)
	{
		if(pos(i,3))
		{
			vi s;
			for(int j=1;j<=n;++j)
				if(i!=j&&!p[j]) s.pb(j);
			if(qry(s)) p3=i;
		}
		if(pos(i,n-2))
		{
			vi s;
			for(int j=1;j<=n;++j)
				if(i!=j&&!p[j]) s.pb(j);
			if(qry(s)) pn2=i;
		}
	}
	p[p3]=3; p[pn2]=n-2; pos.pb(p3);
	chk(6); examine(3);
	int p4,pn3;
	for(int i=1;i<=n;++i)
	{
		if(pos(i,4))
		{
			vi s;
			for(int j=1;j<=n;++j)
				if(i!=j&&!p[j]) s.pb(j);
			if(qry(s)) p4=i;
		}
		if(pos(i,n-3))
		{
			vi s;
			for(int j=1;j<=n;++j)
				if(i!=j&&!p[j]) s.pb(j);
			if(qry(s)) pn3=i;
		}
	}
	p[p4]=4; p[pn3]=n-3; pos.pb(p4);
	chk(8); examine(4);
	int p5,pn4;
	for(int i=1;i<=n;++i)
	{
		if(pos(i,5))
		{
			vi s;
			for(int j=1;j<=n;++j)
				if(i!=j&&!p[j]) s.pb(j);
			if(qry(s)) p5=i;
		}
		if(pos(i,n-4))
		{
			vi s;
			for(int j=1;j<=n;++j)
				if(i!=j&&!p[j]) s.pb(j);
			if(qry(s)) pn4=i;
		}
	}
	p[p5]=5; p[pn4]=n-4; pos.pb(p5);
	chk(10); examine(5);
	int p6,pn5;
	for(int i=1;i<=n;++i)
	{
		if(pos(i,6))
		{
			vi s;
			for(int j=1;j<=n;++j)
				if(i!=j&&!p[j]) s.pb(j);
			if(qry(s)) p6=i;
		}
		if(pos(i,n-5))
		{
			vi s;
			for(int j=1;j<=n;++j)
				if(i!=j&&!p[j]) s.pb(j);
			if(qry(s)) pn5=i;
		}
	}
	p[p6]=6; p[pn5]=n-5; pos.pb(p6);
	chk(12);
	int p7,pn6;
	for(int i=1;i<=n;++i)
	{
		if(pos(i,7))
		{
			vi s;
			for(int j=1;j<=n;++j)
				if(i!=j&&!p[j]) s.pb(j);
			if(qry(s)) p7=i;
		}
		if(pos(i,n-6))
		{
			vi s;
			for(int j=1;j<=n;++j)
				if(i!=j&&!p[j]) s.pb(j);
			if(qry(s)) pn6=i;
		}
	}
	p[p7]=7; p[pn6]=n-6; pos.pb(p7);
	chk(14); examine(7);
	int p8,pn7;
	for(int i=1;i<=n;++i)
	{
		if(pos(i,8))
		{
			vi s;
			for(int j=1;j<=n;++j)
				if(i!=j&&!p[j]) s.pb(j);
			if(qry(s)) p8=i;
		}
		if(pos(i,n-7))
		{
			vi s;
			for(int j=1;j<=n;++j)
				if(i!=j&&!p[j]) s.pb(j);
			if(qry(s)) pn7=i;
		}
	}
	p[p8]=8; p[pn7]=n-7; pos.pb(p8);
	chk(16); examine(8);
	assert(v>n);
	for(int i=1;i<=n;++i)
		if(!p[i]) p[i]=u[i];
	report();
}