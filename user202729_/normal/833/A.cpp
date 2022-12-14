#ifndef LOCAL
#define NDEBUG 1
#endif
#include<bits/stdc++.h>

int main(){
	std::ios::sync_with_stdio(0);std::cin.tie(0);
	int number; std::cin>>number;
	while(number--){
		int a, b; std::cin>>a>>b;
		int const c=(int)std::round(std::cbrt(a*(int64_t)b));

		std::cout<<(
			(int64_t)c*c*c==(int64_t)a*b
			and
			a%c==0 and b%c==0


				? "Yes\n": "No\n"
				);
	}
}