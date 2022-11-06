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
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int nbt;
    cin>>nbt;
    while (nbt--){
        int n;
        cin>>n;
        vector<string> ss(n);
        VI p3(3,0);
        VI q3(3,0);
        REP(i,n){
            cin>>ss[i];
            REP(j,n){
                if (ss[i][j]=='X') p3[(i+j)%3]++;
                if (ss[i][j]=='O') q3[(i+j)%3]++;
                //if ((i+j)%3==2 and ss[i][j]=='X') ss[i][j]='O';
            }
        }
            int b=0;
            int b2=1;
            if (p3[2]+q3[1]<p3[b]+q3[b2]) {b=2; b2=1;}
            if (p3[0]+q3[2]<p3[b]+q3[b2]) {b=0; b2=2;}
            if (p3[1]+q3[0]<p3[b]+q3[b2]) {b=1; b2=0;}
            if (p3[2]+q3[0]<p3[b]+q3[b2]) {b=2; b2=0;}
            if (p3[1]+q3[2]<p3[b]+q3[b2]) {b=1; b2=2;}

        REP(i,n){
            REP(j,n){
                if ((i+j)%3==b and ss[i][j]=='X') ss[i][j]='O';
                if ((i+j)%3==b2 and ss[i][j]=='O') ss[i][j]='X';
            }
            cout<<ss[i]<<"\n";
        }

    }
}