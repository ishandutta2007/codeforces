#include <iostream>
#include <string>
#include <vector>

using namespace std;

template <typename T, typename U>
T mypow(T b, U n) {
    if (n == 0) return 1;
    if (n == 1) return b /* % MOD */;
    if (n % 2 == 0) {
        return mypow(b * b /* % MOD */, n / 2);
    } else {
        return mypow(b, n - 1) * b /* % MOD */;
    }
}

int s2i(string S) {
    int N = S.length(), ret = 1;
    for (int i = 1; i < N; ++i) {
        ret += mypow(26, i);
    }
    for (int i = 0; i < N; ++i) {
        ret += mypow(26, N - i - 1) * (S[i] - 'A');
    }
    return ret;
}

string i2s(int num) {
    --num;
    int N = 1;
    while (num >= mypow(26, N)) {
        num -= mypow(26, N);
        ++N;
    }
    string ret = "";
    for (int i = N - 1; i >= 0; --i) {
        char c = num / mypow(26, i) % 26 + 'A';
        ret.push_back(c);
    }

    return ret;
}

vector<string> decode(string S) {
    vector<string> ret;
    string buf = "";
    buf.push_back(S[0]);

    for (int i = 1; i < S.length(); ++i) {
        if (isdigit(S[i - 1]) != isdigit(S[i])) {
            ret.push_back(buf);
            buf.clear();
        }
        buf.push_back(S[i]);
    }

    ret.push_back(buf);
    return ret;
}

bool is_excel(vector<string> T) {
    return T.size() == 2;
}

string e2n(vector<string> T) {
    return "R" + T[1] + "C" + to_string(s2i(T[0]));
}

string n2e(vector<string> T) {
    return i2s(stoi(T[3])) + T[1];
}

string trans(string S) {
    vector<string> decoded = decode(S);
    if (is_excel(decoded)) {
        return e2n(decoded);
    } else {
        return n2e(decoded);
    }
}

int main() {
    int Q;
    cin >> Q;

    for (int q = 0; q < Q; ++q) {
        string S;
        cin >> S;
        cout << trans(S) << endl;
    }
    return 0;
}