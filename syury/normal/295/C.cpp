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
#define tm dhgdg

const int mod = 1000000007;

struct state{
	int a, b, c;
	state(){}
	state(int ta, int tb, int tc):a(ta),b(tb),c(tc){}
};

int n, k;
int w1 = 0, w2 = 0;

int dp[51][51][2];
int dist[51][51][2];
int C[51][51];
state q[(int)1e6];
int qh = 0, qt = 0;

void add(int & a, int b){
	a += b;
	if(a >= mod)a -= mod;
}

void precalc(){
	F(i, 0, 51){
		F(j, 0, i + 1){
			if(i == 0 || j == 0){C[i][j] = 1; cont;}
			C[i][j] = C[i - 1][j - 1];
			add(C[i][j], C[i - 1][j]);
		}
	}
}

void bfs(){
	while(qh < qt){
		state curr = q[qh++];
		if(curr.c == 0){
			F(i, 0, curr.a + 1){
				F(j, 0, curr.b + 1){
					if(i + j + j > k)brk;
					if(i + j == 0)cont;
					if(dist[curr.a - i][curr.b - j][1] == mod){dist[curr.a - i][curr.b - j][1] = dist[curr.a][curr.b][0] + 1; q[qt++] = state(curr.a - i, curr.b - j, 1);}
					if(dist[curr.a - i][curr.b - j][1] == dist[curr.a][curr.b][0] + 1)add(dp[curr.a - i][curr.b - j][1], ((dp[curr.a][curr.b][0] * 1ll * C[curr.a][i])%mod)*1ll*C[curr.b][j]%mod);
				}
			}
		}
		else{
			F(i, 0, w1 - curr.a + 1){
				F(j, 0, w2 - curr.b + 1){
					if(i + j + j > k)brk;
					if(i + j == 0)cont;
					if(dist[curr.a + i][curr.b + j][0] == mod){dist[curr.a + i][curr.b + j][0] = dist[curr.a][curr.b][1] + 1; q[qt++] = state(curr.a + i, curr.b + j, 0);}
					if(dist[curr.a + i][curr.b + j][0] == dist[curr.a][curr.b][1] + 1)add(dp[curr.a + i][curr.b + j][0], ((dp[curr.a][curr.b][1]*1ll*C[w1 - curr.a][i])%mod)*1ll*C[w2 - curr.b][j]%mod);
				}
			}
		}
	}
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	fi0(dp);
	fi0(C);
	precalc();
	F(i, 0, 51)
		F(j, 0, 51)
			F(b, 0, 2)
				dist[i][j][b] = mod;
	scanf("%d%d", &n, &k);
	k /= 50;
	F(i, 0, n){
		int x;
		scanf("%d", &x);
		if(x == 50)w1++; else w2++;
	}
	dist[w1][w2][0] = 0;
	dp[w1][w2][0] = 1;
	q[qt++] = state(w1, w2, 0);
	bfs();
	if(dist[0][0][1] == mod){printf("-1\n0"); ret 0;}
	printf("%d\n%d", dist[0][0][1], dp[0][0][1]);
	ret 0;
}