#include<iostream>
using namespace std;
#include<algorithm>
#define ll long long int
int main(){
	ll l1,r1,l2,r2,k;
	cin>>l1>>r1>>l2>>r2>>k;
	l1=max(l1,l2);
	r1=min(r1,r2);
	if(l1<=r1){
		if(l1<=k&&k<=r1)
		{
			cout<<r1-l1;
		}
		else{
			cout<<r1-l1+1;
		}
	}
	else
		cout<<0;
}