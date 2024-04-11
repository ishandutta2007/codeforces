#include <bits/stdc++.h>
using namespace std;
int n,cnt;
int main(){
	cin>>n;
	for(int i=1;i<=n;i++){
		int a,b,c;cin>>a>>b>>c;
		if(a+b+c>=2)	cnt++;
	}
	cout<<cnt<<endl;
}