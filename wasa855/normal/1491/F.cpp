#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define eb emplace_back
#define mp make_pair
#define Fast_IO ios::sync_with_stdio(false);
#define DEBUG fprintf(stderr,"Running on Line %d in Function %s\n",__LINE__,__FUNCTION__)
mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());
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
int Rnd(int l,int r) {return rnd()%(r-l+1)+l;}
#define N 2005
int ok[N],lg[N],cnt=0;
char ans[N];
int query(int l,vector<int> r)
{
#ifdef __LOCAL__
	cnt++;
	int A=0,B=0,C=0,D=0;
	if(ans[l]=='N') A++;
	if(ans[l]=='S') B++;
	for(int i:r)
	{
		if(ans[i]=='N') C++;
		if(ans[i]=='S') D++;
	}
	return A*C+B*D-A*D-B*C;
#endif
	printf("? %d %d\n",1,(int)r.size());
	cout<<l<<endl;
	print(r); fflush(stdout);
	return read();
}
void work()
{
	memset(ok,0,sizeof(ok));
	int n=read(); cnt=0;
#ifdef __LOCAL__
//	for(int i=1;i<=n;i++) ans[i]="NS-"[Rnd(0,2)];
	scanf("%s",ans+1);
	int ca=0,cb=0;
	for(int i=1;i<=n;i++)
	{
		if(ans[i]=='-') ca++;
		else cb++;
	}
	if(ca<1) return ;
	if(cb<2) return ;
#endif
	int pos=0,sum=0;
	for(int i=1;i<=n;i++)
	{
		vector<int> r; for(int j=i+1;j<=n;j++) r.pb(j);
		int A=query(i,r);
		if(A!=0) {pos=i,sum=A; break;}
		ok[i]=1;
	}
	for(int j=pos+1;j<n;j++)
	{
		int A=query(pos,{j});
		if(!A) ok[j]=1;
		sum-=A;
	}
	if(!sum) ok[n]=1;
	if(pos!=1)
	{
		int l=1,r=pos-1,ans=0;
		while(l<=r)
		{
			int mid=(l+r)/2;
			vector<int> v;
			for(int i=mid;i<pos;i++) v.pb(i);
			if(query(pos,v)) ans=mid,l=mid+1;
			else r=mid-1;
		}
		if(ans) ok[ans]=0;
	}
#ifdef __LOCAL__
	for(int i=1;i<=n;i++)
	{
		int a=::ans[i]=='-';
		assert(a==ok[i]);
	}
	if(cnt>n+lg[n]) for(int i=1;i<=n;i++) printf("%c",ans[i]);
	cout<<"\n";
	assert(cnt<=n+lg[n]);
	return ;
#endif
	vector<int> ans;
	for(int i=1;i<=n;i++) if(ok[i]) ans.pb(i);
	printf("! %d ",(int)ans.size());
	print(ans),fflush(stdout);
}
signed main()
{
	for(int i=2;i<N;i++) lg[i]=lg[i/2]+1;
	int T=read(); while(T--) work();
	return 0;
}