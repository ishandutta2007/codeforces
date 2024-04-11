#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define mp make_pair
int Ask(vector<int> v, int u)
{
	printf("1\n1\n");
	printf("%i\n",v.size());
	for(int u:v) printf("%i ",u);
	printf("\n%i\n",u);
	fflush(stdout);
	int k;scanf("%i",&k);
	return k;
}
vector<pair<int,int>> edges;
const int N=550;
int sz[N],id[N];
int main()
{
	int n,i,j;
	scanf("%i",&n);
	vector<int> tmp;
	for(i=2;i<=n;i++) tmp.pb(i);
	sz[1]=n;id[1]=1;
	for(i=2;i<=n;i++) sz[i]=Ask(tmp,i),id[i]=i;
	sort(id+1,id+n+1,[&](int x, int y){ return sz[x]<sz[y];});
	vector<int> X;
	X.pb(id[1]);
	for(j=2;j<=n;j++)
	{
		i=id[j];
		int work=Ask(X,i);
		while(work--)
		{
			int top=(int)X.size()-1,bot=0,mid,ans=X.size();
			while(top>=bot)
			{
				mid=top+bot>>1;
				vector<int> Y=X;
				Y.resize(mid+1);
				if(Ask(Y,i)>0) ans=mid,top=mid-1;
				else bot=mid+1;
			}
			if(ans==X.size()) printf("???\n");
			edges.pb(mp(i,X[ans]));
			X.erase(X.begin()+ans);
		}
		X.pb(i);
	}
	printf("ANSWER\n");
	for(auto e:edges) printf("%i %i\n",e.first,e.second);
	fflush(stdout);
	return 0;
}