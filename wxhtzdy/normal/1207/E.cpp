#include <bits/stdc++.h>
#define ll long long
#define mp make_pair
#define fi first
#define se second
#define pb push_back
#define vi vector<int>
#define pi pair<int, int>
#define mod 998244353
template<typename T> bool chkmin(T &a, T b){return (b < a) ? a = b, 1 : 0;}
template<typename T> bool chkmax(T &a, T b){return (b > a) ? a = b, 1 : 0;}
ll ksm(ll a, ll b) {if (b == 0) return 1; ll ns = ksm(a, b >> 1); ns = ns * ns % mod; if (b & 1) ns = ns * a % mod; return ns;}
using namespace std;

int ask(int st) {
    printf("? ");
    for (int i = 1; i <= 100; i++) printf("%d ", i << st);
    fflush(stdout);
    int x;
    scanf("%d", &x);
    return x;
}

const int m = (1 << 7) - 1;

int main() {
    int a = ask(0), b = ask(7);
    printf("! %d", (a & (m << 7)) | (b & m));
    fflush(stdout);
    return 0;
}