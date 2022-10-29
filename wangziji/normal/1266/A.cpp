#include <iostream>
using namespace std;
int main(int argc, char** argv) {
	int T;
	cin >> T;
	while(T--)
	{
		string a;
		cin >> a;
		int cnt=0,sum=0,f=0;
		for(int i=0;i<a.size();i++)
		{
			sum+=a[i]-48;
			cnt+=a[i]%2==0;
			f|=a[i]==48;
		}
		if(sum%3==0&&f&&cnt>=2)
		{
			puts("red");
		}
		else
			puts("cyan");
	}
	return 0;
}