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
	int length, k; std::cin>>length>>k;
	std::string s; std::cin>>s;
	assert((int)s.size()==length);
	assert(k%2==0); assert(k<=length);
	int force0{}, force1{}, any{};
	for(int i=0; i<k; ++i){
		int num0{}, num1{}, numQuestion{};
		for(int pos=i; pos<length; pos+=k){
			switch(s[pos]){
				case '0': ++num0; break;
				case '1': ++num1; break;
				case '?': ++numQuestion; break;
				default: assert(false); __builtin_unreachable();
			}
		}
		if(num0 and num1){
			std::cout<<"NO\n";
			return;
		}
		if(num0) ++force0;
		else if(num1) ++force1;
		else ++any;
	}
	assert(force0+force1+any==k);
	std::cout<<(std::max(force0, force1)<=k/2 ? "YES\n": "NO\n");
}