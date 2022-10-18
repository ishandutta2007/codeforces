#include<bits/stdc++.h>
#define N 1005

inline std::vector<int> cal(int n,int k){
	std::vector<int> res;
	for(int i=1;n;i++,n/=k)
		res.push_back(n%k);
	return res;
}

int n,k;

int main(){
	scanf("%d%d",&n,&k);
	auto x=cal(n-1,k);
	printf("%d\n",x.size());
	for(int i=0;i<n;i++)
		for(int j=i+1;j<n;j++){
			auto u=cal(i,k),v=cal(j,k);
			u.resize(x.size()),v.resize(x.size());
			int tmp=0;
			for(int o=0;o<x.size();o++)
				if(u[o]!=v[o]){
					tmp=o;
				}
			printf("%d ",tmp+1);
		}
}