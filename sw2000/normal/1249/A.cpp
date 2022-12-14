#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn=2e5+10;
const int inf=0x3f3f3f3f;

int arr[maxn],brr[maxn],ans[maxn];

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        int arr[maxn]={0};
        for(int i=0;i<n;i++)
        {
            int a;
            cin>>a;
            arr[a]=1;
        }
        for(int i=1;i<110;i++)
        {
            if(arr[i]&&arr[i-1])
            {
                cout<<2<<endl;
                break;
            }
            if(i==105)
            {
                cout<<1<<endl;
            }
        }
    }
    return 0;
}