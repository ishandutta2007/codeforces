#include<iostream>
using namespace std;
#define ll long long

ll T;

ll n,k;

int main(){
	cin>>T;
	while(T--){
		cin>>n>>k;
		ll cnt=0;
		while(n){
			if(n%k==0){
				n/=k;
				cnt++;
			}
			else{
				cnt+=n%k;
				n-=n%k;
			}
		}
		cout<<cnt<<endl;
	}
}