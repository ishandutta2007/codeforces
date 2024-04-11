#include <bits/stdc++.h>

using namespace std;

#define pb push_back
#define mp make_pair
#define X first
#define Y second
#define I(x, a) for(auto x : a)
#define F(i, l, r) for(auto i = l; i < r; ++i)
#define E(i, l, r) for(auto i = l; i <= r; ++i)
#define DF(i, l, r) for(auto i = l; i >= r; --i)
#define clean(a) memset((a),0,sizeof (a))
#define sync ios_base::sync_with_stdio(0);cin.tie(0)
#define all(x) (x).begin(),(x).end()
#define ret return
#define cont continue
#define brk break
#define ins insert
#define sz(a) ((int)(a).size())

typedef long long ll;
typedef unsigned long long ull;
typedef long double dbl;
typedef pair <int, int> pii;

const int maxn = 1e5 + 5;
const int S = 60;

struct node{
	int t[S];
};

int a[maxn];
node t[4 * maxn];
int n;
int idx[100];
int tmp[S];
int buf[S];
int ptr = 0;

inline void merge(int* l, int* r, int* dest){
	F(start, 0, S){
		int t = *(l + start);
		int pos = (start + t)%S;
		t += *(r + pos);
		*(dest + start) = t;
	}
}

void build(int v, int l, int r){
	if(l == r){
		F(i, 0, S){
			if(i%a[l] == 0)t[v].t[i] = 2;
			else t[v].t[i] = 1;
		}
		return;
	}
	int mid = (l + r)/2;
	build(2*v, l, mid);
	build(2*v + 1, mid + 1, r);
	merge(t[2*v].t, t[2*v + 1].t, t[v].t);
}

void upd(int v, int l, int r, int pos, int val){
	if(l == r){
		a[l] = val;
		F(i, 0, S){
			if(i%a[l] == 0)t[v].t[i] = 2;
			else t[v].t[i] = 1;
		}
		return;
	}
	int mid = (l + r)/2;
	if(pos <= mid)
		upd(2*v, l, mid, pos, val);
	else
		upd(2*v + 1, mid + 1, r, pos, val);
	merge(t[2*v].t, t[2*v + 1].t, t[v].t);
}

void split(int v, int l, int r, int ul, int ur){
	if(ul > ur)
		ret;
	if(l == ul && r == ur){
		idx[ptr++] = v;
		ret;
	}
	int mid = (l + r)/2;
	split(2*v, l, mid, ul, min(ur, mid));
	split(2*v + 1, mid + 1, r, max(ul, mid + 1), ur);
}

int query(int l, int r){
	ptr = 0;
	split(1, 0, n - 1, l, r);
	memcpy(tmp, t[idx[0]].t, S * sizeof(int));
	F(i, 1, ptr){
		merge(tmp, t[idx[i]].t, buf);
		memcpy(tmp, buf, S * sizeof(int));
	}
	return tmp[0];
}

int main() {
    sync;
	cin >> n;
	F(i, 0, n)cin >> a[i];
	build(1, 0, n - 1);
	int q;
	cin >> q;
	F(i, 0, q){
		char t;
		int l, r;
		cin >> t >> l >> r;
		if(t == 'A'){
			--l;
			r -= 2;
			cout << query(l, r) << '\n';
		}
		else{
			--l;
			upd(1, 0, n - 1, l, r);
		}
	}
}