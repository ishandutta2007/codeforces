#include <bits/stdc++.h>
using namespace std;
int num(int n){
	if(n%2)	return (n-1)/2*(n+1)/2;
	else return n/2*n/2;
}
int n;
int main(){
	cin>>n;
	for(int i=1;;i++){
		if(num(i)>=n){
			cout<<i<<endl;
			return 0;
		}
	}
	return 0;
}