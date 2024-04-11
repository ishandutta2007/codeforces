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
    LL n, t;
    cin>>n>>t;
    string s;
    cin>>s;
    VI u(60,0);
    REP(i,n-2){
        u[s[i]-'a']++;
        t-=1LL<<(s[i]-'a');
    }
    t+=1LL<<(s[n-2]-'a');
    t-=1LL<<(s[n-1]-'a');
    t=-t;
    //cout<<"t "<<t<<endl;
    //REP(i,4) cout<<u[i]<<" "; cout<<endl;
    bool isok=(t>=0) and (t%2==0);
    t>>=1;
    //can I do t with my table
    LL v=1;
    int k=0;
    int maxreserve=0;
    while (v<=t or k<26){
        maxreserve/=2;
        if (t&v){
            if (u[k]==0){
                if (!maxreserve) isok=false;
                else maxreserve--;
            }
            else u[k]--;
        }
        maxreserve+=u[k];
        v<<=1;
        k++;
        //cout<<v<<" "<<t<<" "<<k<<" "<<maxreserve<<" "<<isok<<endl;
    }
    if (isok) cout<<"Yes\n";
    else cout<<"No\n";
}