#include<bits/stdc++.h>
using namespace std;
int main(){
	int _;
	cin>>_;
	while(_--){
		int l[10];
		cin>>l[1]>>l[2]>>l[3];
		sort(l+1,l+4);
		if(l[1]+l[2]==l[3])cout<<"YES\n";
		else{
			if(l[1]==l[2] && (l[3]%2==0))cout<<"YES\n";
			else{
				if(l[2]==l[3] &&(l[1]%2==0))cout<<"YES\n";
				else{
					if(l[1]==l[3]&&(l[2]%2==0))cout<<"YES\n";
					else cout<<"NO\n";
				}
			}
		}
	}
	return 0;
}