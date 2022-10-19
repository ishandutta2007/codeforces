#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 5;
const int K = 1e5 + 5;

int L[N * 4] , R[N * 4] , S[N * 4] , lz[N * 4] , n , m , x , y , s[N] , k;

#define lc no << 1
#define rc no << 1 | 1
#define getmid int mid = (L[no] + R[no]) >> 1

void build(int no , int l , int r) {
    L[no] = l; R[no] = r; getmid;
    if(l == r) return;
    build(lc , l , mid); build(rc , mid + 1 , r);
}

void up(int no) {
    S[no] = S[lc] + S[rc];
}

void dn(int no) {
    if(!lz[no]) return;
    if(L[no] == R[no]) return;
    lz[no] = 0; S[lc] = R[lc] - L[lc] + 1 - S[lc]; S[rc] = R[rc] - L[rc] + 1 - S[rc]; lz[lc] ^= 1; lz[rc] ^= 1;
    up(no);
    return;
}

void push(int no, int l , int r) {
    dn(no);
    if(L[no] == l && R[no] == r) {
	S[no] = r - l + 1 - S[no];
	lz[no] ^= 1;
	return;
    }
    getmid;
    if(l > mid) push(rc , l , r);
    else if(r <= mid) push(lc , l , r);
    else push(lc , l , mid) , push(rc , mid + 1 , r);
    up(no);
}

vector <pair<int,int> > all[N];

int query(int no , int x) {
    dn(no);
    if(L[no] == R[no]) return S[no];
    getmid;
    if(x > mid) return query(rc , x);
    else return query(lc , x);
}

int main(void) {
    cin >> n >> k;
    for(int i = 1;i <= n;++ i) scanf("%d" , &s[i]);
    sort(s + 1 , s + n + 1); s[n + 1] = 2e9;
    build(1 , 1 , n);
    for(int i = 1;i <= k;++ i) {
	scanf("%d%d" , &x , &y);
	x = lower_bound(s + 1 , s + n + 1 , x) - s;
	y = upper_bound(s + 1 , s + n + 1 , y) - s - 1;
	if(x >= y) continue;
	all[x].push_back(make_pair(x , y));
	all[y + 1].push_back(make_pair(x , y));
    }
    long long ans = 0;
    for(int i = 1;i <= n;++ i) {
	if(i != 1) push(1 , i - 1 , i - 1);
	for(auto V : all[i]) push(1 , V.first , V.second);
	int now = S[1] - query(1 , i);
	ans = ans + now * 1ll * (now - 1) / 2;
    }
    ans = n * 1ll * (n - 1) * 1ll * (n - 2) / 6 - ans;
    cout << ans;
}