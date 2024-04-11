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
#define y1 adjf

const int MAXN = 5e2 + 3;
const int MAXC = MAXN * MAXN;
char f[MAXN][MAXN];
bool u[MAXN][MAXN];
int comp[MAXN][MAXN];
int sum[MAXN][MAXN];
int n, k;
int sz[MAXC];
int tsum = 0;
int cnt[MAXC];

struct node{
	node *l, *r;
	int val, cnt;
	node(): l(NULL), r(NULL), val(0), cnt(0){}
};

node * root;

node * build(int l, int r){
	node * v = new node;
	v->val = 0; v->cnt = 0;
	if(l == r)
		ret v;
	int mid = (l + r) >> 1;
	v->l = build(l, mid);
	v->r = build(mid + 1, r);
	ret v;
}

/*void upd(node * v, int l, int r, int pos, int ncnt){
	//if(l + r == MAXC - 1){printf("Updating %d with %d\n", pos, ncnt);}
	if(l == r){
		if(ncnt != 0)
			v->cnt += ncnt;
		else
			v->cnt = 0;
		v->val = (v->cnt == 0) ? 0 : sz[l];
		ret;
	}
	int mid = (l + r) >> 1;
	if(pos <= mid)
		upd(v->l, l, mid, pos, ncnt);
	else
		upd(v->r, mid + 1, r, pos, ncnt);
	v->val = v->l->val + v->r->val;
}*/

void upd(node * v, int l, int r, int pos, int ncnt){
	bool w0 = (cnt[pos] == 0);
	cnt[pos] += ncnt;
	if(cnt[pos] == 0)
		tsum -= sz[pos];
	if(w0)
		tsum += sz[pos];
	root->val = tsum;
}

void dfs(int x, int y, int cc){
	//printf("Dfsing %d %d\n", x, y);
	u[x][y] = true;
	sz[cc]++;
	comp[x][y] = cc;
	if(x > 0 && !u[x - 1][y] && f[x - 1][y] == '.')
		dfs(x - 1, y, cc);
	if(y > 0 && !u[x][y - 1] && f[x][y - 1] == '.')
		dfs(x, y - 1, cc);
	if(x < n - 1 && !u[x + 1][y] && f[x + 1][y] == '.')
		dfs(x + 1, y, cc);
	if(y < n - 1 && !u[x][y + 1] && f[x][y + 1] == '.')
		dfs(x, y + 1, cc);
}

int getsum(int x1, int y1, int x2, int y2){
	if(x1 == 0 && y1 == 0)
		ret sum[x2][y2];
	if(x1 == 0)
		ret sum[x2][y2] - sum[x2][y1 - 1];
	if(y1 == 0)
		ret sum[x2][y2] - sum[x1 - 1][y2];
	ret sum[x2][y2] - sum[x1 - 1][y2] - sum[x2][y1 - 1] + sum[x1 - 1][y1 - 1];
}

int ans = 0;

int slowrt(int x, int y){
	set<int> w;
	int res = 0;
	F(i, x, x + k){
		F(j, y, y + k){
			if(f[i][j] == '.' && w.find(comp[i][j]) == w.end()){w.ins(comp[i][j]); res += sz[comp[i][j]];}
		}
	}
	if(x > 0){
		int i = x - 1;
		F(j, y, y + k){
			if(f[i][j] == '.' && w.find(comp[i][j]) == w.end()){w.ins(comp[i][j]); res += sz[comp[i][j]];}
		}
	}
	if(x + k < n){
		int i = x + k;
		F(j, y, y + k){
			if(f[i][j] == '.' && w.find(comp[i][j]) == w.end()){w.ins(comp[i][j]); res += sz[comp[i][j]];}
		}
	}
	if(y > 0){
		int j = y - 1;
		F(i, x, x + k){
			if(f[i][j] == '.' && w.find(comp[i][j]) == w.end()){w.ins(comp[i][j]); res += sz[comp[i][j]];}
		}
	}
	if(y + k < n){
		int j = y + k;
		F(i, x, x + k){
			if(f[i][j] == '.' && w.find(comp[i][j]) == w.end()){w.ins(comp[i][j]); res += sz[comp[i][j]];}
		}
	}
	ret res;
}

int slowsum(int x1, int y1, int x2, int y2){
	int res = 0;
	F(i, x1, x2 + 1){
		F(j, y1, y2 + 1){
			if(f[i][j] == '.')
				res++;
		}
	}
	ret res;
}

int getcurrs(int x, int y){
	//printf("For x = %d y = %d root = %d, should be %d, sum = %d, should be %d\n",x, y, root->val, slowrt(x, y), getsum(x, y, x + k - 1, y + k - 1), slowsum(x, y, x + k - 1, y + k - 1));
	ret tsum - getsum(x, y, x + k - 1, y + k - 1) + k * k;
}

void makefirst(){
	F(i, 0, k){
		F(j, 0, k){
			if(f[i][j] != 'X')
				upd(root, 0, MAXC - 1, comp[i][j], 1);
		}
	}
	if(k < n){
		F(i, 0, k)
			if(f[i][k] != 'X')
				upd(root, 0, MAXC - 1, comp[i][k], 1);
		F(j, 0, k)
			if(f[k][j] != 'X')
				upd(root, 0, MAXC - 1, comp[k][j], 1);
	}
}

int main(){
	//freopen("input.txt", "r", stdin);
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	memset(sz, 0, MAXC * sizeof(int));
	memset(sz, 0, MAXC * sizeof(int));
	auto myget = []()->char{char tmp = '!'; while(tmp != '.' && tmp != 'X'){tmp = getc(stdin);} ret tmp;};
	auto ps = [](char c)->int{ret (c != '.') ? 0 : 1;};
	scanf("%d%d", &n, &k);
	F(i, 0, n){
		memset(u[i], 0, n * sizeof(bool));
		F(j, 0, n){
			f[i][j] = myget();
		}
	}
	int cc = 0;
	root = build(0, MAXC - 1);
	//printf("\n");
	F(i, 0, n){
		F(j, 0, n){
			//putc(f[i][j], stdout);
			if(!u[i][j] && ps(f[i][j]) == 1)
				dfs(i, j, cc++);
			if(i == 0 && j == 0){sum[i][j] = ps(f[i][j]); cont;}
			if(i == 0){sum[i][j] = sum[i][j - 1] + ps(f[i][j]); cont;}
			if(j == 0){sum[i][j] = sum[i - 1][j] + ps(f[i][j]); cont;}
			sum[i][j] = sum[i - 1][j] + sum[i][j - 1] - sum[i - 1][j - 1] + ps(f[i][j]);
			
		}
	//	printf("\n");
	}
	//printf("%d\n", sz[0]);
	makefirst();
	ans = max(ans, getcurrs(0, 0));
	pair<int, int> coord = mk(0, 0);
	pair<int, int> d = mk(0, 1);
//	F(i, 0, n){
//		F(j, 0, n){
		while(true){
			int i = coord.X, j = coord.Y;
			//printf("out at %d %d d = %d %d\n", i, j, d.X, d.Y);

			if(i + k - 1 >= n || j + k - 1 >= n){
								brk;
			}
			//printf("For %d %d getcurrs is %d\n", i, j, getcurrs(i, j));
			ans = max(ans, getcurrs(i, j));
			if(d == mk(0, 1)/*j + k - 1 != n - 1*/){
				if(j != 0){
					F(l, i, i + k){
						if(ps(f[l][j - 1]) == 1)
							upd(root, 0, MAXC - 1, comp[l][j - 1], -1);
					}
				}
				if(i != 0 && ps(f[i - 1][j]) == 1){upd(root, 0, MAXC - 1, comp[i - 1][j], -1);}
				if(i != 0 && ps(f[i - 1][j + k]) == 1){upd(root, 0, MAXC - 1, comp[i - 1][j + k], 1);}
				if(i + k < n && ps(f[i + k][j]) == 1){upd(root, 0, MAXC - 1, comp[i + k][j], -1);}
				if(i + k < n && ps(f[i + k][j + k]) == 1){upd(root, 0, MAXC - 1, comp[i + k][j + k], 1);}
				if(j + k + 1 < n){
					F(l, i, i + k){
						if(ps(f[l][j + k + 1]) == 1)
							upd(root, 0, MAXC - 1, comp[l][j + k + 1], 1);
					}
				}
				coord = mk(i, j + 1);
				if(j + k == n - 1){d = mk(1, 0);}
				cont;
			}
			if(d == mk(1, 0)){
				if(i != 0){
					F(l, j, j + k){

						if(ps(f[i - 1][l]) == 1)
							upd(root, 0, MAXC - 1, comp[i - 1][l], -1);
					}
				}
				if(j != 0 && ps(f[i][j - 1]) == 1){upd(root, 0, MAXC - 1, comp[i][j - 1], -1);}
				if(j != 0 && ps(f[i + k][j - 1]) == 1){upd(root, 0, MAXC - 1, comp[i + k][j - 1], 1);}
				if(j + k < n && ps(f[i][j + k]) == 1){upd(root, 0, MAXC - 1, comp[i][j + k], -1);}
				if(j + k < n && ps(f[i + k][j + k]) == 1){upd(root, 0, MAXC - 1, comp[i + k][j + k], 1);}
				if(i + k + 1 < n){
					F(l, j, j + k){
						if(ps(f[i + k + 1][l]) == 1)
							upd(root, 0, MAXC - 1, comp[i + k + 1][l], 1);
					}
				}
				coord = mk(i + 1, j);
				if(j != 0){d = mk(0, -1);}else{d = mk(0, 1);}
				cont;
			}
			if(d == mk(0, -1)){
				if(j + k < n){
					F(l, i, i + k){
						if(ps(f[l][j + k]) == 1)
							upd(root, 0, MAXC - 1, comp[l][j + k], -1);
					}
				}
				if(i != 0 && ps(f[i - 1][j + k - 1]) == 1){upd(root, 0, MAXC - 1, comp[i - 1][j + k - 1], -1);}
				if(i != 0 && ps(f[i - 1][j - 1]) == 1){upd(root, 0, MAXC - 1, comp[i - 1][j - 1], 1);}
				if(i + k < n && ps(f[i + k][j + k - 1]) == 1){upd(root, 0, MAXC - 1, comp[i + k][j + k - 1], -1);}
				if(i + k < n && ps(f[i + k][j - 1]) == 1){upd(root, 0, MAXC - 1, comp[i + k][j - 1], 1);}
				if(j - 2 >= 0){
					F(l, i, i + k){
						if(ps(f[l][j - 2]) == 1)
							upd(root, 0, MAXC - 1, comp[l][j - 2], 1);
					}
				}
				coord = mk(i, j - 1);
				if(j - 1 == 0){d = mk(1, 0);}
				cont;

			}
		}
//		}
//	}
	printf("%d\n", ans);
	ret 0;
}