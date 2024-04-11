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

VI ps;

int findp(int i){
    if (ps[i]!=i) ps[i]=findp(ps[i]);
    return ps[i];
}

void merge(int i, int j){
    ps[findp(j)]=findp(i);
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    CASET{
        map<int, VI> wtf;
        DRII(n,p);
        DRVI(n,a);
        REP(i,n){
            wtf[a[i]].PB(i);
        }
        ps=VI(n);
        REP(i,n) ps[i]=i;
        LL res=0;
        for (auto c: wtf){
            //cout<<"doing "<<c.F<<endl;
            if (c.F>=p) {break;}
            for (auto ii: c.S){
                //cout<<"subdoing "<<ii<<endl;
                //for (auto p:ps) cout<<p<<" "; cout<<endl;
                int iinf=ii-1;
                //if (iinf>=0) cout<<"iinf"<<iinf<<" "<<findp(iinf)<<" "<<findp(ii)<<endl;
                while (iinf>=0 and findp(iinf)!=findp(ii) and a[iinf]%c.F==0){
                    merge(ii, iinf);
                    res+=c.F;
                    iinf--;
                }
                int isup=ii+1;
                //cout<<"isup"<<isup<<endl;
                while (isup<n and findp(isup)!=findp(ii) and a[isup]%c.F==0){
                    merge(ii, isup);
                    res+=c.F;
                    isup++;
                }
            }
        }

        LL nbg=-1;
        REP(i,n){ if (ps[i]==i) nbg++;}
        res+=nbg*p;
        cout<<res<<"\n";
    }
}