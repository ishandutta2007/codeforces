using namespace std;
#include <bits/stdc++.h>
#define fdto(i, r, l) for(int i = r; i >= l; --i)
#define fto(i, l, r) for(int i = l; i <= r; ++i)
#define forit(it, type, var) for(type::iterator it = var.begin(); it != var.end(); it++)
#define ii pair<int, int>
#define iii pair<int, ii>
#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define ll long long
#define maxN 100005

string s;
bool digit, upper, lower;

int main () {
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        //freopen("output.txt", "w", stdout);
    #endif // ONLINE_JUDGE

    cin >> s;
    fto(i, 0, s.length()-1) {
        if (s[i] >= '0' && s[i] <= '9') digit = true;
        if (s[i] >= 'A' && s[i] <= 'Z') upper = true;
        if (s[i] >= 'a' && s[i] <= 'z') lower = true;
    }

    printf((s.length() >= 5 && digit && upper && lower) ? "Correct" : "Too weak");

    return 0;
}