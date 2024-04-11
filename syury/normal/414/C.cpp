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
#define tm afhdhn

const int MAXN = 23;

lint cnt[MAXN], old[MAXN], tot[MAXN];
int a[1 << MAXN];
int t[1 << MAXN];
//int tm[1 << MAXN];
//int eq[1 << MAXN], te[1 << MAXN];
int n;
int gt = 0;

/*void inc_node(int i){
	if(tm[i] < gt){tm[i] = gt; t[i] = 0;}
	t[i]++;
}

int get_node(int i){
	if(tm[i] < gt){tm[i] = gt; t[i] = 0;}
	ret t[i];
}

void inc(int x){
	for(; x < (1 << n) + 1; x = x | (x + 1))inc_node(x);
}

int get_t(int r){
	int res = 0;
	for(; r >= 0; r = (r & (r + 1)) - 1)res += get_node(r);
	ret res;
}

int get(int l){
	if(l == 0)ret get_t(1 << n); 
	else ret get_t(1 << n) - get_t(l - 1);	
}

void ieq(int i){if(te[i] < gt){te[i] = gt; eq[i] = 0;} eq[i]++;}
int geq(int i){if(te[i] < gt){te[i] = gt; eq[i] = 0;} ret eq[i];}*/

void solve(int x, int l, int r){
	if(x == 0){cnt[x] = tot[x] = 0; ret;}
	int mid = (l + r) >> 1;
	solve(x - 1, l, mid);
	solve(x - 1, mid + 1, r);
	tot[x] += (1 << (x - 1)) * 1ll * (1 << (x - 1));
	int tptr = 0;
	int _l = l, _r = mid + 1;
	int la = 0, al = 0;
	int prv = -1;
	//printf("%d %d %d %d\n", l, r, _l, _r);
	while(_l < mid + 1 || _r <= r){
		if(_l <= mid && (_r > r || a[_l] <= a[_r])){
			t[tptr++] = a[_l];
			al++; if(prv == a[_l])la++; else la = 1;
			_l++;	
		}
		else{
			if(prv != a[_r])la = 0;
			cnt[x] += (mid - l + 1) - al;
			t[tptr++] = a[_r];
			//printf("la = %d at l = %d r = %d\n", la, l, r);
			tot[x] -= la;
			_r++;
		}
		prv = t[tptr - 1];
	}
	F(i, l, r + 1)a[i] = t[i - l];
	/*cnt[x] = cnt[x - 1]; tot[x] = tot[x - 1];
	int bg = 0;
	int col = 0; gt++;
	F(i, 0, 1 << n){
		if(i - bg == (1 << (x - 1))){
			col = 1 - col; if(col == 0)gt++;
			bg = i;
		}
		if(col == 0){inc(a[i]); ieq(a[i]); cont;}
		tot[x] += (1 << (x - 1)) - geq(a[i]);
		cnt[x] += get(a[i] + 1);
	}*/
	//printf("tot[%d] = %lld cnt[%d] = %lld\n", x, tot[x], x, cnt[x]);
}

set<int> ss;
map<int, int> w;

int main(){
	//freopen("input.txt", "r", stdin);
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	scanf("%d", &n);
	F(i, 0, 1 << n)scanf("%d", &a[i]);
	F(i, 0, 1 << n)ss.ins(a[i]);
	int ccc = 0;
	I(v, ss)w[v] = ccc++;
	F(i, 0, 1 << n)a[i] = w[a[i]];
	fi0(cnt); fi0(tot);
	solve(n, 0, (1 << n) - 1);
	F(i, 1, n + 1){
		tot[i] += tot[i - 1]; cnt[i] += cnt[i - 1];
	//	printf("%lld %lld\n", tot[i], cnt[i]);
	}
	int cq;
	scanf("%d", &cq);
	//printf("%lld %lld\n", tot[n], cnt[n]);
	F(i, 0, cq){
		int q; scanf("%d", &q);
		Df(j, q, -1){old[j] = cnt[j]; cnt[j] = tot[j] - cnt[j];}
		F(j, q + 1, n + 1){
			old[j] = cnt[j];
			cnt[j] = cnt[j] - old[j - 1] + cnt[j - 1];
		}
		printf("%lld\n", cnt[n]);
	}
	ret 0;
}