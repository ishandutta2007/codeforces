#include<bits/stdc++.h>
using namespace std;
int main(){
	int n,m;
	cin>>n>>m;
	int mn=-1,mx=-1;
	cin>>mx;
	mn=mx;
	for(int i=2;i<=n;++i){
		int t;
		cin>>t;
		mn=(t<mn?t:mn);
		mx=(t>mx?t:mx);
	}
	mx=(mx>mn*2?mx:mn*2);
	for(int i=1;i<=m;++i){
		int t;
		cin>>t;
		if(t<=mx){
			cout<<"-1"<<endl;
			return 0;
		}
	}
	cout<<mx<<endl;
}