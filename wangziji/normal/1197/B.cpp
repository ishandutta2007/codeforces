#include <iostream>
using namespace std;
int n,a[200005];
int main(int argc, char** argv) {
	cin >> n;
	int pos=0;
	for(int i=1;i<=n;i++)
	{
		cin >> a[i];
		if(a[i]==n) pos=i;
	}
	for(int i=1;i<pos;i++)
	{
		if(a[i]>a[i+1])
		{
			puts("NO");
			return 0;
		}
	}
	for(int i=pos+1;i<=n;i++)
	{
		if(a[i]>a[i-1])
		{
			puts("NO");
			return 0;
		}
	}
	puts("YES");
	return 0;
}