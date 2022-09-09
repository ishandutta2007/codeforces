#include <stdio.h>
#include <vector>
using namespace std;
#define mp make_pair
#define pb push_back
#define ll long long
const int N=200050;
int a[N],c[N],n,d,b;
int min(int a, int b){ return a>b?b:a;}
int Get(int l, int r){ return c[r]-c[l-1];}
bool Check(int mid)
{
	int i;
	/*for(i=1;i<=mid;i++) sum+=a[i];
	bool work=0;
	for(i=mid+1;i<=(n+1)/2;i++)
	{
		if(Get(1,i)<(i-mid)*b) work=1;
		//sum+=a[i];
		//if(sum<(i-mid)*b) break;
	}*/
	//if(!work)
	//{
		//printf("1:%i\n",mid);
		//int j=0;sum=0;int k=mid;
		int k=mid*d+mid;
		if(n<(ll)mid*d+mid) k=n;
		for(i=n-mid;i>(n+1)/2;i--)
		{
			k+=d;k++;
			k=min(n,k);
			//printf("%i %i %i %i\n",i,k,Get(n-k+1,n),(n-mid-i+1)*b);
			if(Get(n-k+1,n)<(n-mid-i+1)*b) return false;
			//if(j<n) while(j<min(d*k,n)) sum+=a[n-j],j++;
			//if(sum<(n-mid-i+1)*b) return false;
		}
	//}
	//else
	//{
		//printf("2:%i\n",mid);
		//int j=0;sum=0;int k=mid;
		k=mid*d+mid;
		if(n<(ll)mid*d+mid) k=n;
		for(i=mid+1;i<=(n+1)/2;i++)
		{
			k+=d;k++;
			k=min(k,n);
			if(Get(1,k)<(i-mid)*b) return false;
			//if(j<n) while(j<min(d*k,n)) sum+=a[j+1],j++;
			//if(sum<(i-mid)*b) return false;
		}
	//}
	return true;
}
int main()
{
	scanf("%i %i %i",&n,&d,&b);
	int i;
	for(i=1;i<=n;i++) scanf("%i",&a[i]);
	for(i=1;i<=n;i++) c[i]=c[i-1]+a[i];
	int top=n/2,bot=0,mid,ans=n/2+1;
	while(top>=bot)
	{
		mid=top+bot>>1;
		if(Check(mid)) ans=mid,top=mid-1;
		else bot=mid+1;
	}
	printf("%i\n",ans);
	return 0;
}