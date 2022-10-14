#include <iostream>
#include <vector>
#include <utility>
#include <map>
#include <set>
#include <algorithm>
#include <bitset>
#include <cmath>
#include <string>
#include <time.h>
#define mp make_pair
#define X first
#define Y second
#define pii pair<ll,ll>
#define x1 dlfjl
#define x2 dkfj
#define x3 dflgkg
#define y1 dskgj
#define y2 dskfj
#define y3 dfhgdh
#define SQ 320
#define PI 3.14159265359
#define MOD 1000000007
typedef long long ll;
using namespace std;
ll n,m,k, y, z, l, i, j, p, x;
pii a[100500];
vector<ll> found, cur;
string bullshit = "sdgjklhndjksbgnhijfnjkernghjernvahfhjbdsfhjbwehjfbehjwabfisvdbdisdgjklhndjksbgnhijfnjkernghjernvahfhjbdsfhjbwehjfbehjwabfisvdbdidkfsgjdfsgjkdsfhgjkdsfghjdsfhgjdsfhgjdhsgjdsfghhjdsfhgjsdgjklhndjksbgnhijfnjkernghjernvahfhjbdsfhjbwehjfbehjwabfisvdbdisdgjklhndjksbgnhijfnjkernghjernvahfhjbdsfhjbwehjfbehjwabfisvdbdidfklgjdjkfgjkdfjshgjkdshfgjdhsfgjhdsjfghdshjfghdjssdgjklhndjksbgnhijfnjkernghjernvahfhjbdsfhjbwehjfbehjwabfisvdbdisdgjklhndjksbgnhijfnjkernghjernvahfhjbdsfhjbwehjfbehjwabfisvdbdidkfsgjdfsgjkdsfhgjkdsfghjdsfhgjdsfhgjdhsgjdsfghhjdsfhgjsdgjklhndjksbgnhijfnjkernghjernvahfhjbdsfhjbwehjfbehjwabfisvdbdisdgjklhndjksbgnhijfnjkernghjernvahfhjbdsfhjbwehjfbehjwabfisvdbdisdgjklhndjksbgnhijfnjkernghjernvahfhjbdsfhjbwehjfbehjwabfisvdbdisdgjklhndjksbgnhijfnjkernghjernvahfhjbdsfhjbwehjfbehjwabfisvdbdidkfsgjdfsgjkdsfhgjkdsfghjdsfhgjdsfhgjdhsgjdsfghhjdsfhgjsdgjklhndjksbgnhijfnjkernghjernvahfhjbdsfhjbwehjfbehjwabfisvdbdisdgjklhndjksbgnhijfnjkernghjernvahfhjbdsfhjbwehjfbehjwabfisvdbdisdgjklhndjksbgnhijfnjkernghjernvahfhjbdsfhjbwehjfbehjwabfisvdbdisdgjklhndjksbgnhijfnjkernghjernvahfhjbdsfhjbwehjfbehjwabfisvdbdidkfsgjdfsgjkdsfhgjkdsfghjdsfhgjdsfhgjdhsgjdsfghhjdsfhgjsdgjklhndjksbgnhijfnjkernghjernvahfhjbdsfhjbwehjfbehjwabfisvdbdisdgjklhndjksbgnhijfnjkernghjernvahfhjbdsfhjbwehjfbehjwabfisvdbdidsfkgldsfjkghdksfjghjdsfhgjdshfgjdsfhgjdfhjsgsdgjklhndjksbgnhijfnjkernghjernvahfhjbdsfhjbwehjfbehjwabfisvdbdisdgjklhndjksbgnhijfnjkernghjernvahfhjbdsfhjbwehjfbehjwabfisvdbdidkfsgjdfsgjkdsfhgjkdsfghjdsfhgjdsfhgjdhsgjdsfghhjdsfhgjsdgjklhndjksbgnhijfnjkernghjernvahfhjbdsfhjbwehjfbehjwabfisvdbdisdgjklhndjksbgnhijfnjkernghjernvahfhjbdsfhjbwehjfbehjwabfisvdbdidfklgjdjkfgjkdfjshgjkdshfgjdhsfgjhdsjfghdshjfghdjssdgjklhndjksbgnhijfnjkernghjernvahfhjbdsfhjbwehjfbehjwabfisvdbdisdgjklhndjksbgnhijfnjkernghjernvahfhjbdsfhjbwehjfbehjwabfisvdbdidkfsgjdfsgjkdsfhgjkdsfghjdsfhgjdsfhgjdhsgjdsfghhjdsfhgjsdgjklhndjksbgnhijfnjkernghjernvahfhjbdsfhjbwehjfbehjwabfisvdbdisdgjklhndjksbgnhijfnjkernghjernvahfhjbdsfhjbwehjfbehjwabfisvdbdisdgjklhndjksbgnhijfnjkernghjernvahfhjbdsfhjbwehjfbehjwabfisvdbdisdgjklhndjksbgnhijfnjkernghjernvahfhjbdsfhjbwehjfbehjwabfisvdbdidkfsgjdfsgjkdsfhgjkdsfghjdsfhgjdsfhgjdhsgjdsfghhjdsfhgjsdgjklhndjksbgnhijfnjkernghjernvahfhjbdsfhjbwehjfbehjwabfisvdbdisdgjklhndjksbgnhijfnjkernghjernvahfhjbdsfhjbwehjfbehjwabfisvdbdisdgjklhndjksbgnhijfnjkernghjernvahfhjbdsfhjbwehjfbehjwabfisvdbdisdgjklhndjksbgnhijfnjkernghjernvahfhjbdsfhjbwehjfbehjwabfisvdbdidkfsgjdfsgjkdsfhgjkdsfghjdsfhgjdsfhgjdhsgjdsfghhjdsfhgjsdgjklhndjksbgnhijfnjkernghjernvahfhjbdsfhjbwehjfbehjwabfisvdbdisdgjklhndjksbgnhijfnjkernghjernvahfhjbdsfhjbwehjfbehjwabfisvdbdisdgjklhndjksbgnhijfnjkernghjernvahfhjbdsfhjbwehjfbehjwabfisvdbdisdgjklhndjksbgnhijfnjkernghjernvahfhjbdsfhjbwehjfbehjwabfisvdbdidkfsgjdfsgjkdsfhgjkdsfghjdsfhgjdsfhgjdhsgjdsfghhjdsfhgjsdgjklhndjksbgnhijfnjkernghjernvahfhjbdsfhjbwehjfbehjwabfisvdbdisdgjklhndjksbgnhijfnjkernghjernvahfhjbdsfhjbwehjfbehjwabfisvdbdidfklgjdjkfgjkdfjshgjkdshfgjdhsfgjhdsjfghdshjfghdjssdgjklhndjksbgnhijfnjkernghjernvahfhjbdsfhjbwehjfbehjwabfisvdbdisdgjklhndjksbgnhijfnjkernghjernvahfhjbdsfhjbwehjfbehjwabfisvdbdidkfsgjdfsgjkdsfhgjkdsfghjdsfhgjdsfhgjdhsgjdsfghhjdsfhgjsdgjklhndjksbgnhijfnjkernghjernvahfhjbdsfhjbwehjfbehjwabfisvdbdisdgjklhndjksbgnhijfnjkernghjernvahfhjbdsfhjbwehjfbehjwabfisvdbdisdgjklhndjksbgnhijfnjkernghjernvahfhjbdsfhjbwehjfbehjwabfisvdbdisdgjklhndjksbgnhijfnjkernghjernvahfhjbdsfhjbwehjfbehjwabfisvdbdidkfsgjdfsgjkdsfhgjkdsfghjdsfhgjdsfhgjdhsgjdsfghhjdsfhgjsdgjklhndjksbgnhijfnjkernghjernvahfhjbdsfhjbwehjfbehjwabfisvdbdisdgjklhndjksbgnhijfnjkernghjernvahfhjbdsfhjbwehjfbehjwabfisvdbdisdgjklhndjksbgnhijfnjkernghjernvahfhjbdsfhjbwehjfbehjwabfisvdbdisdgjklhndjksbgnhijfnjkernghjernvahfhjbdsfhjbwehjfbehjwabfisvdbdidkfsgjdfsgjkdsfhgjkdsfghjdsfhgjdsfhgjdhsgjdsfghhjdsfhgjsdgjklhndjksbgnhijfnjkernghjernvahfhjbdsfhjbwehjfbehjwabfisvdbdisdgjklhndjksbgnhijfnjkernghjernvahfhjbdsfhjbwehjfbehjwabfisvdbdisdgjklhndjksbgnhijfnjkernghjernvahfhjbdsfhjbwehjfbehjwabfisvdbdisdgjklhndjksbgnhijfnjkernghjernvahfhjbdsfhjbwehjfbehjwabfisvdbdidkfsgjdfsgjkdsfhgjkdsfghjdsfhgjdsfhgjdhsgjdsfghhjdsfhgjsdgjklhndjksbgnhijfnjkernghjernvahfhjbdsfhjbwehjfbehjwabfisvdbdisdgjklhndjksbgnhijfnjkernghjernvahfhjbdsfhjbwehjfbehjwabfisvdbdidfklgjdjkfgjkdfjshgjkdshfgjdhsfgjhdsjfghdshjfghdjssdgjklhndjksbgnhijfnjkernghjernvahfhjbdsfhjbwehjfbehjwabfisvdbdisdgjklhndjksbgnhijfnjkernghjernvahfhjbdsfhjbwehjfbehjwabfisvdbdidkfsgjdfsgjkdsfhgjkdsfghjdsfhgjdsfhgjdhsgjdsfghhjdsfhgjsdgjklhndjksbgnhijfnjkernghjernvahfhjbdsfhjbwehjfbehjwabfisvdbdisdgjklhndjksbgnhijfnjkernghjernvahfhjbdsfhjbwehjfbehjwabfisvdbdisdgjklhndjksbgnhijfnjkernghjernvahfhjbdsfhjbwehjfbehjwabfisvdbdisdgjklhndjksbgnhijfnjkernghjernvahfhjbdsfhjbwehjfbehjwabfisvdbdidkfsgjdfsgjkdsfhgjkdsfghjdsfhgjdsfhgjdhsgjdsfghhjdsfhgjsdgjklhndjksbgnhijfnjkernghjernvahfhjbdsfhjbwehjfbehjwabfisvdbdisdgjklhndjksbgnhijfnjkernghjernvahfhjbdsfhjbwehjfbehjwabfisvdbdisdgjklhndjksbgnhijfnjkernghjernvahfhjbdsfhjbwehjfbehjwabfisvdbdisdgjklhndjksbgnhijfnjkernghjernvahfhjbdsfhjbwehjfbehjwabfisvdbdidkfsgjdfsgjkdsfhgjkdsfghjdsfhgjdsfhgjdhsgjdsfghhjdsfhgjsdgjklhndjksbgnhijfnjkernghjernvahfhjbdsfhjbwehjfbehjwabfisvdbdisdgjklhndjksbgnhijfnjkernghjernvahfhjbdsfhjbwehjfbehjwabfisvdbdi";
string query(ll a, ll c, ll b) {
    cout << "? " << a << " " << b << " " << c << endl;
    fflush(stdout);
    string ans;
    cin >> ans;
    return ans;
}
void find_path(ll x, ll y) {
    cur.clear();
    for (int i = 1; i <= n; i++) {
        if (i == x || i == y)
            continue;
        string ans = query(x, y, i);
        if (ans == "Yes") {
            cur.push_back(i);
        }
    }
}

ll find_amount(ll x, ll y) {
    ll t = 0;
    for (int i = 1; i <= n; i++) {
        if (i == x || i == y)
            continue;
        string ans = query(x, y, i);
        if (ans == "Yes") {
            t++;
        }
    }
    return t;
}
int main() {
    ll l = 0;
    for (int i = 0; i < bullshit.size(); i++)
        l = (l * 37 + bullshit[i] - 'a') % MOD;
    srand(l);
    //freopen("input.txt","r",stdin);
    cin >> n >> k;
    x = 0;
    ll ans = 1, p = 1;
    while (ans != n) {
        p *= k;
        ans += p;
        x++;
    }
    k = x;
    ll x = rand() % n + 1, y = rand() % n + 1;
    while (x == y) {
        y = rand() % n + 1;
    }

    ll curx = -1, cury = -1;
    while (1) {
        /*if (curx == -1) {
            curx = x;
        }
        y = rand() % n + 1;
        while (y == curx) {
            y = rand() % n + 1;
        }
        find_path(curx, y);
        set<ll> f;
        ll tot_sz = cur.size() + found.size();
        for (int j = 0; j < cur.size(); j++)
            f.insert(cur[j]);
        for (int j = 0; j < found.size(); j++)
            f.insert(found[j]);
        if (f.size() == tot_sz) {
            if (curx == -1) {
                cury = y;
                for (int i = 0; i < cur.size(); i++)
                    found.push_back(cur[i]);
            } else {
                curx = y;
                for (int i = 0; i < cur.size(); i++)
                    found.push_back(cur[i]);
            }
        } else {
            if (cur.size() > found.size()) {
                found.clear();
                for (int i = 0; i < cur.size(); i++)
                    found.push_back(cur[i]);
                cury = y;
            }
        }
        if (found.size() == 2 * k - 1)
            break;*/
        x = rand() % n + 1;
        y = rand() % n + 1;
        find_path(x, y);
        if (cur.size() == 2 * k - 1)
            break;
    }

    for (int j = 0; j < 2 * k - 1; j++) {
        if (find_amount(cur[j], x) == k - 1) {
            cout << "! " << cur[j] << endl;
            return 0;
        }
    }


    return 0;
}