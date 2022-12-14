#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn=2e5+10;
const int inf=0x3f3f3f3f;
const ll linf=0x3f3f3f3f3f3f3f3f;
const int mod=1e9+7;
int arr[maxn];
int n,k;

bool can()
{
    for(int i=k;i<n;i++)
    {
        if(arr[i]<arr[i-k])return 1;
        if(arr[i]>arr[i-k])return 0;
    }
    return 1;
}

void put()
{
    for(int i=0;i<n;i++)
    {
        printf("%d",arr[i%k]);
    }
}

int main()
{
//    freopen("in.txt","r",stdin);

    scanf("%d%d",&n,&k);
    for(int i=0;i<n;i++)
        scanf("%1d",arr+i);


    printf("%d\n",n);
    if(can())
    {
        put();
        return 0;
    }
    int key=k-1;
    while(1)
    {
        if(arr[key]!=9)
        {
            arr[key]++;
            break;
        }
        else
        {
            arr[key]=0;
            key--;
        }
    }
    put();
    return 0;
}