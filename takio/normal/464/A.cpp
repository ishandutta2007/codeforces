#include <iostream>
#include <cstdio>
using namespace std;

char s[1010], res[1010];
int n, p;

int dfs (int pos, int flag) {
//    cout << pos << ' '<< flag << endl;
    if (pos == n) {
        return 1;
    }
    int f;
    if (flag) f = 0;
    else {
        f = s[pos];
        if (pos == n - 1) f++;
    }
    for (int i = f; i < p; i++) {
        if (pos > 0 && i == res[pos - 1] || pos > 1 && i == res[pos - 2]) continue;
        res[pos] = i;
        if (i > s[pos]) flag = 1;
        if (dfs (pos + 1, flag)) return 1;
    }
    return 0;
}

int main()
{
    cin >> n >> p;
    scanf ("%s", s);
    for (int i = 0; i < n; i++) s[i] -= 'a';

    if (!dfs (0, 0)) {
        cout << "NO\n";
        return 0;
    }

    for (int i = 0; i < n; i++) {
        cout << (char)(res[i] + 'a');
    }
    return 0;
}