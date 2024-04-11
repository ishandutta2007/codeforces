#include<iostream>
#include<stdio.h>
#include<cstring>
#include<string>
#include<vector>
#include<queue>
#include<algorithm>
using namespace std;
#define pb push_back
#define clr(i) memset(i,0,sizeof(i))

typedef pair<int,int> pii;
typedef long long ll;

ll a[2555555][2];
int pre;
int main()
{
    int n;cin>>n;
    int temp = 0;
    a[0][0]++;
    for(int i=1;i<=n;++i)
    {
        int t;
        cin>>t;
        pre = pre ^ t;
        if(i%2==0)
            a[pre][0]++;
        else a[pre][1]++;
    }
    ll ans = 0;
    for(int i=0;i<=2555550;++i)
    {
        ll temp = a[i][0];
        ans += temp * (temp-1) / 2;
        temp = a[i][1];
        ans += temp * (temp-1) / 2;
    }
    cout << ans << endl;
}