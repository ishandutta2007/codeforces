#include <bits/stdc++.h>
typedef long long LL;
#define SZ(X) ((int)(X).size())
#define ALL(X) (X).begin(), (X).end()
#define REP(I, N) for (int I = 0; I < (N); ++I)
#define REPP(I, A, B) for (int I = (A); I < (B); ++I)
#define RI(X) scanf("%d", &(X))
#define RII(X, Y) scanf("%d%d", &(X), &(Y))
#define RIII(X, Y, Z) scanf("%d%d%d", &(X), &(Y), &(Z))
#define DRI(X) int (X); scanf("%d", &X)
#define DRII(X, Y) int X, Y; scanf("%d%d", &X, &Y)
#define DRIII(X, Y, Z) int X, Y, Z; scanf("%d%d%d", &X, &Y, &Z)
#define RS(X) scanf("%s", (X))
#define CASET int ___T, case_n = 1; scanf("%d ", &___T); while (___T-- > 0)
#define MP make_pair
#define PB push_back
#define MS0(X) memset((X), 0, sizeof((X)))
#define MS1(X) memset((X), -1, sizeof((X)))
#define LEN(X) strlen(X)
#define PII pair<int,int>
#define VI vector<int>
#define VL vector<long long>
#define VPII vector<pair<int,int> >
#define PLL pair<long long,long long>
#define VPLL vector<pair<long long,long long> >
#define F first
#define S second
    
using namespace std;
    
int main(){
    LL n,p,d,w;
    scanf("%I64d %I64d %I64d %I64d",&n,&p,&w,&d);
    LL a,b,c;
    LL pp=p;
    a=0;
    b=0;
    c=0;
    LL y=__gcd(d,w);
    if (p%y){ printf("-1\n"); return 0;}
    p/=y;
    pp/=y;
    d/=y;
    w/=y;
    LL z= d * w;
    a+=max((p-z)/w,(LL)0);
    p-=a*w;
    //cout<<z<<endl;
    //cout<<a<<" "<<b<<" "<<z<<" "<<p<<endl;
    for (int k=p/w;k>=0;k--){
        LL tr=p-k*w;
        if (tr>=0 and tr%d==0){
            a+=k;
            b+=tr/d;
            break;
        }
    }
    //cout<<a<<" "<<b<<" "<<a*w+b*d<<" "<<pp<<" "<<c<<" "<<n<<endl;
    c=n-a-b;
    if (c>=0 and a*w+b*d==pp){
        printf("%I64d %I64d %I64d\n",a,b,c);
    }
    else{
        printf("-1\n");
    }
    
}