#include <bits/stdc++.h>
using namespace std;
string dig(int k,int d){
	string s="";
	while(k){
		s=char(k%d+'0')+s;
		k/=d;
	}
	return s;
}
int main(){
	int n;
	cin>>n;
	for(int i=0;i<n-1;i++){
		for(int j=0;j<n-1;j++){
			cout<<dig((i+1)*(j+1),n)<<(j==n-1?'\n':' ');
		}
		cout<<endl;
	}
}