#include<bits/stdc++.h>
using namespace std;
int main()
{
	
	int n;
	cin>>n;
	if(n&1&&n!=1){
	cout<<"YES\n";	
	cout<<'1'<<' ';
	int i=1;
	int j=2;
	while(i<n-1)
	{
		if(!(i&1)){
		cout<<2*n-j<<" " ;
		j=j+1;
	
	}
	else
	{
		cout<<2*n-j<<" ";
		j=j+3;
	}
	i++;
	}
	cout<<2*n-1<<" "<<2<<' ';
	i=1;
	j=3;
	while(i<n-1)
	{
		cout<<2*n-j<<" " ;
		if(!(i&1)) j=j+3;
		else j=j+1;
		i++;
	}
	cout<<2*n;
}
else if(!(n&1)) cout<<"NO";
else
{
	cout<<"YES\n";
	cout<<1<<' '<<2;
}

}