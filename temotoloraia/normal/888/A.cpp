#include <bits/stdc++.h>
#define F first
#define S second
#define mp make_pair
#define pb push_back
#define ll long long int
#define LEFT(a) ((a)<<1)
#define RIGHT(a) (LEFT(a) + 1)
#define MID(a,b) ((a+b)>>1)
#define MAX(a,b) ((a)>(b)?(a):(b))
#define MIN(a,b) ((a)<(b)?(a):(b))
using namespace std;
int n;
int a[10005];
int main()
{
    cin>>n;
    for (int i = 1; i <= n; i++)
        cin>>a[i];
    int ans = 0;
    for (int i = 2; i < n; i++)
        if ((a[i] > a[i - 1] && a[i] > a[i + 1]) || (a[i] < a[i - 1] && a[i] < a[i + 1]))
            ans++;
    cout<<ans<<endl;
    return 0;
}