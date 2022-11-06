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

const int mod= 1000000009;

pair<int, pair<int, int> > bezout(int a, int b) {
    int x = 1, y = 0;
    int xLast = 0, yLast = 1;
    int q, r, m, n;
    while(a != 0) {
        q = b / a;
        r = b % a;
        m = xLast - q * x;
        n = yLast - q * y;
        xLast = x, yLast = y;
        x = m, y = n;
        b = a, a = r;
    }
    return make_pair(b, make_pair(xLast, yLast));
}

LL powmod(int a, int n){
    LL res=1;
    if (n>1){
    res=powmod(a,n/2);
    res*=res;
    }
    res%=mod;
    res*=(n%2)?a:1;
    res%=mod;
    return res;
}

int inv(int a){
    pair<int, pair<int, int> > p=bezout(a,mod);
    int q=p.S.F;
    return ((q%mod)+mod)%mod;
}

int main(){
    int n,a,b,k;
    RII(n,a);
    RII(b,k);
    VI s;
    char c;
    scanf("%c",&c); //new line
    REP(i,k){
        int sig;
        scanf("%c",&c);
        //cout<<c<<endl;
        sig=(c=='+')?1:-1;
        s.PB(sig);
    }
    k=min(k,n+1);
    int bsa= ((LL)inv(a)*b)%mod;
    int bsak=powmod(bsa,k);
 //   cout<<a<<" "<<inv(a)<<" "<<bsa<<" "<<bsak<<endl;
    int r=(n+1)/k;
    if ((n+1)%k){
        r++;
    }
    int N=r*k-1;
    LL f2;
    if (bsak!=1){
    int bsakr=powmod(bsak,r);
    int invbsakm1=inv(bsak-1);
    f2=((LL)(bsakr-1)*invbsakm1)%mod;
   // cout<<bsak-1<<" "<<invbsakm1<<" "<<((LL)(bsak-1)*invbsakm1)%mod<<endl;
    }
    else
    {
        f2=r;
        }
    LL skm1=0;
    LL an=powmod(a,n);
    int fact=an;
    REP(i,k){
        skm1+=s[i]*fact;
        fact = ((LL)fact*bsa)%mod;
        skm1%=mod;
    }
    LL residus=0;
    LL bn=powmod(b,n);
    fact=bn;
    fact = ((LL)fact*bsa)%mod;
    REPP(i,n+1,N+1){
        residus+=fact*s[i%k];
        fact=((LL)fact*bsa)%mod;
        residus%=mod;
    }
   // cout<<bsakr<<"   "<<invbsak<<" "<<bsak<<" "<<r<<" "<<N<<" "<<f2<<endl;
    //for (auto i:s){cout<<i<<" ";} cout<<endl;
  //  cout<<skm1<<" "<<residus<<" "<<f2<<" "<<bsa<<endl;
    LL res=((skm1*f2)%mod-residus+mod)%mod;
    cout<<res;
}