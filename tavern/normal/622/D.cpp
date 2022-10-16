#include<bits/stdc++.h>

using namespace std;

#define FOR(i, x, y) for(int i = (x); i < (y); ++i)
#define REP(i, x, y) for(int i = (x); i <= (y); ++i)
#define MP make_pair
#define PB push_back
#define PH push
#define fst first
#define snd second
typedef long long ll;
typedef unsigned long long ull;
typedef double db;
typedef long double ldb;
typedef pair<int, int> pii;

const int INF = 1e9 + 7;
const int maxn = 1e6 + 5;

int n;
int a[maxn];

int main(){
	scanf("%d", &n);
	FOR(i, 1, n){
		if(i & 1)
			a[i / 2] = a[i / 2 + (n - i)] = i;
		else
			a[n + i / 2 - 1] = a[n + i / 2 - 1 + (n - i)] = i;
	}
	FOR(i, 0, n << 1) if(!a[i])
		a[i] = n;
	FOR(i, 0, n << 1)
		printf("%d ", a[i]);
	return 0;
}