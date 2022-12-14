#ifndef LOCAL
#define NDEBUG
#endif
#include<vector>
#include<algorithm>
#include<cassert>
#include<iostream>

int main(){
	std::ios::sync_with_stdio(0);std::cin.tie(0);
	int n;std::cin>>n;
	std::vector<int> hand(n);for(int& x:hand)std::cin>>x;
	std::vector<int> pile(n);for(int& x:pile)std::cin>>x;

	int out=n*3;

	std::vector<int> pos_in_pile(n+1,-1);
	for(int i=0;i<n;++i)
		pos_in_pile[pile[i]]=i;
	pos_in_pile[0]=-1; // does not matter

	auto const p1=pos_in_pile[1];
	if(p1<n and std::all_of(begin(pile)+p1+1,end(pile),[](int const& x){
				return x==(&x)[-1]+1;
				})){ // reuse segment [p1..] in pile
		for(int j=n-p1+1;j<=n;++j)
			if(pos_in_pile[j]>j-(n-p1+2))
				goto not_possible;

		out=std::min(out,p1);
		not_possible:;
	}

	{
		int x=0;
		for(int i=1;i<=n;++i)
			if(pos_in_pile[i]>=0)
				x=std::max(x,pos_in_pile[i]-i+2);
		out=std::min(out,x+n);
	}

	std::cout<<out<<'\n';
}