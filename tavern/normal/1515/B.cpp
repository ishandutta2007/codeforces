#include<bits/stdc++.h>

using namespace std;

#define FOR(i, x, y) for(int i = (int)(x); i < (int)(y); ++i)
#define REP(i, x, y) for(int i = (int)(x); i <= (int)(y); ++i)
#define MP make_pair
#define PB push_back
#define PH push
#define fst first
#define snd second
#define y0 y2226700
#define y1 y2226701
#define y2 y2226702
typedef double lf;
typedef long double Lf;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;

inline int check(int x){
	int y = sqrt(x);
	return 1ll * y * y == x;
}

int main(){
	int T;
	for(scanf("%d", &T); T--; ){
		int n;
		scanf("%d", &n);
		if(n % 2 == 0 && check(n / 2) || n % 4 == 0 && check(n / 4))
			puts("YES");
		else
			puts("NO");
	}
	return 0;
}