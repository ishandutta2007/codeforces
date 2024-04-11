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
#define N 1005
vector<int> v[5];
int x[N],y[N];
int n;
bool valid()
{
	for(int i=1;i<=n;i++)
	{
		if((x[i]&1)||(y[i]&1)) return 1;
	}
	return 0;
}
signed main()
{
#ifdef __LOCAL__
	freopen("in.txt","r",stdin);
#endif
	n=read();
	for(int i=1;i<=n;i++) x[i]=read(),y[i]=read();
	for(int i=2;i<=n;i++) x[i]-=x[1],y[i]-=y[1];
	x[1]=0,y[1]=0;
//	for(int i=1;i<=n;i++) printf("%d %d\n",x[i],y[i]);
	while(!valid())
	{
		for(int i=1;i<=n;i++) x[i]/=2,y[i]/=2;
	}
	for(int i=1;i<=n;i++)
	{
		if((x[i]&1)&&(y[i]&1)) v[1].pb(i);
		if(!(x[i]&1)&&(y[i]&1)) v[2].pb(i);
		if((x[i]&1)&&!(y[i]&1)) v[3].pb(i);
		if(!(x[i]&1)&&!(y[i]&1)) v[4].pb(i);
	}
	if(v[2].size()+v[3].size()==0)
	{
		cout<<v[1].size()<<endl;
		for(int i:v[1]) cout<<i<<" "; cout<<"\n";
	}
	else
	{
		cout<<v[1].size()+v[4].size()<<endl;
		for(int i:v[1]) cout<<i<<" ";
		for(int i:v[4]) cout<<i<<" ";
		cout<<"\n";
	}
#ifdef __LOCAL__
	cout<<"Time Used : "<<clock()<<endl;
#endif
	return 0;
}