//84104971101048411497 - Can you guess what does this mean?
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef complex<double> point;
#define mapii map<int, int>
#define debug(a) cout << #a << ": " << a << endl
#define debuga1(a, l, r) fto(i, l, r) cout << a[i] << " "; cout << endl
#define fdto(i,  r, l) for(int i = (r); i >= (l); --i)
#define fto(i, l, r) for(int i = (l); i <= (r); ++i)
#define forit(it, var) for(__typeof(var.begin()) it = var.begin(); it != var.end(); it++)
#define forrit(rit, var) for(__typeof(var.rbegin()) rit = var.rbegin(); rit != var.rend(); rit++)
#define ii pair<int, int>
#define iii pair<int, ii>
#define ff first
#define ss second
#define mp make_pair
#define pb push_back
#define X real()
#define Y imag()
#define sz(a) (int)a.size()
#define maxN 100005
#define oo 1000000000000000007LL
#define EPS 1e-9

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

struct Node {
    Node *child[2];
    int cnt;
    Node() {
        fto(i, 0, 1) child[i] = NULL;
        cnt = 0;
    }
};

void add(Node *head, int i, ll x) {
    ++head->cnt;

    if (i == -1) return;

    int b = (x>>i)&1;
//    printf("%d %lld\n", i, x);
    if (head->child[b] == NULL)
        head->child[b] = new Node();
    add(head->child[b], i-1, x);
}

ll query(Node *head, int i, ll x) {
    if (i == -1) return 0;

    int b = (x>>i)&1;
    if (head->child[b^1] != NULL)
        return (1LL<<i) + query(head->child[b^1], i-1, x);
    return query(head->child[b], i-1, x);
}

Node *head = new Node();
int n;
ll a[maxN], pre[maxN], suf[maxN], ans;

int main () {
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        //freopen("output.txt", "w", stdout);
    #endif // ONLINE_JUDGE

    scanf("%d", &n);
    fto(i, 1, n) scanf("%lld", &a[i]);
    fto(i, 1, n) pre[i] = pre[i-1]^a[i];
    fdto(i, n, 1) suf[i] = suf[i+1]^a[i];

    //fto(i, 0, n+1) printf("%lld %lld\n", pre[i], suf[i]);
    add(head, 39, suf[n+1]);
    //return 0;
    fdto(i, n, 0) {
        ans = max(ans, query(head, 39, pre[i]));
        add(head, 39, suf[i]);
    }
    printf("%lld", ans);

    return 0;
}