#include <bits/stdc++.h>
using namespace std;

#define file "file"
#define mp make_pair
#define pb push_back
#define xx real()
#define yy imag()
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef complex<double> point;

#define DEBUG 0
#define dout if(DEBUG) cout

const int MAXN = 1e6 + 6;

int a[MAXN], x[MAXN], t[MAXN];
pair<pii, int> p[MAXN];
map<int, int> beg;
ll tt[4 * MAXN];
int id[MAXN];

void update(int v, int tl, int tr, int pos, int val){
    if(tl == tr){
        tt[v] += val;
        return;
    }
    int tm = (tl + tr) >> 1;
    if(pos <= tm){
        update(2 * v + 1, tl, tm, pos, val);
    }
    else{
        update(2 * v + 2, tm + 1, tr, pos, val);
    }
    tt[v] = tt[2 * v + 1] + tt[2 * v + 2];
}

ll get_sum(int v, int tl, int tr, int l, int r){
    if(l > r) return 0;
    if(tl == l && tr == r){
        return tt[v];
    }
    int tm = (tl + tr) >> 1;
    return get_sum(2 * v + 1, tl, tm, l, min(r, tm)) +
        get_sum(2 * v + 2, tm + 1, tr, max(l, tm + 1), r);
}

void solve(){
    int n;
    cin >> n;
    for(int i = 0; i < n; i++){
        scanf("%d%d%d", &a[i], &t[i], &x[i]);
        p[i] = mp(mp(x[i], t[i]), i);
    }
    sort(p, p + n);
    for(int i = n - 1; i >= 0; i--){
        id[p[i].second] = i;
        beg[p[i].first.first] = i;
    }
    int cnt = 1;
    while(cnt <= n) cnt <<= 1;
    for(int i = 0; i < n; i++){
        int pos = id[i];
        if(a[i] == 1){
            update(0, cnt - 1, 2 * cnt - 2, cnt - 1 + pos, 1);
        }
        else if(a[i] == 2){
            update(0, cnt - 1, 2 * cnt - 2, cnt - 1 + pos, -1);
        }
        else{
            int ans = get_sum(0, cnt - 1, 2 * cnt - 2, cnt - 1 + beg[x[i]], cnt - 1 + pos);
            printf("%d\n", ans);
        }
    }
}

int main()
{
	#ifdef NASTYA
    assert(freopen("input.txt","r",stdin));
    assert(freopen("output.txt","w",stdout));
    #else
    //assert(freopen(file".in","r",stdin)); assert(freopen(file".out","w",stdout));
    #endif
	int t = 1;
	while(t--){
		solve();
	}
	return 0;
}