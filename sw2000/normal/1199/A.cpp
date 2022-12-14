#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int inf=0x3f3f3f3f;
const int maxn=1e5+10;

int main()
{
    int n,x,y;
    int arr[maxn];
    cin>>n>>x>>y;
    for(int i=1;i<=n;i++)cin>>arr[i];

    for(int i=1;i<=n;i++)
    {
        bool flag=1;
        for(int j=i-x;j<=i+y;j++)
        {
            if(j>0&&j<=n&&i!=j&&arr[i]>=arr[j])
            {
                flag=0;
                break;
            }
        }
        if(flag)
        {
            cout<<i;
            return 0;
        }
    }
}