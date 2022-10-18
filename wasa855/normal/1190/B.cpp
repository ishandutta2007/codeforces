#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define mp make_pair
#define Fast_IO ios::sync_with_stdio(false);
#define int long long
inline int read()
{
	char ch=getchar(); int nega=1; while(!isdigit(ch)) {if(ch=='-') nega=-1; ch=getchar();}
	int ans=0; while(isdigit(ch)) {ans=ans*10+ch-48;ch=getchar();}
	if(nega==-1) return -ans;
	return ans;
}
#define N 100005
int a[N];
signed main()
{
#ifdef __LOCAL__
	freopen("in.txt","r",stdin);
#endif
	int n;
	cin>>n;
	int sum=0;
	for(int i=1;i<=n;i++) a[i]=read(),sum+=a[i];
	sort(a+1,a+n+1);
	int cnt=0;
	for(int i=1;i<n;i++)
	{
		if(a[i]==a[i+1]) cnt++;
	}
	if(cnt>1)
	{
		cout<<"cslnb\n";
		return 0;
	}
	if(cnt==1)
	{
		for(int i=1;i<n;i++)
		{
			if(a[i]==a[i+1])
			{
				if(a[i]==0||(i!=1&&a[i]==a[i-1]+1))
				{
					cout<<"cslnb\n";
					return 0;
				}
			}
		}
	}
	sum-=(n*(n-1)/2);
	if(sum<0||sum%2==0) cout<<"cslnb\n";
	else cout<<"sjfnb\n";
#ifdef __LOCAL__
	printf("Time Used : %d\n",clock());
#endif
	return 0;
}