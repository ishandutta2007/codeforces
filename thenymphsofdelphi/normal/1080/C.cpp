#include<bits/stdc++.h>
using namespace std;

#define int long long
#define double long double
#define fi first
#define se second
#define pb push_back
#define pob pop_back
#define mp make_pair
#define endl '\n'
#define For(i, a, b) for (int i = a; i < b; i++)
#define ForE(i, a, b) for (int i = a; i <= b; i++)
#define Ford(i, a, b) for (int i = a; i > b; i--)
#define FordE(i, a, b) for (int i = a; i >= b; i--)

#define PrintV(x) for (int i = 0; i < x.size(); i++) cout << x[i] << ' ';
#define PrintVl(x) for (int i = 0; i < x.size(); i++) cout << x[i] << endl;
#define Ptest(a) return cout << a << endl, 0;
#define isvowel(a) (a == 'a' || a == 'e' || a == 'i' || a == 'o' || a == 'u' || a == 'y')

#define pque priority_queue
#define mts multiset
//typedef queue <int> qi;
typedef vector <int> vi;
typedef pair <int, int> ii;
typedef vector <vi > vvi;
typedef vector <ii > vii;

const int N = 1e5 + 5, mod = 1e9 + 7, inf = 1e18 + 7;

int n, m;

struct node{
    int d, l, u, r;
} nd[5], defa;

void output(node x){
    cout << x.d << ' ' << x.l << ' ' << x.u << ' ' << x.r << endl;
    return;
}

node ovl(node x, node y){
    if ((x.u >= y.d && x.d <= y.u) && (x.r >= y.l && x.l <= y.r)){
        node ans;
        ans.d = max(x.d, y.d); ans.l = max(x.l, y.l); ans.u = min(x.u, y.u); ans.r = min(x.r, y.r);
        return ans;
    }
    return defa;
}

int findw(int x, int y){
    return (((x & 1ll) && (y & 1ll)) ? (x * y / 2 + 1) : (x * y / 2));
}

int findw4(int d, int l, int u, int r){
    if (d < 0 || l < 0 || u < 0 || r < 0){
        return 0;
    }
    int h = u - d + 1, w = r - l + 1;
    //cout << h << ' ' << w << endl;
    if (!((h & 1ll) && (w & 1ll))) return (h * w / 2);
    if ((d + l) & 1) return (h * w / 2);
    return ((h * w / 2) + 1);
}

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    defa.d = -1; defa.l = -1; defa.u = -1; defa.r = -1;
    //cout << findw4(1, 1, 1, 2) << endl;
    int t;
    cin >> t;
    while (t--){
        cin >> m >> n;
        int answ = findw(n, m), ansb = n * m - answ;
        int tansw = answ, tansb = ansb;
        cin >> nd[1].d >> nd[1].l >> nd[1].u >> nd[1].r;
        cin >> nd[2].d >> nd[2].l >> nd[2].u >> nd[2].r;
        //output(nd[2]);
        nd[3] = ovl(nd[1], nd[2]);
        //cout << answ << endl;
        //output(nd[3]);
        int btow = (nd[1].u - nd[1].d + 1) * (nd[1].r - nd[1].l + 1) - findw4(nd[1].d, nd[1].l, nd[1].u, nd[1].r);
        //cout << "BTOW1 " << btow << endl;
        if (nd[3].d >= 0){
            btow -= (nd[3].u - nd[3].d + 1) * (nd[3].r - nd[3].l + 1) - findw4(nd[3].d, nd[3].l, nd[3].u, nd[3].r);
        }
        //cout << "BTOW2 " << btow << endl;
        //output(nd[2]);
        int wtob = findw4(nd[2].d, nd[2].l, nd[2].u, nd[2].r);
        //cout << "WTOB " << wtob << endl;
        cout << answ - wtob + btow << ' ' << ansb - btow + wtob << endl;
        //cout << endl;
    }
}

/*
----------------------------------+
INPUT:                            |
==============================    |
5
2 2
1 1 2 2
1 1 2 2
3 4
2 2 3 2
3 1 4 3
1 5
1 1 5 1
3 1 5 1
4 4
1 1 4 2
1 3 4 4
3 4
1 2 4 2
2 1 3 3

==============================    |
----------------------------------+
OUTPUT:                           |
==============================    |
0 4
3 9
2 3
8 8
4 8

==============================    |
----------------------------------+
*/