#include <bits/stdc++.h>
#define F first
#define S second
#define mp make_pair
#define pb push_back
#define ll long long
#define LEFT(a) ((a)<<1)
#define RIGHT(a) (LEFT(a) + 1)
#define MID(a,b) ((a+b)>>1)
#define MAX(a,b) ((a)>(b)?(a):(b))
#define MIN(a,b) ((a)<(b)?(a):(b))
using namespace std;

const int N = 2100000;

vector < int > Z (string s){
    int n = (int)s.size();
    int l = 0, r = 0;
    vector < int > z (n, 0);
    for (int i = 1; i < n; i++){
        if (i <= r)
            z[i] = min (z[i - l], r - i + 1);
        while (i + z[i] < n && s[i + z[i]] == s[z[i]])
            z[i]++;
        if (i + z[i] - 1 > r)
            l = i, r = i + z[i] - 1;
    }
    return z;
}

int n, a, b;

string s, ss;

vector < int > z;

int d[N], dp[N];



int main()
{
    ios_base::sync_with_stdio(false);
    cin >> n >> a >> b;
    cin >> s;
    for (int i = 1; i < n; i++){
        ss = "";
        for (int j = i; j < i + n; j++)
            ss += s[j % n];
        vector < int > v = Z (ss);
        reverse (v.begin(), v.end());
        for (int j = 0; j < i; j++)
            d[i] = max (d[i], v[j]);
    }
    dp[0] = a;
    //cout << d[2] << endl;
    for (int i = 1; i < n; i++){
        dp[i] = dp[i - 1] + a;
        for (int j = 0; j <= i - 1; j++){
            //if (i == n - 1)
            //cout << i << " " << j << " " << d[j + 1]<< endl;
            if (j + d[j + 1] >= i)
                dp[i] = min (dp[i], dp[j] + b);
        }
        //cout << dp[i] << endl;
    }
    cout << dp[n - 1] << endl;
    return 0;
}