#include <iostream>
#include <vector>

const int mod = 1000000007;
typedef long long ll;
typedef std::vector<int> vi;
typedef std::vector<std::vector<int>> mat;

int nseg;
ll dest;
std::vector<ll> start, finish;
std::vector<int> height;
mat result;

mat matmul(const mat &a, const mat &b) {
    // if (a.size() == 0 || b.size() == 0 || a[0].size() == 0 || b[0].size() == 0 || a[0].size() != b.size()) std::cout << "mul error\n";
    int x = a.size(), y = b[0].size(), t = b.size();
    mat result (x, vi(y, 0));
    for (int i = 0; i < x; ++i) {
        for (int j = 0; j < y; ++j) {
            ll tmp = 0;
            for (int k = 0; k < t; ++k) {
                tmp += ll(a[i][k]) * b[k][j];
            }
            result[i][j] = tmp %mod;
        }
    }
    return result;
}

mat matexp(mat base, ll exp) {
    // if (base.size() == 0 || base.size() != base[0].size()) std::cout << "exp error\n";
    int t = base.size();
    mat result (t, vi(t, 0));
    for (int i = 0; i < t; ++i) result[i][i] = 1;
    while (exp != 0) {
        if (exp & 1) result = matmul(result, base);
        exp >>= 1;
        if (exp == 0) break;
        base = matmul(base, base);
    }
    return result;
}

std::vector<mat> basis;

signed main() {
    for (int h = 0; h < 16; ++h) {
        std::vector<std::vector<int>> mat (h+1, std::vector<int>(h+1));
        for (int i = 0; i <= h; ++i) {
            for (int j = 0; j <= h; ++j) {
                if (-1 <= i-j && i-j <= 1) mat[i][j] = 1;
            }
        }
        basis.push_back(mat);
    }

    std::ios_base::sync_with_stdio(false); std::cin.tie(nullptr);
    std::cin >> nseg >> dest;
    start .resize(nseg);
    finish.resize(nseg);
    height.resize(nseg);
    for (int i = 0; i < nseg; ++i) {
        std::cin >> start[i] >> finish[i] >> height[i];
    }
    finish[nseg-1] = dest;

    result.assign(16, std::vector<int>(1, 0)); result[0][0] = 1;
    for (int seg = nseg-1; seg >= 0; --seg) {
        int h = height[seg];
        result.resize(h+1, std::vector<int>(1, 0)); // resize is intentional
        result = matmul(matexp(basis[h], finish[seg] - start[seg]), result);
    }

    std::cout << result[0][0] << "\n";
}