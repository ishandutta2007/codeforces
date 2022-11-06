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

int main(){
    DRII(r,n);
    VI t(n+1,0);
    VI x(n+1,0);
    VI y(n+1,0);
    //cout<<"bordel"<<x[0]<<y[0]<<t[0]<<endl;
    VI res(n+1,0);
    int kk=0;
    int maxreached=-1;
    int rr=0;
    REPP(i,1,n+1){
        RIII(t[i],x[i],y[i]);
        x[i]--; y[i]--;
        int j=i-1;
        //cout<<"bordel"<<x[0]<<y[0]<<t[0]<<endl;
        while (kk<i and t[kk]<t[i]-1000) {maxreached=max(maxreached, res[kk++]);}
        int br=maxreached;
        //cout<<"fornow "<<br<<endl;
        while (j>=0 and t[j]>t[i]-1000) {
            //cout<<i<<" "<<j<<" eg "<<res[j]<<" "<<(abs(x[j]-x[i])+abs(y[j]-y[i]))<<" "<<(t[i]-t[j])<<endl;
            //cout<<"pff "<<x[i]<<" "<<x[j]<<" "<<y[i]<<" "<<y[j]<<endl;
            if (res[j]>br and abs(x[j]-x[i])+abs(y[j]-y[i])<=(t[i]-t[j])) br=res[j];
            j--;
        }
        res[i]= (br>=0)?(br+1):br;
        rr=max(res[i],rr);
        //cout<<"==>"<<res[i]<<endl;
    }
    printf("%d\n", rr);
}