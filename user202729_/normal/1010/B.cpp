#include<iostream>
#include<vector>
int main(){
	std::ios_base::sync_with_stdio(false);std::cin.tie(nullptr);
	int maxdist,period;std::cin>>maxdist>>period;
	std::vector<char>p(period); // rocket's honesty
	for(char&x:p){
		std::cout<<"1\n"<<std::flush;
		int ans;std::cin>>ans;
		switch(ans){
			case 0:return 0;
			case-1:x=false;break;//nothing less than 1. rocket lied.
			case 1:x=true;break;//of course
			case-2:return 0; // WA!? How?
		}
	}
	int lo=1,hi=maxdist,index=0;
	while(true){
		int mid=(lo+hi)>>1;
		std::cout<<mid<<'\n'<<std::flush;
		int ans;std::cin>>ans;
		if(!p[index]) // rocket lied
			ans=-ans;
		switch(ans){
			case 0:return 0;
			case-1:hi=mid-1;break;
			case 1:lo=mid+1;break;
			case-2:return 0;
		}
		index=(index+1)%period;
	}
}