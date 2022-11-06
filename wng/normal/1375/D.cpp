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

VI a;
VI t;
int n;

int mex(){
    REP(i,n+1){
        if (!t[i]) return i;
    }
    return -1;
}

int main(){
    CASET{
        RI(n);
        a=VI(n);
        t=VI(n+1,0);
        int nbd=0;
        REP(i,n){
            RI(a[i]);
            t[a[i]]++;
        }
        int mb=mex();
        VI res(0);
        while (mb<n){
            //cout<<"mx"<<mb<<endl;
            t[a[mb]]--;
            a[mb]=mb;
            t[mb]++;
            res.PB(mb+1);
            mb=mex();
        }
        REP(i,n){
            if (a[i]!=i){
                VI cycle(1,i);
                int ii=a[i];
                while (ii!=i){
                    cycle.PB(ii);
                    ii=a[ii];
                }
                cycle.PB(i);
                int v=n;
                for (auto c: cycle){
                    res.PB(c+1);
                    int y=a[c];
                    a[c]=v;
                    v=y;
                }
            }
        }
        assert(SZ(res)<=2*n);
        printf("%d\n",SZ(res));
        REP(i,SZ(res)){
            printf("%d%c",res[i], (i==SZ(res)-1)?'\n':' ');
        }
        if (!SZ(res)) {printf("\n");}
        /*for (auto i: a){
            cout<<i<<" ";
        }
        cout<<endl;*/
    }

}