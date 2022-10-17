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
#define int ll
int a[200005],l[100005],r[100005];
int32_t main()
{
    int n;
    cin>>n;
    for(int i=1;i<=2*n;++i) cin>>a[i];
    for(int i=1;i<=2*n;++i)
    {
        if(l[a[i]]) r[a[i]] = i;
        else l[a[i]] = i;
    }
    int ans = 0;
    l[0] = r[0] = 1;
    for(int i=0;i<n;++i)
    {
        ans += min(abs(l[i+1]-l[i])+abs(r[i+1]-r[i]),abs(r[i+1]-l[i])+abs(l[i+1]-r[i]));
    }
    cout << ans << endl;
}