#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int i,j,k,n,m,t,a[20050],res;

int main(){
	ios::sync_with_stdio(0);
	cin>>t;
	while(t--){
		cin>>n>>m;
		res=0;
		for(i=1;i<=n;i++){
			cin>>a[i];
			res=max(res,(a[i]|m));
		}
		cout<<res<<'\n';
	}
}