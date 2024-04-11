#include <bits/stdc++.h>
using namespace std;
int a[300005],b[300005];
int A[300005],B[300005];
int n;
inline bool pd(int x)
{
	for(int i=1;i<=n;i++)
		A[i]=a[i],B[i]=b[i];
	for(int i=n+1;i<=n+x;i++)
		A[i]=100,B[i]=0;
	sort(A+1,A+n+x+1);
	sort(B+1,B+n+x+1);
	int k=n+x;
	k-=k/4;
	long long s=0;
	for(int i=n+x;i>=n+x-k+1;i--)
		s+=A[i]-B[i];
	if(s>=0) return 1;
	return 0;
}
int main(int argc, char** argv) {
	int T;
	cin >> T;
	while(T--)
	{
		cin >> n;
		for(int i=1;i<=n;i++)
			cin >> a[i];
		for(int j=1;j<=n;j++)
			cin >> b[j];
		int l=0,r=n+n/2,ans=r;
		while(l<=r)
		{
			int mid=(l+r)/2;
			if(pd(mid)) ans=mid,r=mid-1;
			else l=mid+1;
		}
		cout << ans << "\n";
	}
	return 0;
}