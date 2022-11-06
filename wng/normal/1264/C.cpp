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

int mod = 998244353;

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

LL inv(int a){
    return powmod(a,mod-2);
}

VI p;
VL a,b;
int n,q;

LL comp(int st,int en){
    LL y = (a[st] * inv(a[en]) -1 + mod )%mod;
    LL W = (((b[en-1] - (st?b[st-1]:0)) - ((en-st) * a[en])%mod + mod) %mod);
    //cout<<"num "<<W;
    W*=inv((a[st] - a[en] + mod)%mod);
    //cout<<"denom "<<inv((a[st] - a[en] + mod)%mod)<<endl;
    W%=mod;
    LL res = ((en - st) + y*W)%mod;
    //cout<<st<<" "<<en<<" "<<y<<" w : "<<W<<" "<<res<<endl;
    return res;
}

int main(){
    RII(n,q);
    int i100=inv(100);
    /*cout<<"pour pas de cp"<<endl;
    cout<<"y : "<<3<<endl;
    cout<<"w : "<<((LL)4*inv(3))%mod<<endl;
    cout<<"pour pas de cp"<<endl;*/
    //calcul des ai
    p=VI(n);
    a=VL(n+1);
    b=VL(n+1);
    REP(i,n) {RI(p[i]);}
    a[0]=1;
    b[0]=1;
    REP(i,n) {
        a[i+1]=((a[i]*i100)%mod * (LL)p[i])%mod;
        b[i+1]=(b[i]+a[i+1])%mod;    
            }
    
    //cout<<"a : "; for (auto i:a) {cout<<i<<" ";} cout<<endl;
    //cout<<"b : "; for (auto i:b) {cout<<i<<" ";} cout<<endl;
    map<PII,LL> m;
    //compute wo cp
    m[{0,n}]=comp(0,n);
    LL res=m[{0,n}];
    //cout<<"for now, res = "<<res<<endl;
    REP(i,q){
        DRI(x);
        x--;
        auto it=m.lower_bound({x,x});
        //cout<<it->F.F<<" "<<it->F.S<<" "<<x<<endl;
        if (it!= m.end() and (it->F).F ==x) {
            int oldeb= it->F.S;
            auto it2=it;
            it2--;
            //cout<<x<<" "<<it->F.F<<" "<<it->F.S<<" "<<it2->F.F<<" "<<it2->F.S<<" are diff?\n";
            int oldsb= it2->F.F;
            LL ri=comp(oldsb,oldeb);
            res+=ri;
            res-=comp(oldsb,x);
            res-=comp(x,oldeb);
            res%=mod;
            res+=mod;
            res%=mod;
            m.erase(it);
            m.erase(it2);
            m[{oldsb,oldeb}]=ri;
        }
        else{
            it--;
            int oldeb= it->F.S;
            int oldsb= it->F.F;
            LL ri1=comp(oldsb,x);
            LL ri2=comp(x,oldeb);
            res+=ri1+ri2;
            res-=comp(oldsb,oldeb);
            res%=mod;
            res+=mod;
            res%=mod;
            m.erase(it);
            m[{oldsb,x}]=ri1;
            m[{x,oldeb}]=ri2;
        }
        printf("%I64d\n",res);
    }
}