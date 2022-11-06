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
    CASET{
        DRIII(n,m,k);
        VI a(n);
        REP(i,n) RI(a[i]);
        VI b(m);
        REP(i,SZ(b)){
            b[i]=max(a[i],a[i+n-m]);
        }
        //cout<<"b :";
        //for (auto i:b) {cout<<i<<" ";} cout<<endl;
        k=min(k,m-1);
        // pour un certain j<=k je me tape un le choix entre   le a[j+p] et a[j+p+(n-m)] pour 0<=p<=m-1-i
        int cl=m-1-k;
        //cout<<"cl "<<cl<<endl;
        map<int,int> poss;
        int res=0;
        REP(i,cl+1){
            poss[b[i]]++;
        }
        res=poss.begin()->F;
        REPP(i,cl+1,SZ(b)){
            poss[b[i-cl-1]]--;
            if (!poss[b[i-cl-1]]) poss.erase(b[i-cl-1]);
            poss[b[i]]++;
            res=max(res,poss.begin()->F);
        }
        printf("%d\n",res);
    }

}