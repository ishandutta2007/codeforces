//CF 833B
#include<iostream>
#include<cstdio>
#include<fstream>
#include<algorithm>
#include<vector>
#include<map>
#include<set>
#include<queue>
#include<cmath>
#include<cstring>
#include<cstdlib>
using namespace std;
typedef long long LL;
int a[35555],b[35555],c[35555];
int dp[35555][55];
int T[1111111],lazy[1111111];
void build(int i,int k,int l,int r){
	if(l>r)
		return;
	if(l==r){
		T[k]=dp[l][i];
		return;
	}
	int md;
	md=(l+r)/2;
	build(i,k*2,l,md);
	build(i,k*2+1,md+1,r);
	T[k]=max(T[k*2],T[k*2+1]);
}
void modify(int L,int R,int V,int k,int l,int r){
	if(L>R||L>r||l>R)
		return;
	if(L==l&&R==r){
		T[k]+=V;
		lazy[k]+=V;
		return;
	}
	if(lazy[k]){
		T[k*2]+=lazy[k];
		lazy[k*2]+=lazy[k];
		T[k*2+1]+=lazy[k];
		lazy[k*2+1]+=lazy[k];
		lazy[k]=0;
	}
	int md;
	md=(l+r)/2;
	modify(L,min(md,R),V,k*2,l,md);
	modify(max(L,md+1),R,V,k*2+1,md+1,r);
	T[k]=max(T[k*2],T[k*2+1]);
}
int query(int L,int R,int k,int l,int r){
	if(L>R||L>r||l>R)
		return 0;
	if(L==l&&R==r)
		return T[k];
	if(lazy[k]){
		T[k*2]+=lazy[k];
		lazy[k*2]+=lazy[k];
		T[k*2+1]+=lazy[k];
		lazy[k*2+1]+=lazy[k];
		lazy[k]=0;
	}
	int md,s;
	md=(l+r)/2;
	s=0;
	s=max(s,query(L,min(md,R),k*2,l,md));
	s=max(s,query(max(L,md+1),R,k*2+1,md+1,r));
	T[k]=max(T[k*2],T[k*2+1]);
	return s;
}
int main()
{
	int n,k,i,j;
	scanf("%d%d",&n,&k);
	for(i=1;i<=n;i=i+1){
		scanf("%d",a+i);
		if(!b[a[i]]){
			b[a[i]]=i;
			c[i]=0;
		}
		else{
			c[i]=b[a[i]];
			b[a[i]]=i;
		}
	}
	memset(dp,0,sizeof(dp));
	for(i=1;i<=n;i=i+1){
		if(c[i])
			dp[i][1]=dp[i-1][1];
		else
			dp[i][1]=dp[i-1][1]+1;
	}
	for(i=2;i<=k;i=i+1){
		memset(T,0,sizeof(T));
		memset(lazy,0,sizeof(lazy));
		//build(i-1,1,1,n);
		for(j=1;j<=n;j=j+1){
			//if(c[j])
			modify(max(1,c[j]),j-1,1,1,1,n);
			if(i<=j)
				dp[j][i]=T[1];//query(i-1,j-1,1,1,n);
			modify(j,j,dp[j][i-1],1,1,n);
			//cout<<dp[j][i]<<' ';
		}
		//cout<<endl;
	}
	cout<<dp[n][k]<<endl;
	return 0;
}
/*
*/