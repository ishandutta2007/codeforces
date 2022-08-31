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
#define itr ::iterator it
#define WL(t) while(t --)
#define gcd(a,b) __gcd((a),(b))
#define lcm(a,b) ((a)*(b))/gcd((a),(b))
#define remin(a,b) (a) = min((a),(b))
#define remax(a,b) (a) = max((a),(b))

int n,m,k,s,cnt = 0;
char a[505][505];
bool vis[505][505];

bool dfs(int i,int j){
    if (cnt == s-k) return true;
    vis[i][j] = true;
    cnt ++;
    if(cnt == s-k) return true;
    if(i > 0 and !vis[i-1][j] and a[i-1][j] == '.'){
        if(dfs(i-1,j)) return true;
    }
    if(i < n-1 and !vis[i+1][j] and a[i+1][j] == '.'){
        if(dfs(i+1,j)) return true;
    }
    if(j > 0 and !vis[i][j-1] and a[i][j-1] == '.'){
        if(dfs(i,j-1)) return true;
    }
    if(j < m-1 and !vis[i][j+1] and a[i][j+1] == '.'){
        if(dfs(i,j+1)) return true;
    }
    return false;
}

int main() {
	
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	
	cin >> n >> m >> k;
	REP(i,n){ 
	    REP(j,m){
    	    cin >> a[i][j];
    	    if (a[i][j] == '.') s ++;
    	}
	}
	REP(i,505) REP(j,505) vis[i][j] = false;
    REP(i,n){ 
        REP(j,m){
            if (a[i][j] == '.'){
                dfs(i,j);
                break;
            }
        }	
        
    }

    REP(i,n){
        REP(j,m){
            if (a[i][j] != '.') cout << a[i][j];
            else if(vis[i][j]) cout << '.';
            else cout << 'X';
        }
        cout << "\n";
    }
}