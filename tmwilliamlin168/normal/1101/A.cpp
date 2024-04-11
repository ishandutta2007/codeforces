#include<bits/stdc++.h>
using namespace std;
int main(){
	int n,a,b,c;
	cin >> n;
	while(n--){
		cin >> a >>b >>c;
		if(c<a){
			cout<<c<<"\n";
		}else{
			cout<< b + (c-(b%c))<<"\n";
		}
	
	}
	
}