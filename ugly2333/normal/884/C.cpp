//CF 884C
#include<iostream>
#include<cstdio>
#include<fstream>
#include<algorithm>
#include<vector>
#include<map>
#include<set>
#include<queue>
#include<cmath>
#include<cstring>
#include<cstdlib>
using namespace std;
typedef long long LL;
int p[111111],a[111111];
vector<int> v;
int main()
{
	int n,i,x,y;
	LL ans;
	scanf("%d",&n);
	for(i=1;i<=n;i=i+1)
		scanf("%d",p+i);
	ans=0;
	for(i=1;i<=n;i=i+1){
		if(a[i])
			continue;
		x=p[i];
		y=1;
		while(x!=i){
			a[x]=i;
			x=p[x];
			y++;
		}
		ans+=(LL)y*y;
		v.push_back(y);
	}
	sort(v.begin(),v.end());
	reverse(v.begin(),v.end());
	if(v.size()>=2)
		ans+=(LL)2*v[0]*v[1];
	cout<<ans<<endl;
	return 0;
}