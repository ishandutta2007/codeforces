#include <iostream>
#include <vector>

typedef long long ll;
const ll mod = 1000000007;

int n_col; long long res =0;
std::vector<int> height, prin_mem;

int n_prin(int col) {return col?std::min(height[col-1],height[col]):height[0];} // no need to %, O(1)

int prin(int);

ll partial_f(int col, int h) {
    return (h <= n_prin(col) ? prin(col) * static_cast<ll>(h-1) : prin(col) * static_cast<ll>(n_prin(col)-1) + (h - n_prin(col))) %mod;
}

int prin(int col) {
    if (prin_mem[col] != -1) return prin_mem[col];
    return prin_mem[col] = (col?(1+partial_f(col-1,n_prin(col))) %mod:1);
}

int main() {
    std::ios_base::sync_with_stdio(false); std::cin.tie(nullptr);
    std::cin >> n_col;
    height.resize(n_col); prin_mem.resize(n_col, -1);
    for (int i=0; i<n_col; ++i) {
        std::cin >> height[i];
    }

    for (int col = 0; col < n_col; ++col) {
        res = (res + partial_f(col, height[col])) %mod;
    }
    std::cout << res;
}