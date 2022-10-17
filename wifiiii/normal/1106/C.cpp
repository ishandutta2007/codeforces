#include<iostream>
#include<stdio.h>
#include<cstring>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;
#define pb push_back
#define clr(i) memset(i,0,sizeof(i))

typedef pair<int,int> pii;
typedef long long ll;

ll a[300005];
int main()
{
    int n;cin>>n;
    for(int i=1;i<=n;++i) cin>>a[i];
    sort(a+1,a+1+n);
    ll ans = 0;
    for(int i=1;i<=n/2;++i)
    {
        ans += (a[i]+a[n-i+1])*(a[i]+a[n-i+1]);
    }
    cout << ans << endl;
}