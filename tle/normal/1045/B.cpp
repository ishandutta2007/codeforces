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
#define cl(x) x.clear()

typedef  long long ll;
typedef unsigned long long ull;
typedef double db;
typedef long double ld;
using namespace std;

const int maxn = 400010;
const int mod = 1e9+7;
const int MAX = 1000000010;
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

int n,m,ans;

int A[maxn],B[maxn],C[maxn],fail[maxn],Ans[maxn];

void Work(){
    if(n==1){
        iout(1);
        iout((A[1]+A[1])%m);
        return;
    }
    REP(i,2,n-1){
        int j;
        for(j=fail[i-1];j&&C[j+1]!=C[i];j=fail[j]);
        if(C[j+1]==C[i])fail[i]=j+1;
    }
    int now=0;
 //   REP(i,1,n-1)printf("%d ",C[i]);puts("");
//    REP(i,1,n*2-1)printf("%d ",B[i]);puts("");
    REP(i,1,n*2-2){
        while(now&&C[now+1]!=B[i])now=fail[now];
        if(C[now+1]==B[i])now++;
        if(now==n-1){
            ans++;
            int t=i-(n-1)+1;
            t=(n-t+1);
            Ans[ans]=(A[1]+A[t])%m;
        }
    }
    sort(Ans+1,Ans+ans+1);
    iout(ans);
    REP(i,1,ans)printf("%d ",Ans[i]);if(ans)puts("");
}

void Init(){
    read(n,m);
    REP(i,1,n)read(A[i]);
    RREP(i,n,2)B[n-i+1]=A[i]-A[i-1];B[n]=(A[1]-A[n]+m)%m;REP(i,1,n-1)B[i+n]=B[i];
    REP(i,1,n-1)C[i]=A[i+1]-A[i];
}

int main(){
    
    Init();
    
    Work();
    
    return 0;
}