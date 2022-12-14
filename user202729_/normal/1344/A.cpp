#ifndef LOCAL
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
	std::vector<char> have(number);
	bool okay=true;
	for(int index=0;index<number;++index) {
		int x; std::cin>>x; x+=index;
		x%=number;
		if(x<0) x+=number;
		if(have[x]) okay=false;
		else have[x]=true;
	}
	std::cout<<(okay? "YES": "NO")<<'\n';
}