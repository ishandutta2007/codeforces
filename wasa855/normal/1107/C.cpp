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
#define N 200005
int a[N];
char s[N];
int t[N];
signed main()
{
#ifdef __LOCAL__
	freopen("in.txt","r",stdin);
#endif
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++) a[i]=read();
	scanf("%s",s+1);
	int ans=0;
	for(int i=1;i<=n;i++)
	{
		int j=i;
		while(s[j+1]==s[i]&&j<n) j++;
		int cnt=0;
		for(int k=i;k<=j;k++) t[++cnt]=a[k];
		sort(t+1,t+cnt+1,greater<int>());
		for(int k=1;k<=min(cnt,m);k++) ans+=t[k];
		i=j;
	}
	cout<<ans<<endl;
#ifdef __LOCAL__
	printf("Time Used : %d\n",clock());
#endif
	return 0;
}