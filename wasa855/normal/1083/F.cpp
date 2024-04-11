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
inline char rdchar()
{
	char ch=getchar();
	while(!(ch>='a'&&ch<='z')&&!(ch>='A'&&ch<='Z')&&!(ch>='0'&&ch<='9')) ch=getchar();
	return ch;
}
typedef pair<int,int> pii;
#define N 200005
int a[N],n,k,q,s[N];
const int S=200;
int pool[N*128];
int *p=pool;
int *_pool[N],**_p=_pool;
vector<int> b[N];
int cat,sum;
int A[N],B[N];
struct Node
{
	bool spe;
	vector<int> val;
	vector<int> tag,L,R;
	// unordered_map<int,int> x[20];
	int **x;
	int tot,ans,len,cnt;
	void init(vector<int> v,bool s)
	{
		spe=s,val=v,len=v.size();
		for(int i=1;i<len;i++) val[i]^=val[i-1];
		tot=val[len-1]; ans=0;
		cnt=(len+S-1)/S;
		if(cnt==1)
		{
			for(int i=0;i<len;i++) if(!val[i]) ans++;
			if(!spe&&tot!=0) cat++;
			return ;
		}
		tag.resize(cnt),L.resize(cnt),R.resize(cnt);
		for(int i=0;i<cnt;i++) L[i]=i*S,R[i]=min((i+1)*S-1,len-1);
		x=_p; _p+=cnt;
		for(int i=0;i<cnt;i++)
		{
			x[i]=p,p+=1<<14;
		}
		for(int i=0;i<cnt;i++)
		{
			for(int j=L[i];j<=R[i];j++)
			{
				x[i][val[j]]++;
				if(val[j]==0) ans++;
			}
		}
		if(!spe&&tot!=0) cat++;
	}
	void rebuild(int id,int pl,int d)
	{
		ans-=x[id][tag[id]];
		for(int i=L[id];i<=R[id];i++) x[id][val[i]]--;
		for(int i=L[id];i<=R[id];i++) val[i]^=tag[id];
		for(int i=pl;i<=R[id];i++) val[i]^=d;
		for(int i=L[id];i<=R[id];i++)
		{
			x[id][val[i]]++;
			if(!val[i]) ans++;
		}
		tag[id]=0;
	}
	void update(int pl,int va)
	{
		// printf("-- %d %d\n",pl,va);
		// for(int i=0;i<len;i++) printf("%d ",val[i]); cout<<"\n";
		if(cnt==1)
		{
			if(!spe&&tot!=0) cat--;
			ans=0;
			for(int i=pl;i<len;i++) val[i]^=va;
			for(int i=0;i<len;i++) if(!val[i]) ans++;
			tot=val[len-1];
			if(!spe&&tot!=0) cat++;
			return ;
		}
		int bel=pl/S;
		int d=va;
		rebuild(bel,pl,d);
		for(int i=bel+1;i<cnt;i++)
		{
			ans-=x[i][tag[i]];
			tag[i]^=d;
			ans+=x[i][tag[i]];
		}
		if(!spe&&tot!=0) cat--;
		tot^=d;
		if(!spe&&tot!=0) cat++;
		// for(int i=0;i<len;i++) printf("%d ",val[i]); cout<<"\n";
	}
};
vector<Node> nd;
void update(int id,int val)
{
	// printf("%d %d\n",id,val);
	int bel=id%k==0?k:id%k;
	int pl=(id-1)/k;
	sum-=nd[bel].ans;
	nd[bel].update(pl,val);
	sum+=nd[bel].ans;
}
void print()
{
	if(cat) printf("-1\n");
	else printf("%d\n",n-sum);
}
signed main()
{
	cin>>n>>k>>q;
	nd.resize(k+1);
	for(int i=1;i<=n;i++) a[i]=A[i]=read();
	for(int i=1;i<=n;i++) a[i]^=(B[i]=read());
	for(int i=1;i<=n;i++) s[i]=a[i-1]^a[i];
	for(int i=1;i<=n;i++)
	{
		int id=i%k==0?k:i%k;
		b[id].pb(s[i]);
	}
//	for(int i=1;i<=n;i++) printf("%d ",s[i]); cout<<"\n";
	for(int i=1;i<=k;i++)
	{
		bool se=(n+1)%k==i%k;
		nd[i].init(b[i],se);
		sum+=nd[i].ans;
	}
	print();
	while(q--)
	{
		char x=rdchar();
		int pl=read(),v=read();
		if(x=='a') v^=A[pl],A[pl]^=v;
		else v^=B[pl],B[pl]^=v;
		a[pl]^=v;
		update(pl,s[pl]^a[pl]^a[pl-1]);
		s[pl]=a[pl]^a[pl-1];
		if(pl!=n)
		{
			update(pl+1,s[pl+1]^a[pl+1]^a[pl]);
			s[pl+1]=a[pl+1]^a[pl];
		}
		print();
	}
	return 0;
}