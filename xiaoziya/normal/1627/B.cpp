#include<stdio.h>
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
const int maxn=500005;
int n,m,T,ans;
int tot[maxn];
string s;
int main(){
	scanf("%d",&T);
	while(T--){
		ans=0;
		scanf("%d%d",&n,&m);
		int now=n+m;
		for(int x=1;x<=n;x++)
			for(int y=1;y<=m;y++)
				tot[max(max(x-1+y-1,x-1+m-y),max(n-x+y-1,n-x+m-y))]++,now=min(now,max(max(x-1+y-1,x-1+m-y),max(n-x+y-1,n-x+m-y)));
		for(int i=0,s=0;i<n*m;i++){
			if(i>=s+tot[now])
				s+=tot[now],now++;
			printf("%d ",now);
		}
		puts("");
		for(int i=0;i<=n+m;i++)
			tot[i]=0;
	}
	return 0;
}