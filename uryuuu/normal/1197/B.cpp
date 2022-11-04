#include<iostream>
#include<cstdio>
#include<vector>
#include<algorithm>
#include<cstring>
#include<cmath>
#include<queue>
#include<string>
#include<stack>
#include<set>
#include<map>
#include<sstream>
typedef long long ll;
#define mm(a) memset(a,0,sizeof(a))
#define lr rt<<1
#define rr rt<<1|1
#define tm(a,b,c) max(max(a,b),c)
#define inf 0x3f3f3f3f
const ll Mod=1e9+7;
#define maxn 20010
using namespace std;
int dd[4][2]={{1,0},{0,1},{-1,0},{0,-1}};
int a[200005];
int main()
{
    int n;
    cin>>n;
    for(int i=0;i<n;i++)
    {
        scanf("%d",&a[i]);
    }
    for(int i=1;i<n;i++)
    {
        if(a[i]==n||a[0]==n)
            break;
        if(a[i]<a[i-1]&&a[i-1]!=n)
        {
            cout<<"NO"<<endl;
            return 0;
        }
    }
    for(int i=n-2;i>=0;i--)
    {
        if(a[i]==n||a[n-1]==n)
            break;
        if(a[i]<a[i+1]&&a[i+1]!=n)
        {
            cout<<"NO"<<endl;
            return 0;
        }
    }
    cout<<"YES"<<endl;
    return 0;
}