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
#define N 2000005
char s[N];
int n,m,L;
int a[N],b[N],pre[N],suf[N];
void QAQ()
{
	int la=0,lb=0,ra=0,rb=0;
	for(int i=1;i<=m;i++)
	{
		if(b[i]<a[1]) la++,lb=max(lb,a[1]-b[i]);
		else ra++,rb=max(rb,b[i]-a[1]);
	}
	if(la>ra) printf("%d %d\n",la,lb);
	else if(ra>la) printf("%d %d\n",ra,rb);
	else printf("%d %d\n",la,min(lb,rb));
}
int f[N];
bool QWQ(const int mid)
{
	for(int i=1;i<=n;i++) f[i]=-inf;
	if(a[1]-b[1]<mid) return 0;
	f[1]=a[1];
	for(int i=2;i<=n;i++)
	{
		if(f[i-1]>=pre[a[i]]) f[i]=max(f[i],a[i]+mid);
		if(f[i-1]>0&&(a[i]<=mid||suf[a[i]-mid]<=suf[f[i-1]+1])) f[i]=max(f[i],a[i]);
		if(i!=2)
		{
			if(f[i-2]>0&&(a[i]<=mid||suf[a[i]-mid]<=suf[f[i-2]+1])&&a[i-1]+mid>=a[i]) f[i]=max(f[i],a[i-1]+mid);
		}
//		assert(f[i]<=10000000);
		assert(mid<=1000000);
	}
	for(int i=1;i<=n;i++) printf("%d%c",f[i]," \n"[i==n]);
	return f[n]>=b[m];
}
/*
bool OvO(const int mid)
{
	for(int i=1;i<=n;i++) f[i]=-inf;
	if(a[2]-mid<=b[1]&&a[1]+mid>=a[2]) f[1]=a[1],f[2]=a[1]+mid;
	else return 0;
	for(int i=3;i<=n;i++)
	{
		if(f[i-1]>=pre[a[i]]) f[i]=max(f[i],a[i]+mid);
		if(f[i-1]>0&&(a[i]<=mid||suf[a[i]-mid]<=suf[f[i-1]+1])) f[i]=max(f[i],a[i]);
		if(i!=2)
		{
			if(f[i-2]>0&&(a[i]<=mid||suf[a[i]-mid]<=suf[f[i-2]+1])&&a[i-1]+mid>=a[i]) f[i]=max(f[i],a[i-1]+mid);
		}
	}
	return f[n]>=b[m];
}
*/
bool chk(const int mid)
{
	for(int i=1;i<=n;i++) f[i]=-inf;
	f[0]=0;
	for(int i=1;i<=n;i++)
	{
		if(f[i-1]>=pre[a[i]]) f[i]=max(f[i],a[i]+mid);
		if(f[i-1]>=0&&(a[i]<=mid||suf[a[i]-mid]<=suf[f[i-1]+1])) f[i]=max(f[i],a[i]);
		if(i>=2)
		{
			// printf("%d %d\n",suf[a[i]-mid],suf[f[i-2]+1]);
			if(f[i-2]>=0&&(a[i]<=mid||suf[a[i]-mid]<=suf[f[i-2]+1])&&a[i-1]+mid>=a[i]) f[i]=max(f[i],a[i-1]+mid);
		}
	}
	// for(int i=1;i<=n;i++) printf("%d%c",f[i]," \n"[i==n]);
	return f[n]>=b[m];
	
	
	// if(a[1]-b[1]>mid) return 0;
	// printf("%d %d\n",QWQ(mid),OvO(mid));
	// return QWQ(mid)||OvO(mid);
}
signed main()
{
	cin>>L; scanf("%s",s+1);
	for(int i=1;i<=L;i++)
	{
		if(s[i]=='P') a[++n]=i;
		if(s[i]=='*') b[++m]=i;
	}
	if(n==1)
	{
		QAQ();
		return 0;
	}
	int l=1,r=L,ans=114514;
	for(int i=1;i<=m;i++) pre[b[i]]=b[i],suf[b[i]]=b[i];
	suf[L+1]=L+1;
	for(int i=1;i<=L;i++) if(!pre[i]) pre[i]=pre[i-1];
	for(int i=L;i>=1;i--) if(!suf[i]) suf[i]=suf[i+1];
	// cout<<chk(1)<<endl;
	// return 0;
	while(l<=r)
	{
		int mid=(l+r)/2;
		if(chk(mid)) r=mid-1,ans=mid;
		else l=mid+1;
	}
	cout<<m<<" ";
	cout<<ans<<endl;
	return 0;
}