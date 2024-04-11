//#pragma GCC optimize("Ofast,unroll-loops")
//#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,tune=native")
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
typedef long double dbl;
typedef pair<int, int> pii;

const int N = (int)1e6;
const int ADD = (int)2e5 + 5;

vector<char> vo = {'a', 'e', 'i', 'o', 'u'};
string s;
vector<int> a;
int t[N*4+6];
int n;

void build(int v, int l, int r){
    t[v] = N;
    if(l == r)ret;
    int mid = (l + r)/2;
    build(2*v, l, mid);
    build(2*v + 1, mid + 1, r);
}

int get(int v, int l, int r, int ul, int ur){
    if(ul > ur)ret N;
    if(l == ul && r == ur)
        ret t[v];
    int mid = (l + r)/2;
    ret min(get(2*v, l, mid, ul, min(ur, mid)), get(2*v + 1, mid + 1, r, max(ul, mid + 1), ur));
}

void upd(int v, int l, int r, int pos, int val){
    t[v] = min(t[v], val);
    if(l == r)ret;
    int mid = (l + r)/2;
    if(pos <= mid)
        upd(2*v, l, mid, pos, val);
    else
        upd(2*v + 1, mid + 1, r, pos, val);
}

int main(){
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> s;
    n = s.length();
    a.resize(n);
    build(1, 0, 3*ADD);
    upd(1, 0, 3*ADD, ADD, -1);
    int pref = 0;
    int len = 0, cnt = 0;
    F(i, 0, n){
        s[i] = tolower(s[i]);
        if(find(all(vo), s[i]) != vo.end())
            a[i] = -1;
        else
            a[i] = 2;
        pref += a[i];
        int kek = get(1, 0, 3*ADD, 0, ADD+pref);
        upd(1, 0, 3*ADD, pref + ADD, i);
        if(kek >= i)cont;
        int cu = i - kek;
        if(cu > len){
            len = cu;
            cnt = 0;
        }
        if(cu == len)++cnt;
    }
    if(!len){cout << "No solution"; ret 0;}
    cout << len << ' ' << cnt << endl;
    return 0;
}