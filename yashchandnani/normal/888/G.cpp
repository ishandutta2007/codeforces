#include <bits/stdc++.h>
using namespace std;


typedef long long ll;
typedef pair<int,int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;
typedef long double ld; 

typedef set<int>::iterator sit;
typedef map<int,int>::iterator mit;
typedef vector<int>::iterator vit;

const int INF = 1e9 + 7;
const int MOD = 1e9 + 7;
const int MAXN = 1e6 + 3;

#define _  %  MOD
#define __ %= MOD

#define      each(it,s)        for(sit it = s.begin(); it != s.end(); ++it)
#define      sortA(v)          sort(v.begin(), v.end())
#define      sortD(v)          sort(v.rbegin(), v.rend())
#define      fill(a)           memset(a, 0, sizeof (a))

#define      rep(i, n)         for(int i = 0; i < (n); ++i)
#define      repA(i, a, n)     for(int i = a; i <= (n); ++i)
#define      repD(i, a, n)     for(int i = a; i >= (n); --i)
#define 	 pq(x)			   priority_queue<x,std::vector<x>,compare>
#define 	 rpq(x)			   priority_queue<x,std::vector<x>,Rcompare>
#define fi first
#define se second
#define mp make_pair
#define pb push_back

#define fbo find_by_order
#define ook order_of_key
#define SZ(x) ((int) (x).size())

struct Rcompare
{
  bool operator()(ii lhs,ii rhs){
    return lhs.fi>rhs.fi;
  }
};
struct compare
{
  bool operator()(ii lhs,ii rhs){
    return lhs.fi<rhs.fi;
  }
};
std::vector<int> a;

struct Node {
    int link[2] = {-1, -1};
};

class Trie {
public:
    Trie(int _lvlMax) {
        nodes.push_back(Node());
        lvlMax = _lvlMax;
    }

    void add(int value) {
        int node = 0;
        for (int lvl = lvlMax; lvl >= 0; --lvl) {
            int b = !!(value & (1 << lvl));
            if (nodes[node].link[b] == -1) {
                int x = newNode();
                nodes[node].link[b] = x;
            }
            node = nodes[node].link[b];
        }
    }

    int getMin(int value) {
        int node = 0;
        int ans = 0;
        for (int lvl = lvlMax; lvl >= 0; --lvl) {
            int b = !!(value & (1 << lvl));
            if (nodes[node].link[b] == -1) {
                ans |= 1 << lvl;
                node = nodes[node].link[b ^ 1];
            } else {
                node = nodes[node].link[b];
            }
        }
        return ans;
    }
private:
    vector<Node> nodes;
    int lvlMax;
    int newNode() {
        nodes.push_back(Node());
        return SZ(nodes) - 1;
    }
};
ll solve(vector<int>& a,int st,int n){
	if (n==1)
	{
		//cout<<a[st]<<endl;
		return 0;
	}
	else{
		int sz =30;
		int bi=0;
		if (a[st]==a[st+n-1])
		{
			return 0;
		}
		else{
			while((a[st]&(1<<sz))==(a[st+n-1]&(1<<sz))) sz--;
		}
		bi = sz;sz =0;
		while((a[st+sz]&(1<<bi))==(a[st]&(1<<bi))) sz++;
		ll ans = solve(a,st,sz);
		ans+=solve(a,st+sz,n-sz);
		Trie t(bi);
		rep(i,sz){
			t.add(a[st+i]);
		}
		int mn = (1<<30);
		repA(i,sz,n-1){
			mn = min(mn,t.getMin(a[st+i]));
		}
		//cout<<a[st]<<" "<<n<<" "<<ans<<endl;
		return ans+mn;

	}
}
int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int n;cin>>n;
  rep(i,n) {
  	int x;cin>>x;
  	a.pb(x);
  }
  sortA(a);
  cout<<solve(a,0,n);
  return 0;
}