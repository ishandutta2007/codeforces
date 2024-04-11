#include<bits/stdc++.h>
#define int long long
#define endl "\n"
#define rd(x) x=read()
#define wt(x) write(x)
#define pii pair<int,int>
#define pq priority_queue<int>
using namespace std;
const int N=4e6+5;
const int M=170;
const int SZ=450;
const int mod=1e9+7;
int read(){int x=0,f=1;char ch=getchar();while(ch>'9'||ch<'0'){if (ch=='-')f=-1;ch=getchar();}while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}return x*f;}
void write(int x){if (x<0){putchar('-');x=-x;}if (x>=10)write(x/10);putchar(x%10+'0');}
int ksm(int x,int y=mod-2,int z=mod){int ret=1;while (y){if (y&1) ret=(ret*x)%z;x=(x*x)%z;y>>=1;}return ret;}
int n,a,b;
int mp[4]={0,2,3,1};
void solve(int n)
{
    int i,x,y;
	for (i=0,x=y=1;y+x<=n;y+=x,x*=4,i+=2);
	a=x+n-y;b=x*2;
	for (i-=2;i>=0;i-=2){int z=a>>i&3;b|=mp[z]<<i;}
}
signed main()
{
    int T;rd(T);while (T--)
    {
        rd(n);solve((n+2)/3);
        if (n%3==1) cout<<a<<"\n";
        if (n%3==2) cout<<b<<"\n";
        if (n%3==0) cout<<(a^b)<<"\n";
    }
}
/*
*/