#include <bits/stdc++.h>
using namespace std;
int sum(int x){
	int sum=0;
	while(x!=0){
		sum+=x%10;
		x/=10;
	}
	return sum;
}
int main(){
	int a;cin>>a;
	for(int i=a;;i++){
		if(sum(i)%4==0){
			cout<<i<<endl;
			return 0;
		}
	}
	return 0;
}