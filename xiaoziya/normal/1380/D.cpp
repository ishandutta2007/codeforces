#include<stdio.h>
#include<iostream>
using namespace std;
const int maxn=200005;
int n,m,x,k,y;
long long ans;
int a[maxn],b[maxn];
int main(){
	scanf("%d%d%d%d%d",&n,&m,&x,&k,&y);
	for(int i=1;i<=n;i++)
		scanf("%d",&a[i]);
	for(int i=1;i<=m;i++)
		scanf("%d",&b[i]);
	int lst=0;
	for(int i=1,j=1;i<=m+1;i++){
		while(j<=n&&a[j]!=b[i])
			j++;
		if(i<=m&&j>n){
			puts("-1");
			return 0;
		}
		//(lst,j)
		int len=j-lst-1,mx=0;
		for(int k=lst;k<=j;k++)
			mx=max(mx,a[k]);
		if(mx==a[lst]||mx==a[j])
			ans+=min(1ll*len*y,1ll*(len/k)*x+1ll*(len%k)*y);
		else{
			if(len<k){
				puts("-1");
				return 0;
			}
			ans+=x+1ll*(len%k)*y+min(1ll*(len/k-1)*k*y,1ll*(len/k-1)*x);
		}
		lst=j;
	}
	printf("%lld\n",ans);
	return 0;
}