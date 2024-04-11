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
    int nt;
    cin>>nt;
    REP(t,nt){
        int n,k;
        VPII ops(0);
        cin>>n>>k;
        string s;
        cin>>s;
        VI ss(n);
        REP(i,n) {ss[i]=s[i]=='('?1:-1;}
        VI reqs(n);
        REP(i,n) {reqs[i]=(i%2)?-1:1;}
        //phasepourrie
        int pp=n/2-k +1;
        REP(i,pp) reqs[i]=1;
        REPP(i,pp,2*pp) reqs[i]=-1;
        VI signs(n,1);
        VI es(n);
        int nextdif=0;
        REP(i,n){
            int initchar=s[i]=='('?1:-1;
            initchar*=signs[i];
            if (initchar!=reqs[i]) {
                        nextdif=max(nextdif,i);
                        while (nextdif<n and (ss[nextdif]*signs[nextdif]==initchar)) nextdif++;
                        signs[nextdif]*=-1;
                        ops.PB({i+1,nextdif+1});
            }
        }
        cout<<ops.size()<<"\n";
        for (auto i: ops) {cout<<i.F<<" "<<i.S<<"\n";}
    }
}