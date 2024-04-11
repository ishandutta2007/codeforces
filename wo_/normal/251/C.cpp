#include<cstdio>
#include<iostream>
#include<algorithm>

using namespace std;

int gcd(int a,int b)
{
	if(a==0&&b==0) return 1;
	if(b==0) return a;
	if(a<b) return gcd(b,a);
	return gcd(b,a%b);
}

int K;
int D;

int dp[360360];
int calc_small(long long a,long long b)
{
	a%=D;b%=D;
	dp[a]=0;
	for(int i=a-1;i>=b;i--)
	{
		dp[i]=dp[i+1]+1;
		for(int j=2;j<=K;j++)
		{
			if(i%j==0)
			{
				for(int k=i+1;k<=min(i+j-1,(int)a);k++) dp[i]=min(dp[i],dp[k]+1);
			}
		}
	}
	return dp[b];
}

int dp1[360360];
int dp2[360360];

void calc1()//from top
{
	dp1[D-1]=0;
	for(int i=D-2;i>=0;i--)
	{
		dp1[i]=dp1[i+1]+1;
		for(int j=2;j<=K;j++) if(i%j==0)
		{
			for(int k=i+1;k<=i+j-1;k++)
			{
				dp1[i]=min(dp1[k]+1,dp1[i]);
			}
		}
	}
}

void calc2()//to bottom
{
	dp2[0]=0;
	for(int i=1;i<D;i++)
	{
		dp2[i]=dp2[i-1]+1;
		for(int j=2;j<=K;j++)
		{
			if(i%j==0) continue;
			int nxt=(i/j)*j;
			dp2[i]=min(dp2[nxt]+1,dp2[i]);
		}
	}
}

int main()
{
	long long A,B;
	cin>>A>>B>>K;
	D=1;
	for(int i=2;i<=K;i++) D*=(i/gcd(i,D));
	if(A/D==B/D)
	{
		int ans=calc_small(A,B);
		cout<<ans<<"\n";
		return 0;
	}
	calc1();
	calc2();
	long long Ad=A/D,Ar=A%D;
	long long Bd=B/D,Br=B%D;
	
	long long ans=0;
	long long num=Ad-Bd-1;
	ans+=num*(dp1[0]+1);
	if(Ar!=0) ans+=dp2[Ar];
	ans+=(dp1[Br]+1);
	cout<<ans<<"\n";
	return 0;
}