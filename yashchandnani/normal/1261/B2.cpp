#include <bits/stdc++.h>
using namespace std;


void __print(int x) {cerr << x;}
void __print(long x) {cerr << x;}
void __print(long long x) {cerr << x;}
void __print(unsigned x) {cerr << x;}
void __print(unsigned long x) {cerr << x;}
void __print(unsigned long long x) {cerr << x;}
void __print(float x) {cerr << x;}
void __print(double x) {cerr << x;}
void __print(long double x) {cerr << x;}
void __print(char x) {cerr << '\'' << x << '\'';}
void __print(const char *x) {cerr << '\"' << x << '\"';}
void __print(const string &x) {cerr << '\"' << x << '\"';}
void __print(bool x) {cerr << (x ? "true" : "false");}

template<typename T, typename V>
void __print(const pair<T, V> &x) {cerr << '{'; __print(x.first); cerr << ','; __print(x.second); cerr << '}';}
template<typename T>
void __print(const T &x) {int f = 0; cerr << '{'; for (auto &i: x) cerr << (f++ ? "," : ""), __print(i); cerr << "}";}
void _print() {cerr << "]\n";}
template <typename T, typename... V>
void _print(T t, V... v) {__print(t); if (sizeof...(v)) cerr << ", "; _print(v...);}
#ifndef ONLINE_JUDGE
#define debug(x...) cerr << "[" << #x << "] = ["; _print(x)
#else
#define debug(x...)
#endif

#define rep(i, n)    for(int i = 0; i < (n); ++i)
#define repA(i, a, n)  for(int i = a; i <= (n); ++i)
#define repD(i, a, n)  for(int i = a; i >= (n); --i)
#define trav(a, x) for(auto& a : x)
#define all(x) x.begin(), x.end()
#define sz(x) (int)(x).size()
#define fill(a)  memset(a, 0, sizeof (a))
#define fst first
#define snd second
#define mp make_pair
#define pb push_back
typedef long double ld;
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

void pre(){


}

void solve(){


}
int a[200009];
class WaveletTree
{
public:
    WaveletTree(std::vector<int> &v, int size) : s(size), nodes(2 * size)
    {
        build(v.begin(), v.end(), 0, s - 1, 1);
    }

    // l, r is 0 based
    // k is 1 based
    // range [l, r)
    int kTh(int l, int r, int k)
    {
        int idx = 1;
        int L = 0, U = s - 1;
        while (L != U) {
            int M = (L + U) / 2;
            int ll = nodes[idx][l];
            int lr = nodes[idx][r];
            if (k <= lr - ll) {
                l = ll, r = lr, U = M, idx = 2 * idx;
            } else {
                k -= lr - ll, l -= ll, r -= lr, L = M + 1, idx = 2 * idx + 1;
            }
        }
        return L;
    }

private:
    int s;
    std::vector<std::vector<int>> nodes;

    using iter = std::vector<int>::iterator;

    void build(iter b, iter e, int L, int U, int idx)
    {
        if (L == U)
            return;
        int M = (L + U) / 2;

        nodes[idx].resize(distance(b, e) + 1);
        nodes[idx][0] = 0;
        int i = 0;
        for (iter it = b; it != e; ++it) {
            nodes[idx][i + 1] = nodes[idx][i] + (*it <= M);
            i++;
        }

        iter p = std::stable_partition(b, e, [M](int i) { return i <= M; });

        build(b, p, L, M, idx * 2);
        build(p, e, M + 1, U, idx * 2 + 1);
    }
};
int val[200009];
int main() {
	cin.sync_with_stdio(0); cin.tie(0);
	cin.exceptions(cin.failbit);
	pre();
	int n;cin>>n;
	vector<pii> v(n);
	rep(i,n) {
		cin>>v[i].fst;
		val[i] = v[i].fst;
		v[i].snd=i;
		v[i].fst=-v[i].fst;
	}
	sort(all(v));
	rep(i,n) a[v[i].snd]=i;
	vi gg(n);
	rep(i,n) gg[i]=v[i].snd;
	WaveletTree W(gg,n);
	int m;cin>>m;
	rep(i,m){
		int k,j;cin>>k>>j;
		cout<<val[W.kTh(0,k,j)]<<'\n';	
	}
	return 0;
}