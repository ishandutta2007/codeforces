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

int n;
int a[100];

string ans = "NO";
void go (int k, int S){
    S = (S % 360 + 360) % 360;
    if (k > n){
        if (S == 0)
            ans = "YES";
        return;
    }
    go (k + 1, S + a[k]);
    go (k + 1, S - a[k]);
}

int main()
{
    ios::sync_with_stdio(false);
    cin>>n;
    for (int i = 1; i <= n; i++)
        cin>>a[i];
    go (1, 0);
    cout<<ans<<endl;
    return 0;
}