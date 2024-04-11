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
inline int add(int x,int y) {return x+y>=mod?x+y-mod:x+y;}
inline int add(int x,int y,int z) {return add(add(x,y),z);}
inline int sub(int x,int y) {return x-y<0?x-y+mod:x-y;}
inline int mul(int x,int y) {return 1LL*x*y%mod;}
inline int mul(int x,int y,int z) {return mul(mul(x,y),z);}
#define N 150005
int ch[N*35][2],siz[N*35],pw[N],cnt=1,n,x;
void ins(int x)
{
	int cur=1;
	for(int i=30;i>=0;i--)
	{
		int c=x>>i&1; siz[cur]++;
		if(!ch[cur][c]) ch[cur][c]=++cnt;
		cur=ch[cur][c];
	}
	siz[cur]++;
}
int solve(int l,int r,int k)
{
	if(!l||!r||k==-1)
	{
		if(l==r) return pw[siz[l]]-1;
		else return pw[siz[l]+siz[r]]-1;
	}
	if(l==r)
	{
		if(x>>k&1)
		{
			int A=solve(ch[l][0],ch[r][1],k-1);
			// int B=solve(ch[l][0],ch[l][0],-1),C=solve(ch[l][1],ch[l][1],-1);
			return A;
		}
		else
		{
			int A=solve(ch[l][0],ch[l][0],k-1),B=solve(ch[l][1],ch[l][1],k-1);
			return add(A,B);
		}
	}
	else
	{
		if(x>>k&1)
		{
			int A=solve(ch[l][0],ch[r][1],k-1),B=solve(ch[l][1],ch[r][0],k-1);
			// int C=mul(pw[siz[ch[l][0]]]-1,pw[siz[ch[r][0]]]-1),D=mul(pw[siz[ch[l][1]]]-1,pw[siz[ch[r][1]]]-1);
			int r=(1LL*(A+1)*(B+1)-1)%mod;
			return r;
		}
		else
		{
			int A=solve(ch[l][0],ch[r][0],k-1),B=solve(ch[l][1],ch[r][1],k-1);
			int C=sub(pw[siz[ch[l][0]]+siz[ch[l][1]]],add(pw[siz[ch[l][0]]],pw[siz[ch[l][1]]])-1);
			int D=sub(pw[siz[ch[r][0]]+siz[ch[r][1]]],add(pw[siz[ch[r][0]]],pw[siz[ch[r][1]]])-1);
			return add(A,B,add(C,D));
		}
	}
}
signed main()
{
	cin>>n>>x;
	for(int i=1;i<=n;i++) ins(read());
	pw[0]=1; for(int i=1;i<N;i++) pw[i]=mul(pw[i-1],2);
	cout<<solve(1,1,30)<<endl;
	return 0;
}