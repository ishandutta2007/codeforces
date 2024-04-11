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
#define sz(a) ((int)a.size())

typedef long long ll;
typedef unsigned long long ull;
typedef long double dbl;
typedef pair<int, int> pii;

struct Heap{
    int sz;
    int pos;
    vector<pii> segs;
};

struct result{
    int gr;
    vector<Heap> dist;
};

pii get_move(Heap heap, int x){
    for(auto s: heap.segs){
        int len = s.Y - s.X;
        if(len >= x){
            return make_pair(0, s.X + x);
        }
        else
            x -= len;
    }
    assert(0);
}

result solve(vector<tuple<int, int, int> > s, int n, int m){
    sort(all(s));
    vector<Heap> ans;
    size_t i = 0;
    int diff = 0;
    set<int> poss;
    int xr = 0;
    while(i < s.size()){
        size_t j = i;
        vector<pii> ss;
        while(j < s.size() && get<0>(s[j]) == get<0>(s[i])){
            ss.push_back(make_pair(get<1>(s[j]), -1));
            ss.push_back(make_pair(get<2>(s[j]), 1));
            ++j;
        }
        ss.push_back(make_pair(m, -1));
        sort(all(ss));
        vector<pii> segs;
        int tot = 0;
        int bal = 0;
        int old = 0;
        for(auto evt: ss){
            int x, d;
            tie(x, d) = evt;
            if(bal == 0 && x > old){
                tot += x - old;
                segs.emplace_back(old, x);
            }
            bal += d;
            if(!bal)
                old = x;
        }
        diff++;
        poss.insert(get<0>(s[i]));
        xr ^= tot;
        ans.push_back(Heap{tot, get<0>(s[i]), segs});
        i = j;
    }
    if(diff < n - 1){
        int i = 1;
        while(i < n && poss.count(i))
            ++i;
        ans.pb(Heap{
                m, i, {make_pair(0, m)}
                });
        if((n - 1 - diff)&1)xr ^= m;
    }
    return result{
        xr,
        ans
    };
}

signed main(){
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n, m, k;
    cin >> n >> m >> k;
    vector<tuple<int, int, int> > v, h;
    for(int i = 0; i < k; i++){
        int x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;
        if(x1 == x2){
            v.emplace_back(x1, min(y1, y2), max(y1, y2));
        }
        else{
            h.emplace_back(y1, min(x1, x2), max(x1, x2));
        }
    }
    auto rv = solve(v, n, m);
    auto rh = solve(h, m, n);
    if(rv.gr^rh.gr){
        cout << "FIRST\n";
        int val = rv.gr^rh.gr;
        for(auto heap: rv.dist){
            int curr = val^heap.sz;
            if(curr < heap.sz){
                auto sol = get_move(heap, heap.sz - curr);
                cout << heap.pos << ' ' << sol.X << ' ' << heap.pos << ' ' << sol.Y << endl;
                return 0;
            }
        }
        for(auto heap: rh.dist){
            int curr = val^heap.sz;
            if(curr < heap.sz){
                auto sol = get_move(heap, heap.sz - curr);
                cout << sol.X << ' ' << heap.pos << ' ' << sol.Y << ' ' << heap.pos << endl;
                return 0;
            }
        }
        assert(0);
    }
    else
        cout << "SECOND\n";
    return 0;
}