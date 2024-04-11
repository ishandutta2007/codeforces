#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define mp make_pair
#define Fast_IO ios::sync_with_stdio(false);
#define int long long
inline int read()
{
	char ch=getchar(); int nega=1; while(!isdigit(ch)) {if(ch=='-') nega=-1; ch=getchar();}
	int ans=0; while(isdigit(ch)) {ans=ans*10+ch-48;ch=getchar();}
	if(nega==-1) return -ans;
	return ans;
}
#define N (1<<24)
int lowbit(int x){return x&(-x);}
string s;
int f[N];
int count(int x)
{
	int ans=0;
	while(x)
	{
		x-=lowbit(x);
		ans++;
	}
	return ans;
}
signed main()
{
#ifdef __LOCAL__
	freopen("in.txt","r",stdin);
#endif
//	cout<<count(5)<<endl;
	int n=read();
	for(int i=1;i<=n;i++)
	{
		cin>>s;
		int tmp=0;
		for(int j=0;j<3;j++) tmp|=(1<<(s[j]-'a'));
		for(int j=tmp;j!=0;j=(j-1)&tmp)
		{
			if(count(j)&1) f[j]++;
			else f[j]--;
		}
	}
//	cout<<"Passed\n";
	for(int i=0;i<24;i++)
	{
		for(int j=0;j<N;j++)
		{
			if(j&(1<<i)) f[j]+=f[j^(1<<i)];
		}
	}
//	for(int i=1;i<=10;i++) printf("%lld ",f[i]);
	int ans=0;
	for(int i=0;i<N;i++)
	{
		ans^=(f[i]*f[i]);
	}
	cout<<ans<<endl;
#ifdef __LOCAL__
	printf("Time Used : %d\n",clock());
#endif
	return 0;
}