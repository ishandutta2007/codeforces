#include<bits/stdc++.h>
#define int long long
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,tune=native")
#define rd(x) x=read()
#define wt(x) write(x)
#define pos(x) (((x)-1)/SZ+1)
using namespace std;
const int N=1e6+5;
const int M=70;
const int SZ=450;
const int mod=998244353;
const int inf=0x3f3f3f3f3f3f3f3f;
int read(){int x=0,f=1;char ch=getchar();while(ch>'9'||ch<'0'){if (ch=='-')f=-1;ch=getchar();}while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}return x*f;}
void write(int x){if(x<0){putchar('-');x=-x;}if(x>=10)write(x/10);putchar(x%10+'0');}
int ksm(int x,int y=mod-2,int z=mod){int ret=1;while (y){if (y&1) ret=(ret*x)%z;x=(x*x)%z;y>>=1;}return ret;}

int n,k,ans;
int xorplus(int a,int b)
{
	int p=0;
	int x=1;
	while (a || b)
	{
		int c=a%k,d=b%k;
		a/=k;b/=k;
		p+=(c+d)%k*x;
		x*=k;
	}
	return p;
}
int xorjian(int a,int b)
{
	int p=0;
	int x=1;
	while (a || b)
	{
		int c=a%k,d=b%k;
		a/=k;b/=k;
		p+=(c-d+k)%k*x;
		x*=k;
	}
	return p;
}
signed main()
{
    int JYZ;rd(JYZ);while (JYZ--)
    {
		rd(n);rd(k);
        int t=0,p=0;
        ans=0;
        while (ans!=1)
        {
        	//cout<<"t="<<t<<" p="<<p<<endl;
        	int x;
			if (t&1) x=xorjian(p,t);else x=xorplus(p,t);
            cout<<x<<endl;
            cin>>ans;
            p=xorjian(x,p);
			t++;
        }
    }
}
/*
5.030718829
5.005050776521
*/