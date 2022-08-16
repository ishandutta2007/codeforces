#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
using namespace std;

typedef tree<int,null_type,less<int>,rb_tree_tag,
tree_order_statistics_node_update> indexed_set;
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

int main() {
	
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	
	int n,k;
	cin >> n >> k;
    int a[n][n];
    REP(i,n) REP(j,n) a[i][j] = 0;
    REP(i,n){
        REP(j,n){
            if (a[i][j] == 1) continue; 
            if (k == 0){
                break;
            }
            if (k == 1){
                if(i == j){
                    a[i][j] = 1;
                    k --;
                }
                continue;
            }
            a[i][j] = 1;
            a[j][i] = 1;
            k -= 2;
            if (i == j) k ++;
        }
    }
    if (k == 0){
        REP(i,n) {REP(j,n) cout << a[i][j] << " "; cout << "\n";}
    }
    else cout << "-1\n";
}