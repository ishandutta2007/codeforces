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

const int N = 5e5 + 5;

int n;
pair < int, int > P[N];
int ans;

int main()
{
    ios::sync_with_stdio(false);
    cin>>n;
    for (int i = 1; i <= n; i++){
        string s;
        cin>>s;
        int x = 0, y = 0;
        for (int j = 0; j < (int)s.size(); j++){
            if (s[j] == '(')
                x++;
            else
                x--;
            y = min (y, x);
        }
        if (x < 0 && x != y)
            x = -10000000;
        if (x >= 0 && y < 0)
            x = -10000000;
        P[i].F = x;
        P[i].S = y;
    }
    sort (P + 1, P + n + 1);
    reverse (P + 1, P + n + 1);
    int I = n;
    for (int i = 1; i <= n && P[i].F >= 0; i++){
        if (P[i].S < 0)
            continue;
        while (P[i].F + P[I].F < 0)
            I--;
        if (P[i].F + P[I].F > 0)
            continue;
        while (P[i].F + P[I].S < 0 && P[I - 1].F + P[i].F == 0 && I > i)
            I--;
        if (I <= i)
            break;
        ans++;
        I--;
    }
    cout<<ans<<endl;
    return 0;
}