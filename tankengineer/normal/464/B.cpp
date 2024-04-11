#include <vector>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;

vector<vector<int> > p(8), mins, ans, tmp(8), bak(8);

vector<int> operator - (const vector<int> &p, const vector<int> &q) {
    vector<int> ret(3);
    ret[0] = p[0] - q[0], ret[1] = p[1] - q[1], ret[2] = p[2] - q[2];
    return ret;
}

vector<int> operator + (const vector<int> &p, const vector<int> &q) {
    vector<int> ret(3);
    ret[0] = p[0] + q[0], ret[1] = p[1] + q[1], ret[2] = p[2] + q[2];
    return ret;
}

long long len(vector<int> p) {
    return (long long)p[0] * p[0] + (long long)p[1] * p[1] + (long long)p[2] * p[2];
}

long long dot(vector<int> p, vector<int> q) {
    long long ret = 0;
    for (int i = 0; i < 3; ++i) {
        ret += (long long)p[i] * q[i];
    }
    return ret;
}

bool check() {
    ans = tmp;
    for (int i = 0; i < 8; ++i) {
        sort(tmp[i].begin(), tmp[i].end());
    }
    sort(tmp.begin(), tmp.end());
    return tmp == mins;
}

bool check(vector<int> o, vector<int> delta1, vector<int> delta2, vector<int> delta3) {
    if (len(delta1) == 0 || len(delta1) != len(delta2) || len(delta1) != len(delta3)) {
        return false;
    }
    if (dot(delta1, delta2) != 0 || dot(delta1, delta3) != 0 || dot(delta2, delta3) != 0) {
        return false;
    }
    tmp[0] = o;
    tmp[1] = o + delta1;
    tmp[2] = o + delta2;
    tmp[3] = o + delta3;
    tmp[4] = o + delta1 + delta2;
    tmp[5] = o + delta1 + delta3;
    tmp[6] = o + delta2 + delta3;
    tmp[7] = o + delta1 + delta2 + delta3;
    return check();
}

bool match() {
    tmp = ans;
    for (int i = 0; i < 8; ++i) {
        sort(tmp[i].begin(), tmp[i].end());
    }
    return tmp == bak;
}

int main() {
    for (int i = 0; i < 8; ++i) {
        p[i].resize(3);
        for (int j = 0; j < 3; ++j) {
            scanf("%d", &p[i][j]);
        }
        sort(p[i].begin(), p[i].end());
    }
    bak = p;
    sort(p.begin(), p.end());
    mins = p;
    bool flag = false;
    for (int i = 1; i < 8 && !flag; ++i) {
        do {
            vector<int> delta1 = p[i] - p[0];
            for (int j = i + 1; j < 8 && !flag; ++j) {
                do {
                    vector<int> delta2 = p[j] - p[0];
                    for (int k = j + 1; k < 8 && !flag; ++k) {
                        do {
                            vector<int> delta3 = p[k] - p[0];
                            flag = check(p[0], delta1, delta2, delta3);
                        } while (!flag && next_permutation(p[k].begin(), p[k].end()));
                        sort(p[k].begin(), p[k].end());
                    }
                } while (!flag && next_permutation(p[j].begin(), p[j].end()));
                sort(p[j].begin(), p[j].end());
            }
        } while (!flag && next_permutation(p[i].begin(), p[i].end()));
        sort(p[i].begin(), p[i].end());
    }
    if (!flag) {
        puts("NO");
    } else {
        puts("YES");
        sort(ans.begin(), ans.end());
        do {
            if (match()) {
                for (int i = 0; i < 8; ++i) {
                    printf("%d %d %d\n", ans[i][0], ans[i][1], ans[i][2]);
                }
                break;
            }
        } while (next_permutation(ans.begin(), ans.end()));
    }
    return 0;
}