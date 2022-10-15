#include<bits/stdc++.h>
using namespace std;

int n,u,v;
int main(){
	cout<<"? ";
	for (int i=1;i<=100;++i){
		cout<<i<<" ";
	}
	cout<<endl;
	cout<<flush;
	cin>>u;
	cout<<"? ";
	for (int i=1;i<=100;++i){
		cout<<(i<<7)<<" ";
	}
	cout<<endl;
	cout<<flush;
	cin>>v;
	int ans=(u&(127<<7))+(v&127);
	cout<<"! "<<ans<<endl;
	
	return 0;
}