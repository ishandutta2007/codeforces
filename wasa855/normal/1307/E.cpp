#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define mp make_pair
#define Fast_IO ios::sync_with_stdio(false);
#define fir first
#define sec second
#define mod 1000000007
#define ll long long
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
#define N 5005
int a[N];
int l[N],r[N],cnt[N][N];
signed main()
{
#ifdef __LOCAL__
	freopen("in.txt","r",stdin);
#endif
	int n,m; cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		a[i]=read();
		r[a[i]]++;
	}
	for(int i=1;i<=m;i++)
	{
		int u=read(),v=read();
		for(int j=v;j<=n;j++) cnt[u][j]++;
	}
	int ans=0,sum=0;
	for(int i=0;i<=n;i++)
	{
		if(i) l[a[i]]++,r[a[i]]--;
		int res=0,tot=1;
		if(i)
		{
			int x=l[a[i]],y=r[a[i]];
			int L=cnt[a[i]][x]-cnt[a[i]][x-1];
			if(!L) continue;
			int R=cnt[a[i]][y]-(y>=x);
			if(!R) res++,tot=mul(tot,L);
			else res+=2,tot=mul(mul(tot,L),R);
		}
		for(int j=1;j<=n;j++)
		{
			if(i==0||a[i]!=j)
			{
				int Ma=l[j],Mi=r[j];
				if(Ma<Mi) swap(Ma,Mi);
				if(cnt[j][Ma])
				{
					if(!cnt[j][Mi]) res++,tot=mul(tot,cnt[j][Ma]);
					else if(cnt[j][Ma]==1) res++,tot=add(tot,tot);
					else res+=2,tot=mul(mul(tot,cnt[j][Mi]),cnt[j][Ma]-1);
				}
			}
		}
		if(res>ans) ans=res,sum=0;
		if(ans==res) sum=add(sum,tot);
	}
	sum=(sum+mod)%mod;
	printf("%d %d\n",ans,sum);
#ifdef __LOCAL__
	cout<<"Time Used : "<<clock()<<endl;
#endif
	return 0;
}