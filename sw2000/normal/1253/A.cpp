#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn=1e5+10;
int arr[maxn],brr[maxn],n;

bool can()
{
    for(int i=0;i<n;i++)
    {
        if(brr[i]<0)return 0;
        if(brr[i])
        {
            for(int j=i+1;j<n;j++)
            {
                if(brr[j]==brr[i])
                {
                    brr[j]=0;
                }
                else
                {
                    break;
                }
            }
            brr[i]=0;
            break;
        }
    }
    for(int i=0;i<n;i++)
    {
        if(brr[i])return 0;
    }
    return 1;
}

int main()
{
    //freopen("in.txt","r",stdin);
    int t;
    cin>>t;
    while(t--)
    {
        scanf("%d",&n);
        for(int i=0;i<n;i++)
        {
            scanf("%d",&arr[i]);
        }
        for(int i=0;i<n;i++)
        {
            scanf("%d",&brr[i]);
            brr[i]-=arr[i];
        }
        if(can())puts("YES");
        else puts("NO");

    }
    return 0;
}