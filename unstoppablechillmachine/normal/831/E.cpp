#include <bits/stdc++.h>

using namespace std;

typedef long double ld;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<ll> vll;
typedef vector<ull> vull;
typedef vector<vll> vvll;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<pii> vpii;
typedef vector<pll> vpll;
typedef vector<ld> vld;
typedef vector<bool> vb;

#define _ inline
#define f first
#define sec second
#define pb push_back
#define ins insert
#define ers erase
#define mk make_pair
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define sz size
#define rsz resize
#define pw(x) (1 << (x))
#define sqr(x) ((x) * (x))
#define fro for
#define itn int
#define forn(i, n) for (register int i(1); i <= n; i++)
#define fore(i, n) for (register int i(0); i < n; i++)
#define chcpy(Vec) copy(Vec.begin(), Vec.end(), ostream_iterator<char>(cout))
#define intcpy(Vec) copy(Vec.begin(), Vec.end(), ostream_iterator<int>(cout, " "))
#define endl "\n"
#define right rightt
#define left leftt
#define prev prevv
#define next nextt

const int INF = 1e9 + 10;
const int MOD = 1e9 + 7;
const int MAXN = 1e6 + 10;
const int LOG = 20;
const long long BINF = 1e18 + 10;
const long long LINF = 1e18 + 10;
const long double EPS = 1e-10;
const long double PI = acos(-1);

_ void error()
{
    cout << -1;
    exit(0);
}

#define TASK ""

struct Node
{
    int val, cnt, mn;
    ll y;
    Node *l, *r;
};

Node *tr, *k;

void out(Node *t)
{
    if (!t)
    {
        return;
    }
    out(t->l);
    cout << t->val << " ";
    out(t->r);
}

int cnt(Node *t)
{
    if (!t)
    {
        return 0;
    }
    else
    {
        return t->cnt;
    }
}

int mn(Node *t)
{
    if (!t)
    {
        return INF;
    }
    else
    {
        return t->mn;
    }
}

void upd(Node *t)
{
    if (!t)
    {
        return;
    }
    t->cnt = 1 + cnt(t->l) + cnt(t->r);
    t->mn = min(t->val, min(mn(t->l), mn(t->r)));
}

pair<Node*, Node*> split(Node *t, int x, int cur = 0)
{
    if (!t)
    {
        return mk(nullptr, nullptr);
    }
    int now = cur + cnt(t->l) + 1;
    if (now > x)
    {
        pair<Node*, Node*> sp = split(t->l, x, cur);
        upd(sp.f);
        upd(sp.sec);
        t->l = sp.sec;
        upd(t);
        return mk(sp.f, t);
    }
    else
    {
        pair<Node*, Node*> sp = split(t->r, x, now);
        upd(sp.f);
        upd(sp.sec);
        t->r = sp.f;
        upd(t);
        return mk(t, sp.sec);
    }
}

Node* merge(Node *t1, Node *t2)
{
    if (!t1)
    {
        return t2;
    }
    if (!t2)
    {
        return t1;
    }
    if (t1->y > t2->y)
    {
        t1->r = merge(t1->r, t2);
        upd(t1);
        return t1;
    }
    else
    {
        t2->l = merge(t1, t2->l);
        upd(t2);
        return t2;
    }
}

Node* insert(Node *t, Node *k, int pos)
{
    if (!t)
    {
        return k;
    }
    pair<Node*, Node*> sp = split(t, pos);
    t = merge(merge(sp.f, k), sp.sec);
    upd(t);
    return t;
}

ll getrand()
{
    ll a = rand() * RAND_MAX + rand();
    return a;
}

int getmin(Node *tr, int cur = 0)
{
    if (!tr)
    {
        return INF;
    }
    int now = cur + 1 + cnt(tr->l);
    if (mn(tr->l) == tr->mn)
    {
        return getmin(tr->l, cur);
    }
    else if (tr->mn == tr->val)
    {
        return now;
    }
    else
    {
        return getmin(tr->r, now);
    }
}

int n, a;
ll ans;

_ void source()
{
    cin >> n;
    forn(i, n)
    {
        cin >> a;
        k = new Node();
        k->l = NULL;
        k->r = NULL;
        k->y = getrand();
        k->val = a;
        k->mn = a;
        k->cnt = 1;
        tr = insert(tr, k, i);
    }
    forn(i, n)
    {
        int a = getmin(tr);
        ans += a;
        pair<Node*, Node*> sp = split(tr, a - 1);
        pair<Node*, Node*> sp2 = split(sp.sec, 1);
        tr = merge(sp2.sec, sp.f);
        upd(tr);
    }
    cout << ans;
}

int main()
{
#ifdef EXTRATERRESTRIAL_
    freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
#else
    //freopen(TASK".in", "r", stdin
    //freopen(TASK".out", "w", stdout);
#endif
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    srand(0);
    source();
    return 0;
}