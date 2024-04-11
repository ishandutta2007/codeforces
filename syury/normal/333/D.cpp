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

const int MAXN = 1e3 + 3;

bool was[MAXN][MAXN];
int wh[MAXN];
int ptr;
int n, m;
int a[MAXN][MAXN];

bool can(int x){
	fi0(was);
	F(i, 0, n){
		ptr = 0;
		F(j, 0, m){
			if(a[i][j] >= x)wh[ptr++] = j;
		}
		F(j, 0, ptr){
			F(k, j + 1, ptr){
				int v = wh[j], u = wh[k];
				if(was[v][u])ret true;
				was[v][u] = was[u][v] = true;
			}
		}
	}
	ret false;
}

int main(){
	scanf("%d%d", &n, &m);
	F(i, 0, n)
		F(j, 0, m)
			scanf("%d", &a[i][j]);
	int l = 0, r = 1e9 + 3;
	while(r - l > 1){
		int mid = (l + r) >> 1;
		if(can(mid))l = mid;
		else r = mid - 1;
	}
	if(can(r))l = r;
	printf("%d", l);
	ret 0;
}