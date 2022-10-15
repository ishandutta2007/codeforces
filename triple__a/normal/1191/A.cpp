#include<bits/stdc++.h>
using namespace std;

const int maxn=100007;
int main(){
	int x;
	cin>>x;
	if (x%4==1){
		printf("0 A");
	}
	if (x%4==0){
		printf("1 A");
	}
	if (x%4==2){
		printf("1 B");
	}
	if (x%4==3){
		printf("2 A");
	}
	return 0;
}