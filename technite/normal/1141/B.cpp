#include<iostream>
using namespace std;
int main(){
	int n,a[210000],mx=-1,m=0;
	cin>>n;
	for(int i = 0; i < n; i++){
		cin>>a[i];
	}
	for(int i=0; i<n*2; i++){
		if(a[i%n]==1){
			m++;
		}else{
			mx=max(mx,m);
			m=0;
		}
	}
	cout<<mx;
	return 0;
}