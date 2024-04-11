#include <iostream>
using namespace std;
int a[200005];
int main(int argc, char** argv) {
	int q;
	cin >> q;
	while(q--)
	{
		int n,k;
		cin >> n >> k;
		int cnt=0;
		for(int i=1;i<=n;i++)
		{
			cin >> a[i];
			if(a[i]&1)
				++cnt;
		}
		if(k>cnt)
		{
			puts("NO");
		}
		else if(cnt%2!=k%2)
		{
			puts("NO");
		}
		else
		{
			puts("YES");
			for(int i=1;i<=n;i++)
			{
				if(a[i]&1)
					--cnt;
				if(cnt==0)
				{
					cout << n;
					break;
				}
				if(cnt<k)
				{
					--k;
					cout << i << " ";
				}
			}
			cout << endl;
		}
	}
	return 0;
}