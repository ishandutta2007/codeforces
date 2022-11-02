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

int n, m;

int main(){
	//freopen("input.txt", "r", stdin);
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	scanf("%d%d", &n, &m);
	if(n == 1){printf("%d", m); ret 0;}
	if(m == 1){printf("%d", n); ret 0;}
	if(n == 2){
		int ans = 4 * (m/4) + 2 * min(2, m%4);
		ans = max(ans, m);
		printf("%d", ans); ret 0;
	}
	if(m == 2){
		int ans = 4 * (n/4) + 2 * min(2, n%4);
		ans = max(ans, n);
		printf("%d", ans); ret 0;
	}
	printf("%d", n * m / 2 + n * m % 2);
	ret 0;
}