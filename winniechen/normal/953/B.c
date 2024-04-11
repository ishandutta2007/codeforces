#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>
#define N 1000005
int a[N],n,last;
int gcd(int a,int b)
{
	if(!b)return a;
	return gcd(b,a%b);
}
int t[N];
void hebing(int l,int mid,int r)
{
    int i=l,j=mid+1,T=l;
    int cnt=1;
    while(T<=r)
    {
        if(i<=mid&&(j>r||a[i]<=a[j]))
        {
            t[cnt]=a[i];
            i++,cnt++;
            T++;
        }else
        {
            t[cnt]=a[j];
            j++,cnt++;
            T++;
        }
    }
    for(int i=l,cnt=1;i<=r;i++,cnt++)
    {
        a[i]=t[cnt];
    }
    return ;
}
void fenzhi(int l,int r)
{
    if(l<r)
    {
        int mid=(l+r)>>1;
        fenzhi(l,mid);
        fenzhi(mid+1,r);
        hebing(l,mid,r);
    }
    return ;
}
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&a[i]);
	}
	fenzhi(1,n);
	for(int i=2;i<=n;i++)
	{
		if(i==2)last=t[2]-t[1];
		last=gcd(t[i]-t[i-1],last);
	}
	int ans=0;
	for(int i=2;i<=n;i++)
	{
		ans+=((t[i]-t[i-1])/last)-1;
	}
	printf("%d\n",ans);
	return 0;
}