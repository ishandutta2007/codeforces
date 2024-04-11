#include <iostream>
#include <vector>

using namespace std;

const int INF = 1LL << 30;

class minSegtree {
public:
    explicit minSegtree(int N) : V_NUM(1) {
        while (V_NUM < N) {
            V_NUM *= 2;
        }

        data.resize(V_NUM * 2);
        fill(data.begin(), data.end(), INF);
    }

    int query(int a, int b, int k, int l, int r) {
        if (r <= a || b <= l) return INF;
        if (a <= l && r <= b) return data[k];

        int vl = query(a, b, k * 2 + 1, l, (l + r) / 2);
        int vr = query(a, b, k * 2 + 2, (l + r) / 2, r);
        return min(vl, vr);
    }

    int query(int a, int b) {
        return query(a, b, 0, 0, V_NUM);
    }

    void update(int i, int v) {
        i += V_NUM - 1;
        data[i] = v;
        while (i > 0) {
            i = (i - 1) / 2;
            data[i] = min(data[i * 2 + 1], data[i * 2 + 2]);
        }
    }

    int V_NUM;
    vector<int> data;
};


int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);

    int N, K;
    cin >> N >> K;

    vector<minSegtree> mis(1 << (K - 1), minSegtree(N)), mas(1 << (K - 1), minSegtree(N));

    for (int i = 0; i < N; ++i) {
        int a[K];

        for (int k = 0; k < K; ++k) {
            cin >> a[k];
        }

        for (int b = 0; b < (1 << (K - 1)); ++b) {
            int sum = a[K - 1];
            for (int k = 0; k < K - 1; ++k) {
                sum += ((b >> k & 1) * 2 - 1) * a[k];
            }

            mis[b].update(i, sum);
            mas[b].update(i, -sum);
        }
    }

    int Q;
    cin >> Q;

    for (int q = 0; q < Q; ++q) {
        int t;
        cin >> t;

        if (t == 1) {
            int i;
            cin >> i;
            --i;

            int a[K];

            for (int k = 0; k < K; ++k) {
                cin >> a[k];
            }

            for (int b = 0; b < (1 << (K - 1)); ++b) {
                int sum = a[K - 1];
                for (int k = 0; k < (K - 1); ++k) {
                    sum += ((b >> k & 1) * 2 - 1) * a[k];
                }

                mis[b].update(i, sum);
                mas[b].update(i, -sum);
            }
        } else if (t == 2) {
            int l, r;
            cin >> l >> r;
            --l;

            int ret = 0;
            for (int b = 0; b < (1 << (K - 1)); ++b) {
                ret = max(ret, -mas[b].query(l, r) - mis[b].query(l, r));
            }

            cout << ret << "\n";
        }
    }
    return 0;
}