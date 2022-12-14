#include<cstdio>
#include<vector>
#include<cstring>
#include<algorithm>

using namespace std;

vector<int> vals;

int card[100100][2];

int fro[200200],bck[200200];

int main()
{
	int N;
	scanf("%d",&N);
	for(int i=0;i<N;i++)
	{
		int a,b;
		scanf("%d%d",&a,&b);
		vals.push_back(a);
		vals.push_back(b);
		card[i][0]=a,card[i][1]=b;
	}
	sort(vals.begin(),vals.end());
	vals.erase(unique(vals.begin(),vals.end()),vals.end());
	for(int i=0;i<N;i++)
	{
		card[i][0]=distance(vals.begin(),lower_bound(vals.begin(),vals.end(),card[i][0]));
		card[i][1]=distance(vals.begin(),lower_bound(vals.begin(),vals.end(),card[i][1]));
	}
	memset(fro,0,sizeof(fro));
	memset(bck,0,sizeof(bck));
	for(int i=0;i<N;i++)
	{
		int f=card[i][0],b=card[i][1];
		fro[f]++;
		if(f!=b) bck[b]++;
	}
	int ans=N*2;
	int bnd=(N+1)/2;
	for(int i=0;i<vals.size();i++)
	{
		if(fro[i]+bck[i]<bnd) continue;
		int tmp=max(0,bnd-fro[i]);
		ans=min(ans,tmp);
	}
	if(ans>N) printf("-1\n");
	else printf("%d\n",ans);
	return 0;
}