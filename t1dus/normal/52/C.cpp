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
#define int ll
 
ll seg[800005],lazy[800005];
int n,m;
int l,r;
ll v;
 
void upd(int node, int a, int b){
    if (lazy[node] != 0){
        seg[node] += lazy[node];
        if (a != b){
            lazy[node*2] += lazy[node];
            lazy[node*2+1] += lazy[node];
        }
        lazy[node] = 0;
    }
    if (a > b or a > r or b < l) return;
    if (l <= a and b <= r){
        seg[node] += v;
        if (a != b){
            lazy[node*2] += v;
            lazy[node*2+1] += v;
        }
        return;
    }
    upd(node*2,a,(a+b)/2);
    upd(node*2+1,((a+b)/2)+1,b);
    seg[node] = min(seg[node*2],seg[node*2+1]);
}
 
ll quer(int node, int a, int b){
    if (lazy[node] != 0){
        seg[node] += lazy[node];
        if (a != b){
            lazy[node*2] += lazy[node];
            lazy[node*2+1] += lazy[node];
        }
        lazy[node] = 0;
    }
    if (a > b or a > r or b < l) return INF;
    if (l <= a and b <= r){
        return seg[node];
    }
    ll q1 = quer(node*2,a,(a+b)/2),q2 = quer(node*2+1,((a+b)/2)+1,b);
    return min(q1,q2);
}
 
signed main() {
	
// 	ios_base::sync_with_stdio(false);
// 	cin.tie(0);
// 	cout.tie(0);
    
    REP(i,400005) seg[i] = lazy[i] = 0;
    cin >> n;
    int cur = 1;
    while(cur < n) cur *= 2;
    REP(i,2*cur) seg[i] = INF;
    REP(i,n) cin >> seg[i+cur];
    FORD(i,cur-1,1) seg[i] = min(seg[i*2],seg[i*2+1]);
    n = cur;
    cin >> m;
    while(m --){
        char c;
        scanf("%lld%lld%c",&l,&r,&c);
        if (c != '\n'){
            cin >> v;
            if (l <= r){
                upd(1,0,n-1);
            }
            else{
                int x = l,y = r;
                r = n-1;
                upd(1,0,n-1);
                l = 0;
                r = y;
                upd(1,0,n-1);
            }
        }
        else{
            int ans = INF;
            if (l <= r){
                remin(ans,quer(1,0,n-1));
            }
            else{
                int x = l,y = r;
                r = n-1;
                remin(ans,quer(1,0,n-1));
                l = 0;
                r = y;
                remin(ans,quer(1,0,n-1));
            }
            cout << ans << endl;
        }
    }
}