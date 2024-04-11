#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <cassert>
#include <iostream>
#include <sstream>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <utility>
#include <numeric>
#include <algorithm>
#include <bitset>
#include <complex>

using namespace std;

typedef unsigned uint;
typedef long long lint;

template<typename T> void pv(T a, T b) { for (T i = a; i != b; ++i) cout << *i << " "; cout << endl; }
template<typename T> void chmin(T& a, T b) { if (a > b) a = b; }
template<typename T> void chmax(T& a, T b) { if (a < b) a = b; }

bool valid(string S)
{
    const int types[] = {0, 0, 1, 0, 0, 1, 0, 0, 0, 0};

    for (int i = 0; i < 10; ++i) {
        if (types[i] == 0 && !isdigit(S[i])) {
            return false;
        }
        if (types[i] == 1 && S[i] != '-') {
            return false;
        }
    }

    const int days[] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

    int day = (S[0] - '0') * 10 + S[1] - '0';
    int month = (S[3] - '0') * 10 + S[4] - '0';
    int year = (S[6] - '0') * 1000 + (S[7] - '0') * 100 + (S[8] - '0') * 10 + S[9] - '0';

    if (year < 2013 || year > 2015) {
        return false;
    }
    if (month < 1 || month > 12) {
        return false;
    }
    if (day < 1 || day > days[month]) {
        return false;
    }

    return true;
}

int main()
{
    string S;
    cin >> S;

    map<string, int> app;
    for (int i = 0; i + 10 <= (int)S.size(); ++i) {
        string sub = "";
        for (int j = 0; j < 10; ++j) {
            sub += S[i + j];
        }
        if (valid(sub)) {
            app[sub]++;
        }
    }

    string res;
    int cnt = 0;
    for (map<string, int>::iterator it = app.begin(); it != app.end(); ++it) {
        if (cnt < it->second) {
            cnt = it->second;
            res = it->first;
        }
    }

    cout << res << endl;

    return 0;
}