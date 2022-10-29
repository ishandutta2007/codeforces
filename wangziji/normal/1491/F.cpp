#include <iostream>
#include <vector>
using namespace std;
int pos=0;
int ans[10005];
signed main() {
	int T;
	cin >> T;
	while(T--)
	{
		int n;
		cin >> n;
		for(int i=1;i<=n;i++) ans[i]=0;
		pos=0;
		for(int i=2;i<=n;i++)
		{
			cout << "? " << i-1 << " " << 1 << endl;
			for(int j=1;j<i;j++) cout << j << " ";
			cout << endl << i << endl;
			int t;
			cin >> t;
			if(t)
			{
				pos=i;
				break;
			}
		}
		int l=1,r=pos-1;
		while(l<r)
		{
			int mid=(l+r)/2;
			cout << "? " << (mid-l+1) << " " << 1 << endl;
			for(int i=l;i<=mid;i++) cout << i << " " ;
			cout << endl << pos << endl;
			int t;
			cin >> t;
			if(t) r=mid;
			else l=mid+1; 
		}
		ans[l]=ans[pos]=1;
		for(int i=pos+1;i<=n;i++)
		{
			cout << "? " << 1 << " " << 1 << endl;
			cout << pos << endl << i << endl;
			int t;
			cin >> t;
			if(t) ans[i]=1; 
		}
		cout << "! ";
		int cnt=0;
		for(int i=1;i<=n;i++) cnt+=!ans[i];
		cout << cnt << " ";
		for(int i=1;i<=n;i++) if(!ans[i]) cout << i << " ";
		cout << endl;
	}
	return 0;
}