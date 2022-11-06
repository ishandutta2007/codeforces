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
    DRI(t);
    while (t--){
        DRII(n,m);
        bool atleast1,atleast1corner,atleast1ontheside,atleast1side, allofthem;
        atleast1=false;
        atleast1corner=false;
        atleast1side=false;
        atleast1ontheside=false;
        allofthem=true;
        vector<VI> a(n,VI(m,0));
        REP(i,n){
            char s[65];
            RS(s);
            REP(j,m){
                if (s[j]=='A'){
                    a[i][j]=1;
                    atleast1=true;
                }
                else {
                    allofthem=false;
                }
            }
        }
        if (a[0][0]) atleast1corner=true;
        if (a[0][m-1]) atleast1corner=true;
        if (a[n-1][0]) atleast1corner=true;
        if (a[n-1][m-1]) atleast1corner=true;

        bool it=true;
        REP(i,n) {if (!a[i][0]) it=false; else atleast1ontheside=true;}
        if (it) atleast1side=true;
        it=true;
        REP(i,n) {if (!a[i][m-1]) it=false; else atleast1ontheside=true;}
        if (it) atleast1side=true;
        it=true;
        REP(j,m) {if (!a[n-1][j]) it=false; else atleast1ontheside=true;}
        if (it) atleast1side=true;
        it=true;
        REP(j,m) {if (!a[0][j]) it=false; else atleast1ontheside=true;}
        if (it) atleast1side=true;
        int res=5;

        int maxfromup=0;
        int maxfrombot=0;
        REP(i,n){
            int j=0;
            while (j<m and a[i][j]) j++;
            maxfromup=max(maxfromup,j);
        }
        REP(i,n){
            int j=m-1;
            while (j>=0 and a[i][j]) j--;
            maxfrombot=max(maxfrombot,m-1-j);
        }

        int maxfromiup=0;
        int maxfromibot=0;
        REP(j,m){
            int i=0;
            while (i<n and a[i][j]) i++;
            maxfromiup=max(maxfromiup,i);
        }
        REP(j,m){
            int i=n-1;
            while (i>=0 and a[i][j]) i--;
            maxfromibot=max(maxfromibot,n-1-i);
        }

        if (allofthem) res=0;
        if (atleast1side) res=min(res,1);
        if (atleast1ontheside) res=min(res,3);
        if (atleast1corner) res=min(res,min(2,min(n,m)));
        if ((max(maxfromup,maxfrombot)>=m) or (max(maxfromiup,maxfromibot)>=n)) res=min(res,2);
        if ((maxfromup+maxfrombot>=m) or (maxfromiup+maxfromibot>=n)) res=min(res,3);
        
        if (atleast1) res=min(res,4);
        if (res<5) printf("%d\n",res);
        else printf("MORTAL\n");
    }

}