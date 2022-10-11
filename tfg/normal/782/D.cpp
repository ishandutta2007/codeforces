#include <iostream>
#include <set>
#include <map>

std::string a[1010][2];
std::set<std::string> hmm;
std::map<std::string, int> haha, wtf;
std::string ans[1010];

void get_ans(int i, int type)
{
	if(hmm.find(a[i][type])!=hmm.end())
		return;
	ans[i]=a[i][type];
	hmm.insert(a[i][type]);
	if(type==1)
	{
		int to=wtf[a[i][1]]-1;
		if(to>=0 && ans[to].size()==0 && haha[a[to][0]]==1)
		{
			get_ans(to, 1);
		}
	}
}

int main()
{
	int n;
	std::cin >> n;
	for(int i=0;i<n;i++)
	{
		std::string s1, s2;
		std::cin >> s1 >> s2;
		a[i][0]+=s1[0];
		a[i][0]+=s1[1];
		a[i][1]=a[i][0];
		a[i][1]+=s2[0];
		a[i][0]+=s1[2];
		haha[a[i][0]]++;
		wtf[a[i][0]]=i+1;
	}
	for(int i=0;i<n;i++)
	{
		if(haha[a[i][0]]>1)
		{
			if(hmm.find(a[i][1])==hmm.end())
			{
				get_ans(i, 1);
			}
			else
			{
				std::cout << "NO\n";
				return 0;
			}
		}
	}
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<3 && ans[i].size()==0;j++)
		{
			if(j==2)
			{
				std::cout << "NO\n";
				return 0;
			}
			get_ans(i, j);
		}
	}
	std::cout << "YES\n";
	for(int i=0;i<n;i++)
		std::cout << ans[i] << '\n';
}