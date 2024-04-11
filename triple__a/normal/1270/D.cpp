#include<bits/stdc++.h>
using namespace std;
int n,k,ans1[707],ans2[707];

int main(){
	cin>>n>>k;
	if (k==1){
		cout<<"! 1"<<endl;
		return 0;
	}
	for (int i=1;i<=k+1;++i){
		cout<<"? ";
		for (int j=1;j<=k+1;++j){
			if (i==j) continue;
			cout<<j<<" ";
		}
		cout<<endl;
		cin>>ans1[i]>>ans2[i];
	}
	int u=-1,v=-1;
	for (int i=1;i<=k+1;++i){
		if (u==-1) u=ans2[i];
		if (u!=-1&&u!=ans2[i]) v=ans2[i];
	}
	if (u>v) swap(u,v);
	int a=0,b=0;
	for (int i=1;i<=k+1;++i){
		if (u==ans2[i]) a++; else b++;
	}
	cout<<"! "<<b<<endl;
	return 0;
}