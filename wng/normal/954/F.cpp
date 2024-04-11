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

int code(int c[3]){
    return ((c[0])?1:0)+((c[1])?2:0)+((c[2])?4:0);
}

#define m3 

int mod=1000000007;

vector<VI> mm(vector<VI> a,vector<VI> b){
        vector<VI> res(a.size(),VI(b[0].size(),0));
        REP(i,a.size()){
            REP(j,b[0].size()){
                LL cij=0;
                REP(k,b.size()){
                    cij+=(LL)a[i][k]*b[k][j];
                }
                cij%=mod;
                res[i][j]=cij;
            }
        }
        return res;
    }

vector<VI> powm(vector<VI> a,LL n){
    int s=a.size();
    vector<VI> res(a.size(), VI(a.size(),0));
    if (n==0) {
        REP(i,s){REP(j,s){res[i][j]=(i==j)?1:0;}}
        return res;}
    else {
        if (n==1) {
            REP(i,s){REP(j,s){res[i][j]=a[i][j];}}
            return res;
        }
        else {
            res=powm(a,n/2);
            return mm(mm(res,res),powm(a,n%2));
        }
    }
}

vector<VI> matfromcode(int c){
    vector<VI> res(3,VI(3,1));
    res[0][2]=0;
    res[2][0]=0;
    int i=1;
    REP(j,3){ if (i&c) {REP(k,3){res[k][j]=0;}} i<<=1;}
    return res;
}

int main(){
    int n; 
    LL m;
    scanf("%d %I64d",&n,&m);
    vector<pair<LL,int>> d;
    int pows[] = {1,2,4};
    for (int i=0;i<2*n;i+=2){
        int a;
        LL l,r;
        scanf("%d %I64d %I64d",&a,&l,&r);
        d.PB({l-1,a});
        d.PB({r,-a});
    }
    d.PB({0,0});
    sort(d.begin(),d.end());
    int mt=0;
    LL cst=0;
    int c[3]={0,0,0};
    map<pair<LL,LL>,int> lt;
    auto it=d.begin();
    while (it!=d.end()){
        LL w=it->F;
        while (it!=d.end() and it->F==w){
            int a=it->S;
            if (a>0) {c[a-1]++;}
            else {c[-a-1]--;}
            it++;
        }
        int nt=code(c);
        if (nt!=mt) { lt[{cst,w}]=mt; mt=nt; cst=w;}
    }
    if (cst<m) {lt[{cst,m}]=0;}
    
    vector<VI> res(3,VI(3,0));
    res[0][0]=1;
    res[1][1]=1;
    res[2][2]=1;
    for (auto i: lt) {
            //cout<<" "<<i.F.F<<" "<<i.F.S<<" "<<i.S<<endl;
           // REP(i,3){REP(j,3){cout<<mfc[i][j]<<" ";}cout<<endl;}
            res=mm(res,powm(matfromcode(i.S),i.F.S-max(i.F.F,(LL)1)));
           // REP(i,3){REP(j,3){cout<<res[i][j]<<" ";}cout<<endl;}
        }
    cout<<res[1][1]<<endl;
    
}