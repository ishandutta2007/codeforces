#include<fstream>
using namespace std;
int n,x,y;
ifstream cin("input.txt");
ofstream cout("output.txt");
int main()
{
	cin>>n;
	for(int i=0;i<3;i++)
		cin>>x>>y,n=n==x?y:n==y?x:n;
	cout<<n;	
	return 0;
}