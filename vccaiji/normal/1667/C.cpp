#include<bits/stdc++.h>
using namespace std;
int n;
int main(){
	cin>>n;	
	if(n==1){
		printf("1\n1 1");
		return 0;
	}
	int m=3*((n+1)/3)-1;
	cout<<n-(n+1)/3<<endl;
	for(int i=1,j=m-1;j>0;i+=3,j-=3)cout<<i<<' '<<j<<endl;
	for(int i=3,j=m-2;j>0;i+=3,j-=3)cout<<i<<' '<<j<<endl;
	for(int i=m+1;i<=n;i++)cout<<i<<' '<<i<<endl;
	return 0;
}