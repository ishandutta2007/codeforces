#include<bits/stdc++.h>
using namespace std;
const int maxn=1000005;
int n,c,T,flg;
int a[maxn],vis[maxn],sum[maxn];
string s;
int main(){
	scanf("%d",&T);
	while(T--){
		flg=0;
		scanf("%d%d",&n,&c);
		for(int i=1;i<=n;i++)
			scanf("%d",&a[i]),vis[a[i]]=1;
		for(int i=1;i<=c;i++)
			sum[i]=sum[i-1]+vis[i];
		for(int i=1;i<=c;i++)
			for(int j=i;j<=c;j+=i)
				if(vis[i]==1&&sum[min(c,j+i-1)]-sum[j-1]>0&&vis[j/i]==0)
					flg=1;
		puts(flg==0? "Yes":"No");
		for(int i=1;i<=c;i++)
			vis[i]=sum[i]=0;
	}
	return 0;
}