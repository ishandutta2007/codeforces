#ifndef LOCAL
#define NDEBUG
#endif
#include<cassert>
#include<iostream>

bool isprime(int x){
	for(int y=2;y*y<=x;++y)
		if(x%y==0)
			return false;
	return true;
}

int main(){
	std::ios::sync_with_stdio(0);std::cin.tie(0);
	int n;std::cin>>n;
	int m=n;
	while(not isprime(m))++m;

	std::cout<<m<<'\n';
	for(int i=1;i<n;++i)
		std::cout<<i<<' '<<i+1<<'\n';
	std::cout<<n<<' '<<1<<'\n';
	for(int i=1;i<=m-n;++i){
		std::cout<<i<<' '<<i+n/2<<'\n';
		assert(i+n/2<=n);
	}
	std::cout<<'\n';
}