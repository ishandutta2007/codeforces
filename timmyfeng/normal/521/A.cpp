#include <bits/stdc++.h>
using namespace std;

const int M = 1000000007;
struct mint {

    int value;

    mint() : value(0) {}

    template <class T>
    mint(T x) {
        value = x % M;
        if (value < 0) {
            value += M;
        }
    }

    mint & operator++() {
        if (++value == M) {
            value = 0;
        }
        return *this;
    }

    mint & operator--() {
        if (--value == -1) {
            value = M - 1;
        }
        return *this;
    }

    mint operator++(int) {
        mint res = *this;
        ++*this;
        return res;
    }

    mint operator--(int) {
        mint res = *this;
        --*this;
        return res;
    }

    mint & operator+=(mint oth) {
        value += oth.value;
        if (value >= M) {
            value -= M;
        }
        return *this;
    }

    mint & operator-=(mint oth) {
        value -= oth.value;
        if (value < 0) {
            value += M;
        }
        return *this;
    }

    mint & operator*=(mint oth) {
        value = (long long) value * oth.value % M;
        return *this;
    }

    mint operator+() const {
        return *this;
    }

    mint operator-() const {
        return mint() - *this;
    }

    mint pow(long long e = M - 2) const {
        mint res = 1, b = *this;
        while (e > 0) {
            if (e % 2 == 1) {
                res *= b;
            }
            b *= b;
            e /= 2;
        }
        return res;
    }

    friend mint operator+(mint a, mint b) {
        return a += b;
    }

    friend mint operator-(mint a, mint b) {
        return a -= b;
    }

    friend mint operator*(mint a, mint b) {
        return mint(a) *= b;
    }

    friend bool operator==(mint a, mint b) {
        return a.value == b.value;
    }

    friend bool operator!=(mint a, mint b) {
        return a.value != b.value;
    }

    friend ostream & operator<<(ostream &out, mint a) {
        out << a.value;
        return out;
    }

};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    string s;
    cin >> n >> s;

    vector<int> freq(26);
    for (auto i : s) {
        ++freq[i - 'A'];
    }
    sort(freq.begin(), freq.end());

    mint choices = 0;
    int common = freq.back();
    while (!freq.empty() && freq.back() == common) {
        freq.pop_back();
        ++choices;
    }

    cout << choices.pow(n) << "\n";
}