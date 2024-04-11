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
#include <functional>
typedef long long ll;
#define mm(a) memset(a,0,sizeof(a))
#define lr rt<<1
#define rr rt<<1|1
#define tm(a,b,c) max(max(a,b),c)
#define inf 0x3f3f3f3f
const ll Mod=1e9+7;
using namespace std;
int dd[4][2]={{1,0},{0,1},{-1,0},{0,-1}};
bool cmp(int a,int b)
{
    return a>b;
}
int main()
{
    ios::sync_with_stdio(false);
    int q;
    scanf("%d",&q);
    while(q--)
    {
        int n;
        scanf("%d",&n);
        int*a = new int[n+1]();
        int b;
        int sum=0;
        for(int i=1;i<=n;i++)
        {
            scanf("%d",&b);
            a[b]++;
        }
        sort(a+1,a+n+1,cmp);
        int z=200005;
        for(int i=1;i<=n;i++)
        {
            z=min(a[i],z);
            sum+=z;
            //            cout<<z<<' ';
            z--;
            if(z<=0||a[i]==0)
                break;
        }
        cout<<sum<<endl;
        delete []a;
        //                for(int i=0;i<n;i++)
        //                {
        //                    cout<<a[i]<<' ';
        //                }
        //                cout<<endl;
    }
    return 0;
}