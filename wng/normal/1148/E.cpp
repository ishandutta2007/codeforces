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
    VPII s(n);
    VI t(n);
    LL ss=0;
    LL st=0;
    REP(i,n) {DRI(x); s[i]={x,i}; ss+=x;}
    REP(i,n) {RI(t[i]); st+=t[i];}
    if (ss!=st) {printf("NO\n"); return 0;}
    sort(s.begin(),s.end());
    sort(t.begin(),t.end());
    priority_queue<pair<PII,int>> droite;
    priority_queue<pair<PII,int>> gauche;
    REP(i,n){
        //<<s[i].S<<" ";
        if (s[i].F<t[i]) {droite.push({{t[i],t[i]-s[i].F},s[i].S});}
        if (t[i]<s[i].F) {gauche.push({{t[i],s[i].F-t[i]},s[i].S});}
    }
    //cout<<endl;
    bool isok=true;
    vector<pair<PII,int>> res;
    while (!droite.empty()){
        auto d=droite.top();
        auto g=gauche.top();
        int parc=0;
        int initdroite=d.F.F-d.F.S;
        int initgauche=g.F.F+g.F.S;
        //cout<<p1<<" "<<p2<<" {"<<droite[p1].F.S<<","<<droite[p1].F.S<<"}";
        parc=min(min(d.F.S,g.F.S),(initgauche-initdroite)/2);
        res.PB({{d.S,g.S},parc});
        droite.pop();
        gauche.pop();
        if (parc<d.F.S) {droite.push({{d.F.F,d.F.S-parc},d.S});}
        if (parc<g.F.S) {gauche.push({{g.F.F,g.F.S-parc},g.S});}
        //cout<<initdroite<<" "<<initgauche<<" "<<parc<<endl;
        if (!parc or res.size()>5*n) {isok=false; break;}
    }
    if (isok){
        printf("YES\n");
        int rs=res.size();
        printf("%d\n",rs);
        REP(i,rs){
            printf("%d %d %d\n",res[i].F.F+1,res[i].F.S+1,res[i].S);
        }
    }
    else { printf("NO\n");}
}