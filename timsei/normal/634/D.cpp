#include <bits/stdc++.h>
using namespace std;

const int N = 2e5 + 5;

#define int long long

struct NODE {
    int pos , price;
    friend bool operator < (NODE xxx , NODE yyy) {
	return xxx.pos < yyy.pos;
    }
    void input(void) {
	cin >> pos >> price;
    }
}E[N];

int n , d , m , ans , nxt[N] , tot;

#define Pair pair<int,int>

int q[N];

signed main(void) {
    cin >> d >> n >> m;
    for(int i = 1;i <= m;++ i) E[i].input();
    E[++ m].pos = 0 , E[m].price = 0;
    sort(E + 1 , E + m + 1); E[++ m].pos = d; E[m].price = -1;
    q[++ tot] = m + 1; E[m + 1].price = -2e9; E[m + 1].pos = d + 1;
    for(int i = m;i >= 1;-- i) {
	int l = 1 , r = tot , res = 1;
	while(l <= r) {
	    int mid = (l + r) >> 1;
	    if(E[q[mid]].price <= E[i].price) {
		res = mid; l = mid + 1;
	    }
	    else r = mid - 1;
	}
	//cerr << res <<" " << endl;
	nxt[i] = q[res];
	while(E[q[tot]].price >= E[i].price) {
	    tot --;
	}
	q[++ tot] = i;
    }
    // for(int i = 1;i <= m;++ i) cerr << nxt[i] <<" ";
    // puts("");
    int now = 1 , P = 0;
    while(now < m) {
	int L = now , R = m , res = now;
	while(L <= R) {
	    int mid = (L + R) >> 1;
	    if(E[mid].pos - E[now].pos <= n) {
		res = mid; L = mid + 1;
	    }
	    else R = mid - 1;
	}
	if(res == now) {
	    puts("-1"); return 0;
	}
	if(res < nxt[now]) {
	    ans += E[now].price * (n - P);
	    P = n; P -= E[now + 1].pos - E[now].pos; ++ now; continue;
	}
	else {
	    int must = E[nxt[now]].pos - E[now].pos;
	    int many = max(0ll, must - P);
	    ans += E[now].price *  many;
	    P += many; P -= must;
	    now = nxt[now];
	}
    }
    cout << ans << endl;
}