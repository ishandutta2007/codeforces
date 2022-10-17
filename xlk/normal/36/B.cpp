#include<fstream>
using namespace std;
int n,m,k;
char s[5][5];
int F(int x,int y,int m)
{
	m/=n;
	return m>0&&(s[x/m][y/m]=='*'||F(x%m,y%m,m));
}
int main()
{
	ifstream cin("input.txt");
	ofstream cout("output.txt");
	cin>>n>>k;
	for(int i=0;i<n;i++)
		cin>>s[i];
	for(int i=m=1;i<=k;i++)
		m*=n;
	for(int i=0;i<m;i++)
	{
		for(int j=0;j<m;j++)
			cout<<(F(i,j,m)?"*":".");
		cout<<endl;
	}
	return 0;
}