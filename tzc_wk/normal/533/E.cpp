#include <bits/stdc++.h>
using namespace std;
string a,b;
int n,ans;
vector<int> dif;
int main(){
	cin>>n>>a>>b;
	int x1,x2,x3;
	for(x1=0;a[x1]==b[x1];x1++);
	for(x2=n-1;a[x2]==b[x2];x2--);
	for(x3=x1;x3<x2&&a[x3]==b[x3+1];x3++);
	if(x3==x2)	ans++;
	for(x3=x1;x3<x2&&a[x3+1]==b[x3];x3++);
	if(x3==x2)	ans++;
	cout<<ans<<endl;
}