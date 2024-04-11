#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define mp make_pair
#define Fast_IO ios::sync_with_stdio(false);
#define fir first
#define sec second
#define ll long long
inline int read()
{
	char ch=getchar(); int nega=1; while(!isdigit(ch)) {if(ch=='-') nega=-1; ch=getchar();}
	int ans=0; while(isdigit(ch)) {ans=ans*10+ch-48;ch=getchar();}
	if(nega==-1) return -ans;
	return ans;
}
typedef pair<int,int> pii;
int add(int x,int y,int mod){return x+y>=mod?x+y-mod:x+y;}
int sub(int x,int y,int mod){return x-y<0?x-y+mod:x-y;}
int mul(int x,int y,int mod){return 1LL*x*y%mod;}
#define N 200005
int B1,B2;
int md1=998244353,md2=993244853;
int p1[N],p2[N];
int d1[N],d2[N];
int s1[N],s2[N];
int a[N],n,cnt[N];
int s[N],b[N],m;
int las[N],nxt[N];
int getdat(int *p,int *d,int *S,int B,int md,int l,int r)
{
	if(a[l]==1&&a[r]==1&&las[l]==las[r])
	{
		if((r-l+1)%2==0) return 0;
		else return 1;
	}
	if(a[l]==0&&a[r]==0)
	{
		l=b[l],r=b[r];
		return sub(d[r],mul(d[l-1],p[r-l+1],md),md);
	}
	if(a[l]==1&&a[r]==0)
	{
		int L=b[nxt[l]+1]; r=b[r];
		int R=sub(d[r],mul(d[L-1],p[r-L+1],md),md);
		if((nxt[l]-l+1)%2==0) return R;
		return add(R,p[r-L+1],md);
	}
	if(a[l]==0&&a[r]==1)
	{
		l=b[l]; int R=b[las[r]-1];
		int T=sub(d[R],mul(d[l-1],p[R-l+1],md),md);
		if((r-las[r]+1)%2==0) return T;
		return add(mul(T,B,md),1,md);
	}
	if(a[l]==1&&a[r]==1)
	{
		int L=b[nxt[l]+1],R=b[las[r]-1];
		int T=sub(d[R],mul(d[L-1],p[R-L+1],md),md),clen=R-L+1;
		if((r-las[r]+1)%2==1)
		{
			T=add(mul(T,B,md),1,md); clen++;
		}
		if((nxt[l]-l+1)%2==1)
		{
			T=add(T,p[clen],md);
		}
		return T;
	}
	exit(6662333);
}
signed main()
{
#ifdef __LOCAL__
	freopen("in.txt","r",stdin);
//	freopen("std.out","w",stdout);
#endif
	srand(time(NULL)); B1=rand()+100; B2=rand()+100;
	cin>>n;
	for(int i=1;i<=n;i++) scanf("%1d",&a[i]);
	for(int i=1;i<=n;i++) cnt[i]=cnt[i-1]+a[i];
	p1[0]=1; for(int i=1;i<=n;i++) p1[i]=mul(p1[i-1],B1,md1);
	p2[0]=1; for(int i=1;i<=n;i++) p2[i]=mul(p2[i-1],B2,md2);
	for(int i=1;i<=n;i++) s1[i]=add(mul(s1[i-1],B1,md1),1,md1);
	for(int i=1;i<=n;i++) s2[i]=add(mul(s2[i-1],B2,md2),1,md2);
	for(int i=1;i<=n;i++)
	{
		if(a[i]==0)
		{
			s[++m]=0;
			b[i]=m;
			continue;
		}
		int j=i;
		while(a[j+1]==1) j++;
		for(int k=i;k<=j;k++) las[k]=i,nxt[k]=j;
		if((j-i+1)%2==1)
		{
			s[++m]=1; b[i]=m;
		}
		i=j;
	}
//	for(int i=1;i<=n;i++) printf("%d ",b[i]); cout<<"\n";
	for(int i=1;i<=m;i++) d1[i]=add(mul(d1[i-1],B1,md1),s[i],md1);
	for(int i=1;i<=m;i++) d2[i]=add(mul(d2[i-1],B2,md2),s[i],md2);
//	for(int i=1;i<=n;i++) printf("%d ",p1[i]); cout<<"\n";
	int Q=read();
	while(Q--)
	{
		int l1=read(),l2=read(),len=read();
		int r1=l1+len-1,r2=l2+len-1;
		if(cnt[r1]-cnt[l1-1]!=cnt[r2]-cnt[l2-1])
		{
			printf("No\n");
			continue;
		}
//		printf("%d %d\n",getdat(p1,d1,s1,B1,md1,l1,r1),getdat(p1,d1,s1,B1,md1,l2,r2));
		if(getdat(p1,d1,s1,B1,md1,l1,r1)!=getdat(p1,d1,s1,B1,md1,l2,r2))
		{
			printf("No\n");
			continue;
		}
		if(getdat(p2,d2,s2,B2,md2,l1,r1)!=getdat(p2,d2,s2,B2,md2,l2,r2))
		{
			printf("No\n");
			continue;
		}
		printf("Yes\n");
	}
#ifdef __LOCAL__
//	cout<<"Time Used : "<<clock()<<endl;
#endif
	return 0;
}
//