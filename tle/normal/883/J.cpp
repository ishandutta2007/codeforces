#include"bits/stdc++.h"


#define PB push_back
#define PF push_front
#define LB lower_bound
#define UB upper_bound
#define fr(x) freopen(x,"r",stdin)
#define fw(x) freopen(x,"w",stdout)
#define iout(x) printf("%d\n",x)
#define lout(x) printf("%lld\n",x)
#define REP(x,l,u) for(ll x = (l);x<=(u);x++)
#define RREP(x,l,u) for(ll x = (l);x>=(u);x--)
#define mst(x,a) memset(x,a,sizeof(x))
#define PII pair<int,int>
#define PLL pair<ll,ll>
#define MP make_pair
#define se second
#define fi first
#define dbg(x) cout<<#x<<" = "<<(x)<<endl;
#define sz(x) ((int)x.size())
#define cl(x) x.clear()

typedef  long long ll;
typedef unsigned long long ull;
typedef double db;
typedef long double ld;
using namespace std;

const int maxn = 100010;
const int mod = 1e9+7;
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

int n,m;

int A[maxn];

ll sm[maxn];

int b[maxn],p[maxn];

PII B[maxn];

int mx[maxn];

priority_queue<int> Q;

ll TOT;int Ans;

int tmp[maxn],cnt;

void Work(){
	for(int i=m,j;i;i=j-1){
		for(j=i;j>1&&mx[j-1]==mx[j];j--);
		cnt=0;
		REP(k,j,i)tmp[++cnt]=B[k].se;
		sort(tmp+1,tmp+cnt+1);
		int pos=cnt;
		ll now=0;
		REP(k,1,cnt){
			if(now+tmp[k]<=sm[mx[i]])now+=tmp[k];
			else{
				pos=k-1;
				break;
			}
		}
		REP(k,1,pos){
			TOT+=tmp[k];
			Ans++;
			Q.push(tmp[k]);
		}
		while(TOT>sm[mx[i]]){
			int x=Q.top();Q.pop();
			TOT-=x;
			Ans--;
		}
	}
	printf("%d\n",Ans);
}

void Init(){
	read(n,m);
	REP(i,1,n)read(A[i]),sm[i]=sm[i-1]+A[i];
	REP(i,1,m)read(b[i]);
	REP(i,1,m)read(p[i]);
	REP(i,1,m)B[i]=MP(b[i],p[i]);
	sort(B+1,B+m+1);
	REP(i,1,n){
		int x=upper_bound(B+1,B+m+1,MP(A[i],1000000010))-B-1;
		mx[x]=i;
	}
	RREP(i,m,1)mx[i]=max(mx[i],mx[i+1]);
}

int main(){
	Init();
	Work();
	return 0;
}