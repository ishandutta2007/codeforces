// http://codeforces.com/contest/1041/problem/F
#include<iostream>
#include<sstream>
#include<vector>
#include<algorithm>

uint32_t revbit(uint32_t x){
	x=((x&0x55555555)<<1)|((x>>1)&0x55555555);
	x=((x&0x33333333)<<2)|((x>>2)&0x33333333);
	x=((x&0x0f0f0f0f)<<4)|((x>>4)&0x0f0f0f0f);
	x=((x&0x00ff00ff)<<8)|((x>>8)&0x00ff00ff);
	return (x>>16)|(x<<16);
}

int ans=2;
template<class It>void solve(It first1,It last1,It first2,It last2,uint32_t bit){
	if((last1-first1)+(last2-first2)<=ans)
		return;
	It mid1=first1==last1?first1:std::lower_bound(first1,last1,((*first1)&(-bit))|bit);
	It mid2=first2==last2?first2:std::lower_bound(first2,last2,((*first2)&(-bit))|bit);
	ans=std::max({ans,(mid1-first1)+(last2-mid2),(mid2-first2)+(last1-mid1)});
	solve(first1,mid1,first2,mid2,bit>>1);
	solve(mid1,last1,mid2,last2,bit>>1);
}

int main(){auto&O=std::cout;
#ifdef _GLIBCXX_DEBUG
std::stringstream I(R"(
3 1
1 5 6
1 3
3

)");
#else
auto&I=std::cin;std::ios::sync_with_stdio(0);I.tie(0);
#endif

std::vector<uint32_t> ptsOnL[2];
for(int i=0;i<2;++i){
	int nPoint,_;I>>nPoint>>_;
	ptsOnL[i].resize(nPoint);
	for(auto& x:ptsOnL[i]){I>>x;x=revbit(x);}
	std::sort(ptsOnL[i].begin(),ptsOnL[i].end());
}
solve(ptsOnL[0].begin(),ptsOnL[0].end(),ptsOnL[1].begin(),ptsOnL[1].end(),uint32_t(1)<<31);
O<<ans<<'\n';

}