#include<bits\stdc++.h>

using namespace std;

int main(){
	
	int n;
	cin>>n;
	int a[n];
	int ma = -1e9;
	for(int i=0;i<n;i++){
		cin>>a[i];
		if(a[i]<0) ma = max(ma,a[i]);
		else{
			int z = sqrt(a[i]+1e-9);
			if(z*z!=a[i]) ma = max(ma,a[i]);
		}
	}
	cout<<ma<<endl;

}