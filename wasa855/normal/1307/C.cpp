#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define mp make_pair
#define Fast_IO ios::sync_with_stdio(false);
#define fir first
#define sec second
#define mod 998244353
#define ll long long
#define int long long
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
#define N 100005
char s[N];
int cnt[30][N];
int n;
int getans(int x,int y)
{
	int ans=0;
	for(int i=1;i<=n;i++)
	{
		if(s[i]-'a'==x) ans+=cnt[y][i+1];
	}
//	printf("%d %d %d\n",x,y,ans);
	return ans;
}
signed main()
{
#ifdef __LOCAL__
	freopen("in.txt","r",stdin);
#endif
	scanf("%s",s+1);
	n=strlen(s+1);
	if(n==1)
	{
		cout<<"1\n";
		return 0;
	}
	for(int i=n;i>=1;i--)
	{
		for(int j=0;j<26;j++) cnt[j][i]=cnt[j][i+1];
		cnt[s[i]-'a'][i]++;
	}
	int ans=0;
	for(int i=0;i<26;i++) ans=max(ans,cnt[i][1]);
//	cout<<ans<<endl;
	for(int i=0;i<26;i++)
	{
		for(int j=0;j<26;j++) ans=max(ans,getans(i,j));
	}
	cout<<ans<<endl;
#ifdef __LOCAL__
	cout<<"Time Used : "<<clock()<<endl;
#endif
	return 0;
}