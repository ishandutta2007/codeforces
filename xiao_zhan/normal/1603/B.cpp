#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int i,j,k,n,m,t,x,y;

int main(){
	cin.tie(0);
	cin>>t;
	while(t--){
		cin>>x>>y;
		if(x>y){
			cout<<(x+y)<<'\n';
			continue;
		}
		
		if(!(y%x)){
			cout<<x<<'\n';continue;
		}
		/*if((x+x)==y){
			cout<<x<<'\n';continue;
		}
		
		if(x+x<y){
			//cout<<(y-x)<<'\n';continue;
		}
		
		else{
			cout<<(y-x)<<'\n';continue;
		}*/
		
		int sb=(y/x)*x;
		cout<<(sb+y)/2<<'\n';
	}
}