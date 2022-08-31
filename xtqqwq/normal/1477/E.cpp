#include<bits/stdc++.h>

#define pb push_back
#define mp make_pair
#define fi first
#define se second

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

template <typename T> bool chkmax(T &x,T y){return x<y?x=y,true:false;}
template <typename T> bool chkmin(T &x,T y){return x>y?x=y,true:false;}

int readint(){
	int x=0,f=1; char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
	return x*f;
}

const int N=1000001;

struct bit{
	ll c[1000005];
	void add(int x,ll v){x++; for(;x<=N;x+=(x&(-x))) c[x]+=v;}
	ll ask(int x){ll ret=0; for(;x;x-=(x&(-x))) ret+=c[x]; return ret;}
	ll query(int l,int r){
		l++; r++;
		chkmax(l,1); chkmin(r,N);
		return ask(r)-ask(l-1);
	}
}T[2];

ll n,m,q,k;
ll a[200005],b[200005],sum[2];
multiset<int> s[2];

ll calc(ll x){
	return T[1].query(x,N)-x*T[0].query(x,N);
}

ll getans(ll tp,ll x){
	ll mina=min(*s[0].begin(),*s[1].begin());
	if(x>k+mina){
		if(tp==1) return sum[0]-n*mina-calc(x-k);
		else return sum[0]-n*mina+(k+mina-x)-calc(x-k);
	}
	else return (k-x)*(n-m)+sum[0]-sum[1];
}

int main(){
	n=readint(); m=readint(); q=readint();
	for(int i=1;i<=n;i++) a[i]=readint();
	for(int i=1;i<=m;i++) b[i]=readint();
	for(int i=1;i<=n;i++) s[0].insert(a[i]);
	for(int i=1;i<=m;i++) s[1].insert(b[i]);
	for(int i=1;i<=n;i++) sum[0]+=a[i];
	for(int i=1;i<=m;i++) sum[1]+=b[i];
	for(int i=1;i<=m;i++) T[0].add(b[i],1),T[1].add(b[i],b[i]);
	int opt,x,y;
	while(q--){
		opt=readint(); x=readint();
		if(opt==1){
			y=readint();
			s[0].erase(s[0].find(a[x]));
			s[0].insert(y);
			sum[0]-=a[x],sum[0]+=y;
			a[x]=y;
		}
		else if(opt==2){
			y=readint();
			s[1].erase(s[1].find(b[x]));
			s[1].insert(y);
			sum[1]-=b[x],sum[1]+=y;
			T[0].add(b[x],-1),T[1].add(b[x],-b[x]);
			b[x]=y;
			T[0].add(b[x],1),T[1].add(b[x],b[x]);
		}
		else{
			k=x;
			ll mina=min(*s[0].begin(),*s[1].begin()),ans=getans(0,mina);
			auto it0=s[0].upper_bound(k+mina),it1=s[1].upper_bound(k+mina);
			ll val0=0,val1=0;
			if(it0!=s[0].begin()) val0=*(--it0);
			if(it1!=s[1].begin()) val1=*(--it1);
			if(val0>val1) chkmax(ans,getans(0,val0));
			else chkmax(ans,getans(0,val1));
			
			int max0=*(--s[0].end()),max1=*(--s[1].end());
			if(max1>k+mina) chkmax(ans,getans(1,max1));
			if(max0>k+mina&&k-max0+max1>=0) chkmax(ans,getans(0,max0));
			else{
				auto it=s[0].lower_bound(k+max1);
				if(it!=s[0].end()) chkmax(ans,getans(0,*it));
				if(it!=s[0].begin()){
					it--;
					chkmax(ans,getans(0,*it));
				}
			}
			printf("%lld\n",ans);
		}
	}
	return 0;
}