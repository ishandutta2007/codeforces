//#pragma GCC optimize("Ofast,unroll-loops")
//#pragma GCC target("tune=native")
#include<bits/stdc++.h>

using namespace std;

#define all(x) (x).begin(),(x).end()
#define I(x, a) for(auto x : (a))
#define ins insert
#define F(i, l, r) for(auto i = (l); i < (r); i++)
#define DF(i, l, r) for(auto i = (l); i >= (r); i--)
#define E(i, l, r) for(auto i = (l); i <= (r); i++)
#define pb push_back
#define X first
#define Y second
#define mp make_pair
#define ret return
#define brk break
#define cont continue
#define move fjgjgjgjghd

typedef long long ll;
typedef unsigned long long ull;
typedef double dbl;
typedef pair<int, int> pii;

const int N = (int)1e5;

int n;
int a[N];
int where[N];
int who[N];
vector<pii> seq;

void mvto(int init, int pos){
    int i = where[init];
    int ws = who[pos];
    swap(where[ws], where[init]);
    swap(who[i], who[pos]);
    if(i != pos)
        seq.pb(mp(i + 1, pos + 1));
}

signed main(){
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
#endif
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    scanf("%d", &n);
    F(i, 0, n)
        scanf("%d", a + i);
    set<pii, greater<pii> > nums;
    int best = (int)1e9 + 228;
    int bpos = 0;
    F(i, 0, n){
        where[i] = who[i] = i;
        nums.insert({a[i], i});
        int x = a[i];
        bool ok = 1;
        while(x){
            if(x%10 != 4 && x%10 != 7){ok = 0; brk;}
            x /= 10;
        }
        if(ok && a[i] < best){
            bpos = i;
            best = a[i];
        }
    }
    if(best > (int)1e9){
        printf("%d", is_sorted(a, a + n) ? 0 : -1);
        ret 0;
    }
    int pos_of_fail = -1;
    DF(i, n - 1, 0){
        if(nums.empty())brk;
        pii cu = *nums.begin();
        nums.erase(nums.begin());
        if(cu == mp(best, bpos)){
            if(nums.empty())
                brk;
            pii to = *--nums.end();
            nums.erase(--nums.end());
            pos_of_fail = i;
            mvto(cu.Y, i);
            mvto(to.Y, i);
            cont;
        }
        if(where[cu.Y] != i){
            mvto(bpos, i);
            mvto(cu.Y, i);
        }
    }
    if(pos_of_fail > 0)
        seq.pb(mp(1, pos_of_fail + 1));
    printf("%d\n", (int)seq.size());
    I(s, seq)
        printf("%d %d\n", s.X, s.Y);
    return 0;
}