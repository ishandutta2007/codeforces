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

const int MAXN = 3e5 + 5, MAXA = 1e6 + 6;



int n;
int a[MAXN];
int st[MAXN][22];
int pw[MAXN];

int get(int l, int r){
	if(l == r)ret a[l];
	int sz = r - l + 1;
	int p = pw[sz] - 1;
	ret __gcd(st[l][p], st[r - (1 << p) + 1][p]);
}

int ans = -1;
set<int> res;

int main(){
	//freopen("input.txt", "r", stdin);
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	scanf("%d", &n);
	F(i, 0, n)scanf("%d", &a[i]);
	//int ptr = 0;
	int L = 0;
	while(1 << L <= n)L++;
	pw[1] = 0;
	F(i, 2, n + 1){
		pw[i] = pw[i - 1];
		if((1 << pw[i - 1]) < i)pw[i]++;
	}
	F(j, 0, L){
		F(i, 0, n){
			if(j == 0){st[i][j] = a[i]; cont;}
			int r = i + (1 << j) - 1;
			if(r >= n){st[i][j] = st[i][j - 1]; cont;}
			st[i][j] = __gcd(st[i][j - 1], st[r - (1 << (j - 1)) + 1][j - 1]);
		}
	}
	F(i, 0, n){
		int l = i, r = n - 1;
		while(r - l > 1){
			int mid = (l + r) >> 1;
			if(get(i, mid) == a[i])l = mid;
			else r = mid - 1;
		}
		if(get(i, r) != a[i])r = l;
		int sz = r - i;
		l = 0, r = i;
		while(r - l > 1){
			int mid = (l + r) >> 1;
			if(get(mid, i) == a[i])r = mid;
			else l = mid + 1;
		}
		if(get(l, i) != a[i])l = r;
		sz += i - l;
		if(sz > ans){res.clear(); ans = sz;}
		if(sz == ans)res.ins(l);
	}
	printf("%d %d\n", (int)res.size(), ans);
	I(v, res)printf("%d ", v + 1);
	ret 0;
}