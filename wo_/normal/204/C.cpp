#include<cstdio>
#include<vector>
#include<algorithm>

using namespace std;

char a[200200],b[200200];

long long suma[200200]={},sumb[200200]={};
vector<int> aid[26],bid[26];

int main()
{
	int N;
	scanf("%d",&N);
	scanf("%s%s",a,b);
	for(int i=0;i<N;i++)
	{
		aid[a[i]-'A'].push_back(i);
		bid[b[i]-'A'].push_back(i);
	}
	for(int ch=0;ch<26;ch++)
	{
		for(int i=0;i<aid[ch].size();i++)
		{
			if(i==0) suma[aid[ch][i]]=aid[ch][i]+1;
			else suma[aid[ch][i]]=suma[aid[ch][i-1]]+aid[ch][i]+1;
		}
		for(int i=0;i<bid[ch].size();i++)
		{
			if(i==0) sumb[bid[ch][i]]=bid[ch][i]+1;
			else sumb[bid[ch][i]]=sumb[bid[ch][i-1]]+bid[ch][i]+1;
		}
	}
	double ans=0;
	for(int j=0;j<N;j++)
	{
		//(i+1 of A)*(N-j of B)
		//i<j
		int ch=b[j]-'A';
		if(aid[ch].empty()) continue;
		vector<int>::iterator it=lower_bound(aid[ch].begin(),aid[ch].end(),j);
		if(it==aid[ch].begin()) continue;
		advance(it,-1);
		ans+=(suma[*it])*(N-j);
		//printf("%d of A and %d of B\n",*it,j);
	}
	for(int j=0;j<N;j++)
	{
		//(i+1 of B)*(N-j of A)
		//i<=j
		int ch=a[j]-'A';
		if(bid[ch].empty()) continue;
		vector<int>::iterator it=lower_bound(bid[ch].begin(),bid[ch].end(),j+1);
		//if(it==bid[ch].end()) advance(it,-1);
		if(it==bid[ch].begin()) continue;
		advance(it,-1);
		ans+=(sumb[*it])*(N-j);
		//printf("%d of B and %d of A\n",*it,j);
	}
	long long total=0;
	for(int i=1;i<=N;i++) total+=((long long)i*i);
	printf("%.9f\n",(double)ans/total);
	return 0;
}