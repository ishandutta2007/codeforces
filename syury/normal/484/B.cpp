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

const int MAXN = 1e6 + 2;

int n;
vector<int> a;
int p[2 * MAXN];
int ans = 0;

int main(){
	//freopen("input.txt", "r", stdin);
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	scanf("%d", &n);
	a.rs(n);
	F(i, 0, n)scanf("%d", &a[i]);
	sort(all(a));
	int ptr = 0;
	F(i, 0, 2 * MAXN){
		p[i] = -1;
		if(i > 0)p[i] = p[i - 1];
		while(ptr < n && a[ptr] < i)ptr++;
		if(a[ptr - 1] < i && a[ptr - 1] > p[i]){p[i] = a[ptr - 1];}
	}
	F(i, 0, n){
		if(i > 0 && a[i] == a[i - 1])cont;
		int c = 2 * a[i];
		while(c < 2 * MAXN){
			int x = p[c];
			if(x != -1)ans = max(ans, x % a[i]);
			c += a[i];
		}
	}
	printf("%d", ans);
	ret 0;
}