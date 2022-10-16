#include<bits/stdc++.h>

using namespace std;

#define FOR(i, x, y) for(int i = (x); i < (y); ++i)
#define REP(i, x, y) for(int i = (x); i <= (y); ++i)
#define eprintf(...) fprintf(stderr, __VA_ARGS__)
#define PB push_back
#define MP make_pair
#define PH push
#define fst first
#define snd second
typedef long long ll;
typedef unsigned long long ull;
typedef double lf;
typedef long double Lf;
typedef pair<int, int> pii;

const int logn = 30;

int q = 0;

int main(){
	scanf("%d", &q);
	FOR(i, 0, q){
		int u, v;
		scanf("%d%d", &u, &v);
		int su = 0, sv = 0, ans = 1;
		ans &= (u <= v);
		FOR(i, 0, logn){
			su += (u >> i & 1);
			sv += (v >> i & 1);
			ans &= (su >= sv); 
		}
		puts(ans ? "YES" : "NO");
	}
	return 0;
}