#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector <int> vi;
typedef vector<vi> vvi;
typedef map<int,int> mii;
typedef pair<int,int> pii;
#define pb push_back
#define INF 1000000000
#define mp make_pair
#define MOD 1000000007
#define F first
#define S second
const double PI=3.14159265358979323846264338327950288419716939937510582097494459230;
#define REP(i,n) for(int i=0;i<(n);i++)
#define FOR(i,a,b) for(int i=(a);i<(b);i++)
#define REPD(i,n) for(int i=(n);i>=0;i--)
#define FORD(i,a,b) for(int i=(a);i>=b;i--)
#define all(v) v.begin(),v.end()
#define itr ::iterator it;
#define WL(t) while(t --)

int dp[101][2];

int solve(int b[][3], int stair, int pos, int f, int n, int m){
    if (pos < f) return -1;
    if (dp[pos][stair] != -1) return dp[pos][stair];
    int cur = 0;
    if (b[pos][2] == 0){
        return dp[pos][stair] = 1+solve(b,stair,pos-1,f,n,m);
    }
    if (stair == 0){
        cur = b[pos][1];
        if (pos != f)
        cur += 1+min(solve(b,0,pos-1,f,n,m)+cur,solve(b,1,pos-1,f,n,m)+m+1-cur);

    }
    else{
        cur = m+1-b[pos][0];
        int mpos = b[pos][0];
        if (pos != f)
        cur += 1+min(solve(b,0,pos-1,f,n,m)+mpos,solve(b,1,pos-1,f,n,m)+m+1-mpos);
    }
    // cout << pos << " " << stair << " " << cur << endl;
    return dp[pos][stair]=cur;
}

int main() {
	
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	int n,m;
	cin >> n >> m;
    
    char a[n][m+2];
    int b[n][3];
    int cnt = 0;
    
    int f = -1;
    
    FOR(i,0,n){
        b[i][0] = -1;
        b[i][1] = -1;
        b[i][2] = 0;
        
        FOR(j,0,m+2){
            cin >> a[i][j];
            if(a[i][j] == '1'){
                if (f == -1) f = i;
                b[i][2] ++;
                cnt ++;
                if (b[i][0] == -1) b[i][0] = j;
                b[i][1] = j;
            }
        }
    }
    if (f == -1){
        cout << 0 << endl;
        return 0;
    }
    for (int i = 0; i <= n; i++){
        dp[i][0] = -1;
        dp[i][1] = -1;
    }
    cout << solve(b,0,n-1,f,n,m) << endl;
}