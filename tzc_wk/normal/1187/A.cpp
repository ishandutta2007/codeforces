#include <bits/stdc++.h>
using namespace std;
int T;
int main(){
	cin>>T;
	while(T--){
		int n,s,t;
		cin>>n>>s>>t;
		cout<<n-min(s,t)+1<<endl;
	}
	return 0;
}