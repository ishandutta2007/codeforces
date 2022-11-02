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

int n, m;
vector<string> M, M2;

int fillRow(char perm[2][2], bool make) {
    int ans = 0;

    rep(i, 0, n) {
        int norm = 0, rev = 0;

        rep(j, 0, m) {
            char a = perm[i%2][j%2];
            char b = perm[i%2][(j+1)%2];
            if (a != M[i][j]) norm++;
            if (b != M[i][j]) rev++;
        }

        ans += min(norm, rev);

        if (make) {
            bool xd = (rev < norm);
            rep(j, 0, m) {
                char a = perm[i%2][(j+xd)%2];
                M2[i][j] = a;
            }
        }
    }

    return ans;
}

int fillCol(char perm[2][2], bool make) {
    int ans = 0;

    rep(i, 0, m) {
        int norm = 0, rev = 0;

        rep(j, 0, n) {
            char a = perm[i%2][j%2];
            char b = perm[i%2][(j+1)%2];
            if (a != M[j][i]) norm++;
            if (b != M[j][i]) rev++;
        }

        ans += min(norm, rev);

        if (make) {
            bool xd = (rev < norm);
            rep(j, 0, n) {
                char a = perm[i%2][(j+xd)%2];
                M2[j][i] = a;
            }
        }
    }

    return ans;
}

char perms[6][2][2] = {
    { {'A','C'}, {'G','T'} },
    { {'A','G'}, {'C','T'} },
    { {'A','T'}, {'C','G'} },
    { {'G','T'}, {'A','C'} },
    { {'C','T'}, {'A','G'} },
    { {'C','G'}, {'A','T'} },
};

void run() {
    cin >> n >> m;
    M.resize(n);
    each(r, M) cin >> r;

    M2.resize(n, string(m, '.'));

    int best = INT_MAX;
    int bestPerm = 0;
    bool col = 0;

    rep(i, 0, 6) {
        int alt1 = fillRow(perms[i], 0), alt2 = fillCol(perms[i], 0);

        if (alt1 < alt2) {
            if (alt1 < best) {
                best = alt1;
                bestPerm = i;
                col = 0;
            }
        } else {
            if (alt2 < best) {
                best = alt2;
                bestPerm = i;
                col = 1;
            }
        }
    }

    if (col) {
        fillCol(perms[bestPerm], 1);
    } else {
        fillRow(perms[bestPerm], 1);
    }

    deb(best);
    each(r, M2) cout << r << '\n';
}