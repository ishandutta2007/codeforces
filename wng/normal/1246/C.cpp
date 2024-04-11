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
    DRII(n,m);
    vector<VI> isr(n,VI(m));
    vector<VI> nbrr(n+1,VI(m+1));
    vector<VI> nbrb(n+1,VI(m+1));
    vector<VI> a(n+1,VI(m+1)); //par la gauche
    vector<VI> b(n+1,VI(m+1)); //par le haut
    vector<VL> da(n+1,VL(m+1)); //par la gauche
    vector<VL> db(n+1,VL(m+1)); //par le haut
    int mod=1000000007;
    REP(i,n){
        char s[2010];
        RS(s);
        REP(j,m) {isr[i][j]=(s[j]=='R')?1:0;}
    }
    for (int i=n-1;i>=0;i--){
        for (int j=m-1;j>=0;j--){
            nbrr[i][j]=isr[i][j]+nbrr[i][j+1];
            nbrb[i][j]=isr[i][j]+nbrb[i+1][j];
        }
    }
    //REP(i,m-nbrr[0][0]) a[0][i]=1;
    VL ca(n);
    REP(i,n-nbrb[0][0]) {b[i][0]=1;
        da[i][1]+=b[i][0];
        da[i][m-nbrr[i][1]]-=b[i][0];
    }
    LL res;
    if (m==1){
        res=(b[n-1][0]%mod+mod)%mod;
    }
    REPP(j,1,m){
        LL cb=0;
        REP(i,n) {
            cb+=db[i][j];
            ca[i]+=da[i][j];
            ca[i]%=mod;
            cb%=mod;
            a[i][j]=ca[i];
            b[i][j]=cb;
            db[i+1][j]+=ca[i];
            db[n-nbrb[i+1][j]][j] -=ca[i];
            da[i][j+1]+=cb;
            da[i][m-nbrr[i][j+1]]-=cb;        
        }
        if (j==m-1) {res=cb+ca[n-1]; res%=mod; res+=mod; res%=mod;}
        //cout<<"ca : "; for (auto i:ca){cout<<i<<" ";} cout<<endl;
    }
    /*
    for (auto i:da){
        for (auto j:i){
            cout<<j<<" ";
        }
        cout<<endl;
    }
    cout<<endl;
    
    for (auto i:db){
        for (auto j:i){
            cout<<j<<" ";
        }
        cout<<endl;
    }
    cout<<endl;*/

    printf("%I64d\n",res);

}