#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define mp make_pair
#define Fast_IO ios::sync_with_stdio(false);
#define fir first
#define sec second
#define mod 998244353
#define ll long long
inline int read()
{
	char ch=getchar(); int nega=1; while(!isdigit(ch)) {if(ch=='-') nega=-1; ch=getchar();}
	int ans=0; while(isdigit(ch)) {ans=ans*10+ch-48;ch=getchar();}
	if(nega==-1) return -ans;
	return ans;
}
typedef pair<int,int> pii;
int add(int x,int y){return x+y>=mod?x+y-mod:x+y;}
int sub(int x,int y){return x-y<0?x-y+mod:x-y;}
int mul(int x,int y){return 1LL*x*y%mod;}
#define N 1000005
int a[N];
signed main()
{
	int n; string s;
	cin>>n>>s;
	s=' '+s;
	int ans=0;
	for(int i=1;i<=n;i++)
	{
		a[i]=a[i-1];
		if(s[i]=='(') a[i]++;
		else a[i]--;
	}
	if(a[n]!=0)
	{
		cout<<"-1\n";
		return 0;
	}
	int las=0;
	for(int i=1;i<=n;i++)
	{
		if(a[i]==0&&a[i-1]<0)
		{
			ans+=i-las;
		}
		if(a[i]==0) las=i;
	}
	cout<<ans<<endl;
	return 0;
}