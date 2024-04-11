#include<bits/stdc++.h>
using namespace std;
const long long inf=0x3f3f3f3f;
const long long inf2=0x3f3f3f3f3f3f3f3f;
const double eps=1e-6;
const long long mod=1000000007;
long long t,n,a,b,k;
bool check(long long mid)
{
	long long big=max(a,b),small=min(a,b);
	long long p=t;long long bigmul=(a>=b?(n+1)/2:n/2),smallmul=(a<b?(n+1)/2:n/2);
	long long bigyu=0,smallyu=0;
	if(k>bigmul)
	{
		if(k>bigmul+smallmul)return false;
		long long minu=k-bigmul;
		if(minu*mid>smallmul*small)return false;
		if(k*mid>smallmul*small+bigmul*big)return false;
		return true;
	}
	else
	{
		long long f=bigmul*(big-small)/k;
		if(f>=mid)return true;
		bigyu+=bigmul*(big-small)%k;
		long long ff=(bigmul+smallmul)*small+bigyu;
		return f+ff/k>=mid;
	}
}
signed main()
{
	cin>>t>>n>>a>>b>>k;
	long long l=0,r=t+1;
	while(r-l>1)
	{
		long long mid=l+r>>1;
		if(check(mid))
			l=mid;
		else 
			r=mid;
	}
	cout<<l<<endl;
	return 0;
}