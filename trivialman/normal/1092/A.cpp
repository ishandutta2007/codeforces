#include<bits/stdc++.h>
using namespace std;
#define LL long long
#define rep(i,a,b) for(int i=(a);i<=(b);++i)

int n,k,t;
int main(){
	#ifndef ONLINE_JUDGE
	freopen("test.in","r",stdin);
	#endif
	cin>>t;
	while(t--){
		cin>>n>>k;
		rep(i,1,k)rep(j,1,n/k)cout<<(char)(i+96);
		rep(i,1,n%k)cout<<(char)(i+96);
		cout<<endl;
	} 
	return 0;
}