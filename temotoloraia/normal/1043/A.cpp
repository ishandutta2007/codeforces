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
//#define temo

using namespace std;
const int N = 305;
int n, a[N];
int ans;
int main()
{
    cin>>n;
    for (int i = 1; i <= n; i++)
        cin>>a[i];
    sort (a + 1, a + n + 1);
    for (int i = 1; i <= n; i++)
        ans += 2 * a[i] - a[n];
    if (ans < 0){
        cout<<a[n]<<endl;
        return 0;
    }
    cout<<a[n] + (ans + n) / n<<endl;
    return 0;
}