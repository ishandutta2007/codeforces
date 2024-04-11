#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn=2e5+10;
const int inf=0x3f3f3f3f;

int arr[maxn];

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int h,n,ans=0;
        cin>>h>>n;
        for(int i=0;i<n;i++)
            cin>>arr[i];
        int len=0;
        arr[n]=0;

        for(int i=1;i<n;i++)
        {
            len++;
            if(arr[i]!=arr[i+1]+1)
            {
                if(len%2&&arr[i]!=1)ans++;
                len=0;
            }
        }
        cout<<ans<<endl;
    }
    return 0;
}