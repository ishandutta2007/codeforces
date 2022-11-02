#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double dbl;
typedef pair<int, int> pii;

#define F(i, l, r) for(int i = (l); i < (r); i++)
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

const int tsz = 1e7 + 7;
const int maxn = 3e5 + 5;

int n;
int32_t nxt[tsz][2];
int32_t bal[tsz];
int a[maxn], p[maxn];
int ptr = 2;
int ans[maxn];
int stk[60];
int sp = 0;

inline void add(int & v, int bit){
	if(nxt[v][bit] == 0)nxt[v][bit] = ptr++;
	v = nxt[v][bit];
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cin >> n;
	F(i, 0, n)cin >> a[i];
	F(i, 0, n)cin >> p[i];
	F(i, 0, n){
		int v = 1;
		bal[v]++;
		DF(j, 29, 0){
			if(p[i]&(1<<j))add(v, 1);
			else add(v, 0);
			bal[v]++;
		}
	}
	F(i, 0, n){
		int v = 1;
		sp = 1;
		stk[0] = v;
		ans[i] = 0;
		DF(j, 29, 0){
			int bit = (a[i]&(1<<j)) ? 1 : 0;
			if(bal[nxt[v][bit]] > 0)v = nxt[v][bit];
			else {v = nxt[v][1 - bit]; ans[i] |= 1<<j;}
			stk[sp++] = v;
		}
		F(j, 0, sp)bal[stk[j]]--;
	}
	F(i, 0, n)cout << ans[i] << ' ';
	return 0;
}