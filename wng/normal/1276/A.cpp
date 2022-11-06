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
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin>>t;
    while (t--){
        string s;
        cin>>s;
        int n(s.size());
        VI tbr(n);
        REP(i,n){
            if (i>1 and i<n-2){
                if (s.substr(i-2,5)=="twone") {tbr[i]=1;}
            }
        }
        REP(i,n){
            if (i and i<n-1){
                if (s.substr(i-1,3)=="two" and not tbr[i+1]) {tbr[i]=1;}
            }
            if (i and i<n-1){
                if (s.substr(i-1,3)=="one" and not tbr[i-1]) {tbr[i]=1;}
            }
        }

        int nbr(0);
        REP(i,n) {nbr+=tbr[i];}
        cout<<nbr<<"\n";
        if (nbr){
            REP(i,n){
                if (tbr[i]){
                    cout<<i+1;
                    if (--nbr) cout<<" ";
                    else cout<<"\n";
                }
            }
        }
    }

}