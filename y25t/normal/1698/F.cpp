#include<bits/stdc++.h>
#define N 505

int T;

int n,a[N],b[N];

std::vector<std::pair<int,int>> ans;
inline void op(int l,int r){
	ans.emplace_back(l,r),std::reverse(a+l,a+r+1);
}

inline void sol(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
		scanf("%d",&a[i]);
	for(int i=1;i<=n;i++)
		scanf("%d",&b[i]);
	ans.clear();
	#define NO return puts("No"),void()
	for(int i=1;i<n;i++){
		if(a[i]!=b[i])
			NO;
		if(a[i+1]!=b[i+1])
			for(int j=i+1;j<=n&&a[i+1]!=b[i+1];j++) if(a[j]==b[i]&&a[j-1]==b[i+1])
				op(i,j);
		if(a[i+1]!=b[i+1]){
			int o=0;
			for(int j=i;j<n&&!o;j++) if(a[j]==b[i]&&a[j+1]==b[i+1])
				o=j;
			if(!o)
				NO;
			for(int j=i,flg=0;j<=o&&!flg;j++) for(int k=o+1;k<=n&&!flg;k++) if(a[j]==a[k])
				flg=1,op(j,k);
			for(int j=i+1;j<=n&&a[i+1]!=b[i+1];j++) if(a[j]==b[i]&&a[j-1]==b[i+1])
				op(i,j);
		}
	}
	if(a[n]!=b[n])
		NO;
	puts("Yes");
	printf("%d\n",(int)ans.size());
	for(auto [i,j]:ans)
		printf("%d %d\n",i,j);
}

int main(){
	scanf("%d",&T);
	while(T--)
		sol();
}