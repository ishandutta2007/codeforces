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
#define DRVI(N, X) VI X(N); for (int ___I=0; ___I<n; ___I++) scanf("%d", &(X[___I]))  
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

VPII res(0);

void solve(int start, int end){
    int siz=end-start;
    int tt=0;
    //cout<<start<<" "<<end<<" "<<siz<<endl;
    REP(p2,20){
        if (siz==(1<<p2)) {
            tt=siz;
            if (end==start+2){
                res.PB({start,start+1});
            }
            else{
                int mid=(end+start)/2;
                REP(i,tt/2){
                    res.PB({start+i,mid+i});
                }
                solve(start,mid);
                solve(mid,end);
            }
            break;
        }
        if (siz<(1<<p2)){
            tt=(1<<(p2-1));
            solve(start, start+tt);
            solve(end-tt, end);
            break;
        }
    }

}

int main(){
    DRI(n);
    if (n==1){
        printf("0\n");
        return 0;
    }
    solve(1,n+1);
    int m=SZ(res);
    printf("%d\n",m);
    REP(i,m){
        printf("%d %d\n", res[i].F, res[i].S);
    }
}