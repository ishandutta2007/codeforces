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

int main(){
    CASET{
        DRII(n,x);
        DRVI(n,a);
        int lastsmallerthanx=-1;
        bool isok=true;
        int bestres=0;
        REP(i,n){
            if (i and a[i-1]>a[i]) {// aie
                if (a[i]<x) {
                    isok=false; //if (a[i-1]>x)
                    //else {int z=a[i]; a[i]=x; x=z; bestres++; lastsmallerthanx=i;}
                }
                else{
                    //cout<<lastsmallerthanx<<" "<<i<<" "<<x<<" "<<a[i-1]<<" "<<a[i]<<endl;
                    int fhigher=lastsmallerthanx+1;
                    if (fhigher<i-1 and a[i-2]>a[i]) isok=false; 
                    REPP(j,fhigher,i){
                        if (a[j]!=x) {bestres++; x=a[j];}
                    }
                    //bestres+=(i-lastsmallerthanx-1);
                    //int z=x;
                    //x=a[i-1];
                    //a[i-1]=x;
                    lastsmallerthanx=i;
                }
            }
            else{
                if (a[i]<=x) lastsmallerthanx=i;
            }
        }
        if (!isok) bestres=-1;
        printf("%d\n",bestres);
    }
}