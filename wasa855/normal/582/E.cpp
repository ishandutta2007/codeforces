#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define mp make_pair
#define Fast_IO ios::sync_with_stdio(false);
#define DEBUG fprintf(stderr,"Running on Line %d in Function %s\n",__LINE__,__FUNCTION__)
#define fir first
#define sec second
#define mod 1000000007
#define ll long long
#define inf 0x3f3f3f3f
#define INF 0x3f3f3f3f3f3f3f3f
inline int read()
{
	char ch=getchar(); int nega=1; while(!isdigit(ch)) {if(ch=='-') nega=-1; ch=getchar();}
	int ans=0; while(isdigit(ch)) {ans=ans*10+ch-48;ch=getchar();}
	if(nega==-1) return -ans;
	return ans;
}
typedef pair<int,int> pii;
inline int min(int x,int y,int z){return min(x,min(y,z));}
inline int max(int x,int y,int z){return max(x,max(y,z));}
inline int add(int x,int y){return x+y>=mod?x+y-mod:x+y;}
inline int add(int x,int y,int z){return add(add(x,y),z);}
inline int sub(int x,int y){return x-y<0?x-y+mod:x-y;}
inline int mul(int x,int y){return 1LL*x*y%mod;}
inline int mul(int x,int y,int z){return mul(mul(x,y),z);}
char s[505];
int lim=16,cnt;
int f[505][1<<16],t[1<<16];
int a[50],b[50];
void fwt_or(int f[],int typ)
{
	for(int i=1;i<(1<<lim);i<<=1)
	{
		for(int j=0;j<(1<<lim);j+=(i<<1))
		{
			for(int k=0;k<i;k++)
			{
				if(typ==1) f[i+j+k]=add(f[i+j+k],f[j+k]);
				else f[i+j+k]=sub(f[i+j+k],f[j+k]);
			}
		}
	}
}
void fwt_and(int f[],int typ)
{
	for(int i=1;i<(1<<lim);i<<=1)
	{
		for(int j=0;j<(1<<lim);j+=(i<<1))
		{
			for(int k=0;k<i;k++)
			{
				if(typ==1) f[j+k]=add(f[j+k],f[i+j+k]);
				else f[j+k]=sub(f[j+k],f[i+j+k]);
			}
		}
	}
}
int dfs(int l,int r)
{
	int id=++cnt;
	if(l==r)
	{
		for(int i=0;i<4;i++)
		{
			if(s[l]=='?'||s[l]=='A'+i)
			{
				int qaq=0;
				for(int j=0;j<16;j++) if((j>>i)&1) qaq|=(1<<j);
				f[id][qaq]=1;
			}
			if(s[l]=='?'||s[l]=='a'+i)
			{
				int qaq=0;
				for(int j=0;j<16;j++) if(!((j>>i)&1)) qaq|=(1<<j);
				f[id][qaq]=1;
			}
		}
		return id;
	}
	int mid=-1,_cnt=0;
	for(int i=l;i<=r;i++)
	{
		if(s[i]=='(') _cnt++;
		if(s[i]==')') _cnt--;
		if(_cnt==0)
		{
			mid=i+1; break;
		}
	}
	assert(mid!=-1);
	int ls=dfs(l+1,mid-2),rs=dfs(mid+2,r-1);
	if(s[mid]!='&')
	{
		fwt_or(f[ls],1),fwt_or(f[rs],1);
		for(int i=0;i<(1<<lim);i++) t[i]=mul(f[ls][i],f[rs][i]);
		fwt_or(t,-1),fwt_or(f[ls],-1),fwt_or(f[rs],-1);
		for(int i=0;i<(1<<lim);i++) f[id][i]=add(f[id][i],t[i]);
	}
	if(s[mid]!='|')
	{
		fwt_and(f[ls],1),fwt_and(f[rs],1);
		for(int i=0;i<(1<<lim);i++) t[i]=mul(f[ls][i],f[rs][i]);
		fwt_and(t,-1),fwt_and(f[ls],-1),fwt_and(f[rs],-1);
		for(int i=0;i<(1<<lim);i++) f[id][i]=add(f[id][i],t[i]);
	}
	return id;
}
signed main()
{
	int m;
	scanf("%s%d",s+1,&m);
	int n=strlen(s+1);
	for(int i=1;i<=m;i++)
	{
		int qaq=0;
		for(int j=0;j<4;j++) qaq|=(read()<<j);
		a[i]=qaq,b[i]=read();
	}
	// for(int i=1;i<=m;i++) printf("%d %d\n",a[i],b[i]);
	dfs(1,n);
	// for(int i=0;i<(1<<lim);i++)
	// {
		// if(f[1][i]) printf("%d %d\n",i,f[1][i]);
	// }
	int ans=0;
	for(int i=0;i<(1<<lim);i++)
	{
		bool ok=1;
		for(int j=1;j<=m;j++)
		{
			if(((i>>a[j])&1)!=b[j]) ok=0;
		}
		if(ok) ans=add(ans,f[1][i]);
	}
	cout<<ans<<endl;
	return 0;
}