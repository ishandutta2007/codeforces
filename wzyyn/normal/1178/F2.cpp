#include <iostream>
#include <vector>

using namespace std;

template <unsigned int N> class Field {
    typedef unsigned int ui;
    typedef unsigned long long ull;
public:
    inline Field(int x = 0) : v(x) {}
	inline Field<N> pow(int p){return (*this)^p; }
    inline Field<N>&operator+=(const Field<N>&o) {if (v+o.v >= N) v += o.v - N; else v += o.v; return *this; }
    inline Field<N>&operator*=(const Field<N>&o) {v=(ull)v*o.v % N; return *this; }
    inline Field<N> operator*(const Field<N>&o) const {Field<N>r{*this};return r*=o;}
	inline explicit operator ui() const { return v; }
private: ui v;
};
template<unsigned int N>ostream &operator<<(std::ostream&os,const Field<N>&f){return os<<(unsigned int)f;}
template<unsigned int N>Field<N> operator+(int i,const Field<N>&f){return Field<N>(i)+f;}
template<unsigned int N>Field<N> operator*(int i,const Field<N>&f){return Field<N>(i)*f;}

typedef Field<998244353> F;

int main() {
    ios_base::sync_with_stdio(false);
    
    int N, M; cin >> N >> M;
    vector<int> C(M); for (int &c: C) { cin >> c; --c; }
    vector<int> W;
    for (int i = 0; i < M; ++i) if (W.empty() || W.back() != C[i]) W.push_back(C[i]);
    M = W.size();
    if (M > 2*N) { cout << "0\n"; return 0; }
    vector<vector<int>> E(N);
    for (int i = 0; i < M; ++i) E[W[i]].push_back(i);
       
    vector<vector<F>> D(M+1, vector<F>(M+1, 1));
    for (int l = 1; l <= M; ++l) {
        for (int a = 0; a + l <= M; ++a) {
            int lo = W[a];
            for (int i = 0; i < l; ++i) lo = min(lo, W[a+i]);
            int j = E[lo][0] - a;
            int k = E[lo].back() - a;
            if (j < 0 || k >= l) { D[a][l] = 0; continue; }
            F left = 0, right = 0;
            for (int u = 0; u <= j; ++u) left += D[a][u] * D[a+u][j-u];
            for (int v = k+1; v <= l; ++v) right += D[a+k+1][v-(k+1)] * D[a+v][l-v];
            D[a][l] = left * right;
            for (int m = 0; m < E[lo].size()-1; ++m) {
                if (E[lo][m] + 1 != E[lo][m+1]) {
                    D[a][l] *= D[E[lo][m]+1][E[lo][m+1] - E[lo][m] - 1];
                }
            }
        }
    }
    
    cout << D[0][M] << endl;
}