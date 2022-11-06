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
    char s[200008];
    RS(s);
    VI listmods;
    listmods.PB(1000000007);
    listmods.PB(999979699);
    listmods.PB(999982561);
    listmods.PB(999981523);
    listmods.PB(999981713);
    listmods.PB(999981547);
    DRI(q);
    int m=SZ(listmods);
    vector<VI> mods2p(m,VI(n+1,1));
    REP(i,m){
        REP(j,n){
            mods2p[i][j+1]=(2*mods2p[i][j])%listmods[i];
        }
    }
    VI n0(n+1,0);
    REP(i,n){
        n0[i+1]=n0[i]; if (s[i]=='0') n0[i+1]++;
        }
    int p=n0[n];
    vector<VL> mods(m,VL(p+1,0));
    vector<VL> modsm2(m,VL(p+1,0));
    int kk=0;
    REP(i,n){
        if (s[i]=='0') {
            REP(j,m){
                mods[j][kk+1]=(mods[j][kk]*(LL)2+(i%2))%listmods[j];
                modsm2[j][kk+1]=(modsm2[j][kk]*(LL)2+((i+1)%2))%listmods[j];
            }
            kk++;
        }
        }
    REP(i,q){
        DRIII(l1,l2,len);
        l1--; l2--;
        int nz=n0[l1+len]-n0[l1];
        int nz2=n0[l2+len]-n0[l2];
        if (nz!=nz2) {printf("No\n"); continue;}
        int n_1=n0[l1];
        int n_2=n0[l2];
        bool isok=true;
      //  cout<<"ns"<<n_1<<" "<<n_2<<" "<<nz<<endl;
        REP(j,m){
            int mod=listmods[j];
            LL m_1=((l1+1)%2)?((LL)mods[j][n_1+nz]-(LL)mods[j][n_1]*mods2p[j][nz]):((LL)modsm2[j][n_1+nz]-(LL)modsm2[j][n_1]*mods2p[j][nz]);
            m_1%=mod;
            m_1+=mod;
            m_1%=mod;
            LL m_2=((l2+1)%2)?((LL)mods[j][n_2+nz]-(LL)mods[j][n_2]*mods2p[j][nz]):((LL)modsm2[j][n_2+nz]-(LL)modsm2[j][n_2]*mods2p[j][nz]);
            m_2%=mod;
            m_2+=mod;
            m_2%=mod;
            //cout<<mod<<" "<<m_1<<" "<<m_2<<endl;
            if (m_1!=m_2) {isok=false; break;}
        }
        if (isok) {printf("Yes\n");}
        else {printf("No\n");}
    }
}