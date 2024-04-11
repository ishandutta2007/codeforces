#include"bits/stdc++.h"


#define PB push_back
#define PF push_front
#define LB lower_bound
#define UB upper_bound
#define fr(x) freopen(x,"r",stdin)
#define fw(x) freopen(x,"w",stdout)
#define iout(x) printf("%d\n",x)
#define lout(x) printf("%lld\n",x)
#define REP(x,l,u) for(int x = (l);x<=(u);x++)
#define RREP(x,l,u) for(int x = (l);x>=(u);x--)
#define mst(x,a) memset(x,a,sizeof(x))
#define PII pair<int,int>
#define PLL pair<ll,ll>
#define MP make_pair
#define se second
#define fi first
#define dbg(x) cout<<#x<<" = "<<(x)<<endl;
#define sz(x) ((int)x.size())

typedef  long long ll;
typedef unsigned long long ull;
typedef double db;
typedef long double ld;
using namespace std;

const int maxn = 100010;
const int mod = 1e9+7,base=31;
const double eps = 1e-6;
const double PI = acos(-1);

template<typename T> inline void read(T &x){
x=0;T f=1;char ch;do{ch=getchar();if(ch=='-')f=-1;}while(ch<'0'||ch>'9');do x=x*10+ch-'0',ch=getchar();while(ch<='9'&&ch>='0');x*=f;
}

template<typename A,typename B> inline void read(A&x,B&y){read(x);read(y);}
template<typename A,typename B,typename C> inline void read(A&x,B&y,C&z){read(x);read(y);read(z);}
template<typename A,typename B,typename C,typename D> inline void read(A&x,B&y,C&z,D&w){read(x);read(y);read(z);read(w);}
template<typename A,typename B> inline A fexp(A x,B p){A ans=1;for(;p;p>>=1,x=1LL*x*x%mod)if(p&1)ans=1LL*ans*x%mod;return ans;}
template<typename A,typename B> inline A fexp(A x,B p,A mo){A ans=1;for(;p;p>>=1,x=1LL*x*x%mo)if(p&1)ans=1LL*ans*x%mo;return ans;}

int n,m,len,cnt,ans;

char st[maxn];

map<ull,int> mp[maxn];
map<pair<int,ull>,bool> mp2;

int has[maxn],A[maxn];

void calc(){
	REP(i,1,cnt)if(A[i]==-1)st[has[i]]='?';else st[has[i]]='a'+A[i];
	ull hs=0;
	int tmp=0;
	REP(i,1,len)if(st[i]!='?'){
		tmp++;
		hs=hs*base+st[i]-'a';
	}
	if(!mp2.count(MP(tmp,hs))){
		ans+=mp[tmp][hs];
		mp2[MP(tmp,hs)]=1;
	}
}

void dfs(int now){
	if(now==cnt+1){
		calc();
		return;
	}
	REP(i,-1,4){
		A[now]=i;
		dfs(now+1);
	}
}

void Work(){
	while(m--){
		scanf("%s",st+1);
		len=strlen(st+1);
		cnt=0;
		REP(j,1,len)if(st[j]=='?')has[++cnt]=j;
		ans=0;
		mp2.clear();
		dfs(1);
		iout(ans);
	}
}

void Init(){
	read(n,m);
	REP(i,1,n){
		scanf("%s",st+1);
		len=strlen(st+1);
		ull hs=0;
		REP(j,1,len)hs=hs*base+st[j]-'a';
		mp[len][hs]++;
	}
}

int main(){
	Init();
	Work();
	return 0;
}