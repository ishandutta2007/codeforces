#include<iostream>
#include<cstdio>
using namespace std;
int main()
{
	int n,i,s,m,x;
	s=0;
	m=0;
	cin>>n;
	for(i=1;i<=n;i=i+1){
		cin>>x;
		s=s+x;
		m=max(m,x);
	}
	cout<<n*m-s<<endl;
	return 0;
}