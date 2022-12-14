#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn=1e5+10;
const int inf=0x3f3f3f3f;
const int mod=1e9+7;
const ll linf=0x3f3f3f3f3f3f3f3f;
int arr[maxn];
int main()
{
//    freopen("in.txt","r",stdin);
    int t;
    for(scanf("%d",&t);t--;)
    {
        int n,s;
        cin>>n>>s;
        for(int i=0;i<n;i++)scanf("%d",arr+i);
        int ma=0,id=0;
        if(arr[0]>s)
        {
            cout<<1<<endl;
            continue;
        }
        for(int i=0;i<n;i++)
        {
            if(arr[i]>s)
            {
                if(arr[i]>ma)cout<<i+1<<endl;
                else cout<<id<<endl;
                break;
            }
            s-=arr[i];
            if(arr[i]>ma)
            {
                ma=arr[i];
                id=i+1;
            }
            if(i==n-1)
            {
                cout<<0<<endl;
            }
        }
    }
    return 0;
}