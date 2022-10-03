#include <bits/stdc++.h>
using namespace std;

int main() {
	int n; cin>>n;
	int a=-1,b=-1;
	for(;n--;) a=b, cin>>b;
	if(b==15) goto down;
	if(b>0 && a!=-1 && a>b) goto down;
	if(b==0) goto up;
	if(b<15 && a!=-1 && a<b) goto up;
	cout<<"-1\n";
	return 0;
	down:;
	cout<<"DOWN\n";
	return 0;
	up:;
	cout<<"UP\n";
}