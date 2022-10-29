#include <iostream>
using namespace std;
int main(int argc, char** argv) {
	int T;
	cin >> T;
	while(T--)
	{
		int n,m;
		cin >> n >> m;
		int mn=1e9,mn2=1e9,sum=0,w,w2;
		for(int i=1;i<=n;i++)
		{
			int t;
			cin >> t;
			if(t<mn) mn2=mn,mn=t,w2=w,w=i;
			else if(t<mn2) mn2=t,w2=i;
			sum+=t; 
		}
		if(m<n||n==2)
		{
			puts("-1");
			continue;
		}
		cout << sum*2+(m-n)*(mn+mn2) << endl;
		for(int i=1;i<=n;i++)
			cout << i << " " << i%n+1 << endl;
		for(int i=n+1;i<=m;i++)
			cout << w << " " << w2 << endl;
	}
	return 0;
}