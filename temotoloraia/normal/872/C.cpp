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
const int MAXN = 100000;
int ans;
void solve (int n){
    if (n % 2 == 1 && n < 9){
        ans = - 1;
        return;
    }
    if (n % 2 == 1){
        ++ans;
        solve (n - 9);
        return;
    }
    if (n == 2){
        ans = - 1;
        return;
    }
    ans += n / 4;
    return;
}
int main()
{
    int t;
    cin>>t;
    while (t--){
        int n;
        cin>>n;
        ans = 0;
        solve (n);
        cout<<ans<<endl;
    }
    return 0;
}