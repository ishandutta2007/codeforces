#include<cstdio>
#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;
#define N 1001
int n;
int m;
int a[N];
int ll[N];
int fen[N];
int d[N];
int cnt;
int r;
bool f1,f2;
long long tot;
long long ans;
long long it[N];
long long er[N];
long long mod=1000000007;
int pr[N];
int p[N];
int c,bb[N];
int yuan[N];
void prepare()
{
	pr[1]=-1;
	for(int i=2;i<=1000;i++)
	{
		if(pr[i]==0)
		{
			pr[i]=++c;
			p[c]=i;
			for(int j=2;j<=1000/i;j++) pr[i*j]=-1;
		}
	}
}
void AC(int n,int k)
{
	for(int i=1;i<=c;i++)
	{
		if(n==1) break;
		if(n%p[i]==0)while(n%p[i]==0) {bb[i]+=k;n/=p[i];}
	}
}
void dance()
{
	for(int i=2;i<=tot;i++)	AC(i,1);
	for(int i=1;i<=cnt;i++)
	for(int j=2;j<=d[i];j++) 
	AC(j,-1);
} 
int main()
{
	cin>>n>>m;
	if(n==m) {puts("1");return 0;}//1A 
	prepare();
	for(int i=1;i<=m;i++)cin>>fen[i];
	sort(fen+1,fen+m+1);
	int l=1;
	for(int i=1;i<=m;i++)
	{
		if(fen[i]==l) l=fen[i]+1;
		else
		{
			r=fen[i];
			d[++cnt]=r-l;
			l=fen[i]+1;
		}
	}if(l<=n) d[++cnt]=n-l+1;if(fen[1]==1) f1=1;else f1=0;	if(fen[m]==n) f2=1;else f2=0;	ans=1;
	
	for(int i=1;i<=cnt;i++) tot+=d[i];
	dance();
	ans=1;
	for(int i=1;i<=c;i++)
	{
		for(int j=1;j<=bb[i];j++) 
		{
			ans*=p[i];
			ans=ans%mod;
		}
	}
	/*it[0]=1;
	for(int i=1;i<=20;i++) it[i]=it[i-1]*i;
	ans*=it[tot];
	for(int i=1;i<=cnt;i++)
	ans=ans/it[d[i]];*/
	er[1]=1;
	for(int i=2;i<=1000;i++) {er[i]=2*er[i-1];er[i]=er[i]%mod;}
	if(cnt==1)
	{
		if(f1&&f2) ans=ans*er[d[1]]%mod;
		else
		if(!f1&&!f2) ans=0;
		ans=ans%mod;
		cout<<ans<<endl;
		return 0; 
	}
	if(f1) ans=ans*er[d[1]]%mod;
	if(f2) ans=ans*er[d[cnt]]%mod;
	for(int i=2;i<=cnt-1;i++)
	ans=ans*er[d[i]]%mod;
	ans=ans%mod;
	cout<<ans%mod;
}