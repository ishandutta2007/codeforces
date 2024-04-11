#include <bits/stdc++.h>
typedef long long LL;
#define SZ(X) ((int)(X).size())
#define ALL(X) (X).begin(), (X).end()
#define RALL(X) (X).rbegin(), (X).rend()
#define REP(I, N) for (int I = 0; I < (N); ++I)
#define REPP(I, A, B) for (int I = (A); I < (B); ++I)
#define RI(X) scanf("%d", &(X))
#define RII(X, Y) scanf("%d%d", &(X), &(Y))
#define RIII(X, Y, Z) scanf("%d%d%d", &(X), &(Y), &(Z))
#define DRI(X) int (X); scanf("%d", &X)
#define DRII(X, Y) int X, Y; scanf("%d%d", &X, &Y)
#define DRIII(X, Y, Z) int X, Y, Z; scanf("%d%d%d", &X, &Y, &Z)
#define DRVI(N, X) VI X(N); for (int ___I=0; ___I<n; ___I++) scanf("%d", &(X[___I]))  
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


set<PII> env;

void insert(PII a){
    auto it=env.upper_bound(a);
  //  cout<<"oui"<<endl;
    //cout<<it!=env.end()<<"  "<<it->F==a.F<<" "<<it->S>=a.S)
    if (it!=env.end() and (it->F==a.F or it->S>=a.S)) return;
   // cout<<"non"<<endl;
    auto it2=it;
    while (it!=env.begin() and it->S<=a.S){
        it--;
    }
    if (it->S>a.S) it++;
    env.erase(it,it2);
    env.insert(a);
}

int main(){
    DRII(n,m);
    VPII r(n);
    REP(i,n){
        DRII(x,y);
        r[i]={x,y};
    }
    VPII s(m);


    REP(i,m){
        DRII(x,y);
        s[i]={x,y};
        REP(j,n){
            PII a={x-r[j].F,y-r[j].S};
            //cout<<i<<" "<<j<<" "<<a.F<<" "<<a.S<<endl;
            if (min(a.F,a.S)>=0) {insert(a);}
           // cout<<(min(a.F,a.S)>=0)<<"sz"<<SZ(env)<<endl;
        }
    }
    if (SZ(env)==0){
        printf("0\n");
    }
    else{
        int res=1<<30;
        //printf("ENV\n");
        PII pa={-1,-1};
        for (auto a:env){
          //  cout<<a.F<<" "<<a.S<<endl;
            //res=min(res,a.F+a.S+1);
            if (pa.F>=0) {
                res=min(res, pa.F+a.S+2);
            }
            pa=a;
        }
        res= min(env.begin()->S+1,res);
        res= min(env.rbegin()->F+1,res);
        
        printf("%d\n",res);
    }

}