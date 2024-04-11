#include<iostream>
#include<numeric>
#include<vector>

int main(){
	std::ios::sync_with_stdio(0);std::cin.tie(0);
	int n;std::cin>>n;

	std::vector<int> a(2*n);
	std::iota(begin(a),begin(a)+n,1);
	int first=0,last=n;

	for(int k=2;k<=n;++k){
		int prevpos=last;
		++last;
		for(int pos=first+(last-first-1)/k*k;pos>=first;pos-=k){
			a[prevpos]=a[pos];prevpos=pos;
		}
		++first;
	}

	for(int i=first;i<last;++i)
		std::cout<<a[i]<<' ';
	std::cout<<'\n';
}