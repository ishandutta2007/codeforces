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
    string s, t; cin >> s >> t;

    Vi cmp(n+1);
    for (int i = n-1; i >= 0; i--) {
        int a = 'z'-s[i], b = t[i]-'a';
        if (a == b) cmp[i] = cmp[i+1];
        else cmp[i] = (a < b ? -1 : 1);
    }

    int flip = 0;

    rep(i, 0, n) {
        int a = s[i]-'a', b = t[i]-'a';
        int sum = a+b;

        if (sum % 2) {
            assert(cmp[i+1] != 0);
            if (cmp[i+1] < 0) sum++;
        }

        int avg = (sum/2 + flip*13) % 26;
        flip = (a+b)%2;
        cout << char(avg+'a');
    }

    cout << '\n';
}