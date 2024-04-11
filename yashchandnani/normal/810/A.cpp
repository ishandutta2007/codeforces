#include <bits/stdc++.h>
using namespace std;

int main(){
	int n,k;
	cin>>n>>k;
	int sum=0,x;
	for (int i = 0; i < n; ++i)
	{
		cin>>x;
		sum+=x;
	}
	x=0;
	double y=k;
	y-=.5;
	while(sum+x*k<y*(x+n)){
		x++;
	}
	cout<<x<<endl;
	return 0;
}