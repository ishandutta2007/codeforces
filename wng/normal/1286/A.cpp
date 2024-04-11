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
    DRI(n);
    VI a(n);
    VI nb(2,0);
    REP(i,n){
        RI(a[i]);
        if (a[i]){
            nb[a[i]%2]++;
        }
    }
    //mincomp for each nb comp for each parity of last;
    int pol=-1;
    VI resp(101,100000);
    VI resi(101,10000);
    int nbpt=n/2;
    int nbit=n-nbpt;
    int totleft=n-nb[0]-nb[1];
    int ires=0;
    int kk=0;
    int tpl= nbpt-nb[0];
    if (!a[kk]){
        if (tpl){
            resp[tpl-1]=0;
        }
        if (totleft-tpl) resi[tpl]=0;
        totleft--;
    }
    else{
        if (a[kk]%2){
            resi[tpl]=0;
        }
        else resp[tpl]=0;
    }
    REPP(kk,1,n){
        VI nresp(101,10000);
        VI nresi(101,10000);
        if (!a[kk]){
            REP(j,100){
                nresp[j]=min(resp[j+1],resi[j+1]+1);
                nresi[j]=min(resp[j]+1,resi[j]);
            }
            totleft--;
        }
        else{
            if (a[kk]%2){
                REP(j,100){
                    nresi[j]=min(resp[j]+1,resi[j]);
                }
            }
            else{
                REP(j,100){
                    nresp[j]=min(resp[j],resi[j]+1);
                }
            }
        }
        resp=nresp;
        resi=nresi;
    }
    printf("%d\n",min(resp[0],resi[0]));
}