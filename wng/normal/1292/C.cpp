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

int n;
VI ps;
vector<VI> cs;
VI tc;


int findp(int i){
    if (ps[i]!=i){
        ps[i]=findp(ps[i]);
    }
    return ps[i];
}

void merge(int i,int j){
    ps[findp(j)]=ps[findp(i)];
}

PII b(int u,int v){
    if (ps[u]==v){
        return {tc[u],n-tc[u]};
    }
    else{
        PII z=b(v,u);
        return {z.S,z.F};
    }
}

int dfs(int i){
    if (ps[i]==-1) ps[i]=i;
    tc[i]=1;
    for (auto c:cs[i]){
        if (ps[c]==-1){
            ps[c]=i;
            tc[i]+=dfs(c);
        }
    }
    return tc[i];
}


int main(){
    RI(n);
    ps=VI(n,-1);
    tc=VI(n,0);
    vector<pair<PII,PII>> tt(0);
    cs=vector<VI>(n,VI(0));
    REP(i,n-1){
        DRII(x,y);
        x--; y--;
        cs[x].PB(y);
        cs[y].PB(x);
        tt.PB({{x,y},{y,x}});
    }
    dfs(0);
    LL mr=0;
    vector<VL> res(n,VL(n,-1));
    REP(i,n){res[i][i]=0;}
    while (SZ(tt)){
        //cout<<"will do :";
        vector<pair<PII,PII>> ntt(0);
        for (auto i:tt){
            int u=i.F.F;
            int v=i.S.F;
            int up=i.F.S;
            int vp=i.S.S;
            if (res[u][v]==-1){
          //      cout<<"("<<u<<" "<<v<<" "<<up<<" "<<vp<<")=";
                PII z=b(u,up);
                PII z2=b(vp,v);
                res[u][v]=max(res[u][vp],res[v][up])+(LL)z.F*z2.S;
                res[v][u]=res[u][v];
                for (auto c:cs[u]){ 
                    if (res[v][c]==-1) {ntt.PB({{c,u},{v,vp}});}
                }
                for (auto c:cs[v]){
                    if (res[u][c]==-1) ntt.PB({{u,up},{c,v}});
                }
                if (res[ps[u]][v]==-1) {ntt.PB({{ps[u],u},{v,vp}});}
                if (res[ps[v]][u]==-1) {ntt.PB({{ps[v],v},{u,up}});}
                mr=max(mr,res[u][v]);
           //     cout<<res[u][v]<<";";
            }
        }
        tt=ntt;
        //cout<<endl;
    }
    printf("%I64d\n",mr);
}