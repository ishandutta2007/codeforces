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
#define int long long
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
int a[N],k[N],rev[N],n,m;
vector<int> v[N];
struct Node{int v,id;};
Node b[N];
int ok1[N],ok2[N],ok3[N];
int rg(int s[],int l,int r) {return s[r]-s[l-1];}
void work()
{
	n=read(),m=read();
	for(int i=1;i<=n;i++) a[i]=read()-1;
	sort(a+1,a+n+1,greater<int>());
	for(int i=1;i<=m;i++)
	{
		k[i]=read(); vector<int> t(k[i]);
		int s=0;
		for(int j=0;j<k[i];j++) t[j]=read(),s+=t[j];
		v[i]=t; b[i].id=i,b[i].v=(s-1)/k[i];
	}
	sort(b+1,b+m+1,[&](Node x,Node y){return x.v>y.v;});
	// for(int i=1;i<=m;i++) printf("%d %d\n",a[i],b[i].v);
	for(int i=1;i<=m;i++) ok1[i]=a[i]>=b[i].v;
	for(int i=1;i<=m;i++) ok2[i]=a[i+1]>=b[i].v;
	for(int i=1;i<=m;i++) ok3[i]=a[i-1]>=b[i].v;
	for(int i=1;i<=m;i++) rev[b[i].id]=i;
	for(int i=1;i<=m;i++) ok1[i]+=ok1[i-1],ok2[i]+=ok2[i-1],ok3[i]+=ok3[i-1];
	for(int i=1;i<=m;i++)
	{
		int s=0; for(int j:v[i]) s+=j;
		for(int j:v[i])
		{
			s-=j; int tv=(s-1)/(k[i]-1);
			auto rk=lower_bound(b+1,b+m+1,(Node){tv,0},[&](Node x,Node y){return x.v>y.v;})-b;
			int las=rev[i];
			if(b[rev[i]].v>tv) rk--;
			// printf("%d %d %d\n",tv,rk,las);
			if(rk>=las)
			{
				int sum=rg(ok1,1,las-1)+rg(ok3,las+1,rk)+rg(ok1,rk+1,m)+(a[rk]>=tv);
				// cout<<rg(ok1,1,las-1)<<endl;
				// printf("%d\n",sum);
				printf("%d",sum==m);
			}
			else
			{
				int sum=rg(ok1,1,rk-1)+rg(ok2,rk,las-1)+rg(ok1,las+1,m)+(a[rk]>=tv);
				printf("%d",sum==m);
			}
			s+=j;
		}
	}
	cout<<"\n";
}
signed main()
{
	int T=read(); while(T--) work();
	return 0;
}