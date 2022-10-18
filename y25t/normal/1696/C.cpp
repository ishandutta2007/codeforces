#include<bits/stdc++.h>
#define ll long long

int T;

int n,m,k;

int main(){
	scanf("%d",&T);
	while(T--){
		scanf("%d%d",&n,&m);
		std::vector<std::pair<int,ll>> A,B;
		for(int i=1;i<=n;i++){
			int x;
			scanf("%d",&x);
			int t=1;
			while(x%m==0)
				x/=m,t*=m;
			if(!A.size()||A.back().first!=x)
				A.emplace_back(x,t);
			else
				A.back().second+=t;
		}
		scanf("%d",&k);
		for(int i=1;i<=k;i++){
			int x;
			scanf("%d",&x);
			int t=1;
			while(x%m==0)
				x/=m,t*=m;
			if(!B.size()||B.back().first!=x)
				B.emplace_back(x,t);
			else
				B.back().second+=t;
		}
		puts(A==B?"Yes":"No");
	}
}