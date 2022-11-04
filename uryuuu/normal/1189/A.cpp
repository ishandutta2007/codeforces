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
#define maxn 11000
using namespace std;
int dd[4][2]={{1,0},{0,1},{-1,0},{0,-1}};
char a[105];
int main()
{
    int n;
    cin>>n;
    int q=0,w=0;
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
        if(a[i]=='1')
            q++;
        if(a[i]=='0')
            w++;
    }
    if(q!=w)
    {
        cout<<1<<endl;
        for(int i=0;i<n;i++)
        {
            cout<<a[i];
        }
        cout<<endl;
    }
    else
    {
        cout<<2<<endl;
        int qq=0,ww=0;
        int j;
        for(j=0;j<n-1;j++)
        {
            cout<<a[j];
            if(a[j]=='1')
                qq++;
            if(a[j]=='0')
                ww++;
            if(q-qq!=w-ww&&(a[j+1]=='1'||j==n-2))
               {
                   cout<<' ';
                   break;
               }
        }
               for(int i=j+1;i<n;i++)
               cout<<a[i];
               cout<<endl;
    }
    return 0;
}