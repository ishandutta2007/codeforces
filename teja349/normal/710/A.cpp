#include<iostream>
using namespace std;
int main(){
	int n;
	char ch;
	cin>>ch>>n;
	if(ch=='a'||ch=='h'){
		if(n==1||n==8){
			cout<<3;
			return 0;
		}
		else
		{
			cout<<5;
			return 0;
		}

	}
	else{
		if(n==1||n==8){
			cout<<5;
			return 0;
		}
		else
		{
			cout<<8;
			return 0;
		}

	}
}