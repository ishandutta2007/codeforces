#include<bits/stdc++.h>
#define ll long long

int n,k,t;

struct node{
	ll a[1<<9][1<<9];
	node(){
		memset(a,0,sizeof(a));
	}
}A,B;
node operator * (node x,node y){
	node z;
	for(int i=0;i<n;i++) for(int j=0;j<n;j++) if(x.a[i][j])
		for(int u=0;u<n;u++) for(int v=0;v<n;v++)
			z.a[(i+u)&(n-1)][(j+v)&(n-1)]^=x.a[i][j]*y.a[u][v];
	return z;
}

int main(){
	scanf("%d",&k);
	n=1<<k;
	for(int i=0;i<n;i++) for(int j=0;j<n;j++)
		scanf("%lld",&A.a[i][j]);
	scanf("%d",&t);
	while(t--){
		int x,y;
		scanf("%d%d",&x,&y);
		B.a[x-1][y-1]^=1;
	}
	for(int i=0;i<k;i++)
		A=B*A,B=B*B;
	int res=0;
	for(int i=0;i<n;i++) for(int j=0;j<n;j++) if(A.a[i][j])
		res++;
	printf("%d\n",res);
}