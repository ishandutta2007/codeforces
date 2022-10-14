#include <bits/stdc++.h>
using namespace std;

#define ar array
#define ll long long
#define it int64_t
#define vt vector
#define pll pair<ll, ll>
#define sum(x) int(accumulate(x.begin(), x.end(), 0))
#define fastio ios_base::sync_with_stdio(false);cin.tie(nullptr);
#define EACH(v, V) for (auto &v : V)
#define FOR(n) for (int i = 0; i < n; i++)
#define FORn(i, n) for (int i = 0; i < n; i++)
#define offset(V, i)  for (auto &v : v) v = i
#define all(x) x.begin(), x.end()
#define f first
#define s second

struct fast_mod
{

    int mod = 1e9 + 7;
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
struct bintree
{
    struct bintree *left;
    struct bintree *right;
    int val;
    bintree(int v)
    {
        val = v;
        left = NULL;
        right = NULL;
    }
};
struct segtree
{

    struct segtree *lChild;
    struct segtree *rChild;
    ll sum;
    int leftmost, rightmost;
    segtree(int left, int right, vector<int> &arr)
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
    void pointUpdate(int index, int newVal) {
        if(leftmost==rightmost) {
            sum=newVal;
            return;
        }
        if(index<=lChild->rightmost) lChild->pointUpdate(index, newVal);
        else rChild->pointUpdate(index, newVal);
        update();
    }
    ll query(int left, int right)
    {

        if (left > rightmost || right < leftmost)
        {
            return 0LL;
        }
        else if (left <= leftmost && right >= rightmost)
            return sum;

        return lChild->query(left, right) + rChild->query(left, right);
    }
};
class Graph {
	int V;
	list<int> *adj;
public:

	Graph(int V);
	void addEdge(int u, int v);


};
Graph::Graph(int V) {
	this->V = V;
	adj = new list<int>[V];
}
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
	vector<int> sieve(int n) {
		bool prime[15000105];
        for(int i =0; i < n; i++) prime[i]=1;
		for(int i = 2; i <= n; i++)if(prime[i]) for(int j=i*i; j <= n; j+=i) prime[j]=0;
		vector<int> ans;
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
    bool isPrime(int n) {
        if(n == 1) return false;
        if(n == 2) return true;
        if(n == 3) return true;
        if(n%3 ==0 || n%2==0) return false;
        for(int i = 5; i * i <=n; i+=6) {
            if(n % i ==0 || n % (i+2) ==0) return false;
        }
        return true;
    }

}
void solve()
{
    int a, b;
    cin >> a >> b;
    for(int i =0; i < b; i++)
        cout << "a";


    int turns =1;
    for(int i =0; i < a-b; i++){
        if(turns % 3 == 0) cout << "a";
        else if(turns % 3 == 1) cout << "b";
        else if(turns % 3 == 2) cout << "c";
        turns++;
    }
    cout << '\n';
}


int main()
{
    fastio;

    int tc;
    cin >> tc;
    while(tc--){
        solve();
    }
}