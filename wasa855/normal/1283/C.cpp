#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define mp make_pair
#define Fast_IO ios::sync_with_stdio(false);
#define fir first
#define sec second
#define mod 998244353
inline int read()
{
	char ch=getchar(); int nega=1; while(!isdigit(ch)) {if(ch=='-') nega=-1; ch=getchar();}
	int ans=0; while(isdigit(ch)) {ans=ans*10+ch-48;ch=getchar();}
	if(nega==-1) return -ans;
	return ans;
}
typedef pair<int,int> pii;
int add(int x,int y){return x+y>mod?x+y-mod:x+y;}
int sub(int x,int y){return x-y<0?x-y+mod:x-y;}
#define N 200005
int a[N];
bool ha[N];
bool dela[N],delb[N];
signed main()
{
#ifdef __LOCAL__
	freopen("in.txt","r",stdin);
#endif
	int n=read();
	vector<int> v1,v2,v3;
	for(int i=1;i<=n;i++)
	{
		a[i]=read();
		ha[a[i]]=1;
	}
	for(int i=1;i<=n;i++)
	{
		if(a[i]==0&&ha[i]==0) v1.pb(i);
		else if(a[i]==0) v2.pb(i);
		else if(ha[i]==0) v3.pb(i);
	}
	if(v1.size()==1)
	{
		a[v1[0]]=v3.back();
		ha[v3.back()]=1;
		v3.pop_back();
		v3.pb(v1[0]);
		v1.pop_back();
	}
	for(int i=1;i<v1.size();i++)
	{
		a[v1[i-1]]=v1[i];
	}
	if(!v1.empty()) a[v1.back()]=v1[0];
	for(int i=0;i<v2.size();i++)
	{
		a[v2[i]]=v3[i];
	}
	for(int i=1;i<=n;i++) printf("%d ",a[i]);
	cout<<"\n";
#ifdef __LOCAL__
	printf("Time Used : %d\n",clock());
#endif
	return 0;
}