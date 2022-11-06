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
    CASET{
        DRII(n,l);
        DRVI(n,a);
        vector<double> wl(n+2,0.0);
        vector<double> wr(n+2,0.0);
        int sl=1;
        int pv=0;
        REP(i,n){
            wl[i+1]=wl[i]+(a[i]-pv)/double(sl);
            pv=a[i];
            sl++;
        }
        wl[n+1]=wl[n]+(l-pv)/double(sl);
        int sr=1;
        pv=l;
        for(int i=n-1;i>=-1;i--){
            if (i>=0){
                wr[i+1]=wr[i+2]+(pv-a[i])/double(sr);
                //cout<<"ah "<<i<<" "<<wr[i+1]<<" "<<wl[i+1]<<endl;
                pv=a[i];
                sr++;
                if (wr[i+1]>wl[i+1]){
                
                    double t0=wr[i+2];
                    double tp0=wl[i+1];
                    double tp1=wl[i+2];
                    double t1=wr[i+1];
                    double ds= 1/(1/(t1-t0) + 1/(tp1-tp0));
                    double couvert = max((t0-tp0)/(tp1-tp0), (tp0-t0)/(t1-t0));
                     double res=max(t0,tp0)+ds*(1-couvert);
                    printf("%.8f\n",res);
                    break;
                }
            }
            else{
                wr[0]=wr[1]+(pv)/double(sr);
                //la sol est entre 0 et 1
                double t0=wr[i+2];
                double tp0=wl[i+1];
                double tp1=wl[i+2];
                double t1=wr[i+1];
                double ds= 1/(1/(t1-t0) + 1/(tp1-tp0));
                double couvert = max((t0-tp0)/(tp1-tp0), (tp0-t0)/(t1-t0));
                double res=max(t0,tp0)+ds*(1-couvert);
                printf("%.8f\n",res);
            }
        }
    }

}