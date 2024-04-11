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
        int n,q;
        cin>>n>>q;
        string s;
        cin>>s;
        VI nb0(n+1,0);
        REP(i,n){
            nb0[i+1]=nb0[i];
            if (s[i]=='0'){
                nb0[i+1]++;
            }
        }
        REP(i,q){
            int l,r;
            cin>>l>>r;
            l--;r--;
            bool isok=false;
            if (l){
                if ((s[l]=='0' and nb0[l]) or (s[l]=='1' and l-nb0[l]))
                    isok=true;
            }
            if (r<n-1){
                if ((s[r]=='0' and nb0[n]-nb0[r+1]) or (s[r]=='1' and n-nb0[n]-(r+1)+nb0[r+1]))
                    isok=true;
            }
            if (isok) cout<<"YES\n";
            else  cout<<"NO\n";
            cout<<endl;
        }
    }
}