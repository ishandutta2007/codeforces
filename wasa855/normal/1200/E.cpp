#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define mp make_pair
#define hash sfidghisdjgn
inline int read()
{
	char ch=getchar(); int nega=1; while(!isdigit(ch)) {if(ch=='-') nega=-1; ch=getchar();}
	int ans=0; while(isdigit(ch)) {ans=ans*10+ch-48;ch=getchar();}
	if(nega==-1) return -ans;
	return ans;
}
#define N 1000005
#define ll unsigned long long
#define Base 13113
ll hash[N];
ll mul[N];
ll tmp[N];
char ans[N],x[N];
int p[N];
bool judge(int lx,int rx,int ly,int ry)
{
//	cout<<lx<<" "<<rx<<" "<<ly<<" "<<ry<<"\n";
//	cout<<(hash[rx]-hash[lx-1]*mul[rx-lx+1])<<" "<<(tmp[ry]-tmp[ly-1]*mul[ry-ly+1])<<endl;
	return (hash[rx]-hash[lx-1]*mul[rx-lx+1])==((tmp[ry]-tmp[ly-1]*mul[ry-ly+1]));
}
signed main()
{
#ifdef __LOCAL__
	freopen("in.txt","r",stdin);
#endif
	mul[0]=1;
	for(int i=1;i<=N-5;i++) mul[i]=mul[i-1]*Base;
	int n;
	cin>>n;
	int len=0;
	for(int i=1;i<=n;i++)
	{
//		cout<<i<<endl;
		scanf("%s",x+1);
		if(i==1)
		{
			int m=strlen(x+1);
			for(int j=1;j<=m;j++) ans[j]=x[j];
			for(int j=1;j<=m;++j) hash[j]=(hash[j-1]*Base+ans[j]);
			len=m;
			continue;
		}
		int m=strlen(x+1);
		int minn=min(len,m),top=m;
		x[++top]='*';
		for(int j=len-minn+1;j<=len;j++) x[++top]=ans[j];
		p[0]=p[1]=0;
		for(int j=1;j<top;j++)
		{
			int k=p[j];
			while(k&&x[k+1]!=x[j+1]) k=p[k];
			if(x[k+1]==x[j+1]) k++;
			p[j+1]=k;
		}
//		cout<<p[top]<<endl;
		for(int j=p[top]+1;j<=m;j++) ans[++len]=x[j];
	}
	for(int i=1;i<=len;i++)
	{
		cout<<ans[i];
	}
	cout<<"\n";
#ifdef __LOCAL__
	printf("Time Used : %d\n",clock());
#endif
	return 0;
}