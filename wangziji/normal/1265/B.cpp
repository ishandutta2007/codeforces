#include <iostream>
using namespace std;
int pos[200005],a[200005],s[200005];
int main(int argc, char** argv) {
	int T;
	cin >> T;
	while(T--)
	{
		int n;
		cin >> n;
		for(int i=1;i<=n;i++)
		{
			cin >> a[i];
			pos[a[i]]=i;
		}
		int now=0;
		for(int i=1;i<=n;i++)
		{
			now+=!s[pos[i]-1];
			now+=!s[pos[i]+1];
			now-=s[pos[i]-1];
			now-=s[pos[i]+1];
			s[pos[i]]=1;
			cout << (now==2);
		}
		cout << endl;
		for(int i=1;i<=n;i++)
			pos[i]=a[i]=s[i]=0;
	}
	return 0;
}