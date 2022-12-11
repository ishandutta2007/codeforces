#include<bits/stdc++.h>
using namespace std;
int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		vector<int> cnt(26);
		char str[5];
		scanf("%s",str);
		++cnt[str[0]-'a'];
		++cnt[str[1]-'a'];
		scanf("%s",str);
		++cnt[str[0]-'a'];
		++cnt[str[1]-'a'];
		vector<int> val;
		for(int i=0;i<26;++i)
		{
			if(cnt[i]>0)
				val.push_back(cnt[i]);
		}
		int sz=val.size();
		cout<<sz-1<<"\n";
	}
	return 0;
}