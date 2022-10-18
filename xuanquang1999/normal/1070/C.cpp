#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

#define debug(a) cout << #a << ": " << a << endl
#define debuga1(a, l, r) fto(i, l, r) cout << a[i] << " "; cout << endl
#define fdto(i, r, l) for(int i = (r); i >= (l); --i)
#define fto(i, l, r) for(int i = (l); i <= (r); ++i)
#define ff first
#define ss second
#define mp make_pair
#define pb push_back
#define sz(a) (int)a.size()
#define left apeifhae
#define right apoefbnuaebfh

const double PI = acos(-1.0);

double fRand(double fMin, double fMax)
{
    double f = (double)rand() / RAND_MAX;
    return fMin + f * (fMax - fMin);
}

template <class T>
T min(T a, T b, T c) {
    return min(a, min(b, c));
}

template <class T>
T max(T a, T b, T c) {
    return max(a, max(b, c));
}

struct node {
    int p, c, i;
    bool operator < (const node &rhs) const {
        return make_tuple(p, c, i) < make_tuple(rhs.p, rhs.c, rhs.i);
    }
};

template<class Node_CItr,
	 class Node_Itr,
	 class Cmp_Fn,
	 class _Alloc>
struct my_node_update
{
    typedef pll metadata_type;

    ll query(int k)
    {
        ll ans = 0;
        auto it=node_begin();
        while(it != node_end())
        {
            auto l=it.get_l_child();
            auto r=it.get_r_child();

            if (l != node_end()) {
                pll p = l.get_metadata();
                if(p.ff > k)
                {
                    it = l;
                    continue;
                } else {
                    k -= p.ff;
                    ans += p.ss;
                }
            }

            int c = (*it)->c, p = (*it)->p;
            ans += 1LL*p*min(k, c);
            if (k <= c)
                return ans;
            k -= c;

            it = r;
        }
        return ans;
    }

    void operator()(Node_Itr it, Node_CItr end_it)
    {
        auto l=it.get_l_child();
        auto r=it.get_r_child();

        pll left={0, 0}, right={0, 0};
        if(l!=end_it) left =l.get_metadata();
        if(r!=end_it) right=r.get_metadata();

        int c = (*it)->c, p = (*it)->p;
        pll t = {left.ff+right.ff + c, left.ss+right.ss + 1LL*c*p};
        const_cast<pll&>(it.get_metadata()) = t;
    }

    virtual Node_CItr
    node_begin() const = 0;

    virtual Node_CItr
    node_end() const = 0;
};

const int MAXN = 1000005;

tree<
node,
null_type,
less<node>,
rb_tree_tag,
my_node_update
> me;

int n, k, m;
vector<node> add[MAXN], sub[MAXN];



int main () {
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
//        fr*eopen("output.txt", "w", stdout);
    #endif // ONLINE_JUDGE

    scanf("%d%d%d", &n, &k, &m);
    fto(i, 1, m) {
        int l, r, c, p;
        scanf("%d%d%d%d", &l, &r, &c, &p);
        add[l].pb({p, c, i});
        sub[r+1].pb({p, c, i});
    }

    ll ans = 0;
    fto(i, 1, n) {
        for(node p: add[i])
            me.insert(p);
        for(node p: sub[i])
            me.erase(p);
        ans += me.query(k);
    }

    printf("%lld\n", ans);

    return 0;
}