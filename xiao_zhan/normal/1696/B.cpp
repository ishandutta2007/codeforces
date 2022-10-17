#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int i,j,k,n,m,t,a[200500],res;

int main(){
	ios::sync_with_stdio(0);
	cin>>t;
	while(t--){
		cin>>n;
		k=0;
		for(i=1;i<=n;i++){
			cin>>a[i];
			k+=!a[i];
		}
		if(k==n){
			cout<<"0\n";continue;
		}
		int sb=0;
		for(i=1;i<=n;i++){
			if(a[i]){
				if(sb==-1){
					cout<<"2\n";goto aaa;
				}
				sb=1;
			}
			else{
				if(sb==1){
					sb=-1;
				}
			}
		}
		cout<<"1\n";
		aaa:;
	}
}