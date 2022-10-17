#include<iostream>
#include<string.h>
using namespace std;
typedef long long ll;
int n,s[52];
ll f[52][2][2],k;
ll F(int x,int p,int q)
{
	ll &t=f[x][p][q];
	if(~t)
		return t;
	t=0;
	if(x*2>=n)
		return t=1;
	for(int i=0;i<2;i++)
		if(s[x]<0||s[x]==i)
			for(int j=0;j<2;j++)
				if(s[n-1-x]<0||s[n-1-x]==j)
					if((i==j||x*2+1!=n)&&(p||i<=j)&&(q||!i||!j))
						t+=F(x+1,p||i<j,q||!i&&!j);
	return t;
}
int main()
{
	cin>>n>>k,k++;
	memset(f,-1,sizeof f);
	memset(s,-1,sizeof s);
	if(F(0,0,0)<k)
		return cout<<-1,0;
	for(int i=0;i<n;i++)
	{
		s[i]=0;
		memset(f,-1,sizeof f);
		if(F(0,0,0)<k)
			s[i]=1,k-=F(0,0,0);
		cout<<s[i];
	}
	return 0;
}