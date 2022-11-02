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
    int t; cin >> t;

    while (t--) {
        int n; cin >> n;
        int a, b, c; cin >> a >> b >> c;
        string s; cin >> s;
        string moves;

        int won = 0;

        each(chr, s) {
            if (chr == 'R') {
                if (b > 0) {
                    b--;
                    won++;
                    moves.pb('P');
                } else {
                    moves.pb('.');
                }
            } else if (chr == 'P') {
                if (c > 0) {
                    c--;
                    won++;
                    moves.pb('S');
                } else {
                    moves.pb('.');
                }
            } else if (chr == 'S') {
                if (a > 0) {
                    a--;
                    won++;
                    moves.pb('R');
                } else {
                    moves.pb('.');
                }
            } else {
                assert(0);
            }
        }

        each(chr, moves) {
            if (chr == '.') {
                if (a > 0) {
                    chr = 'R';
                    a--;
                } else if (b > 0) {
                    chr = 'P';
                    b--;
                } else if (c > 0) {
                    chr = 'S';
                    c--;
                } else {
                    assert(0);
                }
            }
        }

        bool ans = (won >= (n+1)/2);

        if (ans) {
            cout << "YES\n";
            cout << moves << '\n';
        } else {
            cout << "NO\n";
        }
    }
}