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
    int n,m;
    scanf("%d%d",&n,&m);
    vector<int> dnbs(m+1,0);
    
    REP(i,n) {
        int a,b;
        RII(a,b);
        a--;
        dnbs[a]++;
        dnbs[b]--;
    }
    vector<int> cnt(1,0);
    cnt.PB(dnbs[0]+1);
    REPP(i,1,m+1) {cnt.PB(cnt.back()+dnbs[i]); }
 /* for (auto i: cnt) {printf("%d ",i);}
   printf("\n");
  /* for (auto i: dnbs) {printf("%d ",i);}*/
    assert(cnt.back()==1);
    //OK J'ai ma fonction, maintenant c parti pour trouver la plus longue 
    //soussequence croissante qui finit en i pour tout i
    vector<int> st(n+2,0);
    vector<int> ssmax(1,0);
    REPP(i,1,m+1){
        //get current max
        int ii=cnt[i];
        int mr=0;
        while (ii>=1) {
            mr=max(mr,st[ii]);
            ii-=(ii&-ii);
        }
        mr++; 
       // cout<<i<<" "<<mr<<endl;
        //now update
        ii=cnt[i];
        while (ii>0 and ii<=n+1) {
            st[ii]=max(mr,st[ii]);
            ii+=(ii&-ii);
        }
        ssmax.PB(mr);
    }   
 /* for (auto i: st) printf("%d ",i);
    printf("\n");
    for (auto i: ssmax) printf("%d ",i);
    printf("\n");/**/
    //La meme pour le tableau inverse (partant de la fin).
     vector<int> st2(n+2,0);
     vector<int> ssmaxinv(1,0);
     int res=0;
     int bestmid=0;
     REPP(i,1,m+1){
        //get current max
        int ii=cnt[m+1-i];
        int mr=0;
        while (ii>=1) {
            mr=max(mr,st2[ii]);
            ii-=(ii&-ii);
        }
        mr++;
        //now update
        ii=cnt[m+1-i];
        while (ii>0 and ii<=n+1) {
            st2[ii]=max(mr,st2[ii]);
            ii+=(ii&-ii);
        }
        ssmaxinv.PB(mr);
        if (ssmaxinv.back()+ssmax[m+1-i] > res) 
        {
            res=ssmaxinv.back()+ssmax[m+1-i];
            bestmid=i;
        }/**/
    }
   /*for (auto i: st2) printf("%d ",i);
    printf("\n");
    for (auto i: ssmaxinv) printf("%d ",i);
    printf("\n");/**/
    printf("%d\n",res-1);
 //   printf("%d",bestmid);
}