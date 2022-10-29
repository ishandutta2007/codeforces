#include <iostream>
using namespace std;
int main(int argc, char** argv) {
	int n;
	int flag=0,t=0;
	long long ans=0;
	cin >> n;
	for(int i=1;i<=n;i++)
	{
		int a;
		cin >> a;
		if(a<0)
			flag^=1;
		if(a==0)
			t=1;
		if(a<0)
			ans+=-a-1;
		if(a>0)
			ans+=a-1;
		if(a==0)
			++ans;
	}
	if(!t&&flag) ans+=2;
	cout << ans; 
	return 0;
}