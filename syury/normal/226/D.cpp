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
#define acpy(y, x) memcpy(y, x, sizeof(y))
#define y1 adjf
#define ws wejgnjn
#define left fhgfj
#define tm shfhf

const int MAXN = 1e2 + 4;

int n, m;
bool used[2][MAXN];
int sum[2][MAXN];
int a[MAXN][MAXN];
int cnt[2];

set<pair<int, int> > s;

int main(){
	//freopen("output.txt", "w", stdout);
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	fi0(sum); fi0(used); fi0(cnt);
	scanf("%d%d", &n, &m);
	F(i, 0, n){
		F(j, 0, m){
			scanf("%d", &a[i][j]);
		}
	}
	F(i, 0, n){
		F(j, 0, m)sum[0][i] += a[i][j];
		s.ins(mk(sum[0][i], i << 1));
	}
	F(j, 0, m){
		F(i, 0, n)sum[1][j] += a[i][j];
		s.ins(mk(sum[1][j], 1 + (j << 1)));
	}
	while(!s.empty() && s.begin()->X < 0){
		int i = s.begin()->Y;
		s.era(s.begin());
		int ind = i&1;
		i >>= 1;
		if(ind == 0){
			F(j, 0, m){sum[1][j] -= 2 * a[i][j]; a[i][j] = -a[i][j]; s.era(mk(sum[1][j] - 2 * a[i][j], 1 + (j << 1))); s.ins(mk(sum[1][j], 1 + (j << 1)));}
			used[0][i] = !used[0][i]; cnt[0] += (used[0][i]) ? 1 : -1;
		}
		else{
			F(j, 0, n){sum[0][j] -= 2 * a[j][i]; a[j][i] = -a[j][i]; s.era(mk(sum[0][j] - 2 * a[j][i], j << 1)); s.ins(mk(sum[0][j], j << 1));}
			used[1][i] = !used[1][i]; cnt[1] += (used[1][i]) ? 1 : -1;
		}
		sum[ind][i] = -sum[ind][i];
		s.ins(mk(sum[ind][i], ind + (i << 1)));
	}
	printf("%d ", cnt[0]);
	F(i, 0, n)if(used[0][i])printf("%d ", i + 1);
	printf("\n");
	printf("%d ", cnt[1]);
	F(i, 0, m)if(used[1][i])printf("%d ", i + 1);
	ret 0;
}