// [observation]
// >.<
#ifndef LOCAL
#define NDEBUG
#endif
#include<cassert>
#include<iostream>
#include<array>
#include<algorithm>
#include<vector>

bool f(int a,int b,int c,int d,bool dropfirst,bool valflip){
	if(not a)return false;
	std::vector<int> out;
	std::array<int,4> n{{a,b,c,d}};
	int x=0;
	for(;;){
		if(n[x]==0)break;
		--n[x];out.push_back(x);
		if(x==0)++x;
		else if(x==3)--x;
		else if(n[x-1])--x;
		else ++x;
	}
	if(std::any_of(begin(n),end(n),[](int x){return x!=0;}))
		return false;
	if(dropfirst)out.erase(begin(out));
	std::cout<<"YES\n";
	for(int x:out)std::cout<<(valflip?3-x:x)<<' ';
	std::cout<<'\n';
	return true;
}

int main(){
	std::ios::sync_with_stdio(0);std::cin.tie(0);
	int a,b,c,d;std::cin>>a>>b>>c>>d;
	f(a,b,c,d,0,0) or f(a+1,b,c,d,1,0) or f(d,c,b,a,0,1) or f(d+1,c,b,a,1,1) or (std::cout<<"NO\n");
}