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
    CASET{
        DRI(n);
        map<int,int> nbz1;
        set<PII> events;
        REP(i,n){
            DRII(l,r);
            events.insert({l,-i-1});
            events.insert({r,i+1});
        }
        VI res(n,0);
        int cur=0;
        int cnbz1=0;
        int cnbz0=0;
        int lwn=-1;
        int lwt=-1;
        bool couldibein=false;
        bool couldibein0=false;
        int nbz0=0;
        for (auto i:events){
            int whn=i.F;
            int wht=i.S;
            if (wht<0){
                if (couldibein) {cnbz1++; nbz1[lwn]=cnbz1;}
                couldibein=false;
                res[-wht-1]-=cnbz1;
                cur++;
            }
            else{
                cur--;
                if (cur==1) couldibein=true;
                else couldibein=false;
                if (!cur) {nbz0++;}
                res[wht-1]+=cnbz1;
                if (wht==-lwt and cur==0) res[wht-1]--; 
            }
            lwn=whn;
            lwt=wht;
        }
       // cout<<"res"<<endl;
       // for (auto i:res) {cout<<i<<" ";} cout<<endl;
        int mx=res[0];
        REP(i,n) {mx=max(mx,res[i]);}
        printf("%d\n",nbz0+mx);
    }
}