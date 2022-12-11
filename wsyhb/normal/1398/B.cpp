#include<bits/stdc++.h>
using namespace std;
const int max_len=100+5;
char s[max_len];
int main()
{
	int T;
	scanf("%d",&T);
	while(T--)
	{
		scanf("%s",s+1);
		int len=strlen(s+1);
		vector<int> val;
		for(int i=1;i<=len;++i)
		{
			if(s[i]=='0')
				continue;
			int j=i;
			while(j+1<=len&&s[j+1]=='1')
				++j;
			val.push_back(j-i+1);
			i=j;
		}
		sort(val.begin(),val.end(),greater<int>());
		int ans=0;
		for(int i=0;i<int(val.size());i+=2)
			ans+=val[i];
		printf("%d\n",ans);
	}
	return 0;
}