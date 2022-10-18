#include<bits/stdc++.h>

inline int Abs(int x){
	return x<0?-x:x;
}

int T;

std::vector<std::pair<int,int>> ans;

int l;
inline void sol(std::vector<int> &V,int k){
	if(k==1){
		for(int i=0;i<(int)V.size();i++)
			ans.emplace_back(0,l);
		return;
	}
	std::multiset<int> A,B;
	for(auto i:V)
		(i&1?A:B).insert(i);
	while(A.size()>1){
		int x=*std::prev(A.end());
		A.erase(A.find(x));
		for(int i=k;i>x;i>>=1)
			if(A.count(i-x)){
				ans.emplace_back(1ll*x*l/k,1ll*(i-x)*l/k);
				A.erase(A.find(i-x));
				B.insert(i),B.insert(Abs(x+x-i));
				break;
			}
	}
	if(A.size()){
		int x=*A.begin(),y=*B.begin();
		B.erase(B.find(y));
		ans.emplace_back(1ll*x*l/k,1ll*y*l/k);
		int u=x+y,v=Abs(x-y);
		ans.emplace_back(1ll*u*l/k,1ll*v*l/k);
		B.insert(u+v),B.insert(Abs(u-v));
	}
	V.clear();
	for(auto i:B)
		if(i!=k)
			V.push_back(i>>1);
	sol(V,k>>1);
}

int main(){
	scanf("%d",&T);
	while(T--){
		int n;
		scanf("%d",&n);
		if(n==2){
			puts("-1");
			continue;
		}
		l=1;
		while(l<n)
			l<<=1;
		std::vector<int> V(n);
		std::iota(V.begin(),V.end(),1);
		ans.clear();
		sol(V,l);
		printf("%d\n",(int)ans.size());
		for(auto [x,y]:ans)
			printf("%d %d\n",x,y);
	}
}