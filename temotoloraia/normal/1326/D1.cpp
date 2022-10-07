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
#define int long long
 
/*
#pragma GCC optimize ("O3")
#pragma GCC optimize("Ofast")
#pragma GCC target("avx2,fma")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#pragma GCC target ("avx2")
#pragma GCC optimization ("unroll-loops")
#pragma comment(linker, "/STACK: 20000000005")
*/
 
 
using namespace std;
 
const int N = 1000005, MOD = 1e9 + 7;
//998244353;
const int P = 31;
 
int PO[N];
 
int solve (string S){
    int n = (int)S.size();
    S = "#" + S;
    int a = 0, b = 0, x;
    int ans = 1;
    for (int i = 1; i <= n; i++){
        x = S[i] - 'a' + 1;
        a = a * P + x;
        a %= MOD;
        b = (b + x * PO[i - 1]) % MOD;
        if (a == b)
            ans = i;
    }
    return ans;
}
 
main()
{
    ios_base::sync_with_stdio(0);
    PO[0] = 1;
    for (int i = 1; i <= 1e6; i++)
        PO[i] = PO[i - 1] * P % MOD;
    int tes;
    cin >> tes;
    string S;
    int n;
    while (tes--){
        cin >> S;
        string s1 = S;
        n = (int)S.size();
        S = "#" + S;
        int l = 1, r = n;
        while (l < r && S[l] == S[r]){
            l++;
            r--;
        }
        if (l >= r){
            cout << s1 << endl;
            continue;
        }
        string s = "";
        for (int i = l; i <= r; i++)
            s += S[i];
        int pas1 = solve (s);
        reverse (s.begin(), s.end());
        int pas2 = solve (s);
        if (pas1 >= pas2)
            l += pas1;
        else
            r -= pas2;
        for (int i = 1; i <= n; i++)
            if (i < l || r < i)
                cout << S[i];
        cout << endl;
    }
    return 0;
}