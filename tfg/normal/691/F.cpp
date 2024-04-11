#include <cstdio>

const int ms=3000001;

typedef long long ll;

ll freq[ms];
int sum[ms];
int next[ms];

ll ans[ms];

int n,m;

int main()
{
	//std::ios::sync_with_stdio(false);
	scanf("%i",&n);
	for(int i=0;i<n;i++)
	{
		int temp;//std::cin >> temp;
		scanf("%i",&temp);
		freq[temp]++;
	}
	scanf("%i",&m);
	int last=0;
	int first=0;
	//if(m==1000000) std::cout << "lol1\n";
	for(int i=1;i<ms;i++)
	{
		sum[i]=sum[i-1]+freq[i];
		if(freq[i])
		{
			if(last)
				next[last]=i;
			else
				first=i;
			last=i;
		}
	}
	next[last]=ms;
	//if(m==1000000) std::cout << "lol2\n";
	for(int i=1;i!=ms;i++)
	{
		if(freq[i]==0) continue;
		for(int j=i;;j=next[j])
		{
			if((ll)j*(ll)i>=(ll)ms-1LL)
			{
				if(i==j)
				{
					ans[ms-1]+=freq[i]*(freq[i]-1);
					//std::cout << "added " << freq[i]*(freq[i]-1) << " to ans[max]\n";
					j=next[j];
				}
				ans[ms-1]+=freq[i]*(sum[ms-1]-sum[j-1])*2;
				//std::cout << "added " << freq[i]*(sum[ms-1]-sum[j-1]) << " to ans[max]\n";
				break;
			}
			ans[j*i]+=freq[i]*(freq[j]-(j==i?1:0))*(i!=j?2LL:1LL);
		}
	}
	//if(m==1000000) std::cout << "lol3\n";
	for(int i=ms-1;i>0;i--)
		ans[i-1]+=ans[i];
	
	for(int i=0;i<m;i++)
	{
		int temp;//std::cin >> temp;
		scanf("%i",&temp);
		printf("%lli\n",ans[temp]);
	}
}