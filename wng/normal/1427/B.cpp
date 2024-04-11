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
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int nbt;
    cin>>nbt;
    while (nbt--){
        int n,k;
        LL ss(0);
        cin>>n>>k;
        string s;
        cin>>s;
        VI a(n);
        int pv=-1;
        VI rss(0);
        PII ff={0,0};
        int bl=0;
        REP(i,n){
            a[i]=(s[i]=='W')?1:0;
            if (a[i]){
                ss++;
                if (i and a[i-1]) ss++;
                if (pv!=i-1){
                    if (pv!=-1)  rss.PB(i-pv-1);
                    else ff.F=i-pv-1;
                }
                pv=i;
            }
            else bl++;
        }
        if (bl==n){
            cout<<max(0,2*k-1)<<"\n";
            continue;
        }

        //cout<<"rss ";
        //for (auto i:rss) cout<<i<<" "; cout<<endl;
        //cout<<"pre ss "<<ss<<endl;
        ff.S=n-pv-1;
        sort(ALL(rss));
        int i=0;
        while (k>0 and i<SZ(rss)){
            //cout<<"left "<<k<<" "<<rss[i]<<" "<<bl<<endl;
            if (rss[i]<=k){
                ss+=(rss[i]*2+1);
                k-=rss[i];
                bl-=rss[i];
            }
            else break;
            i++;
        }
        if (k>0){
            ss+= (2* (min(k, bl)));
        }
        cout<<ss<<"\n";
    }
}