#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define eb emplace_back
#define mp make_pair
#define Fast_IO ios::sync_with_stdio(false);
#define DEBUG fprintf(stderr,"Running on Line %d in Function %s\n",__LINE__,__FUNCTION__)
//mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());
#define fir first
#define sec second
#define mod 998244353
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
void print(vector<int> x){for(int i=0;i<(int)x.size();i++) printf("%d%c",x[i]," \n"[i==(int)x.size()-1]);}
#define N 22
int s[N],len[N],t[N];
struct Seg
{
	int l,r,id;
};
Seg a[N];
struct Node
{
	int len,id;
};
Node b[N];
int f[1<<N],fr[1<<N],be[1<<N],n,p;
int ans[N],ans2[N];
int get(int val)
{
	for(int i=0;i<n;i++)
	{
		if(val>>i&1) return i;
	}
	assert(0);
}
signed main()
{
	cin>>n>>p;
	for(int i=0;i<n;i++) s[i]=read(),len[i]=read(),t[i]=read();
	for(int i=0;i<n;i++) a[i].l=s[i],a[i].r=s[i]+len[i]-1,a[i].id=i;
	for(int i=0;i<n;i++) b[i].len=t[i],b[i].id=i;
	sort(a,a+n,[&](Seg x,Seg y){return x.l<y.l;});
	sort(b,b+n,[&](Node x,Node y){return x.len<y.len;});
	memset(f,0x3f,sizeof(f));
	f[0]=1;
	a[n].l=inf;
	// for(int i=0;i<n;i++) printf("%d %d\n",a[i].l,a[i].r);
	for(int i=0;i<1<<n;i++)
	{
		if(f[i]==inf) continue;
		int cur=0,beg;
		while(cur<n&&a[cur].r<f[i]) cur++;
		if(cur==n) continue;
		beg=f[i];
		// if(beg==2704023) printf("%d -- %d %d\n",i,cur,beg);
		while(a[cur].l<=beg&&a[cur].r>=beg) beg=a[cur].r+1,cur++;
		// printf("%d - %d\n",i,cur);
		// if(beg==2704023) printf("%d -- %d %d\n",i,cur,beg);
		while(cur<n&&!(i>>a[cur].id&1)) cur++;
		for(int j=0;j<n;j++)
		{
			if(i>>b[j].id&1) continue;
			// printf("%d %d %d\n",a[cur].l,a[cur].l-beg-1,b[j].len);
			if(a[cur].l-beg-1>=b[j].len)
			{
				if(beg+b[j].len<f[i|1<<b[j].id]&&beg+b[j].len<s[b[j].id])
				{
					f[i|1<<b[j].id]=beg+b[j].len;
					fr[i|1<<b[j].id]=i;
					be[i|1<<b[j].id]=beg;
				}
			}
			else
			{
				while(a[cur].l-beg-1<b[j].len)
				{
					beg=a[cur].r+1; cur++;
					while(a[cur].l<=beg&&a[cur].r>=beg) beg=a[cur].r+1,cur++;
					while(cur<n&&!(i>>a[cur].id&1)) cur++;
					// printf("* %d %d\n",beg,cur);
				}
				if(a[cur].l-beg-1>=b[j].len)
				{
					// printf("%d %d\n",beg+b[j].len,s[b[j].id]);
					if(beg+b[j].len<f[i|1<<b[j].id]&&beg+b[j].len<s[b[j].id])
					{
						f[i|1<<b[j].id]=beg+b[j].len;
						fr[i|1<<b[j].id]=i;
						be[i|1<<b[j].id]=beg;
					}
				}
			}
		}
		// cout<<"--\n";
		// for(int i=1;i<1<<n;i++) printf("%d ",f[i]); cout<<"\n";
		// for(int i=1;i<1<<n;i++) printf("%d ",fr[i]); cout<<"\n";
		// cout<<"--\n";
	}
	int LIM=(1<<n)-1;
	// for(int i=1;i<1<<n;i++) printf("%d ",f[i]); cout<<"\n";
	// for(int i=1;i<1<<n;i++) printf("%d ",fr[i]); cout<<"\n";
	if(p==1)
	{
		if(f[LIM]!=inf)
		{
			cout<<"YES\n";
			int tmp=LIM;
			while(tmp)
			{
				int t=fr[tmp];
				ans[get(tmp^t)]=be[tmp];
				ans2[get(tmp^t)]=1;
				tmp=t;
			}
			for(int i=0;i<n;i++) printf("%d %d\n",ans2[i],ans[i]);
			return 0;
		}
		cout<<"NO\n";
		return 0;
	}
	for(int i=0;i<1<<n;i++)
	{
		if(f[i]!=inf&&f[LIM^i]!=inf)
		{
			cout<<"YES\n";
			int tmp=i;
			while(tmp)
			{
				int t=fr[tmp];
				ans[get(tmp^t)]=be[tmp];
				ans2[get(tmp^t)]=1;
				tmp=t;
			}
			tmp=LIM^i;
			while(tmp)
			{
				int t=fr[tmp];
				ans[get(tmp^t)]=be[tmp];
				ans2[get(tmp^t)]=2;
				tmp=t;
			}
			for(int i=0;i<n;i++) printf("%d %d\n",ans2[i],ans[i]);
			return 0;
		}
	}
	cout<<"NO\n";
	return 0;
}