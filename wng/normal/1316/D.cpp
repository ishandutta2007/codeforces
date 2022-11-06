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

vector<VI> visited;
vector<VPII> targets;
int n;
vector<VI> res;

void dfs(int i,int j){
    if (!res[i][j]) {res[i][j]=5;}
    visited[i][j]=1;
    VPII nbs(0);
    if (i) { nbs.PB({i-1,j});}
    if (j) {nbs.PB({i,j-1});}
    if (i<n-1) {nbs.PB({i+1,j});}
    if (j<n-1) {nbs.PB({i,j+1});}
    for (auto c:nbs){
        if (!visited[c.F][c.S] and targets[c.F][c.S]==targets[i][j]){
            if (c.F==i-1) {res[c.F][c.S]=1;}
            if (c.F==i+1) {res[c.F][c.S]=2;}
            if (c.S==j-1) {res[c.F][c.S]=3;}
            if (c.S==j+1) {res[c.F][c.S]=4;}
            dfs(c.F,c.S);
        }
    }
}

int main(){
    RI(n);
    visited=vector<VI>(n,VI(n,0));
    targets=vector<VPII>(n,VPII(n,{-1,-1}));
    res=vector<VI> (n,VI(n,0));
    
    REP(i,n){
        REP(j,n){
            DRII(x,y);
            if (x>0) {
                x--; y--;
            }
            targets[i][j]={x,y};
        }
    }
    bool isok=true;
    REP(i,n){
        REP(j,n){
            if (targets[i][j]==MP(i,j)){
                dfs(i,j);
            }
            if (targets[i][j].F==-1){
                VPII nbs(0);
                if (i) { nbs.PB({i-1,j});}
                if (j) {nbs.PB({i,j-1});}
                if (i<n-1) {nbs.PB({i+1,j});}
                if (j<n-1) {nbs.PB({i,j+1});}
                //cout<<"checking "<<i<<","<<j<<endl;
                for (auto c:nbs){
                    //cout<<c.F<<" "<<c.S<<": "<<(targets[c.F][c.S]==targets[i][j])<<endl;
                    if (targets[c.F][c.S]==targets[i][j]){
                        if (c.F==i-1) {res[i][j]=2;}
                        if (c.F==i+1) {res[i][j]=1;}
                        if (c.S==j-1) {res[i][j]=4;}
                        if (c.S==j+1) {res[i][j]=3;}
                        break;
                    }
                }
            }
        }
    }

    REP(i,n){
        REP(j,n){
            if (!res[i][j]) isok=false;
        }
    }
    if (!isok){
        printf("INVALID\n");
    }
    else{
        printf("VALID\n");
        REP(i,n){
            REP(j,n){
                if (res[i][j]==1) {printf("D");}
                if (res[i][j]==2) {printf("U");}
                if (res[i][j]==3) {printf("R");}
                if (res[i][j]==4) {printf("L");}
                if (res[i][j]==5) {printf("X");}
            }
            printf("\n");
        }
    }

}