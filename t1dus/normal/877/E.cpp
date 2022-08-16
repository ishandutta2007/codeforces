/*input
4
1 1 1
1 0 0 1
9
get 1
get 2
get 3
get 4
pow 1
get 1
get 2
get 3
get 4
*/		
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define int ll
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
const double PI=3.141592653589793238462643383279502884197169399375105820974944;
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

#define MX 200005

int L,R,N,Q,c = 0,T[MX],start[MX],fin[MX],seg[4*MX],lazy[4*MX];
vi adj[MX];

void dfs(int s,int p){
	start[s] = c++;
	for(auto u:adj[s]){
		if(u!=p) dfs(u,s);
	}
	fin[s] = c;
}

void upd(int node,int a,int b){
	if (lazy[node] != 0){
        seg[node] = (b-a+1)-seg[node];
        if (a != b){
            lazy[node*2] = 1-lazy[node*2];
            lazy[node*2+1] = 1-lazy[node*2+1];
        }
        lazy[node] = 0;
    }
    if (a > b or a > R or b < L) return;
    if (L <= a and b <= R){
        seg[node] = (b-a+1)-seg[node];
        if (a != b){
            lazy[node*2] = 1-lazy[node*2];
            lazy[node*2+1] = 1-lazy[node*2+1];
        }
        return;
    }
    upd(node*2,a,(a+b)/2);
    upd(node*2+1,((a+b)/2)+1,b);
    seg[node] = seg[node*2]+seg[node*2+1];
}

int quer(int node,int a,int b){
	if (lazy[node] != 0){
        seg[node] = (b-a+1)-seg[node];
        if (a != b){
            lazy[node*2] = 1-lazy[node*2];
            lazy[node*2+1] = 1-lazy[node*2+1];
        }
        lazy[node] = 0;
    }
    if (a > b or a > R or b < L) return 0;
    if (L <= a and b <= R){
        return seg[node];
    }
    ll q1 = quer(node*2,a,(a+b)/2),q2 = quer(node*2+1,((a+b)/2)+1,b);
    return q1+q2;
}

signed main() {
	
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> N;
	REP(i,N-1){
		int x; cin >> x;
		adj[i+1].pb(x-1);
		adj[x-1].pb(i+1);
	}
	REP(i,N) cin >> T[i];
	dfs(0,-1);
	cin >> Q;

	int xyz = 1; while(xyz < N) xyz *= 2;

	REP(i,N){
		L = start[i];
		R = start[i];
		if(T[i]) upd(1,0,xyz-1);
	}

	N = xyz;

	// REP(i,N){
	// 	cout << start[i] << " " << fin[i] << endl; 
	// }

	WL(Q){
		string type;
		int v;
		cin >> type >> v;
		v --;
		if(type == "pow"){
			L = start[v];
			R = fin[v]-1;
			upd(1,0,N-1);
		} 
		else{
			L = start[v];
			R = fin[v]-1;
			cout << quer(1,0,N-1) << endl;
		}
	}
}