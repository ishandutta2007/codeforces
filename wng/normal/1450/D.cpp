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
#define DRVI(N, X) VI X(N); for (int ___I=0; ___I<N; ___I++) scanf("%d", &(X[___I]))  
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
    CASET{
        DRI(n);
        DRVI(n,a);
        vector<VI> zz(n+1,VI(2,0));
        set<PII> sg;
        sg.insert({0,1});
        VI intervmax(n,-1);
        REP(i,n){
            int ai=a[i];
            auto lb=sg.lower_bound({-ai,-i});
            int when=-(lb->S);
            //cout<<"iwhen"<<i<<" "<<when<<endl;
            intervmax[i]+=(i-when);
            sg.erase(sg.begin(), lb);
            sg.insert({-ai,-i});
        }
        set<PII> sd;
        sd.insert({0,-n});
        for (int i=n-1; i>=0; i--){
            int ai=a[i];
            auto lb=sd.lower_bound({-ai,-i});
            int when=-(lb->S);
            //cout<<"iwhen2 "<<i<<" "<<when<<" ("<<(-(lb->F))<<")"<<endl;
            intervmax[i]+=(when-i);
            sd.erase(sd.begin(),lb);
            sd.insert({-ai,-i});
        }
        //cout<<"les interv max"<<endl;
        //for (auto i:intervmax) {cout<<i<<" ";} cout<<endl;

        REP(i,n){
            zz[a[i]].PB(intervmax[i]);
        }
        REP(i,n+1){
            sort(RALL(zz[i]));
        }
        VI dk(n+2,0);
        REPP(i,1,n+1){
            int nip=n-i+1;
            int z0=zz[i][0];
            int z1=zz[i][1];
            if (z0<nip){
                dk[z0+1]--;
                dk[nip+1]++;
            }
            if (nip<z0){
                dk[nip+1]--;
                dk[z0+1]++;
            }
            if (min(z1, nip)) {dk[1]--; dk[min(z1, nip)+1]++;}
        }
        //cout<<"les dk\n";
        //for (auto i: dk) {cout<<i<<" ";} cout<<endl;
        int ck=0;
        REPP(i,1,n+1){
            ck+=dk[i];
            if (ck<0) {printf("0");}
            else {printf("1");}
        }
        printf("\n");
    }
}