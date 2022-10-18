#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define mp make_pair
#define Fast_IO ios::sync_with_stdio(false);
#define DEBUG fprintf(stderr,"Running on Line %d in Function %s\n",__LINE__,__FUNCTION__)
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
inline int add(int x,int y){return x+y>=mod?x+y-mod:x+y;}
inline int sub(int x,int y){return x-y<0?x-y+mod:x-y;}
inline int mul(int x,int y){return 1LL*x*y%mod;}
#define N 200005
struct Node
{
	int a,b,c,d;
	bool operator < (const Node &x) const
	{
		if(d==0) return 0;
		if(x.d==0) return 1;
		return d<x.d;
	}
};
Node ans[N];
int a[N],n,Q,cnt[N];
int s1[N],s2[N],tp1,tp2;
bool cmp1(int x,int y){return a[x]<a[y];}
bool cmp2(int x,int y){return a[x]>a[y];}
bool gre(int x,int y){return x>y;}
void init_4()
{
	set<int> s;
	for(int i=n;i>=1;i--)
	{
		while(tp1&&a[s1[tp1]]>a[i])
		{
			cnt[s1[tp1]]--;
			if(!cnt[s1[tp1]]) s.insert(s1[tp1]);
			tp1--;
		}
		while(tp2&&a[s2[tp2]]<a[i])
		{
			cnt[s2[tp2]]--;
			if(!cnt[s2[tp2]]) s.insert(s2[tp2]);
			tp2--;
		}
		s1[++tp1]=i,s2[++tp2]=i;
		cnt[i]=2;
		int u=s1[lower_bound(s1+1,s1+tp1+1,i,cmp1)-s1-1];
		int v=s2[lower_bound(s2+1,s2+tp2+1,i,cmp2)-s2-1];
		if(!u||!v) continue;
		set<int>::iterator qaq=s.lower_bound(max(u,v)+1);
		if(qaq==s.end()) continue;
		int qwq=*qaq;
		u=*lower_bound(s1+1,s1+tp1+1,qwq,gre);
		v=*lower_bound(s2+1,s2+tp2+1,qwq,gre);
		ans[i]=(Node){i,min(u,v),max(u,v),qwq};
	}
}
struct Node2
{
	int a,b,c;
	bool operator < (const Node2 &x) const
	{
		if(c==0) return 0;
		if(x.c==0) return 1;
		return c<x.c;
	}
};
Node2 ans3[N];
int l[N],r[N];
void init_3()
{
	stack<int> s;
	for(int i=1;i<=n;i++)
	{
		while(!s.empty()&&a[i]>=a[s.top()]) s.pop();
		if(!s.empty()) l[i]=s.top();
		else l[i]=0;
		s.push(i);
	}
	while(!s.empty()) s.pop();
	for(int i=n;i>=1;i--)
	{
		while(!s.empty()&&a[i]>=a[s.top()]) s.pop();
		if(!s.empty()) r[i]=s.top();
		else r[i]=0;
		s.push(i);
	}
	for(int i=1;i<=n;i++)
	{
		// printf("%d : %d %d\n",i,l[i],r[i]);if(l[i]&&r[i])
		if(l[i]&&r[i])
		{
			Node2 tmp=(Node2){l[i],i,r[i]};
			if(tmp<ans3[l[i]]) ans3[l[i]]=tmp;
		}
	}
	// for(int i=1;i<=n;i++) printf("%d : %d %d %d\n",i,ans3[i].a,ans3[i].b,ans3[i].c);
	while(!s.empty()) s.pop();
	for(int i=1;i<=n;i++)
	{
		while(!s.empty()&&a[i]<=a[s.top()]) s.pop();
		if(!s.empty()) l[i]=s.top();
		else l[i]=0;
		s.push(i);
	}
	while(!s.empty()) s.pop();
	for(int i=n;i>=1;i--)
	{
		while(!s.empty()&&a[i]<=a[s.top()]) s.pop();
		if(!s.empty()) r[i]=s.top();
		else r[i]=0;
		s.push(i);
	}
	for(int i=1;i<=n;i++)
	{
		// printf("%d : %d %d\n",i,l[i],r[i]);
		if(l[i]&&r[i])
		{
			Node2 tmp=(Node2){l[i],i,r[i]};
			if(tmp<ans3[l[i]]) ans3[l[i]]=tmp;
		}
	}
}
signed main()
{
	cin>>n>>Q;
	for(int i=1;i<=n;i++) a[i]=read();
	init_4();
	init_3();
	// for(int i=1;i<=n;i++) printf("4\n%d %d %d %d\n",ans[i].a,ans[i].b,ans[i].c,ans[i].d);
	for(int i=n-1;i>=1;i--)
	{
		if(ans[i+1]<ans[i]) ans[i]=ans[i+1];
	}
	for(int i=n-1;i>=1;i--)
	{
		if(ans3[i+1]<ans3[i]) ans3[i]=ans3[i+1];
	}
	// for(int i=1;i<=n;i++) printf("%d : %d %d %d\n",i,ans3[i].a,ans3[i].b,ans3[i].c);
	while(Q--)
	{
		int l=read(),r=read();
		if(ans[l].d&&ans[l].d<=r)
		{
			printf("4\n%d %d %d %d\n",ans[l].a,ans[l].b,ans[l].c,ans[l].d);
			continue;
		}
		if(ans3[l].c&&ans3[l].c<=r)
		{
			printf("3\n%d %d %d\n",ans3[l].a,ans3[l].b,ans3[l].c);
			continue;
		}
		printf("0\n\n");
	}
	return 0;
}