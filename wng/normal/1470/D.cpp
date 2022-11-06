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
#define DRVI(N, X) VI X(N); for (int ___I=0; ___I<N; ___I++) scanf("%d", &(X[___I]))  
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

vector<VI> cs;
VI ps;


int findp(int i){
    if (ps[i]!=i) ps[i]=findp(ps[i]);
    return ps[i];
}

void merge(int i,int j){
    i=findp(i);
    j=findp(j);
    ps[j]=i;
}

int main(){
    CASET{
        DRII(n,m);
        cs=vector<VI>(n,VI(0));
        ps=VI(n);
        REP(i,n){
            ps[i]=i;
        }
        REP(i,m){
            DRII(x,y);
            x--; y--;
            cs[x].PB(y);
            cs[y].PB(x);
            merge(x,y);
        }
        int fpb=findp(0);
        bool isok=true;
        REPP(i,1,n){
            if (findp(i)!=fpb) isok=false; 
        }
        if (isok){
            VI arein(n,0);
            VI ved(n,0);
            ved[0]=1;
            queue<int> tp;
            tp.push(0);
            VI res(0);
            while (!tp.empty()){
                int z=tp.front();
                tp.pop();
                bool shouldiin=true;
                for (auto c: cs[z]){
                    if (arein[c]){
                        shouldiin = false;
                    }
                    if (!ved[c]) {tp.push(c); ved[c]=1;}
                }
                if (shouldiin){
                    arein[z]=1;
                    res.PB(z+1);
                }
            }
            int sr=SZ(res);
            printf("YES\n");
            printf("%d\n", sr);
            REP(i,sr) {printf("%d%c", res[i], (i==sr-1)?'\n':' ');}
        }
        else{
            printf("NO\n");
        }
    }
}