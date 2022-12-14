#include <bits/stdc++.h>
using namespace std;
const int N=1e2+10;
typedef long long ll;

int arr[N];

int main()
{
//    freopen("in.txt","r",stdin);
    int _;cin>>_;
    while(_--)
    {
        int n,sum=0;
        scanf("%d",&n);
        for(int i=0;i<n;i++)
        {
            scanf("%d",arr+i);
            sum+=arr[i];
        }

        sort(arr,arr+n);
        if(arr[n-1]>sum/2||sum%2)puts("T");
        else puts("HL");
    }
    return 0;
}