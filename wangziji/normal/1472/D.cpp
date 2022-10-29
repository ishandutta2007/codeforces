#include <iostream>
#include <algorithm>
using namespace std;
int a[200005];
int main(int argc, char** argv) {
	int T;
	cin >> T;
	while(T--)
	{
		int n;
		cin >> n;
		for(int i=1;i<=n;i++)
			cin >> a[i];
		sort(a+1,a+n+1);
		long long s=0;
		int flag=1;
		for(int i=n;i>=1;i--)
		{
			if(flag)
			{
				if(a[i]%2==0) s+=a[i];
			}
			else if(a[i]%2==1) s-=a[i]; 
			flag^=1;
		}
		if(s>0) puts("Alice");
		else if(s==0) puts("Tie");
		else puts("Bob"); 
	}
	return 0;
}