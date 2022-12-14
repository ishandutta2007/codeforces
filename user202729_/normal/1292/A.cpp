// I hope there was no issue during the real contest...
#ifndef LOCAL
#define NDEBUG 1
#endif
#include<bits/stdc++.h>

int main(){
	std::ios::sync_with_stdio(0);std::cin.tie(0);
	int ncol,nchange;std::cin>>ncol>>nchange;
	std::vector<std::array<char,2>> lava(ncol);
	int cnt_col_or_diag_lava=0;
	for(int z=nchange;z--;){
		int row,col;std::cin>>row>>col;
		--row;--col;
		lava[col][row]^=1;
		for(int c1=std::max(0,col-1);c1<=std::min(ncol-1,col+1);++c1)
			if(lava[c1][not row]){
				if(lava[col][row]) ++cnt_col_or_diag_lava;
				else --cnt_col_or_diag_lava;
			}

		std::cout<<(cnt_col_or_diag_lava==0 ? "Yes\n" : "No\n");
	}
}