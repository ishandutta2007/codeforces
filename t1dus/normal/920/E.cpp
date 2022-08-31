/*input
5 5
1 2
3 4
3 2
4 2
2 5
*/        
#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define int ll
#define pb push_back
#define INF 1000000000
#define MOD 1000000007
#define mp make_pair
const double PI=3.141592653589793238462643383279502884197169399375105820974944;
#define REP(i,n) for (int i = 0; i < n; i++)
#define FOR(i,a,b) for (int i = a; i < b; i++)
#define REPD(i,n) for (int i = n-1; i >= 0; i--)
#define FORD(i,a,b) for (int i = a; i >= b; i--)
#define remax(a,b) a = max(a,b)
#define remin(a,b) a = min(a,b)
#define all(v) v.begin(),v.end()
#define pii pair<int,int>
#define F first
#define S second
#define mii map<int,int>
#define vi vector<int>
#define vvi vector<vi>
#define itr :: iterator it
#define WL(t) while(t --)
#define gcd(a,b) __gcd((a),(b))
#define lcm(a,b) ((a)*(b))/gcd((a),(b))
#define print(arr) for (auto it = arr.begin(); it != arr.end(); ++it) cout << *it << " "; cout << endl;
#define debug(x) cout << x << endl;
#define debug2(x,y) cout << x << " " << y << endl;
#define debug3(x,y,z) cout << x << " " << y << " " << z << endl;

int power(int a,int b,int m = MOD){
    if(b == 0) return 1;
    if(b == 1) return a;
    int x = power(a,b/2,m)%m;
    x = (x*x)%m;
    if(b%2) return (x*a)%m;
    return x;
}

int n,m,cnt;
set<pii> s;
set<int> uv;
vi v;

void bfs(int u){
    queue<int> q;
    q.push(u);
    uv.erase(u);
    while(!q.empty()){
        vi nt;
        cnt ++;
        int v = q.front(); q.pop();
        for(auto x:uv){
            if(s.find({x,v}) == s.end()) nt.pb(x);
        }
        for(auto x:nt){
            q.push(x);
            uv.erase(x);
        }
    }
}

void solve(){
    cin >> n >> m;
    WL(m){
        int u,v; cin >> u >> v;
        u --; v --;
        s.insert({u,v});
        s.insert({v,u});
    }
    REP(i,n) uv.insert(i);
    REP(i,n){
        if(uv.find(i) != uv.end()){
            cnt = 0;
            bfs(i);
            v.pb(cnt);
        }
    }
    sort(all(v));
    cout << v.size() << endl;
    for(auto x:v) cout << x << " ";
}

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int t = 1;
    // cin >> t;
    WL(t) solve();
}