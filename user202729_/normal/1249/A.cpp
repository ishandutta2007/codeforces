// testing cf CLI. 5
// sudo tc qdisc add dev wlp2s0 root netem delay 800ms 800ms 100% loss 50% 25% duplicate 50% corrupt 25% reorder 50% 50%
#include<iostream>
#include<algorithm>
#include<array>

int main(){
	std::ios::sync_with_stdio(0);std::cin.tie(0);
	int q;std::cin>>q;
	std::array<int,100> a;
	while(q--){
		int n;std::cin>>n;
		for(int i=0;i<n;++i)std::cin>>a[i];
		std::sort(begin(a),begin(a)+n);
		for(int i=1;i<n;++i){
			if(a[i-1]+1==a[i]){
				std::cout<<"2\n";
				goto nexttest;
			}
		}

		std::cout<<"1\n";
nexttest:;
	}
}