#include<cstdio>
#include<vector>
#include<iostream>
#include<algorithm>

using namespace std;

//vector<int> getDigits(long long n)
int getDigits(int n)
{
//	vector<int> vec;
	int res=0;
	while(n>0)
	{
		//vec.push_back(n%10);
		res=max(res,n%10);
		n/=10;
	}
	//return vec;
	return res;
}

int MD[1000100];

int dp[10][1000100];
int     over[10][1000100];

void fill_dp()
{
	for(int i=0;i<=1000000;i++) MD[i]=getDigits(i);
	for(int i=0;i<10;i++) 
	{
		dp[i][0]=0;
		over[i][0]=i;
	}
	for(int i=1;i<1000000;i++)
	{
		//vector<int> vec=getDigits(i);
		//int M=getDigits(i);
		int M=MD[i];
		//for(int j=0;j<vec.size();j++) M=max(M,vec[j]);
		for(int k=0;k<10;k++)
		{
			int dec=max(M,k);
			if(dec>i)
			{
				over[k][i]=dec-i;
				dp[k][i]=0;
			}
			else
			{
				dp[k][i]=dp[k][i-dec]+1;
				over[k][i]=over[k][i-dec];
			}
		}
	}
}

const long long B=1000000;

int solve1(long long N)
{
	return dp[0][N];
}

long long solve2(long long N)
{
	if(N<B) return solve1(N);
	long long U=N/B,L=N%B;
	//vector<int> UDigits=getDigits(U);
	int UM=MD[U];
	//for(int i=0;i<UDigits.size();i++) UM=max(UM,UDigits[i]);
	long long tmp=dp[UM][L];
	long long nxt=B*U-over[UM][L];
	return tmp+1+solve2(nxt);
}

int main()
{
	fill_dp();
	long long N;
	cin>>N;
	cout<<solve2(N)<<"\n";
	return 0;
}