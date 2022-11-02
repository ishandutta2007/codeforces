//#pragma comment(linker, "/STACK:1024000000,1024000000")
#include <algorithm>
#include <map>
#include <cstdio>
#include <cstring>
#include <iostream>
#define LL long long
#define pii pair <LL, int>
#define xx first
#define yy second
using namespace std;

char c;
int cnt[30];

int main () {
//    freopen ("in.txt", "r", stdin);
    int n, res = 0;
    cin >> n;
    getchar ();
    for (int i = 1; i <= 2 * n - 2; i++) {
        scanf ("%c", &c);
        if (c >= 'a' && c <= 'z') cnt[c - 'a']++;
        else if (cnt[c - 'A']) cnt[c - 'A']--;
        else res++;
    }
    cout << res << endl;
}