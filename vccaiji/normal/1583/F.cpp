#include<bits/stdc++.h>
using namespace std;
int k,n;
int a[1100][30];
int main(){
	cin>>n>>k;
	int c=0;
	int nn=n-1;
	while(nn){
		nn/=k;
		c++;
	}
	cout<<c<<"\n";
	for(int i=0;i<n;i++){
		int s=i;
		for(int j=0;j<c;j++){
			a[i][j]=s%k;
			s/=k;
		}
	}
	for(int i=0;i<n;i++)for(int j=i+1;j<n;j++){
		int r=0;
		for(int s=c-1;s>=0;s--)if(a[i][s]!=a[j][s]){
			r=s;
			break;
		}
		cout<<r+1<<" ";
	}
	return 0;
}