#include<iostream>
#include<cstring>
#include<stdio.h>
#include<math.h>
#include<queue>
#include<vector>
using namespace std;
#define pb push_back
#define clr(i) memset(i,0,sizeof(i))

typedef long long ll;

int a[100005];
int main()
{
    int n;cin>>n;
    int M = 0;
    for(int i=1;i<=n;++i) {cin>>a[i];M=max(M,a[i]);}
    int cnt = 0, ans = 0;
    for(int i=1;i<=n;++i)
    {
        if(a[i]==M) cnt++,ans=max(ans,cnt);
        else cnt = 0;
    }
    cout << ans << endl;

}