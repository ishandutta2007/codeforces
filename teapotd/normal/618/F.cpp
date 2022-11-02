#define _USE_MATH_DEFINES////////////////////////////////////////
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

void run() {
    int n; cin >> n;
    vector<ll> A(n), B(n);
    each(k, A) cin >> k;
    each(k, B) cin >> k;

    A.insert(A.begin(), 0);
    B.insert(B.begin(), 0);
    rep(i, 1, n+1) A[i] += A[i-1];
    rep(i, 1, n+1) B[i] += B[i-1];

    bool flip = A.back() > B.back();
    if (flip) A.swap(B);

    vector<Pii> seen(n, {-1, -1});
    int j = 1;

    rep(i, 0, n+1) {
        while (j < n && B[j] <= A[i]) j++;
        int d = int(A[i]-B[j-1]);

        if (seen[d].x != -1) {
            int from1 = i, to1 = seen[d].x;
            int from2 = j-1, to2 = seen[d].y;

            if (from1 > to1) swap(from1, to1);
            if (from2 > to2) swap(from2, to2);

            if (flip) {
                A.swap(B);
                swap(from1, from2);
                swap(to1, to2);
            }

            cout << to1-from1 << '\n';
            rep(k, from1, to1) cout << k+1 << ' ';
            cout << '\n' << to2-from2 << '\n';
            rep(k, from2, to2) cout << k+1 << ' ';
            cout << '\n';
            return;
        }

        seen[d] = {i, j-1};
    }

    assert(0);
}