#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#pragma GCC target("sse,sse2,ssse3,sse3,sse4,popcnt,avx,mmx,abm,tune=native")
#include <bits/stdc++.h>
using namespace std;

vector<int> vec;
int fnd[10000], n, i, x;

int main(){
	for(scanf("%d",&n),i=1;i<=n;i++){
		scanf("%d",&x);
		vec.push_back(x);
	}
	for(i=n-1;i>=0;i--){
		if(fnd[vec[i]]) vec.erase(vec.begin()+i);
		else fnd[vec[i]]=1;
	}
	printf("%d\n",vec.size());
	for(auto v : vec)
		printf("%d ",v);
	return 0;
}