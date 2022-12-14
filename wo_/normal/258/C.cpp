#include<cstdio>
#include<vector>
#include<cstring>
#include<algorithm>

using namespace std;

const long long mod=1000000007;

vector<int> getdiv(int N)
{
	vector<int> res;
	for(int i=1;i*i<=N;i++)
	{
		if(N%i==0)
		{
			res.push_back(i);
			if(i*i!=N) res.push_back(N/i);
		}
	}
	sort(res.begin(),res.end());
	return res;
}

long long ex(int a,int e)
{
	if(e==0) return 1;
	long long res=ex(a,e/2);
	res*=res;
	res%=mod;
	if(e%2==1) res*=a;
	res%=mod;
	return res;
}

int sum[100100];

int main()
{
	int N;
	scanf("%d",&N);
	memset(sum,0,sizeof(sum));
	for(int i=0;i<N;i++)
	{
		int in;
		scanf("%d",&in);
		sum[in]++;
	}
	for(int i=1;i<=100050;i++) sum[i]+=sum[i-1];
	long long ans=1;
	for(int d=2;d<=100000;d++)
	{
		vector<int> divs=getdiv(d);
		long long tmp=1;
		for(int i=1;i<divs.size();i++)
		{
			int cand=sum[divs[i]-1]-sum[divs[i-1]-1];
			tmp*=ex(i,cand);
			tmp%=mod;
		}
		long long rem=tmp;
		int cand=N-sum[divs[divs.size()-1]-1];
		tmp*=ex(divs.size(),cand);
		rem*=ex(divs.size()-1,cand);
		tmp%=mod;
		rem%=mod;
		ans+=(tmp-rem);
		ans%=mod;
	}
	ans%=mod;
	ans+=mod;
	ans%=mod;
	printf("%d\n",(int)ans);
	return 0;
}