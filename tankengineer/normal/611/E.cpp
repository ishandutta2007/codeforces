#include<set>
#include<vector>
#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
using namespace std;

int a, b, c;

int ans;

multiset<int> enemy;

void kills(int a) {
    multiset<int>::iterator it = enemy.upper_bound(a);
    if (it != enemy.begin()) {
        enemy.erase(--it);
    }
}

const int INF = 1000000000;

int calc(int co, int ab, int bb, int aa) {
    if (co) {
        return INF;
    } else {
        return ab + (bb > aa ? bb : (bb + aa + 1) / 2);
    }
}

int solve3(multiset<int> &enemy) {
    vector<int> es(enemy.begin(), enemy.end());
    int co = 0, ab = 0, bb = 0, aa = 0;
    for (int i = 0; i < (int)es.size(); ++i) {
        int ti = es[i];
        if (ti > a + b) {
            ++co;
        } else if (ti > b) {
            ++ab;
        } else if (ti > a) {
            ++bb;
        } else {
            ++aa;
        }
    }
    int ret = es.size();
    for (int i = (int)es.size(); i >= 0; --i) {
        if (i < (int)es.size()) {
            int ti = es[i];
            if (ti > a + b) {
                --co;
            } else if (ti > b) {
                --ab;
            } else if (ti > a) {
                --bb;
            } else {
                --aa;
            }
        }
        int ckill = es.size() - i;
        ret = min(ret, max(ckill, calc(co, ab, bb, aa)));
    }
    return ret;
}

int main() {
    int n;
    scanf("%d", &n);
    scanf("%d%d%d", &a, &b, &c);
    {
        int tmp[3] = {a, b, c};
        sort(tmp, tmp + 3);
        a = tmp[0], b = tmp[1], c = tmp[2];
    }
    ans = 0;
    for (int i = 0; i < n; ++i) {
        int ti;
        scanf("%d", &ti);
        if (ti > a + b + c) {
            printf("-1\n");
            return 0;
        } else if (ti > b + c) {
            ++ans;
        } else {
            enemy.insert(ti);
        }
    }
    while (enemy.size()) {
        int ti = *enemy.rbegin();
        if (ti > a + c) {
            ++ans;
            enemy.erase(enemy.find(ti));
            kills(a);
        } else if (ti > max(c, a + b)) {
            ++ans;
            enemy.erase(enemy.find(ti));
            kills(b);
        } else {
            if (a + b > c) {
                if (ti > c) {
                    ++ans;
                    enemy.erase(enemy.find(ti));
                    kills(c);
                } else {
                    break;
                }
            } else {
                break;
            }
        }
    }
    ans += solve3(enemy);
    printf("%d\n", ans);
    return 0;
}