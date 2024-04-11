#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3f;
const ll MOD = 998244353;

int N;

const int DEB = 0;

int cnt = 0, r;
bool last_lie = false;
bool answer(int x) {
    if (!DEB) {
        printf("! %d\n", x + 1);
        fflush(stdout);
        char ans[3];
        scanf(" %s", ans);
        if (ans[1] == ')') return true;
        return false;
    } else {
        return x == r;
    }
}

bool can[100100];

bool query(const vector<int> &S) {
    if (!DEB) {
        printf("? ");
        printf("%d ", S.size());
        for (const int &v : S) {
            printf("%d ", v + 1);
        }
        puts("");
        fflush(stdout);
        char ans[6];
        scanf(" %s", ans);
        bool res = (ans[0] == 'Y');
        return res;
    } else {
        cnt++;
        bool in = false;
        for (const int &v : S)
            if (v == r) in = true;
        bool res = false;
        if (last_lie) {
            res = in;
            last_lie = false;
        } else {
            last_lie = rand() % 2;
            res = (last_lie ^ in);
        }
        return res;
    }
}

int main() {
    srand(time(NULL));
    scanf("%d", &N);
    r = rand() % N;
    for (int i = 0; i < N; i++) can[i] = true;
    while (true) {
        vector<int> cand;
        for (int i = 0; i < N; i++) {
            if (can[i]) cand.push_back(i);
        }
        int M = cand.size();
        if (M == 3) {
            vector<int> S1, S2;
            S1.push_back(cand[0]);
            S2.push_back(cand[1]);
            bool a1 = query(S1);
            bool a2 = query(S2);
            if (a1 && a2)
                can[cand[2]] = false;
            else if (a1)
                can[cand[1]] = false;
            else if (a2)
                can[cand[0]] = false;
            else {
                bool a = query(S2);
                if (!a)
                    can[cand[1]] = false;
                else {
                    a = query(S1);
                    if (a)
                        can[cand[2]] = false;
                    else
                        can[cand[0]] = false;
                }
            }
            continue;
        }
        if (M <= 2) {
            for (int &v : cand) {
                if (answer(v)) break;
            }
            break;
        }
        vector<int> S1, S2;
        for (int i = 0; i < M; i++) {
            if (i < M * 2 / 4) S1.push_back(cand[i]);
            if (i < M / 4 || (M * 2 / 4 <= i && i < M * 3 / 4))
                S2.push_back(cand[i]);
        }
        bool a1 = query(S1);
        bool a2 = query(S2);
        for (int i = 0; i < M; i++) {
            bool good = false;
            if ((i < M * 2 / 4) == a1) good = true;
            if ((i < M / 4 || (M * 2 / 4 <= i && i < M * 3 / 4)) == a2)
                good = true;
            if (!good) can[cand[i]] = false;
        }
    }
    if (DEB) {
        printf("%d!\n", cnt);
    }

    return 0;
}