#include <iostream>
#define int long long
#define mod 13141702292180207
using namespace std;
int ksm[1000005],qzh[1000005],hzh[1000005];
string a;
inline bool pd(int l,int r)
{
	if(r<l) return 0;
	int L=l,R=r;
	while(L<=R)
	{
		if(a[L]!=a[R]) return 0;
		++L,--R;
	}
	return 1;
}
signed main(int argc, char** argv) {
	ios::sync_with_stdio(false);
	int T;
	cin >> T;
	srand((unsigned long long)new char);
	int base=27;
	ksm[0]=1;
	for(int i=1;i<=1000000;i++)
		ksm[i]=ksm[i-1]*base%mod;
	while(T--)
	{
		cin >> a;
		int n=a.size();
		a=' '+a;
		int l=1,r=n;
		while(a[l]==a[r]&&l<=r) ++l,--r;
		--l,++r;
	//	cout << l << " " << r << "\n";
		if(l==r)
		{
			cout << a.substr(1,a.size()-1) << "\n";
			continue;
		}
		int mx=0;
		for(int i=l+1;i<r;i++)
			if(pd(l+1,i)) mx=i-l;
	//	cout << pd(4,6) << "\n";
		int MX=0;
		for(int i=r-1;i>l;i--)
			if(pd(i,r-1)) MX=r-i;
	//	cout << mx << " " << r << "\n" << l << " " << mx << "\n";
	//	cout << mx << " " << MX << "\n";
		if(mx>=MX) cout << a.substr(1,mx+l) << a.substr(r,a.size()+1-r) << "\n";
		else cout << a.substr(1,l) << a.substr(r-MX,a.size()+1-r+MX) << "\n";
	}
	return 0;
}