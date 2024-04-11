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
		scanf("%s",s+1);
		int len=strlen(s+1);
		assert(len%2==0);
		int cnt_left=0,cnt_right=0;
		vector<int> pos;
		for(int i=1;i<=len;++i)
		{
			if(s[i]=='(')
				++cnt_left;
			else if(s[i]==')')
				++cnt_right;
			else
				pos.push_back(i);
		}
		assert(max(cnt_left,cnt_right)<=len/2);
		for(int i=0;i<len/2-cnt_left;++i)
			s[pos[i]]='(';
		for(int i=len/2-cnt_left;i<(int)pos.size();++i)
			s[pos[i]]=')';
		int sum=0;
		for(int i=1;i<=len;++i)
		{
			sum+=(s[i]=='('?1:-1);
			assert(sum>=0);
		}
		assert(!sum);
		bool ans=true;
		if(cnt_left<len/2&&cnt_right<len/2)
		{
			swap(s[pos[len/2-cnt_left-1]],s[pos[len/2-cnt_left]]);
			ans=false;
			for(int i=1;i<=len;++i)
			{
				sum+=(s[i]=='('?1:-1);
				if(sum<0)
				{
					ans=true;
					break;
				}
			}
		}
		puts(ans?"YES":"NO");
	}
	return 0;
}