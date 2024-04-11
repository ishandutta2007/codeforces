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
    string s;
    cin>>s;
    s+='#';
    int mod=1000000007;
    VL nb(100001);
    int n=s.size();
    nb[1]=1;
    nb[2]=2;
    LL res=1;
    REPP(i,3,n+1){
        nb[i]=(nb[i-1]+nb[i-2])%mod;
    }
    int nbja=0;
    REP(i,n){
        if (s[i]=='m' or s[i]=='w') res=0;
        if (s[i]=='n' or s[i]=='u'){ 
            if (s[i]!=s[i-1]){
                if (nbja) {
                    res*=nb[nbja];
                    res%=mod;
                }
                nbja=0;
            }
            nbja++;
        }
        else{
            if (nbja) {
                res*=nb[nbja];
                res%=mod;
            }
            nbja=0;
        }
    }
    printf("%I64d\n",res);
}