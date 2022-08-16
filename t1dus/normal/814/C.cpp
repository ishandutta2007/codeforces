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

int ord(char c){ return (c-'a');}

int main() {
	
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	
	int n;
	cin >> n;
	string s;
	cin >> s;
	vector<pii> a[26];
	int cnt = 1;
	FOR(i,1,n){
	    if (s[i] == s[i-1]) cnt ++;
	    else{
	        a[ord(s[i-1])].pb(mp(i-cnt,i-1));
	        cnt = 1;
	    }
	}
	a[ord(s[n-1])].pb(mp(n-cnt,n-1));
	vvi sol(26);
	REP(i,26){
	    vi d(n+1,0);
	    int x = a[i].size();
	    REP(j,x){
	        int cost = 0;
	        int cnt = a[i][j].S-a[i][j].F+1;
	        FOR(k,j+1,x){
	            d[cost] = max(d[cost],cnt);
	            cost += a[i][k].F-a[i][k-1].S-1;
                cnt += a[i][k].S-a[i][k].F+1;
                cnt += a[i][k].F-a[i][k-1].S-1;
	        }
	        d[cost] = max(d[cost],cnt);
	    }
	    FOR(j,1,n+1){
	        d[j] = max(d[j],d[j-1]+1);
	        d[j] = min(d[j],n);
	    }
	    sol[i] = d;
	}
	int q;
	cin >> q;
	WL(q){
	    int m;
	    char c;
	    cin >> m >> c;
	    int c1 = ord(c);
	    int ans = 0;
	    REP(i,m+1) ans = max(ans,sol[c1][i]);
	    cout << ans << endl;
	}
}


/*
for i in range(26):
    d = [0]*(n+1)
    x = len(a[i])
    for j in range(x):
        cost = 0
        cnt = a[i][j][1]-a[i][j][0]+1
        for k in range(j+1,x):
            d[cost] = max(d[cost],cnt)
            cost += a[i][k][0]-a[i][k-1][1]-1
            cnt += a[i][k][1]-a[i][k][0]+1
            cnt += a[i][k][0]-a[i][k-1][1]-1
        d[cost] = max(d[cost],cnt) 
    for j in range(1,n+1):
        d[j] = max(d[j],d[j-1]+1)
        d[j] = min(d[j],n)
    sol[i] = d
# for i in sol:
#     print(i)

q = int(input())
for _ in range(q):
    m,c = input().split()
    m = int(m)
    print(max(sol[ord(c)-97][:m+1]))
    
*/