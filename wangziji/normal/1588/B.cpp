#include <bits/stdc++.h>
#define int long long
using namespace std;
inline int query(int l,int r)
{
	cout << "? " << l << " " << r << endl;
	int x;
	cin >> x;
	return x;
}
signed main(int argc, char** argv) {
	int T;
	cin >> T;
	while(T--)
	{
		int n;
		cin >> n;
		int l=1,r=n-1,qwq=query(1,n),i=0;
		while(l<=r)
		{
			int mid=(l+r)/2;
			if(query(mid,n)==qwq) i=mid,l=mid+1;
			else r=mid-1;
		}
		int x=query(i+1,n);
		int j=i+qwq-x+1;
		x=query(j,n);
		int k=sqrt(x*2)+j;
		cout << "! " << i << " " << j << " " << k << endl;
	}
	return 0;
}