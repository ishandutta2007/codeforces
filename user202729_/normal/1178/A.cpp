#ifndef LOCAL
#define NDEBUG
#endif
#include<cassert>
#include<iostream>
#include<vector>
#include<numeric>

int main(){
	std::ios::sync_with_stdio(0);std::cin.tie(0);
	int n;std::cin>>n;
	std::vector<int> a(n);for(int& x:a)std::cin>>x;

	int sum=std::accumulate(begin(a),end(a),0);
	int coalitionsum=0,coalitionsize=0;
	for(int i=0;i<n;++i)
		if(i==0 or a[0]>=2*a[i]){
			coalitionsize+=1;
			coalitionsum+=a[i];
		}

	if(coalitionsum*2>sum){
		std::cout<<coalitionsize<<'\n';
		for(int i=0;i<n;++i)
			if(i==0 or a[0]>=2*a[i]){
				std::cout<<i+1<<' ';
			}
		std::cout<<'\n';
	}else{
		std::cout<<"0\n";
	}
}