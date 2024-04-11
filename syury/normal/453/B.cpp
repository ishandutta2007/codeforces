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

int p[16] = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53};

int n;
int a[102];
int dp[2][1 << 17];
int pm[102][1 << 16];
bool bad[1 << 17];
int msum[1 << 17];
const int inf = 1e9 + 7;
list<int> can[1 << 16];

stack<int> as;

void restore(int i, int mask){
	if(i < 0)ret;
	int best = inf;
	I(u, can[mask - pm[i][mask]]){
		if(abs(a[i] - best) > abs(a[i] - u))best = u;
	}
	as.push(best);
	restore(i - 1, pm[i][mask]);
}

int main(){
//	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);
//	ios_base::sync_with_stdio(false);
//	cin.tie(0);
	scanf("%d", &n);
	F(i, 0, n)
		scanf("%d", &a[i]);
	fi0(bad); fi0(dp);
	F(mask, 0, 1 << 16){
		lint pr = 1ll;
		F(i, 0, 16){
			if(mask&(1 << i))pr *= p[i];
		}
		if(pr >= 59){bad[mask] = true; cont;}
		F(i, 1, 60){
			bool good = true;
			F(j, 0, 16){
				if(mask&(1 << j) && i%p[j] != 0){good = false; brk;}
				if(!(mask&(1 << j)) && i%p[j] == 0){good = false; brk;}
			}
			if(good){can[mask].pb(i);}
		}
	}
	dp[0][0] = 0;
	F(mask, 1, 1 << 16)
		dp[0][mask] = inf;
	int cd = 1;
	F(i, 0, n){
		F(mask, 0, 1 << 16)dp[cd][mask] = inf;
		F(mask, 0, 1 << 16){
			if(bad[mask])cont;
						int best = inf;
				I(u, can[mask]){
					if(abs(a[i] - best) > abs(a[i] - u))best = u;
				}

			int tms = (1 << 16) - 1 - mask;
			int cv = tms;
			while(cv > 0){
				//dp[cd][mask] = min(dp[cd][mask], dp[1 - cd][prv] + abs(a[i] - msum[cv]));
				if(dp[cd][cv + mask] > dp[1 - cd][cv] + abs(a[i] - best)){dp[cd][cv + mask] = dp[1 - cd][cv] + abs(a[i] - best); pm[i][cv + mask] = cv;}
				cv = (cv - 1)&tms;
			}
			//dp[cd][mask] = min(dp[cd][mask], dp[1 - cd][mask] + a[i] - 1);
			if(dp[cd][mask] > dp[1 - cd][0] + abs(a[i] - best)){dp[cd][mask] = dp[1 - cd][0] + abs(a[i] - best); pm[i][mask] = 0;}
		}
		cd = 1 - cd;
	}
	cd = 1 - cd;
	int ans = inf;
	int pos;
	F(mask, 0, 1 << 16)
		if(ans > dp[cd][mask]){ans = dp[cd][mask]; pos = mask;}
	restore(n - 1, pos);
	while(!as.empty()){
		printf("%d ", as.top()); as.pop();
	}
	ret 0;
}