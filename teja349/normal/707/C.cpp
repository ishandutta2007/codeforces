#include<iostream>
#include<math.h>
using namespace std;
int main(){
	long long int n,q;
	cin>>n;
	long long int p=n*n;
	for (int i = 1; i < n ; ++i)
	{
		if(p%i==0)
		{
			q=p/i;
			if((i%2+q%2)%2==0)
			{
				cout<<(i+q)/2<<" "<<(q-i)/2<<endl;
				return 0;
			}
		}
	}
	p=sqrt(n);
	for (int i = 1; i < p+1; ++i)
	{
		for (int j = i+1; j < p+1; ++j)
		{
			q=i*i+j*j;
			if(q==n){
				cout<<j*j-i*i<<" "<<2*j*i<<endl;
				return 0;
			}
			else if(q>n){
				break;
			}
		}
	}
	cout<<-1<<endl;
	return 0;
}