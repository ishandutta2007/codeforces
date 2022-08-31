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

const int maxn = 1100000;
const double eps = 1e-6;
const double PI = acos(-1);

template<typename T> inline void read(T &x){
x=0;T f=1;char ch;do{ch=getchar();if(ch=='-')f=-1;}while(ch<'0'||ch>'9');do x=x*10+ch-'0',ch=getchar();while(ch<='9'&&ch>='0');x*=f;
}

template<typename A,typename B> inline void read(A&x,B&y){read(x);read(y);}
template<typename A,typename B,typename C> inline void read(A&x,B&y,C&z){read(x);read(y);read(z);}
template<typename A,typename B,typename C,typename D> inline void read(A&x,B&y,C&z,D&w){read(x);read(y);read(z);read(w);}
template<typename A,typename B> inline A fexp(A x,B p,A mo){A ans=1;for(;p;p>>=1,x=1LL*x*x%mo)if(p&1)ans=1LL*ans*x%mo;return ans;}

int n,m,a,Q,P;

int Ans[maxn];

int fac[maxn],Inv[maxn];

int Cnk(int n,int k){
	return 1LL*fac[n]*Inv[k]%P*Inv[n-k]%P;
}

void Work(){
	//cout<<P<<endl;
	REP(i,1,min(n,m+1))Ans[n-i+1]=(Ans[n-i+2]+Cnk(m,i-1))%P;
	RREP(i,n-min(n,m+1),1)Ans[i]=Ans[i+1];
	//REP(i,1,n)cout<<Ans[i]<<' ';cout<<endl;
	REP(i,1,n)printf("%d ",fexp(a,Ans[i],Q));
}

void Init(){
	read(n,m,a,Q);
	int now=1;
	for(int i=1;;i++){
		now=1LL*now*a%Q;
		if(now==1){
			P=i;
			break;
		}
	}
	fac[0]=1;REP(i,1,m)fac[i]=1LL*fac[i-1]*i%P;
	Inv[m]=fexp(fac[m],P-2,P);
	RREP(i,m-1,0)Inv[i]=1LL*Inv[i+1]*(i+1)%P;
}

int main(){
	Init();
	Work();
	return 0;
}