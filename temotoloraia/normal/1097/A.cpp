#include <bits/stdc++.h>
#pragma GCC optimize("O3")
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

const int N = 1e6 + 5;

string S, s[5];

int main()
{
    ios::sync_with_stdio(false);
    cin>>S;
    string ans = "NO";
    for (int i = 0; i < 5; i++){
        cin>>s[i];
        if (s[i][0] == S[0] || s[i][1] == S[1])
            ans = "YES";
    }
    cout<<ans<<endl;
    return 0;
}