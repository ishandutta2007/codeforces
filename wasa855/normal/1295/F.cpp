#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define mp make_pair
#define Fast_IO ios::sync_with_stdio(false);
#define fir first
#define sec second
#define int long long
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
int qpow(int x,int y)
{
	int ans=1;
	while(y)
	{
		if(y&1) ans=ans*x%mod;
		x=x*x%mod;
		y>>=1;
	}
	return ans;
}
int Inv(int x)
{
	return qpow(x,mod-2);
}
#define N 55
int l[N],r[N],t[N*2];
int f[N];
int mul[N*2],inv[N*2],C[N*2];
signed main()
{
#ifdef __LOCAL__
	freopen("in.txt","r",stdin);
#endif
	mul[0]=1;
	for(int i=1;i<=100;i++) mul[i]=mul[i-1]*i%mod;
	inv[0]=inv[1]=1;
	for(int i=2;i<=100;i++) inv[i]=(mod-mod/i)*inv[mod%i]%mod;
	int n=read();
	int sum=1;
	int cnt=0;
	for(int i=1;i<=n;i++)
	{
		l[i]=read(),r[i]=read()+1;
		sum=sum*(r[i]-l[i])%mod;
		t[++cnt]=l[i],t[++cnt]=r[i];
	}
	sort(t+1,t+cnt+1);
	int q=unique(t+1,t+cnt+1)-t-1;
	for(int i=1;i<=n;i++)
	{
		l[i]=lower_bound(t+1,t+q+1,l[i])-t;
		r[i]=lower_bound(t+1,t+q+1,r[i])-t;
	}
	C[0]=1,f[0]=1;
	for(int j=q-1;j>=1;j--)
	{
		int len=t[j+1]-t[j];
//		cout<<len<<endl;
		for(int i=1;i<=n;i++) C[i]=C[i-1]*(len+i-1)%mod*inv[i]%mod;
//		for(int i=1;i<=n;i++) printf("%lld ",C[i]);
//		cout<<"\n";
		for(int i=n;i>=1;i--)
		{
			if(l[i]<=j&&r[i]>=j+1)
			{
				int tmp=1;
				for(int k=i-1;k>=0;k--)
				{
					f[i]=(f[i]+C[tmp]*f[k])%mod;
//					printf("%d %d %d\n",i,j,k);
					if(l[k]<=j&&r[k]>=j+1) tmp++;
					else break;
				}
			}
		}
	}
//	for(int i=1;i<=n;i++) printf("%lld ",f[i]);
//	cout<<"\n";
	cout<<f[n]*Inv(sum)%mod<<endl;
#ifdef __LOCAL__
	cout<<"Time Used : "<<clock()<<endl;
#endif
	return 0;
}