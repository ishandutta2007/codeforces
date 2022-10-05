#include <bits/stdc++.h>
using namespace std;
int main(){
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	int n;
	cin>>n;
	for(int i=0;i<3;i++){
		int x,y;
		cin>>x>>y;
		if(x==n)	n=y;
		else if(y==n)	n=x;
	}
	cout<<n<<endl;
	return 0;
}