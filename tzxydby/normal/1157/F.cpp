#include<bits/stdc++.h>
using namespace std;
const int N=200005;
int n,a[N],b[N],l,q,w,x;
int main()
{
    scanf("%d",&n);
    for(int i=0;i<n;i++)
	{
        int x;
        scanf("%d",&x);
        a[x]++;
    }
    for(int i=1;i<N;i++)
		b[i]=b[i-1]+a[i];
    int l=0,x=0,q=0,w=0;
    for(int i=1;i<N;i++)
	{
        if(a[i]<2)
		{
            if(b[i]-b[max(l-1,0)]>x)
				x=b[i]-b[max(l-1,0)],q=l,w=i;
            l=i;
        }
    }
    printf("%d\n",x);
    for(int i=q;i<=w;i++)
		if(a[i])
			printf("%d ",i);
    for(int i=w;i>=q;i--)
		for(int j=0;j<a[i]-1;j++)
			printf("%d ",i);
	return 0;
}