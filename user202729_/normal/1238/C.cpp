#include<iostream>

int main(){
	//std::ios::sync_with_stdio(0);std::cin.tie(0);
	int ntest;std::cin>>ntest;
	while(ntest--){
		int h,n;std::cin>>h>>n;
		bool have_h_1=false;
		int ans=0;
		for(int i=n;i--;){
			int x;std::cin>>x;
			if(x==h)continue;
			if(have_h_1){
				if(x==h-2){
					// ok
					h=x;
					have_h_1=false;
				}else{
					++ans;
					h=x+1;
					have_h_1=true;
				}
			}else{
				h=x+1;
				have_h_1=true;
			}
		}
		if(h>2&&have_h_1)
			++ans;
		std::cout<<ans<<'\n';
	}
}