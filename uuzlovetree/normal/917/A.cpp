#include<bits/stdc++.h>
#define maxn 5005
using namespace std;
int n;
char s[maxn];
int main()
{
	scanf("%s",s+1);
	n=strlen(s+1);
	int ans=0;
	int up=0,down=0;
	for(int l=1;l<=n;++l)
	{
		up=0;down=0;
		for(int r=l;r<=n;++r)
		{
			if(s[r]=='(')up++,down++;
			else if(s[r]==')')up--,down--;
			else if(s[r]=='?')up++,down--;
			down=max(down,0);
			if(up<0)break;
			if((r-l+1)%2==0&&(down==0&&up>=0))ans++;
		}
	}
	printf("%d\n",ans);
	return 0;
}