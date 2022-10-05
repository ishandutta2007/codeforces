#include <bits/stdc++.h>
using namespace std;
const int Maxn=100005,Maxk=14;
int n,k,val[Maxn][Maxk];
struct team
{
	int mini[Maxk],maxi[Maxk],cnt;
	bool operator < (const team &tmp) const
	{
		for(int i=1;i<=k;i++)
			if(maxi[i]>tmp.mini[i]) return false;
		return true;
	}
	void clear(void)
	{
		memset(maxi,0,sizeof(maxi));
		memset(mini,0,sizeof(mini));
		cnt=0;
	}
};
set <team> Se;
int main()
{
	scanf("%d%d",&n,&k);
	for(int i=1;i<=n;i++)
		for(int j=1;j<=k;j++)
			scanf("%d",&val[i][j]);
	for(int i=1;i<=n;i++)
	{	
		team now;
		now.clear();
		for(int j=1;j<=k;j++)
			now.maxi[j]=now.mini[j]=val[i][j];
		now.cnt=1;
		if(Se.empty()){Se.insert(now); printf("1\n"); continue;} 
		set <team>::iterator UP=Se.upper_bound(now),DN=Se.lower_bound(now);
		team MG;
		MG.clear();
		MG.cnt=1;
		for(int j=1;j<=k;j++) MG.mini[j]=MG.maxi[j]=val[i][j];
		set <team>::iterator it=DN;
		if(DN==Se.end()) goto A;
		while(it!=UP)
		{
			MG.cnt+=it->cnt;
			for(int j=1;j<=k;j++) MG.mini[j]=min(MG.mini[j],it->mini[j]),MG.maxi[j]=max(MG.maxi[j],it->maxi[j]);
			Se.erase(it++);
		}
		A:Se.insert(MG);
		set <team>::iterator END=Se.end();
		END--;
		printf("%d\n",END->cnt);
	}
	return 0;
}