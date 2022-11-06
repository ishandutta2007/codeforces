#include <bits/stdc++.h>
typedef long long LL;
#define SZ(X) ((int)(X).size())
#define ALL(X) (X).begin(), (X).end()
#define RALL(X) (X).rbegin(), (X).rend()
#define REP(I, N) for (int I = 0; I < (N); ++I)
#define REPP(I, A, B) for (int I = (A); I < (B); ++I)
#define R(X) cin>>(X)
#define RII(X, Y) cin>>(X)>>(Y)
#define RIII(X, Y, Z)  cin>>(X)>>(Y)>>(Z)
#define DRI(X) int (X); cin>>(X)
#define DRII(X, Y) int X, Y; cin>>(X)>>(Y)
#define DRIII(X, Y, Z) int X, Y, Z; cin>>(X)>>(Y)>>(Z)
#define DRVI(N, X) VI X(N); for (int ___I=0; ___I<N; ___I++) cin>>(X[___I]) 
#define DRVL(N, X) VL X(N); for (int ___I=0; ___I<N; ___I++) cin>>(X[___I])
#define RS(X) cin>>X
#define DRS(X) string X; cin>>X
#define CASET int ___T, case_n = 1; cin>>___T; while (___T-- > 0)
#define MS0(X) memset((X), 0, sizeof((X)))
#define MS1(X) memset((X), -1, sizeof((X)))
#define PII pair<int,int>
#define VI vector<int>
#define VL vector<long long>
#define VPII vector<pair<int,int>>
#define PLL pair<long long,long long>
#define VPLL vector<pair<long long,long long>>
#define PB push_back
#define F first
#define S second

using namespace std;

int main(){
    DRI(n);
    int root=1;
    cout<<"? 1\n";
    cout.flush();
    DRVI(n,rk);
    vector<VI> cs(n,VI(0));
    VI nbpr(n,0);
    int sp=0;
    int si=0;
    REP(i,n){
        if (rk[i]==1) cs[0].PB(i);
        nbpr[rk[i]]++;
        if (rk[i]%2) si++;
        else sp++;
    }   
    if (sp<=si){
        REPP(m,1,n){
            REPP(i,1,n){
                if (rk[i]==2*m){
                    cout<<"? "<<(i+1)<<"\n";
                    cout.flush();
                    DRVI(n,r2);
                    int p=-1;
                    REP(j,n){
                        if (rk[j]==rk[i]-1 and r2[j]==1) p=j;
                        if (rk[j]==rk[i]+1 and r2[j]==1) cs[i].PB(j);
                    }
                    //cout<<p<<" "<<i<<endl;
                    cs[p].PB(i);
                    
                }
            }
        }
    }
    else{
        REPP(m,0,n){
            REPP(i,1,n){
                if (rk[i]==2*m+1){
                    cout<<"? "<<(i+1)<<"\n";
                    cout.flush();
                    DRVI(n,r2);
                    int p=-1;
                    REP(j,n){
                        if (rk[j]==rk[i]-1 and r2[j]==1) p=j;
                        if (rk[j]==rk[i]+1 and r2[j]==1) cs[i].PB(j);
                    }
                    //cout<<p<<" "<<i<<endl;
                    if (m) cs[p].PB(i);
                    
                }
            }
        }

    }
    cout<<"!\n";
    REP(i,n){
        for (auto c:cs[i]){
            cout<<(i+1)<<" "<<(c+1)<<"\n";
        }
    }
    cout.flush();


}