#include <bits/stdc++.h>
#define ll long long
#define mp make_pair
#define fi first
#define se second
#define pb push_back
#define vi vector<int>
#define pi pair<int, int>
#define mod 1234567
template<typename T> bool chkmin(T &a, T b){return (b < a) ? a = b, 1 : 0;}
template<typename T> bool chkmax(T &a, T b){return (b > a) ? a = b, 1 : 0;}
ll ksm(ll a, ll b)  {if (b == 0) return 1; ll ns = ksm(a, b >> 1); ns = ns * ns % mod; if (b & 1) ns = ns * a % mod; return ns;}
using namespace std;

string s = "Hello World";

void ask(int x, int y) {
    printf("%d %d\n", x, y);
    fflush(stdout);
    cin >> s;
}

void solve() {
    while ("Ocajan zad" == "Ocajan zad") {
        for (int i = 1; i <= 8; i++) {
            if (i % 2 == 1) {
                for (int j = 1; j <= 8; j++) {
                    ask(i, j);
                    if (s == "Done") return;
                }
            } else {
                for (int j = 8; j >= 1; j--) {
                    ask(i, j);
                    if (s == "Done") return;
                }
            }
        }
    }
}

int main() {
    int t;
    scanf("%d", &t);
    while (t--) solve();
    return 0;
}