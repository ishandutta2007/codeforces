
#include<bits/stdc++.h>
#include<bits/extc++.h>

using namespace std;
using namespace __gnu_pbds;

template<typename T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

#define pb push_back
#define mp make_pair
#define X first
#define Y second
#define I(x, a) for(auto x : a)
#define F(i, l, r) for(auto i = l; i < r; ++i)
#define E(i, l, r) for(auto i = l; i <= r; ++i)
#define DF(i, l, r) for(auto i = l; i >= r; --i)
#define clean(a) memset((a),0,sizeof (a))
#define sync ios_base::sync_with_stdio(0);cin.tie(0)
#define all(x) (x).begin(),(x).end()
#define ret return
#define cont continue
#define brk break
#define ins insert

typedef long long ll;
typedef unsigned int ull;
typedef long double dbl;
typedef pair <int, int> pii;

const int N = (int)4e3 + 3;

int n, m;
pii a[N];
int w[N];
bool alive[N];
int where[N];
int pa[N];
int cnt = 0;
int uu = 0;
set<pii> pas;

void make_move(int x){
	cout << x << endl;
}

void play(){
	while(cnt > 0){
		if(!pas.empty()){
			int v = pas.begin()->X, u = pas.begin()->Y;
			pas.erase(pas.begin());
			alive[v] = alive[u] = 0;
			if(w[v] < w[u])swap(v, u);
			make_move(v + 1);
			int x;
			cin >> x;
			cnt -= 2;
			continue;
		}
		--cnt;
		while(!alive[a[uu].Y])++uu;
		alive[a[uu].Y] = 0;
		make_move(a[uu].Y + 1);
		if(!cnt)break;
		--cnt;
		int x;
		cin >> x;
		--x;
		alive[x] = 0;
	}
}

signed main(){
	sync;
	cin >> n >> m;
	n *= 2;
	cnt = n;
	F(i, 0, n){
		alive[i] = 1;
		pa[i] = -1;
		cin >> a[i].X;
		a[i].Y = i;
		w[i] = a[i].X;
	}
	sort(a, a + n);
	reverse(a, a + n);
	F(i, 0, n)where[a[i].Y] = i;
	F(i, 0, m){
		int v, u;
		cin >> v >> u;
		--v; --u;
		pa[v] = u;
		pa[u] = v;
		if(v > u)swap(v, u);
		pas.insert({v, u});
	}
	int mv;
	cin >> mv;
	if(mv == 1)
		play();
	else{
		while(true){
			if(!cnt)break;
			int v;
			cin >> v;
			--v;
			alive[v] = 0;
			--cnt;
			if(pa[v] != -1){
				alive[pa[v]] = 0;
				pas.erase({min(v, pa[v]), max(v, pa[v])});
				make_move(pa[v] + 1);
				--cnt;
				continue;
			}
			play();
			break;
		}
	}
	ret 0;
}