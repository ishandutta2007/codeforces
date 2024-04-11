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

int main(){
    CASET{

        DRI(n);
        VI a(2*n);
        VI indimp(0);
        VI indp(0);
        int nbi=0;
        REP(i,2*n){
            RI(a[i]);
            if (a[i]%2){
                nbi++;
                indimp.PB(i);
            }
            else indp.PB(i);
        }
        int ii=0;
        int jj=0;
        if (nbi%2) {
            ii++;
            jj++;
        }
        else{
            if (nbi>=2) ii+=2;
            else jj+=2;
        }
        //cout<<ii<<" "<<jj<<" "<<SZ(indimp)<<" "<<SZ(indp)<<endl;
        while (ii+1<SZ(indimp)){
            printf("%d %d\n",indimp[ii]+1,indimp[ii+1]+1);
            ii+=2;
        }
        while (jj+1<SZ(indp)){
            printf("%d %d\n",indp[jj]+1,indp[jj+1]+1);
            jj+=2;
        }
        
    }

}