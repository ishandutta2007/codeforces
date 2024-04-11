#include <iostream>
#include <cmath>
using namespace std;
int main(int argc, char** argv) {
	int n;
	string a;
	cin >> n >> a;
	a=' '+a;
	for(int x='z';x>='a';x--)
	{
		int T=100;
		while(T--)
		{
			for(int i=1;i<a.size();i++)
			{
				if((a[i]-a[i-1]==1||a[i]-a[i+1]==1)&&a[i]==x)
				{
					a=a.substr(0,i)+a.substr(i+1,a.size()-i-1);
					break; 
				}
			}
		}
	}
	cout << n+1-a.size();
	return 0;
}