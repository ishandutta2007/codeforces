#ifndef LOCAL
#define NDEBUG
#endif
#include<cassert>
#include<iostream>
#include<algorithm>
#include<vector>

int main(){
	std::ios::sync_with_stdio(0);std::cin.tie(0);
	std::vector<int> a;
	int tt;std::cin>>tt;while(tt--){
		int n;std::cin>>n;
		std::vector<int> a(n);
		for(int& ai:a)std::cin>>ai;
		int ng=std::find_if(begin(a),end(a),[a0=a[0]](int ai){return a0>ai;})-begin(a);
		if(ng==n){
failed:
			std::cout<<"0 0 0\n";
			continue;
		}

		int ns=ng+1;
		while(ng+ns<n and a[ng+ns]==a[ng+ns-1])
			++ns;
		if(ng+ns ==n)
			goto failed;

		int least_total=ng+ns+(ng+1);
		int most_total=n/2;

		while(most_total>0 and a[most_total-1]==a[most_total])
			--most_total;
		if(least_total>most_total)
			goto failed;

		std::cout<<ng<<' '<<ns<<' '<<most_total-ng-ns<<'\n';
	}
}