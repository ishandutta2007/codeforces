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
#define acpy(x, y) memcpy(x, y, sizeof(y))
#define y1 adjf

const int mod = 1000000007;

int dp[76][1 << 20];
bool good[1 << 20];
int rz[76];
int n;
string s;

int main(){
//	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cin >> n >> s;
	fi0(dp); fi0(good);
	F(i, 0, n + 1){
		dp[i][0] = 1;
	}
	rz[n] = n;
	Df(i, n - 1, -1){
		if(s[i] == '0')rz[i] = rz[i + 1];
		else rz[i] = i;
	}
	F(i, 0, 1 << 20){
		bool is = true;
		if(i == 0)cont;
		int kek = i;
		while(kek > 0){
			if(!(kek&1)){is = false; brk;}
			kek >>= 1;
		}
		good[i] = is;
	}
	lint ans = 0;
	F(i, 0, n){
		int j = rz[i];
		F(mask, 0, 1 << 20){
			if(dp[i][mask] == 0)cont;
			j = rz[i];
			//printf("At dp[%d][%d] = %d\n", i, mask, dp[i][mask]);
			int cnum = 0;
			while(j < n){
				cnum = (cnum << 1) + (s[j] - '0');
				if(cnum > 20)brk;
				int nmask = mask | (1 << (cnum - 1));
				dp[j + 1][nmask] += dp[i][mask];
				//printf("Increasing dp[%d][%d] with dp[%d][%d] at cnum = %d\n", j + 1, nmask, i, mask, cnum);
				if(dp[j + 1][nmask] >= mod)dp[j + 1][nmask] -= mod;
				j++;
			}
			if(good[mask])ans += dp[i][mask];
		}
	}
	F(mask, 0, 1 << 20)if(good[mask])ans += dp[n][mask];
	cout << ans%mod;
	ret 0;
}