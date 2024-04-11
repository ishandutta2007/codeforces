#include <bits/stdc++.h>
using namespace std;
#define pb push_back
typedef long long ll;
typedef vector<int> vi;
typedef pair<ll,ll> pll;

const int maxn = 2006;

struct node {
    ll x, y;
    node () {}
    node (ll x, ll y): x(x),y(y) {}
    node operator-(const node &b) {
        return {x-b.x,y-b.y};
    }
    node operator+(const node &b) {
        return {x+b.x,y+b.y};
    }
    ll xmul(node b) {
        return x*b.y-y*b.x;
    }
};

bool judge(node a, node b, node c) {
    return (b-a).xmul(c-a) > 0;
}

node a[maxn];
bool v[maxn];
char s[maxn];
vi p;
int n;

int main() {
    scanf( "%d", &n);
    for (int i = 1; i <= n; ++i) scanf( "%lld%lld", &a[i].x, &a[i].y );
    scanf( "%s", s+1);
    int o = 1;
    for (int i = 2; i <= n; ++i) if (a[i].x < a[o].x) o = i;
    p.clear();
    p.pb(o);
    v[o] = true;
    for (int i = 2; i <= n; ++i) {
        bool t = false;
        if (i == n || s[i-1] == 'R') t = true;
        int k = -1;
        for (int j = 1; j <= n; ++j)
            if (!v[j]) {
                if (k == -1) k = j;
                else if (judge(a[o],a[j],a[k])^t) k = j;
            }
        o = k;
        p.pb(k);
        v[o] = true;
    }
    for (auto i : p) printf("%d ", i);
    puts( "" );
}