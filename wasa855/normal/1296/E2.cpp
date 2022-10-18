#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define mp make_pair
#define Fast_IO ios::sync_with_stdio(false);
#define fir first
#define sec second
#define mod 998244353
inline int read()
{
	char ch=getchar(); int nega=1; while(!isdigit(ch)) {if(ch=='-') nega=-1; ch=getchar();}
	int ans=0; while(isdigit(ch)) {ans=ans*10+ch-48;ch=getchar();}
	if(nega==-1) return -ans;
	return ans;
}
typedef pair<int,int> pii;
int add(int x,int y){return x+y>mod?x+y-mod:x+y;}
int sub(int x,int y){return x-y<0?x-y+mod:x-y;}
#define N 200005
char s[N];
int f[N],maxn[N];
int col[N];
signed main()
{
#ifdef __LOCAL__
	freopen("in.txt","r",stdin);
#endif
	int n=read();
	scanf("%s",s+1);
	int ans=0;
	for(int i=n;i>=1;i--)
	{
		col[i]=maxn[s[i]-'a']+1;
		for(int j=s[i]-'a'+1;j<=25;j++)
		{
			if(col[i]>maxn[j]) maxn[j]=col[i];
		}
		if(col[i]>ans) ans=col[i];
	}
	cout<<ans<<endl;
	for(int i=1;i<=n;i++) printf("%d ",col[i]);
	cout<<"\n";
#ifdef __LOCAL__
	cout<<"Time Used : "<<clock()<<endl;
#endif
	return 0;
}