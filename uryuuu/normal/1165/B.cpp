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
typedef long long ll;
#define mm(a) memset(a,0,sizeof(a))
#define lr rt<<1
#define rr rt<<1|1
int dd[4][2]={{1,0},{0,1},{-1,0},{0,-1}};
using namespace std;
int a[200010];
int main()
{
    mm(a);
    int n;
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        scanf("%d",&a[i]);
    }
    sort(a+1,a+n+1);
    int s=0;
    int v[200010];
    mm(v);
    int j=1;
    for(int i=1;i<=n;i++)
    {
        while(a[j]<i&&j<=n)
            j++;
        if(j>n)
            break;
        if(a[j]>=i)
        {
            s++;
            j++;
        }
    }
    cout<<s<<endl;
    return 0;
}