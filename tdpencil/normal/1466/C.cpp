#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#pragma GCC optimize("Ofast") 
#define sz(a) int(a.size())
#define atoi(x) (x-'0')
#define cnst const
#define lb lower_bound
#define ub upper_bound 
#define endl '\n'
#define ar array
#define it int64_t
#define vt vector
#define gcd __gcd
#define lcm(x, y) (x*y/(gcd(x, y)))
#define pll pair<ll, ll>
#define sum(x) int(accumulate(x.begin(), x.end(), 0LL))
#define fastio ios_base::sync_with_stdio(false);cin.tie(nullptr);
#define rep(i, a, b) for(int i =a; i < (b); i++)
#define EACH(v, V) for (auto &v : V)
#define FOR(n) for (int i = 0; i < int(n); i++)
#define FORn(i, n) for (int i = 0; i < int(n); i++)
#define rep1(i, a, b, d) for(int i =a; i < (b); i+=d)
#define offset(V, i)  for (auto &v : V) v = i
#define all(x) x.begin(), x.end()
#define pqueue priority_queue
#define YES "YES"
#define NO "NO"
#define Yes "Yes"
#define No "No"
#define atcoder(event) (event?Yes:No)
#define psh push
#define pb push_back
#define minel(x) (*min_element(all(x)))
#define maxel(x) (*max_element(all(x)))
#define findel(x, y) (lower_bound(all(x), y)-x.begin())
#define eval(x) (x)
#define numtheory number_theory
#define pr pair
#define pi pr<int,int>
#define ts to_string
#define dbl double
#define tpl tuple
#define pv print_vector
typedef vector<int> vi;
typedef vector<ll> vl;
typedef pr<ll,ll> pl;
typedef pr<int,int> pii;
typedef pr<it,it> pit;
typedef pr<string, ll> psl;
typedef pr<ll, string> pls;
typedef string str;
typedef vt<pll> vpl;
typedef queue<int> qi;
typedef queue<ll> ql;
const int mod = 1e9 + 7;
const ll inf = ll(1e18);
const int mxN = 2e5+1;
const double PI = 3.1415926535897932;
ll fdiv(ll a, ll b) { return a/b-((a^b)<0&&a%b); }
ll cdiv(ll a, ll b) { return a/b+((a^b)>0&&a%b); } 
template<typename A, typename B> ostream& operator<<(ostream &os, const pair<A, B> &p) { return os << '(' << p.first << ", " << p.second << ')'; }
template<typename T_container, typename T = typename enable_if<!is_same<T_container, string>::value, typename T_container::value_type>::type> ostream& operator<<(ostream &os, const T_container &v) { os << '{'; string sep; for (const T &x : v) os << sep << x, sep = ", "; return os << '}'; }
void dbg_out() {cerr << endl;}
template<typename Head, typename... Tail> void dbg_out(Head H, Tail... T) { cerr << ' ' << H; dbg_out(T...); }
#define dbg(...) cerr << "(" << #__VA_ARGS__ << "):", dbg_out(__VA_ARGS__);
template<class T> using pqg = priority_queue<T, vt<T>, greater<T>>;
const int dx[4] = {1,0,-1,0}, dy[4] = {0,1,0,-1};
constexpr int pct(int x) { return __builtin_popcount(x); } 
constexpr int p2(int x) { return 1<<x; }
constexpr int msk2(int x) { return p2(x)-1; }
template<class T> void print_vector(vector<T> &nums) {
    for(auto &num: nums)
        cout << num << " ";
    cout << '\n';
}
template<class T> void print(T t) {
    cout << t << "\n";
}
template<class T> void remDup(vector<T>& v) { // sort and remove duplicates
    sort(all(v)); v.erase(unique(all(v)),end(v)); }
struct edge {
    ll from;
    ll to;
    ll cost;
};
struct DSU {
	vector<int> e; void init(int N) { e = vector<int>(N,-1); }
	int get(int x) { return e[x] < 0 ? x : e[x] = get(e[x]); } 
	bool sameSet(int a, int b) { return get(a) == get(b); }
	int size(int x) { return -e[get(x)]; }
	bool unite(int x, int y) { // union by size
		x = get(x), y = get(y); if (x == y) return 0;
		if (e[x] > e[y]) swap(x,y);
		e[x] += e[y]; e[y] = x; return 1;
	}
};
bool operator<(edge t, edge f) {
    return t.cost > f.cost;
}
struct fast_mod
{
    template <typename T>
    bool isEven(T x)
    {
        return !(x & 1);
    }
    template <typename T>
    bool isOdd(T x)
    {
        return x & 1;
    }
    int addmod(int x, int y, int m)
    {
        // simple mod addition
        return ((x % m) + (y % m)) % m;
    }
    int multmod(int x, int y, int m)
    {
        return ((x % m) * (y % m)) % m;
    }
    int submod(int x, int y, int m)
    {
        return ((x % m) - (y % m)) % m;
    }
    int regmod(int x)
    {
        // now just do whatever
        return x % mod;
    }
};

struct binary_tree {
    struct binary_tree *left;
    struct binary_tree *right;
    int val;
    binary_tree(int n) {
        val=n;
        left=NULL;
        right=NULL;
    }
    int height(struct binary_tree *node) {
        if(node==NULL) return 0;
        return 1 + max(height(node->left), height(node->right));
    }
};
namespace graph_theory {
	void fast_io() {
		ios::sync_with_stdio(false);cin.tie(nullptr);
	}
	template<class T, class H> H djikstra(vector<T> adjList[], H totalNodes, H u, H v) {
		pqg<T> pq;
		// assuming adjList is {cost, node};
		vt<H> dist(200000, inf);
		dist[u] = 0;
		vt<bool> vis(200000, 0);
		while(pq.size()) {
			T t = pq.top().second;
			pq.pop();
			if(vis[t]) continue;
			vis[t]=1;
			for(auto &edge: adjList[t]) {
				T x = edge.first;
				T y = edge.second;
				if(dist[y] > dist[t] + x) {
					dist[y] = dist[t] + x;
					pq.push({dist[y], y});
				}
			}
		}
		return dist[v];
	}
	void bfs(vector<ll> adjList[], vt<bool> &vis, int n) {
		queue<int> s;
		s.push(n);
		while(s.size()) {
			int a = s.front();
			s.pop();
			if(vis[a]) continue;
			vis[a]=true;
			for(auto &edge: adjList[a]) {
				s.push(edge);
			}
		}
	}
	void dfs(vector<ll> adjList[], vt<bool>& vis, int n) {
		stack<int> curNodes;
		curNodes.push(n);
		while(curNodes.size()) {
			int t = curNodes.top();
			curNodes.pop();
			if(vis[t]) continue;
			vis[t]=true;
			for(auto &edge: adjList[t]) {
				curNodes.push(edge);
			}
		}
	}


}

template<class T> struct fast_array {
    vector<T> values;
    fast_array(int n) {
        values.resize(n);
    }
    
    void add(T t) {
        values.push_back(t);
    }
    int size() {
        return (int) values.size();
    }
    void remove(T t) {
        for(int i =0; i < values.size(); ++i) {
            if(values[i] == t) {
                swap(values[this.size()-1], values[i]);
                break;
            }
        }
        values.pop_back();
    }
    void arraysort() {
        sort(values.begin(), values.end());
    }
    T get(int i) {
        return values[i];      
    }
    void resize(int n) {
        values.resize(n);
    }
    void printVec() {
        for(auto &e: values) 
            cout << e << " ";
        cout << endl;
    }
    void clear() {
        values.clear();
    } 
};
template<class T> struct segtree
{

    struct segtree *lChild;
    
    struct segtree *rChild;
    
    T sum;
    
    int leftmost, rightmost;
    
    segtree(int left, int right, vector<T> &arr)
    {

        leftmost = left;
        rightmost = right;
        if (left == right)
        {
            sum = arr[left];
        }
        else
        {
            int mid = (left + right) / 2;

    
            lChild = new segtree(left, mid, arr);
            rChild = new segtree(mid + 1, right, arr);
            this->update();
        }
    }
    void update(){
    
        if(leftmost==rightmost) return;
        sum=lChild->sum+rChild->sum;
    }
    void pointUpdate(int index, T newVal) {
        if(leftmost==rightmost) {
            sum=newVal;
            return;
        }
    
        if(index<=lChild->rightmost) lChild->pointUpdate(index, newVal);
        else rChild->pointUpdate(index, newVal);
        update();
    }
    T query(int left, int right)
    {

        if (left > rightmost || right < leftmost)
        {
            return 0;
            // remember to make INF when doing contest!
        }
        else if (left <= leftmost && right >= rightmost)
            return sum;

        return lChild->query(left, right) + rChild->query(left, right);
    }
};
template<int SZ> struct udGraph{
    vector<vector<int>> adjList;
    
    vector<bool> vis;
    
    int size = SZ;
    void addNodes(int u, int v) {
        
        adjList[u].push_back(v);
        
        adjList[v].push_back(u);
    }
    void dfs(int n) {
        vis[n]=true;

        for(auto &edge: adjList[n]) if(!this->vis[edge]) dfs(edge);
    }
    bool connected() {
        this->dfs(0);

        int n = this->size;

        for(int i =0; i < n; i++)
            if(!this->vis[i]) return false;
        
        return true;
        // O(n)
    }

};
template<typename T> 
bool binsearch(vector<T> &nums, int target)
{

    int left = 0, right = nums.size() - 1;

    while (left <= right)
    {
        int mid = (left + right) / 2;
        if (nums[mid] == target)
            return true;
        else if (nums[mid] < target)
            left = mid + 1;
        else
            right = mid - 1;
    }
    return false;
}
namespace number_theory {
	template<class T> vector<T> sieve(int n) {
		bool prime[150000];

        for(int i =0; i <= n; i++) prime[i]=1;

		for(int i = 2; i <= n; i++)if(prime[i]) for(int j=i*i; j <= n; j+=i) prime[j]=0;

		vector<T> ans;

		for(int i =2; i <=n; i++) if(prime[i]) ans.push_back(i);

		return ans;
	}
    vector<ll> pfactors(int n) {
        vector<ll> pf;
        for(ll i = 2; i < n/2; i++) {

            int c=0;

            while(n%i==0) {
                c++;
                n/=i;
            }

            if(c) pf.push_back(i);
        }

        return pf;
        // O(sqrt(n))
    }
    vector<ll> factors(int n) {
        set<ll> ans;
        vector<ll> v;
        for(int i =1; i * i < n; ++i) {
            if(n%i==0) {
                ans.insert(n/i);
                ans.insert(i);
            }
        }

        for(auto &factor: ans)
            v.push_back(factor);
        return v;
    }
    bool isPrime(int n) {
        if(n == 1) return false;

        if(n == 2) return true;

        if(n == 3) return true;

        if(n%3 ==0 || n%2==0) return false;

        for(int i = 5; i * i <=n; i+=6)
            if(n % i ==0 || n % (i+2) ==0) return false;

        return true;
    }
}

void solve()
{
    string s;
    cin >> s;

    int ans = 0;
    for(int i=1; i < sz(s); i++) {
        if(s[i] == s[i-1] || (i>=2 && s[i] == s[i-2])) {
            ans += 1;
            s[i] = '*';
        }
    }
    cout << ans << endl;
    
}
int main()
{
    fastio;

    int tc = 1;

	cin >> tc;
	while(tc--){
        solve();

	}
}
/* stuff you should look for
    * int overflow, array bounds
    * special cases (n=1?)
    * do smth instead of nothing and stay organized
    * WRITE STUFF DOWN
    * DON'T GET STUCK ON ONE APPROACH
*/
// Thanks benq!