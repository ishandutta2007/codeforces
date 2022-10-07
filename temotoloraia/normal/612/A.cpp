#include <bits/stdc++.h>
using namespace std;
int main(){
	int n,p,q;
	string s;
	cin>>n>>p>>q;
	cin>>s;
	int temp;
	for( int i=0; i<=n/p;i++){
		temp=n-i*p;
		if(temp%q==0){
			printf("%d\n",i+temp/q);
			for( int j=0; j<i;j++){
				cout<<s.substr(j*p,p)<<endl;
			}
			for( int j=0; j<temp/q;j++){
				cout<<s.substr(i*p+j*q,q)<<endl;
			}
			return 0;
		}
	}
	printf("%d\n",-1);
}