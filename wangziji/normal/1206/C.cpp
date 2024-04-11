#include <iostream>
using namespace std;
int ans[200005];
int main(int argc, char** argv) {
	int n;
	cin >> n;
	if(!(n&1))
	{
		puts("NO");
		return 0;
	}
	puts("YES");
	for(int i=1;i<=n;i++)
	{
		if(i&1)
			ans[i]=2*i-1;
		else
			ans[i]=2*i;
	}
	for(int i=n+1;i<=n*2;i++)
	{
		if(ans[i-n]&1)
			ans[i]=ans[i-n]+1;
		else
			ans[i]=ans[i-n]-1;
	}
	for(int i=1;i<=n*2;i++)
		cout << ans[i] << " ";
	return 0;
}