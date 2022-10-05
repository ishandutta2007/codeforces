#include <bits/stdc++.h>
using namespace std;
const int T[31]={1,3,6,10,15,21,28,36,45,55,66,78,91,105,120,136,153,171,190,210,231,253,276,300,325,351,378,406,435,465,496};
int n;
int main(){
	cin>>n;
	for(int i=0;i<31;i++)	if(T[i]==n)	cout<<"YES",exit(0);
	cout<<"NO";
	exit(0);
}