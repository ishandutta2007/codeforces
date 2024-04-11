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
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    LL m;
    int k;
    R(m); R(k);
    vector<vector<__int128>> t(k, vector<__int128>(m));
    VL S(k,0);
    REP(i,k){
        REP(j,m){
            int x;
            R(x);
            t[i][j]=x;
            S[i]+=x;
        }
    }
    int mechant;
    LL d=S[1]-S[0];
    if (d!=S[2]-S[1]){
        //le mechant est 1 ou 2
        d=S[4]-S[3];
        if (S[1]-S[0]!=d) mechant=1;
        else mechant=2;
    }
    else{
        REPP(i,3,k){
            if (S[i]-S[i-1]!=d) {mechant=i; break;}    
            }
    }
    //for (auto i: S) {cout<<i<<" ";} cout<<endl;
    //cout<<"le mechant est "<<mechant<<endl;
    //cout<<"deplacement de "<<S[mechant]-S[mechant-1]-d<<endl;
    int dep=S[mechant]-S[mechant-1]-d;
    int res;
    if (mechant>=3){
        VL T(3,0);
        REPP(i,-3,0){
            REP(j,m){
                T[i+3]+=((__int128)m*t[mechant+i][j]-S[mechant+i])*((__int128)m*t[mechant+i][j]-S[mechant+i]);
            }
        }
        LL Ttheo= T[2]+ (T[2]-T[1])+(T[2]-2*T[1]+T[0]);
        LL VraiT=0;
        REP(j,m){
            VraiT+=(m*t[mechant][j]-(S[mechant-1]+d))*(m*t[mechant][j]-S[mechant-1]-d);
            //cout<<"je suis "<<j<<"je changerais de "<<(m*t[mechant][j]-(S[mechant-1]+d))*(m*t[mechant][j]-S[mechant-1]-d) - (m*(t[mechant][j]-dep)-(S[mechant-1]+d))*(m*(t[mechant][j]-dep)-S[mechant-1]-d)<<endl;
        }
        //cout<<"Vrai T - deplacement"<<VraiT<<" "<<Ttheo<<endl;
        int changeur;
        REP(j,m){
            //cout<<"je suis "<<j<<"je changerais de "<<(m*t[mechant][j]-(S[mechant-1]+d))*(m*t[mechant][j]-S[mechant-1]-d) - (m*(t[mechant][j]-dep)-(S[mechant-1]+d))*(m*(t[mechant][j]-dep)-S[mechant-1]-d)<<endl;
            if ((m*t[mechant][j]-(S[mechant-1]+d))*(m*t[mechant][j]-S[mechant-1]-d) - (m*(t[mechant][j]-dep)-(S[mechant-1]+d))*(m*(t[mechant][j]-dep)-S[mechant-1]-d) == VraiT-Ttheo) {
                changeur=j;
                res=t[mechant][j]-dep;
                break;
            }
        }
    }
    else{
        VL T(3,0);
        REPP(i,1,4){
            REP(j,m){
                T[i-1]+=(m*t[mechant+i][j]-S[mechant+i])*(m*t[mechant+i][j]-S[mechant+i]);
            }
        }
        LL Ttheo= T[0]+ (T[0]-T[1])+(T[0]-2*T[1]+T[2]);
        LL VraiT=0;
        REP(j,m){
            VraiT+=(m*t[mechant][j]-(S[mechant-1]+d))*(m*t[mechant][j]-S[mechant-1]-d);
            //cout<<"je suis "<<j<<"je changerais de "<<(m*t[mechant][j]-(S[mechant-1]+d))*(m*t[mechant][j]-S[mechant-1]-d) - (m*(t[mechant][j]-dep)-(S[mechant-1]+d))*(m*(t[mechant][j]-dep)-S[mechant-1]-d)<<endl;
        }
        //cout<<"Vrai T - deplacement"<<VraiT<<" "<<Ttheo<<endl;
        int changeur;
        REP(j,m){
            //cout<<"je suis "<<j<<"je changerais de "<<(m*t[mechant][j]-(S[mechant-1]+d))*(m*t[mechant][j]-S[mechant-1]-d) - (m*(t[mechant][j]-dep)-(S[mechant-1]+d))*(m*(t[mechant][j]-dep)-S[mechant-1]-d)<<endl;
            if ((m*t[mechant][j]-(S[mechant-1]+d))*(m*t[mechant][j]-S[mechant-1]-d) - (m*(t[mechant][j]-dep)-(S[mechant-1]+d))*(m*(t[mechant][j]-dep)-S[mechant-1]-d) == VraiT-Ttheo) {
                changeur=j;
                res=t[mechant][j]-dep;
                break;
            }
        }

    }
    cout<<mechant<<" "<<res<<"\n";
    cout.flush();
}