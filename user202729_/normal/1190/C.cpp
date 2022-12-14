#include<iostream>
#include<string>
#include<algorithm>

int main(){
	std::ios::sync_with_stdio(0);std::cin.tie(0);

	int n,k;std::cin>>n>>k;
	std::string s;s.reserve(n);std::cin>>s;
	char cl=s[0];int spanl=int(std::find(begin(s),end(s),1^cl)-begin(s));
	if(spanl==n){
		std::cout<<"tokitsukaze\n";
		return 0;
	}
	char cr=s.back();int spanr=int(std::find(rbegin(s),rend(s),1^cr)-rbegin(s));
	if((cl==cr?spanl+spanr:std::max(spanl,spanr))>=n-k){
		std::cout<<"tokitsukaze\n";
		return 0;
	}
	if(cl!=cr&&k*2>=n&&spanl==n-k-1&&spanr==n-k-1){
		std::cout<<"quailty\n";
		return 0;
	}
	std::cout<<"once again\n";
}