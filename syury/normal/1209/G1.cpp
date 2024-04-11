#include<bits/stdc++.h>
#include<bits/extc++.h>

using namespace std;

#define F(i, l, r) for(auto i = (l); i < (r); i++)
#define E(i, l, r) for(auto i = (l); i <= (r); i++)
#define DF(i, l, r) for(auto i = (l); i >= (r); i--)
#define I(x, a) for(auto x : (a))
#define mp make_pair
#define X first
#define Y second
#define clean(x) memset((x), 0, sizeof(x))
#define ret return
#define cont continue
#define brk break
#define ins insert
#define all(x) (x).begin(),(x).end()
#define sync ios_base::sync_with_stdio(false);cin.tie(0)
#define pb push_back
#define y1 fjfg
#define tm shjfhg

typedef long long ll;
typedef unsigned long long ull;
typedef long double dbl;
typedef pair<int, int> pii;

const int N = (int)3e5 + 5;

int L[N], R[N];
int a[N];
int p[N];
int add[N];
int current_alive = 1;
int cmx = 0;
int cnt[N];
int gt[N];
int n;

void aa(int pos){
    if(gt[pos] != current_alive){
        gt[pos] = current_alive;
        cnt[pos] = 0;
    }
    ++cnt[pos];
    cmx = max(cmx, cnt[pos]);
}

signed main(){
#ifdef LOCAL
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
#endif
	sync;
    cin >> n;
    int lol;
    cin >> lol;
    F(i, 0, n)
        cin >> a[i];
    fill(L, L + N, -1);
    fill(R, R + N, -1);
    iota(p, p + N, 0);
    F(i, 0, n){
        if(L[a[i]] == -1)L[a[i]] = i;
        R[a[i]] = i;
    }
    F(i, 0, N){
        if(L[i] == -1)cont;
        add[L[i]]++;
        add[R[i]]--;
    }
    int ans = 0;
    int bal = 0;
    int last_end = -1;
    F(i, 0, n){
        aa(a[i]);
        p[i] = current_alive;
        bal += add[i];
        if(bal == 0){
            ans += i - last_end - cmx;
            cmx = 0;
            ++current_alive;
            last_end = i;
        }
    }
    cout << ans;
	return 0;
}