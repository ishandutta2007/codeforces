#include<bits/stdc++.h>
#define ll long long
#define N 100005

int T;

int n,a[N],b[N];

std::vector<int> A[2];

inline ll cal(){
	ll res=A[0].back();
	int i;
	for(i=0;i<(int)A[0].size()-1&&i<(int)A[1].size();i++)
		res+=((ll)A[1][i]+A[0][i])<<1;
	for(int j=i;j<(int)A[0].size()-1;j++)
		res+=A[0][j];
	if(i<(int)A[1].size())
		res+=A[1][i++]<<1;
	for(int j=i;j<(int)A[1].size();j++)
		res+=A[1][j];
	return res;
}

int main(){
	scanf("%d",&T);
	while(T--){
		scanf("%d",&n);
		A[0].clear(),A[1].clear();
		for(int i=1;i<=n;i++)
			scanf("%d",&a[i]);
		for(int i=1;i<=n;i++)
			scanf("%d",&b[i]),A[a[i]].emplace_back(b[i]);
		std::sort(A[0].begin(),A[0].end(),std::greater<int>());
		std::sort(A[1].begin(),A[1].end(),std::greater<int>());
		if(!A[0].size()){
			ll sum=0;
			for(auto i:A[1])
				sum+=i;
			printf("%lld\n",sum);
		}
		else if(!A[1].size()){
			ll sum=0;
			for(auto i:A[0])
				sum+=i;
			printf("%lld\n",sum);
		}
		else{
			ll res=cal();
			std::swap(A[0],A[1]);
			res=std::max(res,cal());
			printf("%lld\n",res);
		}
	}
}