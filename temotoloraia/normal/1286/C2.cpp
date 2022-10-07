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

const int N = 105;

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

int VV[N][30];

string amoxsna (int n){
    map < string, int > M;
    if (n == 1){
        cout << "? 1 1" << endl;
        string ch;
        cin >> ch;
        return ch;
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
            VV[m][s[i] - 'a']++;
    }
    string pas = "";
    for (int i = 1; i <= n; i++)
        for (int x = 0; x < 26; x++){
            if (VV[i][x] > VV[i - 1][x]){
                char ch = x + 'a';
                pas += ch;
                break;
            }
        }
    return pas;
}


int n;

string S;

vector < string > V[N];
map < string, int > M;

int mas[30], a[30], b[30];

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
    cout << "? 1 " << n << endl;
    int num = n * (n + 1) / 2;
    while (num--){
        string s;
        cin >> s;
        s = F (s);
        int m = (int)s.size();
        V[m].pb (s);
    }
    S = "#" + V[n][0];
    int m = (n) / 2;
    string s = "#" + amoxsna (m);
    for (int i = 1; i <= m; i++)
        for (int j = i; j <= n; j++){
            if (S[j] == s[i]){
                swap (S[i], S[j]);
                break;
            }
        }
    for (int i = 1; i <= n; i++)
        mas[S[i] - 'a']++;
    for (int I = n - 1; I > m; I--){
        for (int i = 1; i + I <= n; i++){
            string s = "";
            for (int j = i + 1; j <= i + I; j++)
                s += S[j];
            s = F (s);
            M[s]++;
        }
        string ss = "";
        for (string s : V[I]){
            if (M[s]){
                M[s]--;
                continue;
            }
            ss = s;
            break;
        }
        for (int i = 0; i < 26; i++)
            a[i] = 0;
        for (int i = 0; i < I; i++)
            a[ss[i] - 'a']++;
        char ch;
        for (int i = 0; i < 26; i++){
            if (mas[i] > a[i]){
                mas[i] = a[i];
                ch = i + 'a';
            }
        }
        for (int i = I + 1; i > m; i--)
            if (S[i] == ch){
                swap (S[i], S[I + 1]);
                break;
            }
    }
    string pas = "";
    for (int i = 1; i <= n; i++)
        pas += S[i];
    cout << "! " << pas << endl;
}