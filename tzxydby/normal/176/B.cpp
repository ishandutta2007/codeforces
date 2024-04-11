#include<bits/stdc++.h>
using namespace std;
const int N=100005;
const int mod=1000000007;
const int h=31;
long long good[N],bad[N];
string a,b;
int main()
{
	ios::sync_with_stdio(false);
	int k,n,x=0;
	int s1=0,s2=0,t=1;
	char c;
	cin>>a>>b>>k;
	n=a.size();
	if(a==b)
		good[0]=1;
	else
		bad[0]=1;
	for(int i=0;i<n;i++)
		s2=s2*h+b[i];
	for(int i=0;i<n;i++)
		s1=s1*h+a[i];
	for(int i=1;i<=n;i++)
		t*=h;
	a=a+a;
	for(int i=n;i<2*n;i++)
	{
		if(s1==s2)
			x++;
		s1=s1*h-(a[i-n])*t+a[i];
	}
	for(int i=1;i<=k;i++)
	{
		good[i]=(good[i-1]*(x-1)+bad[i-1]*x)%mod;
		bad[i]=(good[i-1]*(n-x)+bad[i-1]*(n-x-1))%mod;
	}
	cout<<good[k]<<endl;
	return 0;
}