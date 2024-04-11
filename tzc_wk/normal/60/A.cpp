#include <bits/stdc++.h>
using namespace std;
int n,m;
int main(){
	cin>>n>>m;
	int l=1,r=n;
	for(int i=0;i<m;i++){
		string a,b,c,d;
		int x;
		cin>>a>>b>>c>>d>>x;
		if(c=="left")	r=min(r,x-1);
		else if(c=="right")	l=max(l,x+1);
	}
	if(r-l<0)	cout<<"-1\n";
	else	cout<<r-l+1<<endl;
}