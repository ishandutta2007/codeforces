#include<cstdio>
#include<iostream>
#include<string>
#include<algorithm>

using namespace std;

long long first[3000],last[3000];

int main()
{
	string in;
	cin>>in;
	int n=in.size();
	for(int i=0;i<n;i++)
	{
		//i,(i-1,i+1),(i-2,i+2),etc
		first[i]++;
		last[i]++;
		for(int k=1;;k++)
		{
			if(i+k>=n||i-k<0) break;
			if(in[i-k]!=in[i+k]) break;
			first[i-k]++;last[i+k]++;
		}
	}
	for(int i=0;i+1<n;i++)
	{
		//(i,i+1),(i-1,i+2),etc
		if(in[i]!=in[i+1]) continue;
		first[i]++;last[i+1]++;
		for(int k=1;;k++)
		{
			if(i-k<0||i+k+1>n) break;
			if(in[i-k]!=in[i+k+1]) break;
			first[i-k]++;last[i+k+1]++;
		}
	}
	long long ans=0;
	for(int i=0;i<n;i++)
	{
		for(int j=i+1;j<n;j++)
		{
			ans+=last[i]*first[j];
		}
	}
	cout<<ans<<"\n";
	return 0;
}