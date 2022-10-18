#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define mp make_pair
#define Fast_IO ios::sync_with_stdio(false);
inline int read()
{
	char ch=getchar(); int nega=1; while(!isdigit(ch)) {if(ch=='-') nega=-1; ch=getchar();}
	int ans=0; while(isdigit(ch)) {ans=ans*10+ch-48;ch=getchar();}
	if(nega==-1) return -ans;
	return ans;
}
#define N 2005
int a[N];
int b[N];
int n;
map<int,int> c;
bool cmp(int x,int y)
{
	int cnt=0;
	for(int i=1;i<x;i++) b[++cnt]=a[i];
	for(int i=y+1;i<=n;i++) b[++cnt]=a[i];
	sort(b+1,b+cnt+1);
	for(int i=1;i<cnt;i++) if(b[i]==b[i+1]) return false;
	return true;
}
signed main()
{
#ifdef __LOCAL__
	freopen("in.txt","r",stdin);
#endif
	cin>>n;
	for(int i=1;i<=n;i++) a[i]=read();
	if(cmp(0,0))
	{
		cout<<"0"<<endl;
		return 0;
	}
	int ans=n;
	for(int i=0;i<=n;i++)
	{
		if(c[a[i]]!=0) break;
		c[a[i]]++;
		for(int j=n;j>=i;j--)
		{
			if(c[a[j]]!=0)
			{
				if(j-i<ans) ans=j-i;
				for(int k=j+1;k<=n;k++) c[a[k]]--;
				break;
			}
			c[a[j]]++;
		}
	}
	cout<<ans<<endl;
#ifdef __LOCAL__
	printf("Time Used : %d\n",clock());
#endif
	return 0;
}
//