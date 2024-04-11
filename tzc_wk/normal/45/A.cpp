#include <bits/stdc++.h>
using namespace std;
const string M[12] = {"January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December"};
string s;
int m;
int main(){
	cin>>s>>m;
	int cur;
	for(int i=0;i<12;i++){
		if(M[i]==s)	cur=i;	
	}
	cur=(cur+m)%12;
	cout<<M[cur]<<endl;
	return 0;
}