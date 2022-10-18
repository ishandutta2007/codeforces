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
#define N 100005
int r[N],q[N],tmp[N],ans[N],m,n;
char s[N];
void work()
{
	memset(r,0,sizeof(r));
	memset(q,0,sizeof(q));
	memset(tmp,0,sizeof(tmp));
	memset(ans,0,sizeof(ans));
	cin>>n;
	if(n/2>=1)
	{
		printf("Q %d ",n/2); for(int i=1;i+1<=n;i+=2) printf("%d %d ",i,i+1);
		cout<<endl;
		scanf("%s",s+1);
		for(int i=1;i<=n/2;i++) r[i*2-1]=s[i]=='1';
	}
	if((n-1)/2>=1)
	{
		printf("Q %d ",(n-1)/2); for(int i=2;i+1<=n;i+=2) printf("%d %d ",i,i+1);
		cout<<endl;
		scanf("%s",s+1);
		for(int i=1;i<=(n-1)/2;i++) r[i*2]=s[i]=='1';
	}
	m=0;
//	for(int i=1;i<=n;i++) printf("%d%c",r[i]," \n"[i==n]);
	for(int i=1;i<=n;i++)
	{
		int j=i;
		while(j<n&&r[j]) j++;
		tmp[++m]=i,i=j;
	}
//	for(int i=1;i<=m;i++) printf("%d%c",tmp[i]," \n"[i==m]);
	if((m/4*2+((m%4)>=3))>=1)
	{
		printf("Q %d ",m/4*2+((m%4)>=3)); for(int i=1;i<=m;i++) if((i%4==1||i%4==2)&&i+2<=m) printf("%d %d ",tmp[i],tmp[i+2]);
		cout<<endl;
		scanf("%s",s+1); int cur=0;
		for(int i=1;i<=m;i++) if((i%4==1||i%4==2)&&i+2<=m) q[i]=s[++cur]=='1';
	} 
	if(((m-2)/4*2+(((m-2)%4)>=3))>=1)
	{
		printf("Q %d ",(m-2)/4*2+(((m-2)%4)>=3)); for(int i=3;i<=m;i++) if((i%4==3||i%4==0)&&i+2<=m) printf("%d %d ",tmp[i],tmp[i+2]);
		cout<<endl;
		scanf("%s",s+1); int cur=0;
		for(int i=3;i<=m;i++) if((i%4==3||i%4==0)&&i+2<=m) q[i]=s[++cur]=='1';
	}
	for(int i=1;i<=m;i++)
	{
		if(i==1) ans[tmp[i]]=1;
		else if(i==2) ans[tmp[i]]=2;
		else
		{
			if(q[i-2]==1) ans[tmp[i]]=ans[tmp[i-2]];
			else ans[tmp[i]]=ans[tmp[i-1]]^ans[tmp[i-2]];
		}
	}
	for(int i=1;i<=n;i++) if(!ans[i]) ans[i]=ans[i-1];
	int cnt[4]={0,0,0,0};
	for(int i=1;i<=n;i++) cnt[ans[i]]++;
	printf("A %d %d %d\n",cnt[1],cnt[2],cnt[3]);
	for(int i=1;i<=3;i++)
	{
		for(int j=1;j<=n;j++) if(ans[j]==i) printf("%d ",j);
		cout<<"\n";
	}
}
signed main()
{
	int T=read(); while(T--) work();
	return 0;
}