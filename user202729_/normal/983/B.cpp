// Brain debugging won!
#ifndef LOCAL
#define NDEBUG
#endif
#include<cassert>
#include<iostream>
#include<vector>
#include<algorithm>

int main(){
	std::ios::sync_with_stdio(0);std::cin.tie(0);
	int n;std::cin>>n;
	std::vector<int> a(n);
	for(int& x:a)std::cin>>x;

	struct query{ int l,r,id; };
	int nquery;std::cin>>nquery;
	std::vector<query> qq(nquery);
	std::generate(begin(qq),end(qq),[id=0]() mutable { int l,r;std::cin>>l>>r;return query{l-1,r,id++}; });
	std::sort(begin(qq),end(qq),[](query a,query b){ return a.r<b.r; });

	std::vector<int> out(nquery);

	std::vector<int> prev(n),cur(n),maxnxt(n);

	auto iter=begin(qq);
	for(int r=1;;++r,std::swap(cur,prev)){
		// now prev[l] = f(a[l..r-1]) for l<r-1
		cur[r-1]=a[r-1];
		maxnxt[r-1]=std::max(maxnxt[r-1],cur[r-1]);
		for(int l=r-1;l--;){
			cur[l]=cur[l+1] xor prev[l];
			maxnxt[l]=std::max({maxnxt[l],maxnxt[l+1],cur[l]});
		}
		// now cur[l] = f(a[l..r]) for l<r

		while(true){
			if(iter==end(qq)) goto break_outer;
			if(iter->r==r){
				out[iter->id]=maxnxt[iter->l];
				++iter;
			}else break;
		}
	}
break_outer:
	
	for(auto& x:out)std::cout<<x<<'\n';
}