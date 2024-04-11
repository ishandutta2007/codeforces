#include <iostream>
#include <vector>

using namespace std;

template <class Type>
class BIT {
public:
    explicit BIT(int length) : length(length) {
        data.assign(length + 1, 0);
    }

    Type query(int index) const {
        ++index;
        Type sum = 0;
        while (index > 0) {
            sum += data[index];
            index -= (index & -index);
        }
        return sum;
    }

    void update(int index, Type diff) {
        ++index;
        while (index <= length) {
            data[index] += diff;
            index += (index & -index);
        }
    }

    int length;
    std::vector<Type> data;
};

const int L = 1000;  // 1

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);

    int N, Q;
    cin >> N >> Q;

    vector<BIT<int>> bit((N + L - 1) / L, BIT<int>(N));
    // bit[i].query(j): [L*i, L*(i+1))j

    int apos[N];  // apos[x]: a[i]=xi
    for (int i = 0; i < N; ++i) {
        int a;
        cin >> a;
        --a;
        apos[a] = i;
    }

    int b[N];
    for (int i = 0; i < N; ++i) {
        int x;
        cin >> x;
        --x;

        b[i] = apos[x];
        bit[i / L].update(b[i], 1);
    }

    for (int q = 0; q < Q; ++q) {
        int id;
        cin >> id;

        if (id == 1) {
            int la, ra, lb, rb;
            cin >> la >> ra >> lb >> rb;
            --la, --ra, --lb;
            // b[lb, rb)[la, ra]

            int ans = 0;
            while (lb < rb && lb % L > 0) {
                if (la <= b[lb] && b[lb] <= ra) ++ans;
                ++lb;
            }

            while (lb < rb && rb % L > 0) {
                --rb;
                if (la <= b[rb] && b[rb] <= ra) ++ans;
            }

            for (int i = lb / L; i < rb / L; ++i) {
                ans += bit[i].query(ra) - bit[i].query(la - 1);
            }

            cout << ans << "\n";
        } else {
            int x, y;
            cin >> x >> y;
            --x, --y;

            bit[x / L].update(b[x], -1);
            bit[x / L].update(b[y], 1);

            bit[y / L].update(b[y], -1);
            bit[y / L].update(b[x], 1);

            swap(b[x], b[y]);
        }
    }

    return 0;
}