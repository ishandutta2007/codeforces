#include<stdio.h>
#include<iostream>
#include<string.h>
#include<stdlib.h>
#include<algorithm>
#include<vector>
using namespace std;
#define fr(i,n) for(int i=0;i<n;i++)
#define fo(i,n) for(int i=1;i<=n;i++)
#define fe(i,n) for(__typeof(n.begin()) i=n.begin();i!=n.end();i++)
typedef long long ll;
int a[100010],b[100010],q[100010],h,t,n;
long long f[100010];
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
		scanf("%d",&a[i]);
	for(int i=1;i<=n;i++)
		scanf("%d",&b[i]);
	q[++t]=1;
	h=1;
	for(int i=2;i<=n;i++)
	{
		while(h<t&&f[q[h+1]]-f[q[h]]<=(ll)a[i]*(b[q[h]]-b[q[h+1]]))
			h++;
		f[i]=(ll)a[i]*b[q[h]]+f[q[h]];
		while(h<t&&(double)(f[q[t]]-f[q[t-1]])/(b[q[t-1]]-b[q[t]])>=(double)(f[i]-f[q[t]])/(b[q[t]]-b[i]))
			t--;
		q[++t]=i;
	}
	printf("%I64d\n",f[n]);
	return 0;
}