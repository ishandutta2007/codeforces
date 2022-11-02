#include<bits/stdc++.h>

using namespace std;
typedef long long lint;
typedef long double ldb;
typedef unsigned long long uli;

#define X first
#define Y second
#define F(i, l, r) for(auto i = l; i != r; i++)
#define Df(i, l, r) for(auto i = l; i != r; i--)
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

const int MAXN = 5e2 + 4;
const int MAXD = 1e5 * (510);

int gr[MAXN][MAXN];
int n;
lint ans = 0ll;
int mark[MAXN];
int al[MAXN];
int ord[MAXN];
lint out[MAXN];
int d[MAXN];
int ad[MAXN];
int d0[MAXN][MAXN];

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	scanf("%d", &n);
	fi0(al);
	F(i, 0, n){
		F(j, 0, n){
			scanf("%d", &gr[i][j]);
		}
	}
	F(i, 0, n){
		scanf("%d", &ord[i]); ord[i]--;
	}
	finf(d0);
	Df(i, n - 1, -1){
		al[ord[i]] = true;
		finf(d); finf(ad);
		fi0(mark);
		d[ord[i]] = 0; ad[ord[i]] = 0;
		F(iter, 0, n){
			int v = -1;
			F(j, 0, n){
				if(mark[j] || !al[j]){cont;}
				if(v == -1 || d[j] < d[v]){v = j;}
			}
			if(v == -1 || d[v] > MAXD){brk;}
			mark[v] = 1;
			F(j, 0, n){
				if(mark[j] || !al[j]){cont;}
				if(d[j] > d[v] + gr[v][j]){d[j] = d[v] + gr[v][j];}
			}
		}
		fi0(mark);
		F(iter, 0, n){
			int v = -1;
			F(j, 0, n){
				if(mark[j] || !al[j]){cont;}
				if(v == -1 || ad[j] < ad[v]){v = j;}
			}
			if(v == -1 || ad[v] > MAXD){brk;}
			mark[v] = 1;
			F(j, 0, n){
				if(mark[j] || !al[j]){cont;}
				if(ad[j] > ad[v] + gr[j][v]){ad[j] = ad[v] + gr[j][v];}
			}
		}
		F(v, 0, n){
			F(u, 0, n){
				if(v == u){cont;}
				if(!al[v] || !al[u]){cont;}
				if(ad[v] + d[u] < d0[v][u]){
					if(d0[v][u] <= MAXD){ans -= d0[v][u];}
					ans += ad[v] + d[u];
					d0[v][u] = ad[v] + d[u];
				}
			}
		}
		out[i] = ans;
	}
	F(i, 0, n)
		printf("%lld ", out[i]);
	ret 0;
}