#include <bits/stdc++.h>
using namespace std;
const int Maxn=100005;
int n,cnt[Maxn],ans,ct;
string str[Maxn];
char sta[Maxn*5];
map <int,int> Ma;
int main()
{
	//freopen("C.in","r",stdin);
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	{
		ct=0;
		cin>>str[i];
		int siz=str[i].size();
		for(int j=0;j<siz;j++)
		{
			if(sta[ct]=='('&&str[i][j]==')') ct--;
			else
				sta[++ct]=str[i][j];
		}
		if(sta[1]==')'&&sta[ct]=='(') cnt[i]=0x3f3f3f3f;
		else cnt[i]=ct*(sta[1]==')'?1:-1);
	}
	sort(cnt+1,cnt+1+n);
	for(int i=1;i<=n;i++)
	{
		if(cnt[i]==0x3f3f3f3f) continue;
		Ma[cnt[i]]++;
	}
	for(int i=1;i<=n;i++)
	{
		if(cnt[i]==0x3f3f3f3f) continue;
		if(cnt[i]==0&&Ma[0]>=2) ans++,Ma[0]-=2;
		if(cnt[i]!=0&&Ma[-cnt[i]]&&Ma[cnt[i]]) ans++,Ma[-cnt[i]]--,Ma[cnt[i]]--;
	}
	printf("%d",ans);
	return 0;
}