#include <iostream>
#define int long long
#define mod 13141702292180207
using namespace std;
int ksm[1000005],qzh[1000005],hzh[1000005];
string a;
int n;
inline int mul(int x,int y){
    int z=(long double)x/mod*y;
    int res=(unsigned int)x*y-(unsigned int)z*mod;
    return (res+mod)%mod;
}
inline int hsh1(int l,int r)
{
//	cout << l << " " << r << "   " << (mul(hzh[l]-hzh[r+1],ksm[n-l+1])+mod)%mod << "\n";
	return (mul(hzh[l]-hzh[r+1],ksm[n-l+1])+mod)%mod;
}
inline int hsh2(int l,int r)
{
//	cout << l << " " << r << "   " << (mul(qzh[r]-qzh[l-1],ksm[r])+mod)%mod << "\n\n";
	return (mul(qzh[r]-qzh[l-1],ksm[r])+mod)%mod;
}
inline bool pd(int l,int r)
{
	if(r<l) return 0;
	int mid=(l+r)/2;
	if((l+r)&1) return hsh1(l,mid)==hsh2(mid+1,r);
	else return hsh1(l,mid)==hsh2(mid,r);
	/*int L=l,R=r;
	while(L<=R)
	{
		if(a[L]!=a[R]) return 0;
		++L,--R;
	}
	return 1;*/
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
		n=a.size();
		a=' '+a;
		for(int i=1;i<=n;i++)
			qzh[i]=(qzh[i-1]+mul(a[i],ksm[n-i+1]))%mod;
		hzh[n+1]=0;
		for(int i=n;i>=1;i--)
			hzh[i]=(hzh[i+1]+mul(a[i],ksm[i]))%mod;
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