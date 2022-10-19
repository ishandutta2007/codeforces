#include <bits/stdc++.h>
using namespace std;

const int N = 1e6 + 5;

int n , fa[N] , S[N], x , y , m, a[N];

typedef pair <int,int> Pair;

long long ans;

Pair c[N];

vector <int> G[N];

void add(int x , int y) {
    G[x].push_back(y);
}

void link(int x , int y) {
    add(x , y); add(y , x);
}

void init(void) {
    for(int i = 1 ;i <= n ; ++ i) fa[i] = i , S[i] = 1;
}

int getf(int x) {
    return (fa[x] == x) ? x : fa[x] = getf(fa[x]);
}

bool cmp(Pair xxx , Pair yyy) {
    return xxx > yyy;
}

int main(void) {
    scanf("%d" , &n);
    for(int i = 1;i <= n;++ i) scanf("%d" , &a[i]);
    for(int i = 1;i < n;++ i) {
	scanf("%d%d" , &x, &y);
	link(x , y);
    }
    for(int i = 1;i <= n;++ i) c[i] = make_pair(a[i] , i);
    sort(c + 1 , c + n + 1); init();
    for(int i = 1;i <= n;++ i) {
	int cur = c[i].second , A = getf(cur) , B;
	for(auto V : G[cur]) {
	    B = getf(V);
	    if(A == B) continue;
	    if(a[A] >= a[B]) {
		ans += a[A] * 1ll * S[A] * S[B];
		S[A] += S[B]; fa[B] = A;
	    }
	}
    }
    sort(c + 1 , c + n + 1 , cmp); init();
    for(int i = 1;i <= n;++ i) {
	int cur = c[i].second , A = getf(cur) , B;
	for(auto V : G[cur]) {
	    B = getf(V);
	    if(A == B) continue;
	    if(a[A] <= a[B]) {
		ans -= a[A] * 1ll * S[A] * S[B];
		S[A] += S[B]; fa[B] = A;
	    }
	}
    }
    cout << ans;
}