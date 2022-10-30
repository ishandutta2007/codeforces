#include<bits/stdc++.h>

using namespace std;

#define F(i, l, r) for(int i = (l); i < (r); i++)
#define E(i, l, r) for(int i = (l); i <= (r); i++)
#define DF(i, l, r) for(int i = (l); i >= (r); i--)
#define I(x, a) for(auto x : (a))
#define mp make_pair
#define X first
#define Y second
#define clean(x) memset((x), 0, sizeof(x))
#define ret return
#define cont continue
#define brk break
#define ins insert
#define all(x) (x).begin(),(x).end()
#define sync ios_base::sync_with_stdio(false);cin.tie(0)
#define pb push_back
#define y1 fjfg
#define tm shjfhg

typedef long long ll;
typedef unsigned long long ull;
typedef long double dbl;
typedef pair<int, int> pii;

const int N = (int)1e5 + 5;

vector<int> who[N];
bool alive[N];
bool kek[N];
int n;

int main() {
	scanf("%d", &n);
	fill(alive, alive + N, true);
	F(i, 2, n + 1){
		if(kek[i])cont;
		who[i].pb(i);
		for(int j = i + i; j <= n; j += i){
			kek[j] = true;
			who[i].pb(j);
		}
	}
	vector<pii> ans;
	DF(i, n, 1){
		if(who[i].empty())cont;
		vector<int> curr;
		I(x, who[i])if(alive[x])curr.pb(x);
		if(curr.size()%2){
			if(curr.size() == 1u)cont;
			curr.erase(curr.begin() + 1);
			for(int j = 0; j < (int)curr.size(); j += 2){
				int x = curr[j], y = curr[j + 1];
				alive[x] = alive[y] = false;
				ans.pb(mp(x, y));
			}
		}
		else{
			for(int j = 0; j < (int)curr.size(); j += 2){
				int x = curr[j], y = curr[j + 1];
				alive[x] = alive[y] = false;
				ans.pb(mp(x, y));
			}
		}
	}
	printf("%u\n", ans.size());
	I(x, ans)printf("%d %d\n", x.X, x.Y);
	return 0;
}