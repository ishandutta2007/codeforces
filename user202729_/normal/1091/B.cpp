#include<iostream>
#include<algorithm>

int main(){
	std::ios::sync_with_stdio(0);std::cin.tie(0);
	int n;std::cin>>n;
	int64_t sx=0,sy=0;
	for(int _=2*n;_--;){
		int x,y;std::cin>>x>>y;
		sx+=x;sy+=y;
	}
	std::cout<<sx/n<<' '<<sy/n<<'\n';
}