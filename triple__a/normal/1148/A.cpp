#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;

int main(){
	long long a,b,c,ans;
	cin>>a>>b>>c;
	if (a==b){
		ans=2*a+2*c;
	}
	else{
		ans=1+2*min(a,b)+2*c;
	}
	cout<<ans;
	return 0;
}