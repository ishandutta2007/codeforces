#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

bool cmp(int a,int b)
{
    return a>b;
}

int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        int n,arr[1010];
        cin>>n;
        for(int i=0;i<n;i++)
        {
            cin>>arr[i];
        }
        sort(arr,arr+n,cmp);
        int ans=0;
        for(int i=0;i<n;i++)
        {
            if(arr[i]<i+1)break;
            ans=i+1;
        }
        cout<<ans<<endl;
    }
}