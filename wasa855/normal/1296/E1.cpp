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
#define N 205
char s[N];
struct Node
{
	char ch;
	int id;
};
Node a[N];
int id[N],ok[N];
int pl[N];
bool cmp(Node x,Node y)
{
	if(x.ch!=y.ch) return x.ch<y.ch;
	return x.id<y.id;
}
int ans[N],col[N];
signed main()
{
#ifdef __LOCAL__
	freopen("in.txt","r",stdin);
#endif
	int n=read();
	scanf("%s",s+1);
	for(int i=1;i<=n;i++) id[i]=i;
//	{
//		a[i].ch=s[i],a[i].id=i;
//	}
//	sort(a+1,a+n+1,cmp);
//	for(int i=1;i<=n;i++) pl[i]=a[i].id;
	int las=0;
	for(int i=1;i<=n;i++)
	{
		int minn=i;
		for(int j=i+1;j<=n;j++)
		{
			if(s[id[j]]<s[id[minn]]) minn=j;
		}
		if(minn==i) continue;
		if(ok[id[minn]]==1)
		{
			cout<<"NO\n";
			return 0;
		}
		col[id[minn]]=1;
		for(int j=minn-1;j>=i;j--)
		{
			if(col[id[j]]==col[id[j+1]])
			{
				cout<<"NO\n";
				return 0;
			}
			ok[id[j]]=1;
			swap(id[j],id[j+1]);
		}
//		cout<<i<<endl;
//		for(int i=1;i<=n;i++) printf("%c",s[id[i]]);cout<<"\n";
//		for(int i=1;i<=n;i++) printf("%d",col[id[i]]);cout<<"\n";
	}
	cout<<"YES\n";
	for(int i=1;i<=n;i++) printf("%d",col[i]);
	cout<<"\n";
#ifdef __LOCAL__
	cout<<"Time Used : "<<clock()<<endl;
#endif
	return 0;
}