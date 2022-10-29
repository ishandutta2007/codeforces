#include <iostream>
using namespace std;
int a[200005];
int main(int argc, char** argv) {
	int T;
	cin >> T;
	while(T--)
	{
		int n,lst;
		string b;
		cin >> n >> b;
		for(int i=1;i<=n;i++) a[i]=n-i+1;
		lst=1;
		b[n-1]='>';
		for(int i=1;i<=n;i++)
		{
			if(b[i-1]=='<') continue;
			if(b[i-1]=='>')
			{
				int x=lst,y=i;
				while(x<=y) swap(a[x++],a[y--]);
				lst=i+1;
			}
		}
		for(int i=1;i<=n;i++)
			cout << a[i] << " ";
		cout << "\n";
		for(int i=1;i<=n;i++) a[i]=i;
		lst=1;
		b+='<';
		for(int i=1;i<=n;i++)
		{
			if(b[i-1]=='>') continue;
			if(b[i-1]=='<')
			{
				int x=lst,y=i;
				while(x<=y) swap(a[x++],a[y--]);
				lst=i+1;
			}
		}
		for(int i=1;i<=n;i++)
			cout << a[i] << " ";
		cout << "\n";
	}
	return 0;
}