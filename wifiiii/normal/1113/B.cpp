#include<iostream>
#include<stdio.h>
#include<cstring>
#include<string>
#include<vector>
#include<queue>
#include<cmath>
#include<algorithm>
#include<set>
#include<ctime>
using namespace std;
#define pb push_back
#define clr(i) memset(i,0,sizeof(i))

typedef long long ll;
typedef vector<int> vec;
typedef pair<ll,ll> pii;

int a[105];
int main()
{
    int n;cin>>n;
    int m = 1e9, sum = 0;
    for(int i=1;i<=n;++i)
    {
        int t;cin>>t;
        m = min(t,m);
        sum += t;
        a[t]++;
    }
    int ans = sum, minn = 1e9;
    for(int i=1;i<=100;++i)
    {
        if(!a[i]) continue;
        for(int j=2;j*j<=i;++j)
        {
            if(i%j) continue;
            if(i/j+m*j-i-m<minn) minn=i/j+m*j-i-m,ans=min(ans,sum+(i/j+m*j-i-m));
        }
    }
    cout << ans << endl;
}