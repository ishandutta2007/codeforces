#include <bits/stdc++.h>

#include <cstdint>
template<int M> struct modint {
private:
    int64_t binary_exponentiation(int a, int b) {
        int64_t res = 1;
        while(b > 0) {
            if(a&1) {
                res = res * a % M;
            }
            a = 1LL * a * a % M;
            b /= 2;
        }
        return res;
    }
    int64_t modinv(int64_t x) { 
        long othermod = binary_exponentiation(x, M - 2);
        return othermod;
    }
public:
    int64_t v;
    modint() : v(0) {}
    modint(int64_t x) { v = x % M; }

    modint operator * (int64_t x) { return modint<M>(v * x); }
    modint operator / (int64_t x) { return modint<M>(v * modinv(x)); }
    modint operator + (int64_t x) { return modint<M>(v+x);}
    modint operator - (int64_t x) { v -= x; if (v < 0) v += M; return modint<M>(v); }
    modint operator ^ (int64_t x) { return modint<M>(v ^ x); }
    modint operator & (int64_t x) { return modint<M> (v & x); }    
    bool operator == (const modint& other) {return v == other.v; }

    bool operator != (const modint& other) { return v != other.v; }
    
    modint operator ^= (const modint& other) { return *this = modint<M>(v ^ other.v); }

    modint operator &= (const modint& other) { return *this = modint<M>(v & other.v); }

    modint operator += (const modint& other) { return *this = modint<M>(v += other.v); }
    
    modint operator -= (const modint& other) { return *this = modint<M>(v -= other.v); }

    modint operator *= (const modint& other) { return *this = modint<M>(v * other.v); }

    modint operator /= (const modint& other) { return *this = modint<M>(v * modinv(other.v)); } 
};
int main() {
    using namespace std;
    ios::sync_with_stdio(false);
    cin.tie(0);

    int T;
    cin >> T;
    vector<int64_t> answers(T);
    while(T--) {
        int N, M;
        cin >> N >> M;

        vector<int64_t> A(N), B(M), L(N);

        for(int64_t &a: A)
            cin >> a;

        for(int i = 0; i < N; i++)
            L[A[i] - 1] = i;
    
        for(int64_t &b: B) 
            cin >> b;

        int64_t ans = 0;
        int64_t max_level = 0, been = 0;
        for(int i = 0; i < M; i++, been++) {
            int num = B[i];
            if (L[num - 1] <= max_level)
                ans += 1;
            else 
                ans += 2 * L[num - 1] + 1 - 2 * been;
            max_level = max(max_level, L[num - 1]);
        }

        answers[T] = ans;
    }
    reverse(answers.begin(), answers.end());

    for(int64_t answer : answers) {
        cout << answer << "\n";
    }
}