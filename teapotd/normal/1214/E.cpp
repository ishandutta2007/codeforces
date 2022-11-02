#define _USE_MATH_DEFINES
#include<bits/stdc++.h>//////////////////////////////////////////
#define deb(...)/////////////////////////////////////////////////
#define DBP(...)/////////////////////////////////////////////////
#ifdef LOC///////////////////////////////////////////////////////
#include"debuglib.h"/////////////////////////////////////////////
#endif///////////////////////////////////////////////////////////
#define x first//////////////////////////////////////////////////
#define y second/////////////////////////////////////////////////
#define pb push_back/////////////////////////////////////////////
#define sz(x)int((x).size())/////////////////////////////////////
#define each(a,x)for(auto&a:(x))/////////////////////////////////
#define all(x)(x).begin(),(x).end()//////////////////////////////
#define rep(i,b,e)for(int i=(b);i<(e);i++)///////////////////////
using namespace std;using ll=long long;using Pii=pair<int,int>;//
using Vi=vector<int>;void run();int main(){cin.sync_with_stdio///
(0);cin.tie(0);cout<<fixed<<setprecision(18);run();return 0;}////
//-------------------------------------------------------------//

int uplg(int n) { return 32-__builtin_clz(n); }
int uplg(ll n)  { return 64-__builtin_clzll(n); }

Vi par;

void edge(int p, int c) {
    cout << p+1 << ' ' << c+1 << '\n';
    par[c] = p;
}

void run() {
    int n; cin >> n;

    vector<Pii> d(n);
    rep(i, 0, n) {
        cin >> d[i].x;
        d[i].y = i;
    }

    sort(all(d), [&](Pii l, Pii r) { return l > r; });
    par.resize(n*2);

    rep(i, 1, n) {
        edge(d[i-1].y*2, d[i].y*2);
    }

    int tail = d.back().y*2;
    int dist = 0;

    rep(i, 0, n) {
        int p = i+d[i].x-1;

        if (p < n-1) {
            edge(d[p].y*2, d[i].y*2+1);
        } else {
            int k = p - (n-1);

            while (dist > k) {
                tail = par[tail];
                dist--;
            }

            edge(tail, d[i].y*2+1);
            tail = d[i].y*2+1;
            dist++;
        }
    }
}