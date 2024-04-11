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
#define tm dhgdg

const int MAXN = 5e3 + 3;
const int inf = 1e5 + 5;

int n;
int dp[MAXN][MAXN];
int sm[MAXN][MAXN];
int a[MAXN];

int main(){
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	dp[0][0] = 0;
	sm[0][0] = 0;
	scanf("%d", &n);
	scanf("%d", &a[0]);
	F(i, 1, n){
		scanf("%d", &a[i]);
		int ptr = i - 1;
		int cs = 0;
		int ds = a[i];
		Df(j, i - 1, -1){
			while(ptr >= 0 && cs <= ds){cs += a[ptr]; ptr--;}
			if(cs <= ds)dp[i][j + 1] = i - j - 1 + sm[j][ptr + 1];
			else {
				int k = ptr + 2;
				if(k <= j)dp[i][j + 1] = i - j - 1 + sm[j][ptr + 2];
				else dp[i][j + 1] = inf;
			}
			cs -= a[j];
			ds += a[j];
			//printf("dp[%d][%d] = %d\n", i, j + 1, dp[i][j + 1]);
		}
		dp[i][0] = i;
		sm[i][i] = dp[i][i];
		Df(j, i - 1, -1)sm[i][j] = min(sm[i][j + 1], dp[i][j]);
	}
	printf("%d", sm[n - 1][0]);
	ret 0;
}