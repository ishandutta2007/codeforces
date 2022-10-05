#include<bits/stdc++.h>
using namespace std;
int n,h,l,r,t;
int main() {
	cin>>n>>h>>l>>r>>t;
	int a,b,c,d;
	for(int e=0;e<t;e++){
		cin>>a>>b>>c>>d;
		if (a==c) cout<<abs(b-d);
		else {
			if (b<l&&d<l) cout<<abs(a-c)+l-b+l-d;
			else if (b>r&&d>r) cout<<abs(a-c)+b-r+d-r;
			else cout<<abs(a-c)+abs(d-b);
		}
		cout<<endl;
	}
}//