#include <bits/stdc++.h>
#define For(i, a, b) for(int i = a; i < b; ++i)
#define Out(i, a, b) for(int i = a - 1; i >= b; --i)
#define pb push_back
#define point pair <int, int>
#define x first
#define y second
#define files(FileName) read(FileName); write(FileName)
#define read(FileName) freopen((FileName + ".in").c_str(), "r", stdin)
#define write(FileName) freopen((FileName + ".out").c_str(), "w", stdout)

using namespace std;

string FileName = "input";

typedef long long base;

int L = 2, R = 100;

vector <int> NoS[2];



int main() {
    //ios::sync_with_stdio(false);
    For(M, 0, 20) {
        map <int, int> cnt;
        For(i, L, R + 1) {
            bool OK = true;
            for(int j: NoS[0]) {
                if (i % j == 0)
                    OK = false;
            }
            for(int j: NoS[1]) {
                if (i % j != 0)
                    OK = false;
            }
            if (!OK) continue;
            For(j, 2, i + 1) {
                if (i % j == 0)
                    ++cnt[j];
            }
        }
        for(int j: NoS[1]) {
            cnt[j] = 0;
        }
        int ans = 1;
        for(auto j: cnt) {
            if (j.y > cnt[ans]) {
                ans = j.x;
            }
        }
        if (ans == 1) break;
        cout << ans << endl; fflush(stdout);
        string s; cin >> s;
        NoS[s == "yes"].pb(ans);
    }
    if (NoS[1].size() > 1) {
        cout << "composite" << endl;
    } else {
        cout << "prime" << endl;
    }
    fflush(stdout);
}