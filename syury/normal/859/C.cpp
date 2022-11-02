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

int n;
int a[55];
pair<int, int> dp[55][2];

int main(){
//	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);
	scanf("%d", &n);
	F(i, 0, n)scanf("%d", &a[i]);
	dp[n - 1][1] = mk(0, a[n - 1]);
	dp[n - 1][0] = mk(a[n - 1], 0);
	Df(i, n - 2, -1){
		F(c, 0, 2){
			if(c == 0){
				if(dp[i + 1][c].X > dp[i + 1][1 - c].X + a[i]){dp[i][c] = mk(dp[i + 1][c].X, dp[i + 1][c].Y + a[i]);}else{dp[i][c] = mk(dp[i + 1][1 - c].X + a[i], dp[i + 1][1 - c].Y);}
			}
			else{
				if(dp[i + 1][c].Y > dp[i + 1][1 - c].Y + a[i]){dp[i][c] = mk(dp[i + 1][c].X + a[i], dp[i + 1][c].Y);}else{dp[i][c] = mk(dp[i + 1][1 - c].X, dp[i + 1][1 - c].Y + a[i]);}
			}
		}
	}
	printf("%d %d", dp[0][1].X, dp[0][1].Y);
	ret 0;
}