#include <iostream>
#include <vector>
#include <utility>

typedef std::pair<int, int> ii;

const int ms=100100;

std::vector<int> mat[ms];
int prefix[ms];

ii where[ms];

bool got[ms];

int until;
int ans=0;

void go()
{
	while(got[until+1])
	{
		until++;
		ans++;
	}
}

void take_until(int on, int num)
{
	while(mat[on].back()!=num)
	{
		got[mat[on].back()]=true;
		mat[on].pop_back();
		ans++;
	}
	got[num]=true;
	mat[on].pop_back();
}

int main()
{
	int n, k;
	std::cin >> n;
	std::cin >> k;
	for(int i=0;i<k;i++)
	{
		int t;
		std::cin >> t;
		while(t--)
		{
			int temp;
			std::cin >> temp;
			where[temp]=ii(i, mat[i].size());
			mat[i].push_back(temp);
		}
	}
	for(int i=0;i<k;i++)
	{
		prefix[i]=1;
		while(prefix[i]<mat[i].size() && mat[i][prefix[i]]==mat[i][prefix[i]-1]+1)
			prefix[i]++;
		//std::cout << i << ": " << prefix[i] << '\n';
	}
	
	until=0;
	for(int i=1;i<=prefix[where[1].first];i++)
	{
		got[i]=true;
		until++;
	}
	//std::cout << "starting on " << until << '\n';
	take_until(where[1].first, until);

	while(until<n)
	{
		take_until(where[until+1].first, until+1);
		go();
	}
	std::cout << ans << '\n';
}