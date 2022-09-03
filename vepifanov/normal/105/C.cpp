#include <cstdio>
#include <numeric>
#include <iostream>
#include <vector>
#include <set>
#include <cstring>
#include <string>
#include <map>
#include <cmath>
#include <ctime>
#include <algorithm>
#include <bitset>
#include <queue>
#include <sstream>
#include <deque>

using namespace std;

#define mp make_pair
#define pb push_back
#define rep(i,n) for(int i = 0; i < (n); i++)
#define re return
#define fi first
#define se second
#define sz(x) ((int) (x).size())
#define all(x) (x).begin(), (x).end()
#define sqr(x) ((x) * (x))
#define sqrt(x) sqrt(abs(x))
#define y0 y3487465
#define y1 y8687969
#define fill(x,y) memset(x,y,sizeof(x))
                         
typedef vector<int> vi;
typedef long long ll;
typedef long double ld;
typedef double D;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<string> vs;
typedef vector<vi> vvi;

template<class T> T abs(T x) { re x > 0 ? x : -x; }

int n;
int m;

int s[3][1001], par[1001], cur[1001], was[1001];
string item[100], name[1000], type[100], clss[1000];
int atk[100], def[100], res[100], num[100], cnt[100];
vii v[3];

int main () {
    cin >> n;
    for (int i = 0; i < n; i++) cin >> item[i] >> type[i] >> atk[i] >> def[i] >> res[i] >> num[i];
    cin >> m;
    for (int i = 0; i < m; i++) {
        string tmp;
        cin >> name[i] >> clss[i] >> par[i] >> tmp;
        int nc;
        if (clss[i] == "gladiator") nc = 0;
        if (clss[i] == "sentry") nc = 1;
        if (clss[i] == "physician") nc = 2;
        v[nc].pb (mp (par[i], i));
        for (int j = 0; j < n; j++)
            if (tmp == item[j]) {
                cnt[j]++;
                cur[i] = j;
            }
    }
    int free = 0;
    for (int i = 0; i < n; i++)
        if (cnt[i] < num[i])
            free = 1;
    if (free) {
        for (int i = 0; i < 3; i++) {
            sort (all (v[i]));
            reverse (all (v[i]));
        }
        s[0][0] = s[1][0] = s[2][0];
        for (int j = 0; j < 3; j++)
            for (int i = 0; i < sz (v[j]); i++) 
                s[j][i + 1] = s[j][i] + v[j][i].fi;
        int a1 = -1, a2 = -1, a3 = -1, b1 = 0, b2 = 0, b3 = 0;
        for (int i = 0; i < n; i++)
            if (type[i] == "weapon")
                for (int j = 0; j < n; j++)
                    if (type[j] == "armor")
                        for (int k = 0; k < n; k++)
                            if (type[k] == "orb") {
                                int c1 = atk[i] + s[0][min (sz (v[0]), num[i])];
                                int c2 = def[j] + s[1][min (sz (v[1]), num[j])];
                                int c3 = res[k] + s[2][min (sz (v[2]), num[k])];
                                if (c1 > a1 || c1 == a1 && c2 > a2 || c1 == a1 && c2 == a2 && c3 > a3) {
                                    a1 = c1;
                                    a2 = c2;
                                    a3 = c3;
                                    b1 = i;
                                    b2 = j;
                                    b3 = k;
                                }
                            }
        int rem = m;
        for (int i = 0; i < min (num[b1], sz (v[0])); i++, rem--) was[v[0][i].se] = 1;
        for (int i = 0; i < min (num[b2], sz (v[1])); i++, rem--) was[v[1][i].se] = 1;
        for (int i = 0; i < min (num[b3], sz (v[2])); i++, rem--) was[v[2][i].se] = 1;
        int tmp = min (num[b1], sz (v[0]));
        cout << item[b1] << " " << tmp + min (num[b1] - tmp, rem);
        for (int i = 0; i < num[b1] && i < sz (v[0]); i++)
            cout << " " << name[v[0][i].se];
        for (int i = 0; i < m && tmp < num[b1]; i++)
            if (was[i] == 0) {
                was[i] = 1;
                tmp++;
                rem--;
                cout << " " << name[i];
            }   
        cout << endl;   
        tmp = min (num[b2], sz (v[1]));
        cout << item[b2] << " " << tmp + min (num[b2] - tmp, rem);
        for (int i = 0; i < num[b2] && i < sz (v[1]); i++)
            cout << " " << name[v[1][i].se];
        for (int i = 0; i < m && tmp < num[b2]; i++)
            if (was[i] == 0) {
                was[i] = 1;
                tmp++;
                rem--;
                cout << " " << name[i];
            }   
        cout << endl;  
        tmp = min (num[b3], sz (v[2]));
        cout << item[b3] << " " << tmp + min (num[b3] - tmp, rem);
        for (int i = 0; i < num[b3] && i < sz (v[2]); i++)
            cout << " " << name[v[2][i].se];
        for (int i = 0; i < m && tmp < num[b3]; i++)
            if (was[i] == 0) {
                was[i] = 1;
                tmp++;
                rem--;
                cout << " " << name[i];
            }   
        cout << endl;   
    } else {
        for (int i = 0; i < sz (v[0]); i++)
            atk[cur[v[0][i].se]] += v[0][i].fi;
        for (int i = 0; i < sz (v[1]); i++)
            def[cur[v[1][i].se]] += v[1][i].fi;
        for (int i = 0; i < sz (v[2]); i++)
            res[cur[v[2][i].se]] += v[2][i].fi;
        int a1 = -1, a2 = -1, a3 = -1, b1 = 0, b2 = 0, b3 = 0;
        for (int i = 0; i < n; i++)
            if (type[i] == "weapon")
                for (int j = 0; j < n; j++)
                    if (type[j] == "armor")
                        for (int k = 0; k < n; k++)
                            if (type[k] == "orb") {
                                int c1 = atk[i];
                                int c2 = def[j];
                                int c3 = res[k];
                                if (c1 > a1 || c1 == a1 && c2 > a2 || c1 == a1 && c2 == a2 && c3 > a3) {
                                    a1 = c1;
                                    a2 = c2;
                                    a3 = c3;
                                    b1 = i;
                                    b2 = j;
                                    b3 = k;
                                }
                            }
        cout << item[b1] << " " << num[b1];
        for (int i = 0; i < m; i++)
            if (cur[i] == b1)
                cout << " " << name[i];
        cout << endl;   
        cout << item[b2] << " " << num[b2];
        for (int i = 0; i < m; i++)
            if (cur[i] == b2)
                cout << " " << name[i];
        cout << endl;   
        cout << item[b3] << " " << num[b3];
        for (int i = 0; i < m; i++)
            if (cur[i] == b3)
                cout << " " << name[i];
        cout << endl;   
    }
    return 0;
}