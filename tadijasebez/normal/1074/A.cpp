#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
#define mp make_pair
const int inf=1e9;
int main()
{
	int n,m,i,x,l,r,j;
	scanf("%i %i",&n,&m);
	vector<int> ver,hor;
	for(i=1;i<=n;i++) scanf("%i",&x),ver.pb(x);
	sort(ver.begin(),ver.end());ver.pb(inf);
	int ans=inf,tmp=0;
	for(i=1;i<=m;i++)
	{
		scanf("%i %i %i",&l,&r,&x);
		if(l==1 && x!=inf) hor.pb(r),tmp++;
	}
	sort(hor.begin(),hor.end());
	j=0;
	for(i=0;i<ver.size();i++)
	{
		while(j<hor.size() && hor[j]<ver[i]) tmp--,j++;
		//printf("i:%i ver:%i tmp:%i\n",i,ver[i],tmp);
		ans=min(ans,i+tmp);
	}
	printf("%i\n",ans);
	return 0;
}