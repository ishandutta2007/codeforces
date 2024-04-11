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
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin>>n;
    string s,t;
    cin>>s>>t;
    set<int> sb0;
    set<int> sb1;
    REP(i,n){
        if (s[i]!=t[i]){
            if (s[i]=='1'){
                sb1.insert(i);
            }
            else sb0.insert(i);
        }
    }
    if (SZ(sb0)!=SZ(sb1)) {cout<<"-1\n"; return 0;}

    int res=0;
    while (sb0.begin()!=sb0.end()){
        auto it0=sb0.begin();
        auto it1=sb1.begin();
        VI tr0(0),tr1(0);
        res++;
        if (*it0<*it1){
            while (it0!= sb0.end() and it1!=sb1.end()){
                it1=sb1.lower_bound(*it0);
                if (it1==sb1.end()) break;
                tr0.PB(*it0);
                tr1.PB(*it1);
                it0=sb0.lower_bound(*it1);
            }

        }
        else {
            while (it0!= sb0.end() and it1!=sb1.end()){
                it0=sb0.lower_bound(*it1);
                if (it0==sb0.end()) break;
                tr0.PB(*it0);
                tr1.PB(*it1);
                it1=sb1.lower_bound(*it0);
            }
        }
        for (auto i : tr0) sb0.erase(i);
        for (auto i : tr1) sb1.erase(i);
    }
    printf("%d\n",res);
}