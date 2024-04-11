// way too slow...
#if not LOCAL
#define NDEBUG 1
#endif
#include<bits/stdc++.h>

int main(){
	std::ios::sync_with_stdio(0);std::cin.tie(0);
	int n; std::cin>>n;
	std::vector<int> a(n), b(n);

	int sumB{};
	for(int i=0; i<n; ++i){
		std::cin>>a[i]>>b[i];
		sumB+=b[i];
	}

	std::vector data(n+1, std::vector<int>(sumB+1, INT_MIN));
	//[count][b] -> maximum a
	
	data[0][0]=0;
	for(int i=0; i<n; ++i){
		auto const curA=a[i], curB=b[i];
		for(int count=i; count>=0; count--){
			for(int sumBSubset=0; sumBSubset+curB<=sumB; ++sumBSubset)
				if(auto const sumASubset=data[count][sumBSubset]; sumASubset!=INT_MIN){
					data[count+1][sumBSubset+curB] =std::max(data[count+1][sumBSubset+curB], sumASubset+curA);
				}
		}
	}


	std::cout<<std::fixed<<std::setprecision(2);
	for(int count=1; count<=n; ++count){
		int result{};
		for(int sumBSubset=0; sumBSubset<=sumB; ++sumBSubset)
			if(auto const sumASubset=data[count][sumBSubset]; sumASubset!=INT_MIN){
				result=std::max(result, std::min(sumASubset*2, sumBSubset+sumB));
			}
		std::cout<<result/2.<<' ';
	}
	std::cout<<'\n';
}