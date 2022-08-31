#include<iostream>
using namespace std;
int main(){
	int n,m,t,p=0,q=0;
	cin>>n;
	for (int i = 0; i < n; ++i)
	{
		cin>>t>>m;
		if(t<m)
			q++;
		else if(m<t)
			p++;
	}
	if(p>q)
		cout<<"Mishka";
	else if(q>p)
		cout<<"Chris";
	else
		cout<<"Friendship is magic!^^";

}