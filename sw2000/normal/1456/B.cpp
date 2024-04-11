#include<bits/stdc++.h>
#define fi first
#define se second
using namespace std;
typedef long long ll;
typedef vector<int>vi;
typedef pair<int, int>pii;
const int inf = 0x3f3f3f3f;
const int N = 1e5 + 10;
const int mod=1e9+7;
int n,arr[N];
int main()
{
    ios::sync_with_stdio(0), cin.tie(0);
//    freopen("in.txt", "r", stdin);
    cin>>n;
    for(int i=1;i<=n;i++)
        cin>>arr[i];
    for(int i=2;i<n;i++)
    {
        if( (arr[i]^arr[i+1])<arr[i-1] )
        {
            cout<<1;
            return 0;
        }
    }
    int ans=n;
    for(int i=1;i<n;i++)
    {
        int l=0;
        for(int j=i;j;j--)
        {
            l^=arr[j];
            int r=0;
            for(int k=i+1;k<=n;k++)
            {
                r^=arr[k];
                if(r<l)
                {
                    ans=min(ans,k-j-1);
                }
            }
        }
    }

    cout<<(ans==n?-1:ans);
    return 0;
}