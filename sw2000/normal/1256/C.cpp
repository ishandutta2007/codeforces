#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn=1e3+10;
const int inf=0x3f3f3f3f;
const ll mod=1e9+7;
 
int arr[maxn];
 
int main()
{
    int n,m,d,sum=0;
    cin>>n>>m>>d;
    for(int i=0;i<m;i++)
    {
        cin>>arr[i];
        sum+=arr[i];
    }
    if(sum+(d-1)*(m+1)<n)
    {
        puts("NO");
        return 0;
    }
    puts("YES");
    sum=n-sum;
 
    int x=sum/(m+1),y=sum%(m+1);
    for(int i=0;i<m;i++)
    {
        for(int j=0;j<x;j++)
        {
            printf("0 ");
        }
        if(i<y)printf("0 ");
        for(int j=0;j<arr[i];j++)
        {
            printf("%d ",i+1);
        }
    }
    for(int i=0;i<x;i++)
        printf("0 ");
 
    return 0;
}