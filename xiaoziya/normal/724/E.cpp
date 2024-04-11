#include<bits/stdc++.h>
using namespace std;
const int maxn=100005;
int n,c;
int a[maxn],b[maxn];
long long val[maxn];
long long mn,sum;
int main(){
	scanf("%d%d",&n,&c);
	for(int i=1;i<=n;i++)
		scanf("%d",&a[i]);
	for(int i=1;i<=n;i++)
		scanf("%d",&b[i]);
	for(int i=1;i<=n;i++)
		sum+=b[i],val[i]=a[i]-b[i]+1ll*(i-1)*c;
	sort(val+1,val+1+n);
	long long now=0;
	mn=sum;
	for(int i=1;i<=n;i++)
		now+=val[i],mn=min(mn,sum+now-1ll*i*(i-1)/2*c);
	printf("%lld\n",mn);
	return 0;
}