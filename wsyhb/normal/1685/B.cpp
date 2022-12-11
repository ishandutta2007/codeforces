#include<bits/stdc++.h>
using namespace std;
const int max_len=2e5+5;
char s[max_len];
int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		int a,b,c,d;
		scanf("%d%d%d%d%s",&a,&b,&c,&d,s+1);
		int len=strlen(s+1);
		assert(len==a+b+2*c+2*d);
		int cntA=0;
		for(int i=1;i<=len;++i)
			cntA+=s[i]=='A';
		if(cntA!=a+c+d)
		{
			puts("NO");
			continue;
		}
		vector<int> v1,v2,v3;
		int cnt_AB=0;
		for(int i=1;i<=len;++i)
		{
			int j=i;
			while(j+1<=len&&s[j+1]!=s[j])
				++j;
			if(j==i)
				continue;
			int cnt=0;
			for(int k=i;k<j;++k)
				cnt+=s[k]=='A'&&s[k+1]=='B';
			if(s[i]=='B'&&s[j]=='A')
				v1.push_back(cnt);
			else if(s[i]==s[j])
				v2.push_back(cnt);
			else if(cnt>0)
				v3.push_back(cnt);
			cnt_AB+=cnt;
			i=j;
		}
		if(cnt_AB<c)
		{
			puts("NO");
			continue;
		}
		int delta=cnt_AB-c;
		sort(v1.begin(),v1.end());
		int cnt_BA=0;
		for(int i=0;i<int(v1.size());++i)
		{
			if(delta>=v1[i])
			{
				delta-=v1[i];
				cnt_BA+=v1[i]+1;
			}
			else
			{
				cnt_BA+=delta;
				delta=0;
			}
		}
		for(int i=0;i<int(v2.size());++i)
		{
			if(delta>=v2[i])
			{
				delta-=v2[i];
				cnt_BA+=v2[i];
			}
			else
			{
				cnt_BA+=delta;
				delta=0;
			}
		}
		sort(v3.begin(),v3.end(),greater<int>());
		for(int i=0;i<int(v3.size());++i)
		{
			if(delta>=v3[i])
			{
				delta-=v3[i];
				cnt_BA+=v3[i]-1;
			}
			else if(delta>0)
			{
				cnt_BA+=delta-1;
				delta=0;
			}
		}
		puts(cnt_BA>=d?"YES":"NO");
	}
	return 0;
}