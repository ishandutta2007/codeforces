// time-limit: 1000
// problem-url: https://codeforces.com/contest/1616/problem/C
#if not LOCAL
#define NDEBUG 1
#endif
#include<bits/stdc++.h>

void up();
int main(){
	std::ios::sync_with_stdio(0);std::cin.tie(0);
	int numTest; std::cin>>numTest;
	while(numTest--) up();
}

void up(){
	int number; std::cin>>number;
	std::vector<int> a(number);
	for(auto& it: a) {
		std::cin>>it;
	}
	if(number<=2){
		std::cout<<"0\n";
	}else{
		int minChange=INT_MAX;
		for(int i=0; i<number; ++i)
			for(int j=0; j<i; ++j){
				int numChange {};
				for(int k=0; k<number; ++k)
					if(
							(i-j)*a[k]
							!=
							(k-j)*a[i]
							+
							(i-k)*a[j]
					  ) numChange++;
				minChange=std::min(minChange, numChange);
			}
		std::cout<<minChange<<'\n';
	}

}