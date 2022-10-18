#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define mp make_pair
#define Fast_IO ios::sync_with_stdio(false);
#define fir first
#define sec second
inline int read()
{
	char ch=getchar(); int nega=1; while(!isdigit(ch)) {if(ch=='-') nega=-1; ch=getchar();}
	int ans=0; while(isdigit(ch)) {ans=ans*10+ch-48;ch=getchar();}
	if(nega==-1) return -ans;
	return ans;
}
typedef pair<int,int> pii;
#define N 200005
int cnt[N];
int n;
char s[N];
int ok(int x)
{
	for(int i=0;i<x;i++)
	{
		int now=0;
		for(int j=i;j<n;j+=x) now^=(s[j]-'0');
		if(now) return 0;
	}
	return 1;
}
signed main()
{
#ifdef __LOCAL__
	freopen("in.txt","r",stdin);
#endif
	cin>>n;
	scanf("%s",s);
	for(int i=0;i<n;i++) cnt[__gcd(i,n)]++;
	int ans=0;
	for(int i=1;i<=n;i++)
	{
		if(cnt[i]&&ok(i)) ans+=cnt[i];
	}
	cout<<ans<<endl;
#ifdef __LOCAL__
	printf("Time Used : %d\n",clock());
#endif
	return 0;
}