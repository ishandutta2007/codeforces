#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
#include <map>
using namespace std;
const int bl=32;
inline int ask(int l,int r)
{
	cout << "? " << l << " " << r << endl;
	int x;
	cin >> x;
	return r-l+1-x; 
}
inline void solve(int L,int R,int k)
{
	int l=L,r=R,ans=0;
	while(l<=r)
	{
		int mid=(l+r)/2;
		if(ask(L,mid)<k) ans=mid,l=mid+1;
		else r=mid-1;
	}
	cout << "! "<< ans+1 << endl;
}
signed main(int argc, char** argv) {
	int n,t,k;
	cin >> n >> t >> k;
	solve(1,n,k);
	return 0;
}