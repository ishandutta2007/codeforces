#include<stdio.h>
#include<iostream>
#include<string.h>
#include<stdlib.h>
#include<algorithm>
#include<vector>
#define X first
#define Y second
using namespace std;
#define fr(i,n) for(int i=0;i<n;i++)
#define fo(i,n) for(int i=1;i<=n;i++)
#define fe(i,n) for(__typeof(n.begin()) i=n.begin();i!=n.end();i++)
long long k[100020];
long long b[100020];
typedef pair<long long,long long>LL;
LL a[100020];
int n,z;
bool cmp(const LL&a,const LL&b)
{
    return -(double)a.X/a.Y<-(double)b.X/b.Y;
}
int main()
{
    scanf("%d",&n);
    for(int i=0;i<n;i++)
    {
        scanf("%I64d%I64d",k+i,b+i);
        if(k[i]==0)
        {
            i--;
            n--;
            continue;   
        }
        a[i].X=b[i];
        a[i].Y=k[i];
    }
    sort(a,a+n,cmp);
    int j;
    for(int i=0;i<n;i=j)
    {
        for(j=i;j<n&&a[i].X*a[j].Y==a[j].X*a[i].Y;j++)
            ;
        z++;
    }
    printf("%d",z);
    return 0;
}