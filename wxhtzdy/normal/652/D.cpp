#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/rope>

#define ff(i,a,b) for(int (i) = (a); (i) <= (b); ++(i))
#define fb(i,a,b) for(int (i) = (a); (i) >= (b); --(i))
#define xx first
#define yy second
#define all(a) (a).begin(), (a).end()
#define pb push_back
#define ll long long
#define pii pair<int, int>



using namespace std;
using namespace __gnu_pbds;
typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

int n;
pii niz[200005];
int rez[200005];
int fenw[400005];

bool cmp(int x, int y){
    return niz[x].xx < niz[y].xx;
}

void add(int x, int y){
    for(; x < 400005; x += x & (-x)) fenw[x] += y;
}

int get(int x){
    int res = 0;
    for(; x > 0; x -= x & (-x)) res += fenw[x];
    return res;
}

int main()
{

    ios::sync_with_stdio(false); cin.tie(0);
    cin >> n;
    vector<int> svi;
    ff(i,0,n-1){
        cin >> niz[i].xx >> niz[i].yy;
        svi.pb(niz[i].xx);
        svi.pb(niz[i].yy);
    }
    sort(all(svi));
    ff(i,0,n-1){
        niz[i].xx = lower_bound(all(svi), niz[i].xx) - svi.begin() + 1;
        niz[i].yy = lower_bound(all(svi), niz[i].yy) - svi.begin() + 1;
    }
    vector<int> id(n);
    iota(all(id), 0);
    sort(all(id), cmp);
    for(int i : id)add(niz[i].yy, 1);
    for(int i : id){
        rez[i] = get(niz[i].yy);
        add(niz[i].yy, -1);
    }
    ff(i,0,n-1){
        cout << rez[i] - 1 << "\n";
    }
    return 0;
}