#include <cstdio>
#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
#include <utility>

int n;
typedef long long int ll;
typedef std::pair<int, int> ii;

const ll MOD=ll(1e9)+7;

int a[1000100];


ll fat[1000100];

int largest_p[1000100];
int group[1000100];

int get_group(int x)
{
	if(group[x]!=0) return group[x];
	if(x==largest_p[x]) return group[x]=x;
	if((x/largest_p[x])%largest_p[x]==0) return group[x]=get_group(x/largest_p[x]);
	return group[x]=largest_p[x]*get_group(x/largest_p[x]);
}

int group_perms[1000100];
bool got_own[1000100];
int in_group[1000100];
int pos_own[1000100];

int main()
{
	
	scanf("%i",&n);
	fat[0]=1;
	fat[1]=1;
	largest_p[1]=1;
	int one_group=0;
	for(int i=1;i<=n;i++)
		scanf("%i",a+i);
	for(int i=2;i<=n;i++)
	{
		fat[i]=(fat[i-1]*(ll)i)%MOD;
		if(largest_p[i]) continue;
		//printf("%i is prime\n",i);
		largest_p[i]=i;
		for(int j=i+i;j<=n;j+=i)
		{
			largest_p[j]=i;
		}
		if(n/i>1)
			group_perms[n/i]++;
	}
	for(int i=1;i<=n;i++)
	{
		if(largest_p[i]==i && (i+i>n || i==1))
		{
			if(largest_p[a[i]]==a[i] && (a[i]+a[i]>n || a[i]==1 || a[i]==0))
			{
				if(!a[i])
					one_group++;
				continue;
			}
			printf("0\n");
			return 0;
		}
		int n_group=get_group(i);
		int largest=largest_p[i];
		//printf("%i:pos (%i,%i)\n",i,n_group,largest);
		if(a[i]==0)
			in_group[n_group]++;
		else
		{
			int o_group=get_group(a[i]);
			int o_largest=largest_p[a[i]];
			//printf("a (%i,%i)\n",o_group,o_largest);
			if(n/largest != n/o_largest)
			{
				printf("0\n");
				return 0;
			}
			if(got_own[o_largest] && pos_own[largest]!=o_largest)
			{
				printf("0\n");
				return 0;
			}
			got_own[o_largest]=true;
			if(pos_own[largest]==0)
			{
				pos_own[largest]=o_largest;
				group_perms[n/largest]--;
			}
			else
			{
				if(pos_own[largest]!=o_largest)
				{
					printf("0\n");
					return 0;
				}
			}
		}
		
	}
	ll ans=fat[one_group];
	//printf("%i groups of one.\n",one_group);
	for(int i=1;i<=n;i++)
	{
		ans=(ans*fat[group_perms[i]])%MOD;
		ans=(ans*fat[in_group[i]])%MOD;
		//if(group_perms[i]) printf("there are %i group_perms[%i]\n",group_perms[i],i);
		//if(in_group[i]) printf("there are %i in_group[%i]\n",in_group[i],i);
	}
	std::cout << ans << std::endl;


}