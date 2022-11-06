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



map<LL,LL> f;
map<LL,LL> df;
map<LL,LL> dg;
map<LL,LL> g;

LL getdf(LL x){
    auto it=df.lower_bound(x+1);
    if (it==df.begin()) return 0;
    it--;
    LL k = it->F;
    LL v = it->S;
    return v;
}

LL getdg(LL x){
    auto it=dg.lower_bound(x+1);
    if (it==dg.end()) return 0;
    LL k = it->F;
    LL v = it->S;
    return v;
}

LL getf(LL x){
    auto it=f.lower_bound(x);
    if (it==f.begin()) return 0;
    it--;
    LL k = it->F;
    LL v = it->S;
    LL vdf= df[k];
    return v+vdf*(x-k);
}

LL getg(LL x){
    auto it=g.lower_bound(x+1);
    if (it==g.end()) return 0;
    LL k = it->F;
    LL v = it->S;
    LL vdg= dg[k];
    //cout<<"kk"<<k<<" "<<v<<" "<<x<<" "<<vdg<<endl;
    return v+vdg*(k-x);
}


bool isxpossible(LL x, LL mxp){
    LL tt=1<<30;
    LL res=0;
    while (tt){
        LL tatt=res+tt;
        if (getdf(tatt)-getdg(tatt+x)<0) res=tatt;
        //cout<<"pff "<<tatt<<" "<<tt<<" "<<min(tatt,tatt+x)<<" "<<getdf(tatt)-getdg(tatt+x)<<endl;
        tt>>=1;
    }
    res++;
    //cout<<x<<" "<<res<<" "<<getf(res)<<" "<<getg(res+x)<<endl;
    return getf(res)+getg(res+x)<=mxp;
}

int main(){
    LL n,k;
    scanf("%I64d %I64d",&n,&k);
    VI a(n);
    REP(i,n){
        RI(a[i]);
    }
    sort(a.begin(),a.end());
    LL cdf=0;
    for (auto i:a){
        cdf++;
        df[i]=cdf;
        if (dg.find(i) == dg.end()) dg[i]=n-cdf+1;
    }
    LL cf=0;
    cdf=0;
    LL pk=0;
    for (auto it: df){
        LL k,v;
        k=it.F;
        v=it.S;
        cf+=(LL)cdf*(k-pk);
        f[k]=cf;
        pk=k;
        cdf=v;
    }
    LL cg=0;
    LL cdg=0;
    for (auto it= dg.rbegin();it!=dg.rend(); it++){
        LL k,v;
        k=it->F;
        v=it->S;
        cg+=(LL)cdg*(pk-k);
        g[k]=cg;
        pk=k;
        cdg=v;
    }
   /* for (auto i: df){
        cout<<i.F<<","<<i.S<<" ";
    }
    cout<<endl;
    for (auto i: f){
        cout<<i.F<<","<<i.S<<" ";
    }
    cout<<endl;
    for (auto i: dg){
        cout<<i.F<<","<<i.S<<" ";
    }
    cout<<endl;
    for (auto i: g){
        cout<<i.F<<","<<i.S<<" ";
    }
    cout<<endl;
    cout<<getdf(5)<<" "<<getf(5)<<" "<<getdg(5)<<" "<<getg(5)<<endl;
    cout<<getdf(2)<<" "<<getf(2)<<" "<<getdg(2)<<" "<<getg(2)<<endl;
    cout<<getdf(1)<<" "<<getf(1)<<" "<<getdg(1)<<" "<<getg(1)<<endl;
*/

    LL tt=1<<30;
    LL res=-1;
    while (tt){
        if (res+tt>=0 and not isxpossible(res+tt,k)) res+=tt;
        tt>>=1;
    }
    printf("%d\n",res+1);
           
}