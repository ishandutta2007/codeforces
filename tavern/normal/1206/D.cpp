// orz dxm
#include<bits/stdc++.h>

using namespace std;

#define PH push
#define MP make_pair
#define PB push_back
#define fst first
#define snd second
#define FOR(i, x, y) for(int i = (x); i < (y); ++i)
#define REP(i, x, y) for(int i = (x); i <= (y); ++i)
#define y0 yORZDXM
#define y1 yORZDXM
#define y2 yORZDXM
typedef double db;
typedef long long ll;
typedef long double ldb;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

const int INF = 1e9 + 7;
const int maxn = 2e5 + 5;

int n, m;
int cnt[64];
int dis[130][130], ed[130][130];
ll a[maxn], b[maxn];

int main(){
	scanf("%d", &n);
	FOR(i, 0, n){
		scanf("%lld", a + i);
		FOR(j, 0, 63) if(a[i] >> j & 1) ++cnt[j];
	}
	FOR(j, 0, 63) if(cnt[j] >= 3){
		puts("3");
		return 0;
	}
	FOR(i, 0, n) if(a[i]) b[m++] = a[i];
	memset(dis, 0x3f, sizeof(dis));
	FOR(i, 0, m) dis[i][i] = 0;
	FOR(i, 0, m) FOR(j, 0, m) if(b[i] & b[j]) ed[i][j] = ed[j][i] = dis[i][j] = dis[j][i] = 1;
	int ans = INF;
	FOR(k, 0, m){
        FOR(i, 0, k){
            FOR(j, i + 1, k){
                if(ed[i][k] && ed[k][j]) ans = min(ans, dis[i][j] + 2);
        	}
		}
        FOR(i, 0, m) if(dis[i][k] < 0x3f3f3f3f){
            FOR(j, 0, m) if(dis[k][j] < 0x3f3f3f3f){
            	dis[i][j] = min(dis[i][j], dis[i][k] + dis[k][j]);
            }
        }
        //FOR(i, 0, m){FOR(j, 0, m) printf("%d ", dis[i][j]); puts("");}
    }
    printf("%d\n", ans == INF ? -1 : ans);
	return 0;
}