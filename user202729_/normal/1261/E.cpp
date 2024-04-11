/*
It appears that whether I can solve such "observation-based" problems is completely random...

However, I did spend 30 minutes in the contest, have a solution, but I didn't realize
that sometimes there might not be a solution when some ai values are 0.

I proved that this algorithm is correct, but there are (is this countable?) some hand-waving.
UPD: forgot to sort. This is just an implementation error.
UPD2: forgot to unsort. This is (another) implementation error.
/me feel bad for not checking sample test cases before submitting,
but for problems l)e this, manually checking the correctness is hard.
(I did check that there's no run time error)

*/
#ifndef LOCAL
#define NDEBUG
#endif
#include<cassert>
#include<functional>
#include<iostream>
#include<vector>
#include<algorithm>
#include<climits>
#include<string>

int main(){
	std::ios::sync_with_stdio(0);std::cin.tie(0);
	int n;std::cin>>n;

	struct item{int val,ind;};
	std::vector<item> a(n);
	for(int i=0;i<n;++i){
		std::cin>>a[i].val;
		a[i].ind=i;
	}
	std::sort(begin(a),end(a),[](item a,item b){
			return a.val>b.val;
			});

	std::vector<std::string> ops(n+1,std::string(n,'0'));
	for(int i=0;i<n;++i){
		auto const ai=a[i];
		for(int j=0;j<ai.val;++j)
			ops[(j+i)%(n+1)][ai.ind]='1';
	}
	if(ops.back()==std::string(n,'0'))
		ops.pop_back();

	std::cout<<ops.size()<<'\n';
	for(auto const& op:ops)
		std::cout<<op<<'\n';
}