#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define mp make_pair
#define Fast_IO ios::sync_with_stdio(false);
#define fir first
#define sec second
#define int long long
inline int read()
{
	char ch=getchar(); int nega=1; while(!isdigit(ch)) {if(ch=='-') nega=-1; ch=getchar();}
	int ans=0; while(isdigit(ch)) {ans=ans*10+ch-48;ch=getchar();}
	if(nega==-1) return -ans;
	return ans;
}
typedef pair<int,int> pii;

signed main()
{
#ifdef __LOCAL__
	freopen("in.txt","r",stdin);
#endif
	int n=read();
	int ans=n;
	int ax=1,ay=n;
	for(int i=1;i*i<=n;i++)
	{
		if(n%i==0)
		{
			int j=n/i;
			if(i/__gcd(i,j)*j==n)
			{
				if(max(i,j)<ans) ans=max(i,j),ax=i,ay=j;
			}
		}
	}
	cout<<ax<<" "<<ay<<endl;
#ifdef __LOCAL__
	printf("Time Used : %d\n",clock());
#endif
	return 0;
}