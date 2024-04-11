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
    DRI(n);
    vector<pair<PII,int>> croiss;
    vector<pair<PII,int>> decroiss;
    REP(i,n){
        DRII(x,y);
        if (x>y){ decroiss.PB({{x,y},i});}
        if (x<y){ croiss.PB({{x,y},i});}
    }
    if (croiss.size()>decroiss.size()){
        sort(croiss.rbegin(),croiss.rend());
        printf("%d\n",croiss.size());
        REP(i,croiss.size()){
            printf("%d%c",croiss[i].S+1,(i==croiss.size()-1)?'\n':' ');
        }
    }
    else{
        sort(decroiss.begin(),decroiss.end());
        printf("%d\n",decroiss.size());
        REP(i,decroiss.size()){
            printf("%d%c",decroiss[i].S+1,(i==croiss.size()-1)?'\n':' ');
        }
    }
}