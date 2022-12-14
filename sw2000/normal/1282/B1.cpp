#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int inf=0x3f3f3f3f;
const ll linf=0x3f3f3f3f3f3f3f3f;
const int maxn=2e5+10;
const ll mod=1e9+7;
int arr[maxn];

int main()
{
//    freopen("in.txt","r",stdin);
    int a,b,c,d;
    int t;
    cin>>t;
    while(t--)
    {
        int n,p,k;
        scanf("%d%d%d",&n,&p,&k);
        for(int i=0;i<n;i++)
            scanf("%d",arr+i);
        sort(arr,arr+n);
        for(int i=k;i<n;i++)
        {
            arr[i]+=arr[i-k];
        }
        arr[n]=inf*2;
        if(arr[0]>p)
        {
            printf("0\n");
            continue;
        }
        for(int i=0;i<n;i++)
        {
            if(arr[i]<=p&&arr[i+1]>p)
            {
                printf("%d\n",i+1);
                break;
            }
        }
    }
    return 0;
}