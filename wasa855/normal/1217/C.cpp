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
#define N 200005
string s;
int nxt[N];
void work()
{
	cin>>s;
	int n=s.length();
	int ans=0;
	nxt[n]=n;
	for(int i=n-1;i>=0;i--)
	{
		if(s[i]=='0') nxt[i]=nxt[i+1];
		else nxt[i]=i;
	}
	for(int i=0;i<n;i++)
	{
		int t=min(nxt[i]+20,n);
		int tsum=0;
		for(int j=nxt[i];j<t;j++)
		{
			tsum=tsum*2+s[j]-'0';
			if(tsum==j-i+1) ans++;
		}
//		cout<<ans<<endl;
	}
	printf("%d\n",ans);
}
signed main()
{
#ifdef __LOCAL__
	freopen("in.txt","r",stdin);
#endif
	int T=read();
	while(T--) work();
#ifdef __LOCAL__
	printf("Time Used : %d\n",clock());
#endif
	return 0;
}