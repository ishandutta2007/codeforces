#include<cstdio>
#include<iostream>
using namespace std;
int T;
int n,a[500010],c[500010],b[500010];
long long ans;

void msort(int b,int e)//
{
    if(b==e)  
		return;
    int mid=(b+e)/2,i=b,j=mid+1,k=b;
    msort(b,mid),msort(mid+1,e);
    while(i<=mid&&j<=e)
    	if(a[i]<=a[j])
    		c[k++]=a[i++];
    	else
    		c[k++]=a[j++],ans+=mid-i+1;//
    while(i<=mid)
    	c[k++]=a[i++];
    while(j<=e)
    	c[k++]=a[j++];
    for(int l=b;l<=e;l++)
    	a[l]=c[l];
} 

int main()
{
	scanf("%d",&T);
	while(T--)
	{
    	scanf("%d",&n); 
    	for(int i=1;i<=n;i++)
    	{
    		scanf("%d",&a[i]),b[a[i]]++;
    	}
    	int f=0;
    	for(int i=1;i<=n;i++)
    	{
    		if(b[i]>1)
    			f=1;
    		b[i]=0;
    	}
    	if(f){
    		puts("YES");
    		continue;
    	}
		ans=0;
    	msort(1,n);
    	puts(ans%2==0? "YES":"NO");
    }
    return 0;
}