#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> PII;

const int MAXN = 1200;
const int MAXM = 1010;
const int MM = 1e9 + 7;

struct piii {
    piii() = default;
    piii(int _d, int _r, int _t): d(_d), r(_r), t(_t) {}
    int d{0}, r{0}, t{0};
} f[MAXM * 4][MAXN];
int A;
const int B = 2020;
const int C = 4040;

int S(int x) {
    int y = 0;
    while (x != 0) {
        y += x % 10;
        x = x / 10;
    }
    return y;
}

queue<PII> O;
int FIND = 0;
int D, R;

bool try_update(int delta, int rm, int pd, int pr, int trans) {
    // cout << delta - B << ' ' << rm << ' ' << pd - B << ' ' << pr << ' ' << trans << endl;
    if (delta <= 0 || delta >= C) return false;
    if (f[delta][rm].d == 0 && f[delta][rm].r == 0) {
        f[delta][rm] = piii(pd, pr, trans);
        O.push(PII(delta, rm));
        if (delta - A * S(rm) == B) {
            D = delta, R = rm;
            return FIND = true;
        }
    }
    return false;
}

void solve(int casi){
    scanf("%d", &A);
    for (int i = 1; i <= 9; i++) {
        if (try_update(i - A * S(A * i % 10) + B, i * A / 10, -1, -1, i)) {
            break;
        }
    }
    while (!O.empty() && !FIND) {
        auto pdr = O.front();
        O.pop();
        int delta = pdr.first;
        int rm = pdr.second;
        for (int i = 0; i <= 9; i++) {
            int nrp = i * A + rm;
            int nd = delta + i - A * (nrp % 10);
            if (try_update(nd, nrp / 10, delta, rm, i)) break;
        }
        if (FIND) break;
    }
    if (!FIND) puts("-1");
    else {
        while (D != -1 || R != -1) {
            printf("%d", f[D][R].t);
            auto nico = f[D][R];
            D = nico.d;
            R = nico.r;
        }
        puts("");
    }
}

int main(){
    int T = 1;
    for (int i = 1; i <= T; i++)
        solve(i);
    return 0;
}