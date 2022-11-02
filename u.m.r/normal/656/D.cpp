#include<bits/stdc++.h>
using namespace std;

int main(){
	int n;
	cin>>n;int x = 0;
	while(n){
		x += (n % 8 == 1);
		n /= 8;
	}
	cout<<x<<endl;
	return 0;
}