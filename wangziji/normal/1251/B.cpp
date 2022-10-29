#include <iostream>
using namespace std;
int main(int argc, char** argv) {
	int T;
	cin >> T;
	while(T--)
	{
		int n;
		cin >> n;
		int flag=0,cnt=0;
		for(int i=1;i<=n;i++)
		{
			string a;
			cin >> a;
			if(a.size()%2==1)
				flag=1;
			for(int j=0;j<a.size();j++)
				cnt+=(a[j]==49);
		}
		if(flag==1)
			cout << n << endl;
		else
		{
			if(cnt&1)
				cout << n-1 << endl;
			else
				cout << n << endl;
		}
	}
	return 0;
}