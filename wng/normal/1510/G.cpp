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


int best = 0;
int bestIdx = 0;
int M;


vector<int> res;

vector<int> depths;
vector<int> reverseAdj;

void computeDepth(int N, vector<vector<int> > &adj, int depth) {
    depths[N] = depth;
    for(auto z:adj[N]) {
        computeDepth(z,adj,depth+1);
    }
    if(depths[N] <= M && depths[N] > best) {
        best = depths[N];
        bestIdx = N;
    }
}

void computePath(int N, int &needs, vector<vector<int> > &adj, vector<bool> &seen) {
    res.push_back(N);
    seen[N]=true;
    for(auto z:adj[N]) {
        if(needs == 0) break;
        if(seen[z]) continue;
        seen[z]=true;
        needs-=1;
        computePath(z,needs,adj,seen);
        return ;
    }
    if(N!=0)
        computePath(reverseAdj[N],needs,adj,seen);
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int T;
    cin>>T;

    while(T--) {
        int N;
        cin>>N>>M;
        vector<vector<int> > adj(N);
        reverseAdj.resize(N);
        depths.resize(N);
        for(int c=0;c+1<N;c++){
            int z;
            cin>>z;
            adj[z-1].push_back(c+1);
            reverseAdj[c+1] = z-1;
        }
        res.clear();

        best = 0;
        computeDepth(0,adj,1);


        int needs = M - best;
        vector<bool> seen(N,false);
        seen[bestIdx]=true;
        computePath(bestIdx,needs,adj,seen);

        reverse(res.begin(),res.end());
        cout<<res.size()-1<<endl;
        for(auto z:res) {
            cout<<z+1<<" ";
        }
        cout<<endl;
    }

}