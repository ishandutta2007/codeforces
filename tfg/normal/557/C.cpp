#include <iostream>
#include <cstdio>

typedef long long ll;

int a[100100][201];
int freq[201];

int type[100100];

int main()
{
	int n;
	std::cin >> n;
	for(int i=0;i<n;i++)
		scanf("%i",type+i);
	for(int i=0;i<n;i++)
	{
		int temp;
		scanf("%i",&temp);
		freq[temp]++;
		a[type[i]][temp]++;
		a[type[i]][0]++;
	}
	ll ans=int(1e8);
	ll sum=0;
	for(int i=100100-1;i>=0;i--)
	{
		if(!a[i][0])
			continue;
		for(int j=1;j<=200;j++)
			freq[j]-=a[i][j];
		ll cur_ans=sum;
		int cur_got=n-a[i][0];
		//std::cout << "fixing " << i << '\n';
		for(int j=1;j<=200 && cur_got-a[i][0]>=0;j++)
		{
			int lul=std::min(cur_got-a[i][0]+1, freq[j]);
			cur_got-=lul;
			cur_ans+=lul*j;
			//if(lul)
			//	std::cout << "got " << lul << " on " << j << '\n';
		}
		//std::cout << "cur_ans = " << cur_ans << '\n';
		ans=std::min(ans, cur_ans);
		for(int j=1;j<=200;j++)
			sum+=j*a[i][j];
		n-=a[i][0];
	}
	std::cout << ans << '\n';
}