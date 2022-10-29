#include <iostream>
using namespace std;
long long a[100005];
int main(int argc, char** argv) {
	long long mx=0,sum=0;
	int n;
	cin >> n;
	for(int i=1;i<=n;i++)
	{
		cin >> a[i];
		mx=max(mx,a[i]);
		sum+=a[i];
	}
	if((sum&1)||mx>sum/2)
	{
		puts("NO");
	}
	else puts("YES");
	return 0;
}