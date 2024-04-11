#include <stdio.h>
#include <vector>
using namespace std;
vector<int> vec;
bool dp[2][2][2][2];
int a[4],b[4];
int main()
{
	int n,k,i,j;
	bool ok=false;
	scanf("%i %i",&n,&k);
	for(i=0;i<n;i++)
	{
		for(j=0;j<k;j++) scanf("%i",&a[j]);
		for(j=0;j<k;j++) b[j]=0;
		if(dp[b[0]][b[1]][b[2]][b[3]]) ok=true;
		vec.clear();
		for(j=0;j<k;j++) if(a[j]==0) vec.push_back(j);
		if(vec.size()==1)
		{
			b[vec[0]]=1;
			if(dp[b[0]][b[1]][b[2]][b[3]]) ok=true;
		}
		if(vec.size()==2)
		{
			b[vec[0]]=1;
			if(dp[b[0]][b[1]][b[2]][b[3]]) ok=true;
			b[vec[1]]=1;
			if(dp[b[0]][b[1]][b[2]][b[3]]) ok=true;
			b[vec[0]]=0;
			if(dp[b[0]][b[1]][b[2]][b[3]]) ok=true;
		}
		if(vec.size()==3)
		{
			b[vec[0]]=1;
			if(dp[b[0]][b[1]][b[2]][b[3]]) ok=true;
			b[vec[1]]=1;
			if(dp[b[0]][b[1]][b[2]][b[3]]) ok=true;
			b[vec[0]]=0;
			if(dp[b[0]][b[1]][b[2]][b[3]]) ok=true;
			b[vec[0]]=1;
			b[vec[2]]=1;
			if(dp[b[0]][b[1]][b[2]][b[3]]) ok=true;
			b[vec[1]]=0;
			if(dp[b[0]][b[1]][b[2]][b[3]]) ok=true;
			b[vec[0]]=0;
			if(dp[b[0]][b[1]][b[2]][b[3]]) ok=true;
			b[vec[1]]=1;
			if(dp[b[0]][b[1]][b[2]][b[3]]) ok=true;
		}
		if(vec.size()==4) ok=true;
		if(vec.size()==k) ok=true;
		dp[a[0]][a[1]][a[2]][a[3]]=true;
	}
	if(ok) printf("YES\n");
	else printf("NO\n");
	return 0;
}