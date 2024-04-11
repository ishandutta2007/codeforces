#include <bits/stdc++.h>
using namespace std;
int n,m,k;
int mk1[5001],mk2[5001],tm1[5001],tm2[5001];
int main(){
	cin>>n>>m>>k;
	for(int _=1;_<=k;_++){
		int a,b,c;
		cin>>a>>b>>c;
		if(a==1)	mk1[b]=c,tm1[b]=_;
		else		mk2[b]=c,tm2[b]=_;
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			cout<<((tm1[i]>tm2[j])?mk1[i]:mk2[j])<<" ";
		}
		cout<<endl;
	}
}