#include<iostream>
#include<cmath>
using namespace std;

typedef long long ll;

ll a,b,c;
int main(){
	cin>>a>>b>>c;
	ll ans1=(a+b)/c,ans2=a/c+b/c;
	if (ans1==ans2){
		cout<<ans1<<" "<<0;
	} 
	else{
		cout<<ans1<<" "<<min(c-a%c,c-b%c);
	}
	return 0;
}