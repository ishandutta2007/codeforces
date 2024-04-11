#include<bits/stdc++.h>
using namespace std;
 
int a[100005],b[100005];
int d[100005];
bool cmp(int a,int b)
{
    return a>b;
}
int main()
{
    int n,m;
    long long sum=0,sum2=0;
    cin>>n>>m;
    for(int i=0;i<n;i++)
    {
        cin>>a[i]>>b[i];
        d[i]=a[i]-b[i];
        sum+=a[i];sum2+=b[i];
    }
    if(sum<=m){printf("0");return 0;}
    if(sum2>m){printf("-1");return 0;}
    sort(d,d+n,cmp);
    long long t=sum-m;
    int ans=0;
    for(int i=0;i<n;i++)
    {
		t-=d[i];
        ans++;
        if(t<=0)break;
    }
    printf("%d",ans);
}