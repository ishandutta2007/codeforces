#include <bits/stdc++.h>

using namespace std;

typedef long long LL;

int N;
char s[3][200010];
int cnt[128]; 
int len;
int score[3];
char name[3][20] = {"Kuro","Shiro","Katie"};

int main()
{
	scanf("%d",&N);
	for (int i=0;i<3;i++)scanf("%s",s[i]);
	len = strlen(s[0]);
	int maxscore = 0;
	for (int i=0;i<3;i++)
	{
		memset(cnt,0,sizeof(cnt));
		for (int j=0;j<len;j++)cnt[s[i][j]]++;
		int mx = 0;
		for (int j=0;j<128;j++)mx = max(mx,cnt[j]);
		//printf("%d\n",mx);
		if (N == 1 && mx == len) score[i] = len - 1;
		else score[i] = min(mx + N, len);
		maxscore = max(maxscore,score[i]);
		//printf("%d\n",score[i]);
	}
	int C = 0,v;
	for (int i=0;i<3;i++)if (score[i] == maxscore) C++, v = i;
	if (C > 1) return 0 * puts("Draw");
	printf("%s\n",name[v]);
}