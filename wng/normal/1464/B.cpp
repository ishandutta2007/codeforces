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
    string s;
    cin>>s;
    LL a,b;
    cin>>a>>b;
    b=b-a;
    int N=SZ(s);
    VL c(3,0);
    int nbinvbase=0;
    VI dinv(N+1,0);
    VI dinv2(N+1,0); // si inversions maximises
    VI x(N+1,0);
    VI y(N+1,0);
    VI z(N+1,0);
    REP(i,N){
        x[i+1]=x[i];
        z[i+1]=z[i];
        y[i+1]=y[i];
        if (s[i]=='1'){
            c[1]++;
            x[i+1]++;
        }
        if (s[i]=='0'){
            c[0]++;
            y[i+1]++;
            nbinvbase+=c[1];
        }
        if (s[i]=='?'){
            c[2]++;
            z[i+1]++;
        }
    }
    REP(i,N){
        if (s[i]=='?'){
            dinv[0]+=c[0]-y[i];
            dinv2[0]+=x[i];
        }
    }

    LL bestres=(c[0])*(c[1]+c[2]) *a + (nbinvbase + dinv[0]) *b;
    LL bestres2=(c[0]+c[2])*(c[1]) *a + (nbinvbase + dinv2[0]) *b;
    //cout<<c[0]<<" "<<c[1]<<" "<<c[2]<<" "<<nbinvbase<<" "<<dinv[0]<<endl;
    //cout<<"resbase "<<bestres<<" "<<endl;
    LL rbr=bestres;
    LL kk=c[2];
    LL kkk=0;
    REP(i,N){
        dinv[i+1]=dinv[i];
        dinv2[i+1]=dinv2[i];
        if (s[i]=='?'){
            //si on switche ce gars vers 0, on gagne un nombre d'inversions
            kk--;
            kkk++;
            dinv[i+1]+=x[i] - (c[0]-y[i]);
            bestres=(c[0]+kkk)*(c[1]+kk) * a + b* (nbinvbase+dinv[i+1]);
            rbr=min(rbr, bestres);
            //cout<<i<<" "<<bestres<<" "<<dinv[i+1]<<endl;
            
            //si on switche ce gars vers 1, on gagne un nombre d'inversions
            dinv2[i+1]-=x[i] - (c[0]-y[i]);
            bestres=(c[0]+kk)*(c[1]+kkk) * a + b* (nbinvbase+dinv2[i+1] + kk*kkk);
            rbr=min(rbr, bestres);
            //cout<<i<<" "<<bestres<<" "<<dinv2[i+1]<<endl;
        }
    }
    cout<<rbr<<"\n";
}