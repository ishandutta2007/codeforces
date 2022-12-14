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
	int numRow, numCol; std::cin>>numRow>>numCol;
	bool okay=true;
	for(int row=0; row<numRow; ++row)
		for(int col=0; col<numCol; ++col){
			int numAdjacent=(row>0)+(row<numRow-1)+(col>0)+(col<numCol-1);
			int value; std::cin>>value;
			if(value>numAdjacent) okay=false;
		}
	if(not okay){std::cout<<"NO\n"; return;}

	std::cout<<"YES\n";
	for(int row=0; row<numRow; ++row){
		for(int col=0; col<numCol; ++col){
			int numAdjacent=(row>0)+(row<numRow-1)+(col>0)+(col<numCol-1);
			std::cout<<numAdjacent<<' ';
		}
		std::cout<<'\n';
	}

}