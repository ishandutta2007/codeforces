#include <iostream>
#include <vector>
#include <algorithm>
#define mod 1000000007
using namespace std;
int fa[500005];
inline int ff(int x)
{
	if(fa[x]==x) return x;
	return fa[x]=ff(fa[x]);
}
vector <int> Ans;
int main(int argc, char** argv) {
	int n,m;
	scanf("%d%d",&n,&m);
	for(int i=1;i<=m;i++) fa[i]=i;
	int ans=1;
	for(int i=1;i<=n;i++)
	{
		int k;
		scanf("%d",&k);
		if(k==2)
		{
			int u,v;
			scanf("%d%d",&u,&v);
			if(ff(u)!=ff(v))
				ans=(ans+ans)%mod,Ans.push_back(i),fa[ff(u)]=ff(v);
		}
		else
		{
			int u;
			scanf("%d",&u);
			if(ff(u)!=ff(0))
				ans=(ans+ans)%mod,Ans.push_back(i),fa[ff(u)]=0;
		}
	}
	cout << ans << " " << Ans.size() << "\n";
	for(auto t:Ans) printf("%d ",t);
	return 0;
}