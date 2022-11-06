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
VI visited;
    
vector<VPII> cs;
    
//good place : j'ai besoin de la parit
//bad place : j'ai besoin du nb total
    
LL resbad,resgood;
int isleft;
    
int visit(int i){
    if (!visited[i]){
        visited[i]=1;
        // cout<<"ving "<<i<<"\n";
        for (auto j:cs[i]){
            if (!visited[j.F]){
                int ch=j.F;
                int c=j.S;
                int vch=visit(ch);
          //        cout<<"ch :"<<ch<<" "<<vch<<","<<isleft;
                while (vch>isleft-vch) {vch-=2; isleft-=2;}
                resgood+=(vch%2)*c;
                visited[i]+=vch;
                int visbad=vch;
                resbad+=(LL)vch*c;
            //     cout<<" "<<vch<<" "<<vch*c<<" "<<(vch%2)*c<<endl;
            }
        }
        //cout<<"ved "<<i<<" "<<visited[i]<<"\n";
    }
    return visited[i];
}
    
    
int main(){
    DRI(nbt);
    while (nbt--){
        DRI(k);
        visited=VI(2*k,0);
        cs=vector<VPII>(2*k,VPII(0));
        REP(i,2*k-1){
            DRIII(x,y,c);
            x--; y--;
            cs[x].PB({y,c});
            cs[y].PB({x,c});
        }
        resbad=0;
        resgood=0;
        isleft=2*k;
        visit(0);
        printf("%I64d %I64d\n",resgood,resbad);
    }
}