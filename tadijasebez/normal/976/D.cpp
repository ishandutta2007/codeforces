#include <stdio.h>
#include <vector>
using namespace std;
#define mp make_pair
#define pb push_back
vector<pair<int,int> > Solve(int add, vector<int> d)
{
	//printf("%i %i\n",add,d.size());
	if(d.empty()) return vector<pair<int,int> >(0);
	if(d.size()==1)
	{
		vector<pair<int,int> > ans;
		int i,j;
		for(i=0;i<=d[0];i++) for(j=i+1;j<=d[0];j++) ans.pb(mp(i+add,j+add));
		return ans;
	}
	vector<pair<int,int> > ans;
	vector<int> tmp;
	int i,j;
	for(i=0;i<d[0];i++) for(j=i+1;j<=d.back();j++) ans.pb(mp(i+add,j+add));
	for(i=1;i<d.size()-1;i++) tmp.pb(d[i]-d[0]);
	vector<pair<int,int> > sol=Solve(add+d[0],tmp);
	for(i=0;i<sol.size();i++) ans.pb(sol[i]);
	return ans;
}
int main()
{
	int n,i,x;
	scanf("%i",&n);vector<int> d;
	while(n--) scanf("%i",&x),d.pb(x);
	vector<pair<int,int> > ans=Solve(1,d);
	printf("%i\n",ans.size());
	for(i=0;i<ans.size();i++) printf("%i %i\n",ans[i].first,ans[i].second);
	return 0;
}