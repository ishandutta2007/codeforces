#ifndef _GLIBCXX_DEBUG
#define NDEBUG
#endif
#include<iterator>
#include<cassert>
#include<iostream>
#include<vector>

std::vector<std::vector<int>> ad;
std::vector<int> maxd;

int calc_maxdepth(int x){
	int mdy=-1;
	for(int y:ad[x])
		mdy=std::max(mdy,calc_maxdepth(y));
	return maxd[x]=mdy+1; // leaves have maxdepth 0
}

std::vector<int> ans; // blank id -> node id
std::vector<int> ops; // list of blank id

template<bool needret>
int work(int node,int blankid){
	ans[blankid]=node;
	++blankid;
	if(needret){
		for(int y:ad[node])
			blankid=work<true>(y,blankid);
		ops.push_back(blankid);
	}else{
		if(ad[node].empty())
			//return blankid;
			return -1;

		int maxdy=maxd[node]-1;
		int maxd_child=-1;
		for(int y:ad[node]){
			if(maxd[y]==maxdy&&maxd_child<0){
				maxd_child=y;
			}else{
				blankid=work<true>(y,blankid);
			}
		}

		assert(maxd_child>=0);
		blankid=work<false>(maxd_child,blankid);
		return -1;
	}
	return blankid;
}

int main(){
	std::ios::sync_with_stdio(0);std::cin.tie(0);
	int n;std::cin>>n;
	ad.resize(n);
	for(int i=1;i<n;++i)
		ad[*std::istream_iterator<int>(std::cin)].push_back(i);

	maxd.resize(n);
	calc_maxdepth(0);

	ans.resize(n);
	ops.reserve(n-maxd[0]-1);
	work<false>(0,0);
	assert((int)ops.size()==(n-maxd[0]-1));

	for(auto x:ans)std::cout<<x<<' ';
	std::cout<<'\n';
	std::cout<<ops.size()<<'\n';
	for(auto blankid:ops)std::cout<<ans[blankid]<<' ';
	std::cout<<'\n';
}