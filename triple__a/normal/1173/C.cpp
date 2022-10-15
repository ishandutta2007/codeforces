#include<algorithm>
#include<cmath>
#include<iostream>
#include<cstdio> 
#include<algorithm>
using namespace std;

const int maxn=200007;

int n;
int a[maxn],b[maxn],ans[maxn],sum[maxn];

int consec(){
	int u=b[n],ans=u;
	for (int i=n;u>0;i--){
		if (b[i]!=u){
			return 0;
		}
		u--;
	}
	return ans;
}

int main(){
	scanf("%d",&n);
	for (int i=1;i<=n;++i){
		scanf("%d",&a[i]);
	}
	for (int i=1;i<=n;++i){
		scanf("%d",&b[i]);
	}
	sum[0]=0;
	for (int i=1;i<=n;++i){
		if (b[i]){
			ans[b[i]]=i; 
		}
		if (a[i]){
			sum[a[i]]=1;
		}
	}
	for (int i=1;i<=n;++i){
		sum[i]+=sum[i-1];
	}
	int ret=consec(),min_extract=0;
	if (ret>0){
		bool flag=true;
		for (int i=ret+1;i<=n;++i){
			if (ans[i]>=i-ret){
				flag=false;
			}
		}
		if (flag){
			printf("%d\n",n-ret);
			return 0;
		}
	}
	for (int i=1;i<=n;++i){
		min_extract=max(min_extract,ans[i]-i+1);
	}
	printf("%d\n",min_extract+n);
	return 0;
}