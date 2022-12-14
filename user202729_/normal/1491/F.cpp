// huh!? seriously?
// (why so long? what's the idleless time limit?)
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
	int n; std::cin>>n;
	for(int i=1; i<n; i++){
		std::cout<<"? "<<i<<" 1\n";
		for(int j=0; j<i; ++j) std::cout<<j+1<<' ';
		std::cout<<'\n'<<i+1<<'\n'<<std::flush;

		int value; std::cin>>value;
		if(value!=0){ // i is magnetized
			std::vector<int> tmp; // indices of the non-magnets (demagnetized magnets?) on the right of i
			for(int j=i+1; j<n; ++j){
				std::cout<<"? 1 1\n"<<j+1<<'\n'<<i+1<<'\n'<<std::flush;
				int value; std::cin>>value;
				if(value==0) tmp.push_back(j);
			}

			int left=0, right=i;
			while(right-left!=1){
				int const middle=(left+right)>>1;

				std::cout<<"? "<<middle-left<<" 1\n";
				for(int j=left; j<middle; ++j) std::cout<<j+1<<' ';
				std::cout<<'\n'<<i+1<<'\n'<<std::flush;

				int value; std::cin>>value;
				if(value==0)
					// middle-left doesn't contain the other magnet
					left=middle;
				else
					right=middle;
			}

			std::cout<<"! "<<(int)tmp.size()+i-1;
			for(auto it: tmp) std::cout<<' '<<it+1;
			for(int j=0; j<i; ++j) if(j!=left) std::cout<<' '<<j+1;
			std::cout<<'\n'<<std::flush;
			return;
		}
	}
	assert(false);
}