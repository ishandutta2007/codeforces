#ifndef LOCAL
#define NDEBUG
#endif
#include<cassert>
#include<iostream>

int main(){
	std::ios::sync_with_stdio(0);std::cin.tie(0);
	int n,m,k;std::cin>>n>>m>>k;
	if(k==1 or n*(int64_t)m*2%k!=0){
		std::cout<<"NO\n";
		return 0;
	}
	int64_t cross =n*(int64_t)m*2/k;

	int x1,y1,x2,y2;

	x2=n-((cross-1)%n+1);
	y1=1;
	x1=n;
	assert((cross+x2)%n==0);
	y2=(cross+x2)/n;

	assert(x1*y2-x2*y1==cross);

	assert(x1<=n);
	assert(x2<=n);
	assert(y1<=m);
	assert(y2<=m);

	std::cout<<"YES\n0 0\n"
		<<x1<<' '<<y1<<'\n'
		<<x2<<' '<<y2<<'\n';
}