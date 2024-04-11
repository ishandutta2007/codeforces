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

const int MAXN = 1e5 + 5;
const int SZ = MAXN * sizeof(lint);
const int S2 = MAXN * sizeof(bool);

lint dp[MAXN];
bool w[MAXN];
int n, q;
int v[MAXN], c[MAXN];

int main(){
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	scanf("%d%d", &n, &q);
	F(i, 0, n)scanf("%d", &v[i]);
	F(i, 0, n)scanf("%d", &c[i]), c[i]--;
	F(j, 0, q){
		int a, b;
		scanf("%d%d", &a, &b);
		memset(dp, 0, SZ); memset(w, 0, S2);
		lint m1 = 0, p1 = -2;
		lint m2 = 0, p2 = -1;
		F(i, 0, n){
			if(w[c[i]] && v[i] * 1ll * a > 0)dp[c[i]] += v[i] * 1ll * a;
			lint prv = (p1 == c[i]) ? m2 : m1;
			if(!w[c[i]]){dp[c[i]] = prv + v[i] * 1ll * b; w[c[i]] = true;} else dp[c[i]] = max(dp[c[i]], prv + v[i] * 1ll * b);
			if(p1 == c[i]){m1 = dp[c[i]]; cont;}
			if(p2 == c[i]){m2 = dp[c[i]]; if(m2 > m1){swap(m1, m2); swap(p1, p2);} cont;}
			if(dp[c[i]] > m1){m2 = m1; p2 = p1; m1 = dp[c[i]]; p1 = c[i];}
			else if(dp[c[i]] > m2){m2 = dp[c[i]]; p2 = c[i];}
		}
		printf("%lld\n", m1);
	}
	ret 0;
}