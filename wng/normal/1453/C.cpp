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
        vector<VI> t(n,VI(n,0));
        REP(i,n){
            cin>>ss[i];
            REP(j,n) {t[i][j]=ss[i][j]-'0';}
        }
        vector<VI> mdb(10,VI(n,0));
        VI curb2a(10,0);
        REP(i,n){
            VI mind(10,-1);
            VI maxd(10,-1);
            REP(j,n){
                if (mind[t[i][j]]==-1){
                    mind[t[i][j]]=j;
                }
                maxd[t[i][j]]=j;
            }
            REP(d,10){
                if (mind[d]!=maxd[d]) { curb2a[d]=max(curb2a[d],(maxd[d]-mind[d])*max(i,n-1-i));}
                if (mind[d]!=-1){
                    mdb[d][i]=max(max(mind[d],n-1-mind[d]),max(maxd[d],n-1-maxd[d]));
                    REP(j,i){
                        if (mdb[d][j]) curb2a[d]=max(curb2a[d], (i-j)*max(mdb[d][i],mdb[d][j]));
                    }
                }
            }
        }
        vector<VI> mdb2(10,VI(n,0));
        REP(i,n){
            VI mind(10,-1);
            VI maxd(10,-1);
            REP(j,n){
                if (mind[t[j][i]]==-1){
                    mind[t[j][i]]=j;
                }
                maxd[t[j][i]]=j;
            }
            REP(d,10){
                if (mind[d]!=maxd[d]) { curb2a[d]=max(curb2a[d],(maxd[d]-mind[d])*max(i,n-1-i));}
                //cout<<i<<" "<<d<<" "<<curb2a[d]<<endl;
                if (mind[d]!=-1){
                    mdb2[d][i]=max(max(mind[d],n-1-mind[d]),max(maxd[d],n-1-maxd[d]));
                    REP(j,i){
                        if (mdb2[d][j]) curb2a[d]=max(curb2a[d], (i-j)*max(mdb2[d][i],mdb2[d][j]));
                    }
                }
                //cout<<i<<" "<<d<<" "<<curb2a[d]<<endl;
            }
        }
        REP(i,10){
            cout<<curb2a[i]<<((i==9)?"\n":" ");
        }
    }
}