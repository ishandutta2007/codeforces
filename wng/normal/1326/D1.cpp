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

    VI listmods;
    listmods.PB(1000000007);
    listmods.PB(999979699);
    listmods.PB(999982561);
    listmods.PB(999981523);
    listmods.PB(999981713);
    listmods.PB(999981547);
    int ms=SZ(listmods);
    int lim=1000000;
    vector<VI> mods2p(ms,VI(lim+1,1));
    REP(i,ms){
        REP(j,lim){
            mods2p[i][j+1]=((LL)26*mods2p[i][j])%listmods[i];
        }
    }
    
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin>>t;
    while (t--){
        string s;
        cin>>s;
        int n=SZ(s);
        int m=0;
        int brp=0;
        int brm=0;
        while (m<n/2 and s[m]==s[n-1-m]) m++;
        string rs=s.substr(m,n-2*m);
        //cout<<s<<" "<<rs<<endl;
        n=SZ(rs);
        vector<VL> rm(n+1,VL(ms,0));
        vector<VL> rmr(n+1,VL(ms,0));
        REP(i,n) {
            REP(j,ms){
                rm[i+1][j]=(rm[i][j]*26+(rs[i]-'a'))%listmods[j];
            }
        }
        for (int i=n-1;i>=0;i--) {
            REP(j,ms){
                rmr[i][j]=(rmr[i+1][j]*26+(rs[i]-'a'))%listmods[j];
            }
        }
        bool isok;
        REP(i,n/2+1){
            //palindrome de longueur 2 * i
            if (i) {
                isok=true;
                REP(j,ms){
                    LL sti=rm[i][j];
                    LL ste=(rmr[i][j]-rmr[2*i][j]*mods2p[j][i]);
                    ste%=listmods[j];
                    ste+=listmods[j];
                    ste%=listmods[j];
                    if (ste!=sti){
                        isok=false;
                        break;
                    }
                }
                if (isok){
                    brp=2*i;
                }
            }
            //palindrome de longueur 2*i+1
            if (2*i+1<=n){
                isok=true;
                if (i) REP(j,ms){
                    LL sti=rm[i][j];
                    LL ste=(rmr[i+1][j]-rmr[2*i+1][j]*mods2p[j][i]);
                    ste%=listmods[j];
                    ste+=listmods[j];
                    ste%=listmods[j];
                    if (ste!=sti){
                        isok=false;
                        break;
                    }
                }
                if (isok){
                    brp=2*i+1;
                }
            }
        //palindrome de longueur 2 * i reversed
            if (i) {
                isok=true;
                REP(j,ms){
                    LL sti=(rm[n-i][j]-rm[n-2*i][j]*mods2p[j][i]); //rm[i][j];
                    LL ste=rmr[n-i][j];
                    sti%=listmods[j];
                    sti+=listmods[j];
                    sti%=listmods[j];
                 //   cout<<i<<" "<<j<<" "<<ste<<" "<<sti<<endl;
                    if (ste!=sti){
                        isok=false;
                        break;
                    }
                }
                if (isok){
                    brm=2*i;
                }
            }
            if (2*i+1<=n){
                isok=true;
                if (i) REP(j,ms){
                    LL sti=(rm[n-i-1][j]-rm[n-2*i-1][j]*mods2p[j][i]); //rm[i][j];
                    LL ste=rmr[n-i][j];
                    sti%=listmods[j];
                    sti+=listmods[j];
                    sti%=listmods[j];
                    if (ste!=sti){
                        isok=false;
                        break;
                    }
                }
                if (isok){
                    brm=2*i+1;
                }
            }
        }
        cout<<s.substr(0,m);
        if (brm>brp){
            cout<<rs.substr(n-brm,brm);
        }
        else{
            cout<<rs.substr(0,brp);
        }
        REP(i,m){
            cout<<s[m-1-i];
        }
        cout<<"\n";
    }
}