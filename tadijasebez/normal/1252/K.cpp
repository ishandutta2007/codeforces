#include <iostream>
using namespace std;
int main()
{
	int n;
	cin>>n;
	int p[6]={4,1,3,2,0,5};
	int m=0;
	for(int i=0;i<6;i++)if(n>>i&1)m+=1<<p[i];
	cout<<m;
	return 0;
}