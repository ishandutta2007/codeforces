// time-limit: 2000
// problem-url: https://codeforces.com/contest/1530/problem/B
//(what a waste of time.)
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
	int h; std::cin>>h;
	int w; std::cin>>w;
	
	// not really proven...?
	
	if(h%2==0 and w%2==0){
		for(int _=0; _<w/2-1; ++_)
			std::cout<<"01";
		std::cout<<"00\n";

		std::string long_zero(w-1, '0');
		for(int _=0; _<h/2-1; ++_){
			std::cout<<long_zero<<"1\n"
			"1"<<long_zero<<'\n';
		}

		std::cout<<"00";
		for(int _=0; _<w/2-1; ++_)
			std::cout<<"10";
		std::cout<<'\n';
	}
	else if(h%2==1 and w%2==0){
		for(int _=0; _<w/2; ++_)
			std::cout<<"01";
		std::cout<<'\n';

		std::string long_zero(w-2, '0');
		for(int _=0; _<h/2-1; ++_){
			std::cout<<
				'0'<<long_zero<<"0\n"
				"1"<<long_zero<<"1\n";
		}

		std::cout<<'0'<<long_zero<<"0\n";

		for(int _=0; _<w/2; ++_)
			std::cout<<"10";
		std::cout<<'\n';
	}
	else if(h%2==0 and w%2==1){
		std::cout<<'0';
		for(int _=0; _<w/2; ++_) std::cout<<"01";
		std::cout<<'\n';

		std::string long_zero(w-1, '0');
		for(int _=0; _<h/2-1; ++_)
			std::cout<<
				'1'<<long_zero<<'\n'
				<<long_zero<<"1\n";

		for(int _=0; _<w/2; ++_) std::cout<<"10";
		std::cout<<"0\n";
	}
	else{ assert(h%2==1 and w%2==1);
		std::cout<<'1';
		for(int _=0; _<w/2; ++_) std::cout<<"01";
		std::cout<<'\n';

		std::string long_zero(w-2, '0');
		for(int _=0; _<h/2-1; ++_){
			std::cout<<
				'0'<<long_zero<<"0\n"
				"1"<<long_zero<<"1\n";
		}

		std::cout<<
			'0'<<long_zero<<"0\n";

		std::cout<<'1';
		for(int _=0; _<w/2; ++_) std::cout<<"01";
		std::cout<<'\n';
		
	}

	std::cout<<'\n';
}