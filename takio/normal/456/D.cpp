#include <iostream>
#include <cstring>
#include <cstdio>
#include <cmath>
#include <algorithm>
#define pii pair <int, int>
#define LL long long
using namespace std;

const int N = 100005;

int ch[N][27], sz = 1;
char s[N];

void ins (char *s){
    int u = 0, n = strlen (s);
    for (int i = 0; i < n; i++){
        int c = s[i] - 'a';
        if (!ch[u][c]){
            memset (ch[sz], 0, sizeof (ch[sz]));
            ch[u][c] = sz++;
        }
        u = ch[u][c];
    }
}

int dfs (int u){
    int flag0 = 0, flag1 = 0, flag2 = 0;
    for (int i = 0; i < 26; i++)
    if (ch[u][i]){
        int t = dfs(ch[u][i]);
//        cout << i << ' ' << t << endl;
        if (t == 0) flag0 = 1;
        if (t == 1) flag1 = 1;
        if (t == 2) flag2 = 1;
        if (t == 3) return 2;
    }
    if (!flag0 && !flag1 && !flag2) return 1;
    if (flag0 && flag1) return 2;
    if (!flag2){
        if (flag0) return 1;
        return 0;
    }
    else {
        if (!flag0 && !flag1) return 3;
        if (flag0) return 1;
        return 0;
    }
}

int main () {
    int n, k;
    cin >> n >> k;
    for (int i = 1; i <= n; i++){
        scanf ("%s", s);
        ins(s);
    }
    int t = dfs(0);
//    cout << t << endl;
    if (t < 2) t = 1 - t;
    if (t == 0) cout << "Second\n";
    else if (t == 1){
        if ((k - t) % 2 == 0) cout << "First\n";
        else cout << "Second\n";
    }
    else if (t == 2) {
        cout << "First\n";
    }else {
        cout << "Second\n";
    }
}