#include<iostream>
#include<sstream>
#include<vector>
#include<algorithm>
#include<random>
#include<cassert>
int main(){auto&O=std::cout;
#ifdef _GLIBCXX_DEBUG
std::stringstream I(R"(
1 1
1

)");
#else
auto&I=std::cin;std::ios::sync_with_stdio(0);I.tie(0);
#endif

int nNum,maxDec;I>>nNum>>maxDec;
std::vector<int> nums(nNum);
for(int& x:nums)I>>x;
std::sort(nums.begin(),nums.end());
nums.erase(std::unique(nums.begin(),nums.end()),nums.end());
nNum=nums.size();

if(nNum==1){
	O<<nums[0]<<'\n';
	return 0;
}

std::mt19937 engine(12476134);
int gcdUpperBound=1e9;
for(int i=0;i<10000;++i){
	int index1=std::uniform_int_distribution<int>(1,nNum-1)(engine);
	int index2=std::uniform_int_distribution<int>(0,index1-1)(engine);
	int maxA=nums[index1],maxB=nums[index2]; // maxB < maxA
	int minA=std::max(maxA-maxDec,1),minB=std::max(maxB-maxDec,1);
	while(minA>maxB){
		assert(0<=minA);assert(minA<=maxA);
		assert(0<=minB);assert(minB<=maxB);
		int q=minA/maxB;
		assert(q>0);
		minA-=maxB*q;
		maxA-=minB*q;
		std::swap(minA,minB);std::swap(maxA,maxB);
	}
	if(minA>0)
		gcdUpperBound=std::min(gcdUpperBound,maxA);
	if(minB>0)
		gcdUpperBound=std::min(gcdUpperBound,maxB);
}
int d=gcdUpperBound;
for(;;){
	continue_outer:
	for(int a:nums){
		if(a%d>maxDec){
			assert(a/(a/d+1)<d);
			d=a/(a/d+1);
			goto continue_outer;
		}
	}
	O<<d<<'\n';
	return 0;
}

}