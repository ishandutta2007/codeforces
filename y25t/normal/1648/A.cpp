#include<bits/stdc++.h>
#define N 100005

int n,m;

std::vector<int> A[N],B[N];

int main(){
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++){
			int x;
			scanf("%d",&x);
			A[x].push_back(i),B[x].push_back(j);
		}
	long long ans=0;
	for(int i=1;i<=100000;i++)
		for(int o=0;o<2;o++){
			std::sort(A[i].begin(),A[i].end());
			for(int j=0;j<(int)A[i].size()-1;j++)
				ans+=1ll*(A[i][j+1]-A[i][j])*(j+1)*((int)A[i].size()-j-1);
			std::swap(A[i],B[i]);
		}
	printf("%lld\n",ans);
}