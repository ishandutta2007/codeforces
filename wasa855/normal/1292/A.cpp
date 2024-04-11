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
bool a[3][N];
signed main()
{
#ifdef __LOCAL__
	freopen("in.txt","r",stdin);
#endif
	int n,q;
	cin>>n>>q;
	int ans=0;
	for(int i=1;i<=q;i++)
	{
		int x=read()-1,y=read();
		if(a[x][y]==0)
		{
			if(a[x^1][y-1]) ans++;
			if(a[x^1][y]) ans++;
			if(a[x^1][y+1]) ans++;
			a[x][y]=1;
		}
		else
		{
			if(a[x^1][y-1]) ans--;
			if(a[x^1][y]) ans--;
			if(a[x^1][y+1]) ans--;
			a[x][y]=0;
		}
		if(ans==0) cout<<"Yes\n";
		else cout<<"No\n";
	}
#ifdef __LOCAL__
	printf("Time Used : %d\n",clock());
#endif
	return 0;
}