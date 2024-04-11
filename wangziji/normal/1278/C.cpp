#include <iostream>
using namespace std;
int a[500005],b[500005];
int main(int argc, char** argv) {
	int T;
	cin >> T;
	while(T--)
	{
		int n;
		cin >> n;
		for(int i=1;i<=n*2;i++)
			cin >> a[i];
		int x=0,y=0;
		for(int i=200000-n;i<=200000+n;i++)
			b[i]=-1;
		b[200000]=0;
		for(int i=1;i<=n;i++)
		{
			x+=2-a[i],y+=a[i]-1;
			b[x-y+200000]=i;
		}
		x=y=0;
		int ans=0;
		ans=max(ans,b[200000]);
		for(int i=2*n;i>=n+1;i--)
		{
			x+=2-a[i],y+=a[i]-1;
			if(b[y-x+200000]!=-1)
			{
				//cout << b[y-x+200000] << " " << n*2-i+1 << endl;
				ans=max(ans,b[y-x+200000]+2*n-i+1);
			}
		}
		cout << 2*n-ans << endl;
	}
	return 0;
}