#include <bits/stdc++.h>
using namespace std;
int cnt=0,a,b;
int main(){
	cin>>a>>b;
	while(a<=b){
		a*=3;
		b*=2;
		cnt++;
	}
	cout<<cnt<<endl;
	return 0;
}