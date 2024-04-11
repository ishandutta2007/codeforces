#include <bits/stdc++.h>
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
typedef int ll;
using namespace std;
ll n,m,k,x,  y, z, l, r, i, j, p[335], q;
char a[1005000], b[1000500], s[1005000], t[1005000];
int ass[45], used[45];
int main() {
    //freopen("input.txt","r",stdin);
    ll tt;
    cin >> tt;
    while (tt--) {
        scanf("%d", &k);
        for (int i = 0; i < k; i++)
            ass[i] = -1, used[i] = 0;
        scanf("%s", t);
        scanf("%s", a);
        scanf("%s", b);
        bool flag = 0;
        n = strlen(t);
        bool ok = true;
        int pnt = -1;
        for (int i = 0; i < n; i++)
            s[i] = t[i];
        for (int i = 0; i < n; i++) {
            if (a[i] != b[i]) {
                pnt = i;
                break;
            } else {
                if (ass[s[i]-'a'] == -1) {
                    if (!used[a[i]-'a']) {
                        ass[s[i]-'a'] = a[i] - 'a';
                        used[a[i]-'a'] = 1;
                    } else {
                        ok = false;
                    }
                } else if (ass[s[i]-'a'] != a[i]-'a') {
                    ok = false;
                }
            }
            s[i] = ass[s[i] - 'a'] + 'a';
        }
        if (pnt == -1) {
            pnt = n;
        }


        for (int i = pnt; i < n; i++) {
            if (ass[s[i]-'a'] == -1) {
                if (flag) {
                    ll id = -1;
                    for (int j = 0; j < k; j++) {
                        if (!used[j]) {
                            id = j;
                            break;
                        }
                    }
                    used[id] = 1;
                    ass[s[i]-'a'] = id;
                } else {
                    ll id = -1;
                    ll tmp = k-1;
                    if (i == pnt) {
                        tmp = b[i] - 'a' - 1;
                    }
                    for (int j = tmp; j >= a[i]-'a'; j--) {
                        if (!used[j]) {
                            id = j;
                            break;
                        }
                    }
                    if (id == -1) {
                        ok = false;
                        break;
                    }
                    used[id] = 1;
                    ass[s[i]-'a'] = id;
                    if (id != a[i] - 'a') {
                        flag = 1;
                    }
                }
            }
            if (!flag) {
                if (ass[s[i] - 'a'] + 'a' > a[i]) {
                    flag = 1;
                }
                else if (ass[s[i] - 'a'] + 'a' < a[i]) {
                    ok = false;
                    break;
                }
            }
            s[i] = ass[s[i]-'a'] + 'a';
        }

        for (int i = 0; i < n; i++)
        if (s[i] > a[i]) {
            break;
        } else if (s[i] < a[i]) {
            ok = false;
            break;
        }

        for (int i = 0; i < n; i++)
        if (s[i] < b[i]) {
            break;
        } else if (s[i] > b[i]) {
            ok = false;
            break;
        }

        if (!ok) {
            for (int i = 0; i < n; i++)
                s[i] = t[i];
            for (int i = 0; i < k; i++)
                ass[i] = -1, used[i] = 0;
            bool ok = true;
            bool flag = 0;
            int pnt = -1;
            for (int i = 0; i < n; i++) {
                if (a[i] != b[i]) {
                    pnt = i;
                    break;
                } else {
                    if (ass[s[i]-'a'] == -1) {
                        if (!used[a[i]-'a']) {
                            ass[s[i]-'a'] = a[i] - 'a';
                            used[a[i]-'a'] = 1;
                        } else {
                            ok = false;
                        }
                    } else if (ass[s[i]-'a'] != a[i]-'a') {
                        ok = false;
                    }
                }
                s[i] = ass[s[i] - 'a'] + 'a';
            }
            if (pnt == -1) {
                pnt = n;
            }

            for (int i = pnt; i < n; i++) {
                if (ass[s[i]-'a'] == -1) {
                    if (flag) {
                        ll id = -1;
                        for (int j = 0; j < k; j++) {
                            if (!used[j]) {
                                id = j;
                                break;
                            }
                        }
                        used[id] = 1;
                        ass[s[i]-'a'] = id;
                    } else {
                        ll id = -1;
                        ll tmp = 0;
                        if (i == pnt) {
                            tmp = a[i] - 'a' + 1;
                        }
                        for (int j = tmp; j <= b[i] - 'a'; j++) {
                            if (!used[j]) {
                                id = j;
                                break;
                            }
                        }
                        if (id == -1) {
                            ok  = false;
                            break;
                        }
                        used[id] = 1;
                        ass[s[i]-'a'] = id;
                        if (id != b[i] - 'a') {
                            flag = 1;
                        }
                    }
                }
                if (!flag) {
                    if (ass[s[i] - 'a'] + 'a' < b[i]) {
                        flag = 1;
                    }
                    else if (ass[s[i] - 'a'] + 'a' > b[i]) {
                        ok = false;
                        break;
                    }
                }
                s[i] = ass[s[i]-'a'] + 'a';
            }

            for (int i = 0; i < n; i++)
            if (s[i] > a[i]) {
                break;
            } else if (s[i] < a[i]) {
                ok = false;
                break;
            }

            for (int i = 0; i < n; i++)
            if (s[i] < b[i]) {
                break;
            } else if (s[i] > b[i]) {
                ok = false;
                break;
            }
            if (!ok) {
                cout << "NO" << endl;
                continue;
            }
        }

        cout << "YES" << endl;
        char ans[27];
        vector<ll> ff;
        for (int j = 0; j < k; j++)
        if (!used[j]) {
            ff.push_back(j);
        }
        for (int i = 0; i < k; i++) {
            if (ass[i] == -1) {
                ass[i] = ff.back();
                ff.pop_back();
            }
            ans[i] = ass[i] + 'a';
        }
        ans[k] = 0;
        printf("%s\n", ans);
    }
    return 0;
}