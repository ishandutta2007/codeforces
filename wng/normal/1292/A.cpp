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
    DRII(n,q);
    vector<VI> arelava(n,VI(2,0));
    vector<VI> areblocked(n,VI(2,0));
    vector<VI> nbblocking(n,VI(2,0));
    int totblock=0;
    REP(i,q){
        DRII(x,y);
        x--; y--;
        arelava[y][x]=1-arelava[y][x];

        if (arelava[y][x]){
            if (nbblocking[y][x]) {areblocked[y][x]=1; totblock++;}
            nbblocking[y][1-x]++;
            if (arelava[y][1-x] and !areblocked[y][1-x]) {areblocked[y][1-x]=1; totblock++;}
            if (y){
                nbblocking[y-1][1-x]++;
                if (arelava[y-1][1-x] and !areblocked[y-1][1-x]) {areblocked[y-1][1-x]=1; totblock++;}        
            }
            if (y<n-1){
                nbblocking[y+1][1-x]++;
                if (arelava[y+1][1-x] and !areblocked[y+1][1-x]) {areblocked[y+1][1-x]=1; totblock++;}            
            }
        }
        else{
            if (nbblocking[y][x]) {areblocked[y][x]=0; totblock--;}
            nbblocking[y][1-x]--;
            if (nbblocking[y][1-x]==0 and areblocked[y][1-x]) {areblocked[y][1-x]=0; totblock--;}
            if (y){
                nbblocking[y-1][1-x]--;
                if (nbblocking[y-1][1-x]==0 and areblocked[y-1][1-x]) {areblocked[y-1][1-x]=0; totblock--;}
            }
            if (y<n-1){
                nbblocking[y+1][1-x]--;
                if (nbblocking[y+1][1-x]==0 and areblocked[y+1][1-x]) {areblocked[y+1][1-x]=0; totblock--;}
            }
        }
        if (totblock) {printf("No\n");}
        else {printf("Yes\n");}
    }

}