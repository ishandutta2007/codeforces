#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define mp make_pair
#define Fast_IO ios::sync_with_stdio(false);
#define mod 1000000007
inline int read()
{
	char ch=getchar(); int nega=1; while(!isdigit(ch)) {if(ch=='-') nega=-1; ch=getchar();}
	int ans=0; while(isdigit(ch)) {ans=ans*10+ch-48;ch=getchar();}
	if(nega==-1) return -ans;
	return ans;
}
#define N 100005
int f[N][2];
char s[N];
signed main()
{
#ifdef __LOCAL__
	freopen("in.txt","r",stdin);
#endif
	scanf("%s",s+1);
	int n=strlen(s+1);
	f[1][0]=1;
	f[0][0]=1;
	if(s[1]=='w'||s[1]=='m')
	{
		cout<<"0\n";return 0;
	}
	for(int i=2;i<=n;i++)
	{
		f[i][0]=(f[i-1][0]+f[i-1][1])%mod;
		if(s[i-1]==s[i]&&(s[i]=='u'||s[i]=='n')) f[i][1]=(f[i-2][0]+f[i-2][1])%mod;
		if(s[i]=='w'||s[i]=='m')
		{
			cout<<"0\n";return 0;
		}
	}
	cout<<(f[n][0]+f[n][1])%mod<<endl;
#ifdef __LOCAL__
	printf("Time Used : %d\n",clock());
#endif
	return 0;
}