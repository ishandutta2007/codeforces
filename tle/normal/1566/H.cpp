#pragma GCC optimize("-Ofast","-funroll-all-loops","-ffast-math")
#include <iostream>
#include <stdio.h>
#include <math.h>
#include <string.h>
#include <time.h>
#include <stdlib.h>
#include <string>
#include <bitset>
#include <vector>
#include <set>
#include <map>
#include <queue>
#include <algorithm>
#include <sstream>
#include <stack>
#include <iomanip>
#include <assert.h>
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
#define SZ 1234556
int n=1e6;
vector<int> f[SZ];
//bool fd[SZ];
ll hf[SZ];
struct B {
	int a[30],b[30];
	vector<int> fre,bae;
	B(){memset(a,0,sizeof a);memset(b,0,sizeof b);}
	inline bool ins(int x)
	{
		int y=1<<(bae.size()); int A=x;
	    for(int i=29;~i;--i) if(x&(1LL<<i))
	    {
	        if(a[i]) x^=a[i],y^=b[i];
	        else
			{
				bae.pb(A);
	            for(int j=0;j<i;j++) if(x>>j&1) x^=a[j],y^=b[j];
	            for(int j=i+1;j<=29;j++) if(a[j]>>i&1) a[j]^=x,b[j]^=y;
	            a[i]=x; b[i]=y; return 1;
	        }
	    }
	    fre.pb(A); return 0;
	}
	inline vector<int> dec(int w)
	{
		int y=0;
	    for(int i=29;~i;--i) if(w&(1LL<<i)) {
	    	w^=a[i],y^=b[i];
	    }
	    if(w!=0) throw "?";
	    vector<int> s;
	    for(int u=0;u<bae.size();++u)
	    	if(y&(1<<u)) s.pb(bae[u]);
	    return s;
	}
};
int w;

vector<int> xll{1,4,5,6,8,10};
int qryf(int q) {
	int aa=0;
	for(int o:xll) if(__gcd(o,q)==1) aa^=o;
	return aa;
}
int qn=0,qs[666666],aa[666666],ans[SZ],fu[SZ];
//vector<int> po[SZ];
int main()
{
	cerr<<sizeof(f)/1024.0/1024.0<<"M\n";
	cin>>n>>w;
	#ifdef LOCAL
	if(n!=10)
	{
	xll.clear();
	for(int i=1;i<=n;++i)
		if(rand()&1) xll.pb(i);
	w=xll.size();
	cerr<<n<<":"<<w<<"\n";
	if(n<=10000) {
	for(auto t:xll) cerr<<t<<",";
	cerr<<"\n";
	}
	}
	#endif
	int tot=0,qry=0;
	for(int i=2;i<=n;++i) if(f[i].empty())
		for(int j=i;j<=n;j+=i)
			f[j].pb(i);
	map<ll,vector<int>> tl;
	for(int i=1;i<=n;++i) {
		hf[i]=1;
		for(int j=0;j<f[i].size();++j)
			hf[i]=hf[i]*123456789+f[i][j]+j+2;
		tl[hf[i]].pb(i);
	}
	for(auto &u:tl) {
		auto&v=u.se;
		int vn=v.size();
		qs[++qn]=v[0];
//		B w; for(auto t:v) w.ins(t);
//		if(cm!=v.size()) {
//			cout<<cm<<" "<<v.size()<<"sad\n";
//		}
	}
	static int rm[SZ];
//	map<int,int> rm;
	sort(qs+1,qs+1+qn);
	for(int i=1;i<=qn;++i) rm[qs[i]]=i;
	fflush(stdout);
	#ifdef LOCAL
	if(n<=10000)
	for(int i=1;i<=qn;++i) aa[i]=qryf(qs[i]);
	#else
	printf("%d",qn);
	for(int i=1;i<=qn;++i)
		printf(" %d",qs[i]);
	puts("");
	fflush(stdout);
	for(int i=1;i<=qn;++i) scanf("%d",aa+i);
	#endif
	for(auto &u:tl) {
		auto&v=u.se;
		int vn=v.size();
		int pp=rm[v[0]];
		for(auto o:v) ans[o]=aa[pp];
	}
	#define SS 5000000
	int S=0;
	static int np[SS],fp[SZ],pp[SS];
	for(auto &u:tl) {
		auto&v=u.se;
		int vn=v.size();
//		fu[v[0]]=ans[v[0]]^ans[1];
//		cout<<v[0]<<":"<<fu[v[0]]<<","<<ans[1]<<"\n";
		for(int w=v[0];w<=n;w+=v[0])
			if(rm[w]) ++S,np[S]=fp[w],fp[w]=S,pp[S]=v[0];//po[w].pb(v[0]);
	}
	cerr<<"S="<<S<<"\n";
	srand(time(0));
	int rst=ans[1];
	for(int i=qn;i>=1;--i){
		int w=qs[i];
		for(int p_=fp[w];p_;p_=np[p_]) {
			int p=pp[p_];
			fu[w]^=ans[p]^ans[1];
		}
		for(int p_=fp[w];p_;p_=np[p_]) {
			int p=pp[p_];
			if(w!=p) fu[p]^=fu[w];
		}
		if(w!=1) rst^=fu[w];
	}
	fu[1]=rst;
	while(1) {
		cerr<<"ty"<<clock()<<"ms\n";
		static vector<int> G[666666][3];
		for(auto &u:tl) {
			auto&v=u.se;
			int vn=v.size(),pp=fu[v[0]];
			B w;
			for(auto t:v) w.ins(t);
			vector<int> p[3];
			for(int o=0;o<3;++o) {
				vector<int> op;
				int ts=pp;
				for(int j=0;j<w.fre.size();++j) if(rand()&1) {
					op.pb(w.fre[j]);
					ts^=w.fre[j];
				}
				auto rs=w.dec(ts);
				for(auto c:rs) op.pb(c);
				p[o]=op;
			}
			for(auto t:p) {
				int xo=0;
				for(auto c:t) xo^=c;
				assert(xo==pp);
			}
			sort(p,p+3,[](vector<int> a,vector<int> b) {
				return a.size()<b.size();
			});
			G[rm[v[0]]][0]=p[0];
			G[rm[v[0]]][1]=p[1];
			G[rm[v[0]]][2]=p[2];
		}
		vector<int> ooo;
		for(int i=1;i<=qn;++i) if(G[i][0].size()!=G[i][2].size()) ooo.pb(i);
		static vector<int>*cho[SZ];
		int cs=0;
		int opp=0;
		for(int j=0;j<7;++j) {
			cs=0;
			for(int i=1;i<=qn;++i) cho[i]=&G[i][j%3],cs+=cho[i]->size();
			int stale=0;
			for(;;) {
				int mov=0;
				random_shuffle(ooo.begin(),ooo.end());
				for(int i:ooo) {
					int om=abs(cs-w),mi=om;
					cs-=cho[i]->size();
					for(int tt=0;tt<3;++tt) {
						auto t=&G[i][tt];
						if(abs(cs+(int)t->size()-w)<mi)
							mi=abs(cs+(int)t->size()-w),cho[i]=t;
					}
					cs+=cho[i]->size();
					if(om!=mi) mov=1;
					if(cs==w) break;
				}
				if(!mov) ++stale;
				if(stale==4) break;
				if(cs==w) break;
			}
//			for(int i=1;i<=qn;++i)
//				cerr<<(cho[i]->size()-G[i][14].size())<<",";
//			cerr<<cs<<","<<w<<"??\n";
			if(cs==w) break;
		}
		if(cs!=w) continue;
		vector<int> ans;
		for(int i=1;i<=qn;++i)
			for(auto c:*cho[i]) ans.pb(c);
		assert(ans.size()==w);
		sort(ans.begin(),ans.end());
//		for(int i=1;i<=qn;++i) {
//			int q=qs[i],x=0;
//			for(auto c:ans) if(__gcd(q,c)==1) x^=c;
//			cout<<x<<" "<<aa[i]<<"?\n";
//		}
//		cout<<"GG\n";
		for(auto t:ans) printf("%d ",t);
		fflush(stdout);
		return 0;
	}
}