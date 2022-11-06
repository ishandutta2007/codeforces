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

int n,m,t;

VPII nbs(PII a){
    int i=a.F;
    int j=a.S;
    VPII res;
    if (i>0) res.PB({i-1,j});
    if (i<n-1) res.PB({i+1,j});
    if (j>0) res.PB({i,j-1});
    if (j<m-1) res.PB({i,j+1});
    return res;
}

vector<vector<VI>> cs;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin>>n>>m>>t;
    vector<vector<bool>> a(n,vector<bool>(m,false));
    REP(i,n){
        string s;
        cin>>s;
        REP(j,m){
            if (s[j]=='1') a[i][j]=true;
        }
    }
    vector<vector<int>> startcli(n,VI(m,-1));
    queue<PII> tv;

    REP(i,n){
        REP(j,m){
            VPII nes=nbs({i,j});
            //cout<<i<<" "<<j<<" has "<<SZ(nes)<<" children\n";
            for (auto c:nes){
                int i2=c.F;
                int j2=c.S;
                //cout<<i2<<" "<<j2<<" "<<"is a child of "<<i<<" "<<j<<" "<<a[i2][j2]<<" "<<a[i][j]<<endl;
                if (a[i2][j2]==a[i][j]) {
                    startcli[i][j]=0;
                    tv.push({i,j});
                    break;
                }
            }
        }
    }

    while (!tv.empty()){
        PII tp=tv.front();
        int i=tp.F;
        int j=tp.S;
        tv.pop();
        VPII nes=nbs({i,j});
        for (auto c:nes){
            int i2=c.F;
            int j2=c.S;
            if (startcli[i2][j2]==-1){
                startcli[i2][j2]=startcli[i][j]+1;
                tv.push({i2,j2});
            }
        }
    }

    REP(q,t){
        int i,j;
        LL p;
        cin>>i>>j>>p;
        i--;j--;
        bool res=a[i][j];
        if (startcli[i][j]==-1 or startcli[i][j]>p or (p-startcli[i][j])%2==0){
        }
        else{
            res=!res;
        }
        cout<<(res?1:0)<<"\n";
    }

}