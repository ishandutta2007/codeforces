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

const int N = 1e5 + 5;

int n, k;
string S;
int a[26];

int main()
{
    ios_base::sync_with_stdio(false);
    cin >> n >> k >> S;
    int t = 0;
    S = "#" + S;
    for (int i = 1; i <= n; i++){
        if (S[i] == S[i - 1])
            t++;
        else
            t = 1;
        if (t >= k){
            t = 0;
            a[S[i] - 'a']++;
        }
    }
    int ans = 0;
    for (int i = 0; i < 26; i++)
        ans = max (ans, a[i]);
    cout << ans << endl;
    return 0;
}