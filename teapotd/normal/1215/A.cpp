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
    int a1, a2, k1, k2, n;
    cin >> a1 >> a2 >> k1 >> k2 >> n;

    if (k1 > k2) {
        swap(k1, k2);
        swap(a1, a2);
    }

    int small = 0;
    int great = 0;

    int tmp = n - (k1-1)*a1 - (k2-1)*a2;
    if (tmp > 0) {
        small += tmp;
    }

    if (n > k1*a1) {
        great = a1 + (n-k1*a1) / k2;
    } else {
        great = n / k1;
    }

    cout << small << ' ' << great << endl;
}