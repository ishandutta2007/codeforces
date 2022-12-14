// Have I done this problem before?
#ifndef LOCAL
#define NDEBUG
#endif
#include<cassert>
#include<iostream>
#include<vector>

int main(){
	std::ios::sync_with_stdio(0);std::cin.tie(0);
	int nrow,ncol;std::cin>>nrow>>ncol;
	std::vector<std::vector<char>> a(nrow,std::vector<char>(ncol));
	for(auto& row:a)for(char& c:row){ std::cin>>c;c-='0'; }
	for(int r=0;r<nrow;++r)for(int c=0;c<ncol;++c){
		char ch;std::cin>>ch;ch-='0';
		a[r][c]^=ch;
		if(a[r][c]){
			a[0][0]^=1;
			a[0][c]^=1;
			a[r][0]^=1;
			a[r][c]^=1;
		}
	}

	for(int r=0;r<nrow;++r)for(int c=0;c<ncol;++c){
		if(a[r][c]){
			std::cout<<"No\n";
			return 0;
		}
	}
	std::cout<<"Yes\n";
}