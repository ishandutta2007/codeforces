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
    //toute zone assez grande (>=10 ou 15) contient un truc. On mate juste les zones plus petites.
    string s;
    cin>>s;
    int n=s.size();
    int nbbad=0;
    int beststart=-1;
    REP(i,n){
        for(int j=1;i-2*j>beststart;j++){
            if (s[i]==s[i-j] and s[i]==s[i-2*j]) {
                //cout<<i<<" "<<j<<" is good"<<endl;
                beststart=i-2*j;
                break;
            }
        }
        nbbad+=i-beststart;
    }
    //cout<<(LL)n*(n-1)/2+n<<" "<<nbbad<<endl;
    LL res=(LL)n*(n-1)/2+n-nbbad;
    printf("%I64d\n",res);
}