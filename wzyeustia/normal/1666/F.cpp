#include<bits/stdc++.h>
#define For(i,j,k)  for(int i=j;i<=k;++i)
#define Dow(i,j,k)  for(int i=k;i>=j;--i)
#define ll long long
#define pb push_back
#define fir first
#define sec second
#define mk make_pair
 
using namespace std;
 
inline ll read()
{
    ll t=0,dp=1;char c=getchar();
    while(!isdigit(c))  {if(c=='-') dp=-1;c=getchar();}
    while(isdigit(c))   t=t*10+c-48,c=getchar();
    return t*dp;
}
inline void write(ll x){if(x<0) {putchar('-');x=-x;}    if(x>=10)   write(x/10);putchar(x%10+48);}
inline void writeln(ll x){write(x);puts("");}
inline void write_p(ll x){write(x);putchar(' ');}

const int N=5005;
int top;
int n,cnt[N],c[N][N],sum[N],dp[N][N],q[N];
int mo=998244353;
void Upd(int &x,int y) {x=x+y>=mo?x+y-mo:x+y;}
void Pre()
{
	c[0][0]=1;
	For(i,1,5000)
	{
		c[i][0]=1;
		For(j,1,i)	c[i][j]=(c[i-1][j-1]+c[i-1][j])%mo;
	}
}
int main()
{
	int T=read();
	Pre();
	while(T--)
	{
		top=0;
		n=read();
		For(i,1,n)	cnt[i]=0;
		For(i,1,n)	cnt[read()]++;
		Dow(i,1,n)	
			if(cnt[i])	q[++top] = cnt[i];
		For(i,1,top)	sum[i] = sum[i - 1] + q[i];
		For(i,0,n)	For(j,0,n)
			dp[i][j]=0;
		dp[0][0]=1; 
		For(i,1,top)
			For(j,0,sum[i-1])
			{
				if(j>n/2)	break;
				For(k,0,1)
				{
					int odd=q[i]-k, pos=max(0,j-1);
					if(j==n/2)	pos++;
					pos=pos-sum[i-1]+j;
//					if(i==5)	cout<<"DEBUG:"<<j<<" "<<dp[i-1][j]<<' '<<pos<<' '<<odd<<' '<<k<<' '<<q[i]<<endl; 
					if(pos>=0&&j+k<=n/2)	Upd(dp[i][j+k], 1LL*dp[i-1][j] * c[pos][odd] % mo);
				}	
			}
//		For(i,1,top){
//			For(j,0,sum[i]) write_p(dp[i][j]);
//			puts("");
//		}
		writeln(dp[top][n/2]);
	}
}