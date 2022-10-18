#include<bits/stdc++.h>
#define N 105

int n;

int c[N][N];
std::set<int> s[N];
inline void ins(int i,int x){
	if(c[i][x]++==1)
		s[i].insert(x);
}
inline void ers(int i,int x){
	if(--c[i][x]==1)
		s[i].erase(x);
}

int a[N];

std::vector<std::vector<int>> ans;

int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++) for(int j=1;j<=n;j++){
		int x;
		scanf("%d",&x);
		ins(i,x);
	}
	while(1){
		for(int i=1;i<=n;i++)
			a[i]=s[i].size()?*s[i].begin():0;
		for(int i=2;i<=n;i++) if(!a[i])
			a[i]=a[i-1];
		if(!a[1])
			a[1]=a[n];
		for(int i=2;i<=n;i++) if(!a[i])
			a[i]=a[i-1];
		if(!a[n])
			break;
		ans.emplace_back(a+1,a+n+1);
		for(int i=1;i<=n;i++)
			ers(i,a[i]);
		for(int i=1;i<=n;i++)
			ins(i,a[i==1?n:i-1]);
	}
	printf("%d\n",(int)ans.size()+n*(n-1)/2);
	for(auto &i:ans){
		for(auto j:i)
			printf("%d ",j);
		puts("");
	}
	for(int i=1;i<n;i++) for(int j=i;j;j--){
		for(int k=1;k<=n;k++)
			printf("%d ",(k+j-1)%n+1);
		puts("");
	}
}