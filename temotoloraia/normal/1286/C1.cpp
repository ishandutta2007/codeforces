#include <bits/stdc++.h>
#define F first
#define S second
#define mp make_pair
#define pb push_back
//#define ll __int128
#define ll long long
#define LEFT(a) ((a)<<1)
#define RIGHT(a) (LEFT(a) + 1)
#define MID(a,b) ((a+b)>>1)
#define MAX(a,b) ((a)>(b)?(a):(b))
#define MIN(a,b) ((a)<(b)?(a):(b))
#define y1 y122

#pragma GCC optimize ("O3")

#pragma GCC optimize("Ofast")
#pragma GCC target("avx2,fma")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#pragma GCC target ("avx2")
#pragma GCC optimization ("unroll-loops")
/*
#pragma comment(linker, "/STACK: 20000000005")
*/
//#define int long long

using namespace std;

string F (string s){
    int n = (int)s.size();
    vector < char > v;
    for (int i = 0; i < n; i++)
        v.pb (s[i]);
    sort (v.begin(), v.end());
    string S = "";
    for (int i = 0; i < n; i++)
        S += v[i];
    return S;
}

const int N = 105;

int n;

map < string, int > M;

int V[N][30];

main() {
    ios_base::sync_with_stdio(0);
    cin >> n;
    if (n == 1){
        cout << "? 1 1" << endl;
        string ch;
        cin >> ch;
        cout << "! " << ch << endl;
        return 0;
    }
    int X = n * (n - 1) / 2, Y = n * (n + 1) / 2;
    cout << "? 2 " << n << endl;
    while (X--){
        string s;
        cin >> s;
        s = F (s);
        M[s]++;
    }
    cout << "? 1 " << n << endl;
    while (Y--){
        string s;
        cin >> s;
        s = F (s);
        if (M[s]){
            M[s]--;
            continue;
        }
        int m = (int)s.size();
        for (int i = 0; i < m; i++)
            V[m][s[i] - 'a']++;
    }
    string pas = "";
    for (int i = 1; i <= n; i++)
        for (int x = 0; x < 26; x++){
            if (V[i][x] > V[i - 1][x]){
                char ch = x + 'a';
                pas += ch;
                break;
            }
        }
    cout << "! " << pas << endl;
}