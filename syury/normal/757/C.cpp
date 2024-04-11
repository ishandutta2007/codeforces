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

const lint mod = 1000000007;
const int MAXM = 1e6 + 6;
const int MAXN = 1e5 + 5;

struct node{
	map<int, node*> nxt;
	int cnt = 0;
};

lint fac[MAXM];
int n, m;
int tp[MAXM];
pair<int, int> kek[MAXM];
int cid = 0;
node* lastv[MAXM];
node * root = new node;

node * extend(node * v, int c){
	if(!v->nxt.count(c))v->nxt[c] = new node;
	ret v->nxt[c];
}

int main(){
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	scanf("%d%d", &n, &m);
	F(i, 0, m)lastv[i] = root;
	fac[0] = 1ll;
	F(i, 1, m + 3)fac[i] = fac[i - 1] * i % mod;
	F(i, 0, n){
		int g;
		scanf("%d", &g);
		F(j, 0, g){
			scanf("%d", &tp[j]); tp[j]--;
		}
		sort(tp, tp + g);
		int cc = 0;
		int ptr = 0;
		F(j, 0, g){
			if(j > 0 && tp[j] == tp[j - 1])cc++;
			else{
				if(j != 0){
					kek[ptr++] = mk(cc, tp[j - 1]);
				}
				cc = 1;
			}
		}
		kek[ptr++] = mk(cc, tp[g - 1]);
		sort(kek, kek + ptr);
		int lpos = 0;
		F(j, 0, ptr){
			if(j == 0)cont;
			if(kek[j - 1].X == kek[j].X)cont;
			F(tmp, lpos, j){
				lastv[kek[tmp].Y] = extend(lastv[kek[tmp].Y], cid);
			}
			cid++;
			lpos = j;
		}
		F(tmp, lpos, ptr){
				lastv[kek[tmp].Y] = extend(lastv[kek[tmp].Y], cid);
		}
		cid++;
	}
	lint ans = 1ll;
	F(i, 0, m){
		lastv[i]->cnt++;
	}
	F(i, 0, m){
		ans = ans * fac[lastv[i]->cnt] % mod;
		lastv[i]->cnt = 0;
	}
	printf("%lld", ans);
	ret 0;
}