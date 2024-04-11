#include<bits/stdc++.h>

using namespace std;
typedef long long lint;
typedef long double ldb;
typedef unsigned long long uli;

#define X first
#define Y second
#define F(i, l, r) for(auto i = l; i != r; i++)
#define Df(i, l, r) for(auto i = l; i != r; i--)
#define I(i, a) for(auto i : a)
#define pb push_back
#define rs resize
#define mk make_pair
#define asg assign
#define all(x) x.begin(),x.end()
#define ret return
#define cont continue
#define brk break
#define ins insert
#define era erase
#define fi0(x) memset(x, 0, sizeof(x))
#define finf(x) memset(x, 127, sizeof(x))
#define y1 adjf
#define tm afhdhn

int n;
vector<int> last;
list<int> divs;

int main(){
	//freopen("input.txt", "r", stdin);
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	scanf("%d", &n);
	int _s = 1e5 + 5;
	last.rs(_s); last.asg(_s, -1);
	F(i, 0, n){
		int x, y;
		scanf("%d%d", &x, &y);
		divs.clear();
		for(int i = 1; i * i <= x; i++){
			if(x%i != 0)cont;
			divs.pb(i); if(i * i != x)divs.pb(x/i);
		}
		int ans = 0;
		I(v, divs){
			if(last[v] < i - y)ans++;
			last[v] = i;
		}
		printf("%d\n", ans);
	}
	ret 0;
}