#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define mp make_pair
#define Fast_IO ios::sync_with_stdio(false);
#define fir first
#define sec second
#define mod 998244353
#define INF 0x3fffffff
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
#define N 300005
#define M 1005
int sg[M][3];
int a[N],n,x,y,z,cir;
int mex(int x,int y,int z)
{
	int R=0;
	while(R==x||R==y||R==z) R++;
	return R;
}
int get(int x,int y)
{
	if(x<=1000) return sg[x][y];
	int R=(x-500)/cir*cir;
	return sg[x-R][y];
}
void work()
{
	n=read(),x=read(),y=read(),z=read();
	for(int i=1;i<=n;i++) a[i]=read();
	sg[0][0]=sg[0][1]=sg[0][2]=0;
	for(int i=1;i<=1000;i++)
	{
		sg[i][0]=mex(sg[max(i-x,0LL)][0],sg[max(i-y,0LL)][1],sg[max(i-z,0LL)][2]);
		sg[i][1]=mex(sg[max(i-x,0LL)][0],10,sg[max(i-z,0LL)][2]);
		sg[i][2]=mex(sg[max(i-x,0LL)][0],sg[max(i-y,0LL)][1],10);
	}
	cir=1;
	while(1)
	{
		bool ok=1;
		for(int i=1000;i>=500&&ok;i--)
		{
			for(int j=0;j<=2;j++)
			{
				if(sg[i][j]!=sg[i-cir][j]) ok=0;
			}
		}
		if(ok) break;
		cir++;
	}
	// cout<<cir<<endl;
	int A=0;
	for(int i=1;i<=n;i++) A^=get(a[i],0);
	int ans=0;
	for(int i=1;i<=n;i++)
	{
		if((A^get(a[i],0)^get(max(a[i]-x,0LL),0))==0) ans++;
		if((A^get(a[i],0)^get(max(a[i]-y,0LL),1))==0) ans++;
		if((A^get(a[i],0)^get(max(a[i]-z,0LL),2))==0) ans++;
	}
	printf("%lld\n",ans);
}
signed main()
{
	int T=read();
	while(T--) work();
	return 0;
}