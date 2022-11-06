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
        int n,k;
        cin>>n>>k;
        string s;
        cin>>s;
        VI a(n);
        REP(i,n) {a[i]=(s[i]=='0')?1:0;} // invers
        int nbp= n-k+1;
        VI arein(nbp+1, 0);
        LL cur=0;
        set<int> ones;

        REP(i,k){
            if (a[i]) ones.insert(i);
        }
        REP(i,n-k+1){
            while ( ones.begin()!=ones.end() and (*ones.begin())<i) ones.erase(ones.begin());
            int mv= (ones.begin()!=ones.end())? (*ones.begin()) : (i+k-1);
            if ((i - mv + k -1) < 30){
                LL cv=0;
                for (auto j: ones) {/*cout<<j<<" is one \n";*/ cv+=1LL<<(i - j + k-1);}
                if (cv<=nbp) arein[cv]++;
                //cout<<i<<" "<<cv<<endl;
            }
            if (i==n-k) break;
            if (a[i+k]) ones.insert(i+k);
        }
        int ii=0;
        LL res=-1;
        LL lim = 1LL<<min(k,30);
        //cout<<"until "<<min(lim, (LL)SZ(arein))<<endl;
        while (ii<min(lim, (LL)SZ(arein))){
            //cout<<ii<<endl;
            if (!arein[ii]) {
                res=ii;
                break;
            }
            ii++;
        }
        //cout<<"myres "<<res<<endl;
        if (res==-1){
            cout<<"NO\n";
        }
        else{
            cout<<"YES\n";
            VI rr(k,0);
            LL tt=1;
            int kk=0;
            while (res){
                //cout<<"res "<<res<<endl;
                if (res&tt) {
                    res-=tt;
                    rr[kk]=1;
                }
                kk++;
                tt<<=1;
            }
            //cout<<"monk "<<k<<endl;
            //cout<<"======> ";
            for (int i=k-1; i>=0;i--){
                cout<<rr[i];
            }
            cout<<"\n";
        }
    }
}