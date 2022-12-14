#ifndef LOCAL
#define NDEBUG
#endif
#include<cassert>
#include<iostream>
#include<string>

int main(){
	std::ios::sync_with_stdio(0);std::cin.tie(0);
	int n,k;std::cin>>n>>k;
	std::string x;std::cin>>x;
	std::string y;y.reserve(x.size());

	int eqprefix=0;
	for(int step=1<<30;step>>=1;)if(eqprefix+step<=k){
		eqprefix+=step;
		y.assign(begin(x),begin(x)+eqprefix);
		y.insert(end(y),k-eqprefix,'9');
		while(y.size()<x.size())
			y+=y.end()[-k];

		assert(y.size()==x.size());
		if(y<x){
			// fail
			eqprefix-=step;
		}
	}
	assert(eqprefix<=k);

	y.assign(begin(x),begin(x)+eqprefix);
	if(eqprefix<k){
		assert(x[eqprefix]<'9');
		y+=char(x[eqprefix]+1);
	}
	y.insert(end(y),k-y.size(),'0');
	while(y.size()<x.size())
		y+=y.end()[-k];

	assert(y>=x and y.size()==x.size());
	std::cout<<y.size()<<'\n'<<y<<'\n';
}