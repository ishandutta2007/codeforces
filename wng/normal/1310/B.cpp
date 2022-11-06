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
    DRII(n,k);
    VI a(k);
    REP(i,k){
        RI(a[i]); a[i]--;
    }
    sort(ALL(a));
    VI r(1<<(n-1));
    REP(i,k){r[a[i]/2]++;}
    int res=k?1:0;
    for (auto i:r) {if (i) res++;}
    vector<VI> ra(1<<(n-2),VI(4,-4*(1<<n)));
    REP(i,SZ(ra)){
        if (max(r[2*i],r[2*i+1])>=2) {
            ra[i][3]=0;
        }
        else {
            if (min(r[2*i],r[2*i+1])){
                ra[i][1]=0;
                ra[i][2]=0;
                ra[i][3]=0;
            }
            else {
                if (max(r[2*i],r[2*i+1])){
                    ra[i][1]=0;
                    ra[i][2]=0;   
                }
                else {
                    ra[i][0]=0;
                }   
            }
        }
    }
    int kk=n-3;
    //cout<<kk<<" "<<res<<endl;
    int lim=-4*(1<<n);
    //for (auto i:ra) {cout<<"("<<i[0]<<","<<i[1]<<","<<i[2]<<","<<i[3]<<"),";} cout<<endl;
    while (kk>=0){
        vector<VI> nra(1<<kk,VI(4,lim));
        REP(i,SZ(nra)){
            nra[i][0]=max(lim,ra[2*i][0]+ra[2*i+1][0]);
            nra[i][1]=max(max(max(lim,ra[2*i][1]+ra[2*i+1][1]+2),ra[2*i][1]+ra[2*i+1][0]+1),ra[2*i][0]+ra[2*i+1][1]+1);
            nra[i][2]=max(max(max(lim,ra[2*i][2]+ra[2*i+1][2]+4),ra[2*i][2]+ra[2*i+1][0]+2),ra[2*i][0]+ra[2*i+1][2]+2);
            nra[i][3]=max(max(max(lim,ra[2*i][3]+ra[2*i+1][0]+3),ra[2*i][3]+ra[2*i+1][1]+4),ra[2*i][3]+ra[2*i+1][2]+5);
            nra[i][3]=max(max(max(nra[i][3],ra[2*i][0]+ra[2*i+1][3]+3),ra[2*i][1]+ra[2*i+1][3]+4),ra[2*i][2]+ra[2*i+1][3]+5);
            nra[i][3]=max(max(max(nra[i][3],ra[2*i][3]+ra[2*i+1][3]+6),ra[2*i][1]+ra[2*i+1][2]+3),ra[2*i][2]+ra[2*i+1][1]+3);
        }
        ra=nra;
        kk--;
      // for (auto i:nra) {cout<<"("<<i[0]<<","<<i[1]<<","<<i[2]<<","<<i[3]<<"),";} cout<<endl;
    }
    int madd=-4;
    REP(i,4) {madd=max(madd,ra[0][i]+i);}

    printf("%d\n",res+madd);

}