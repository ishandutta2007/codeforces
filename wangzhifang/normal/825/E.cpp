#include <set>
#include <vector>
#include <cstdio>
#include <cstring>
using namespace std;
#define max_n 100000
int a[max_n+1],to[max_n+1];
vector<int>v[max_n+1];
set<int,greater<int>> st;
int main(){
	memset(a,0,sizeof(a));
	memset(to,0,sizeof(to));
	int n,m;
	scanf("%d%d",&n,&m);
	for(int x,y; m; --m,v[x].push_back(y),++to[y])
		scanf("%d%d",&y,&x);
	for(int i=1; i<=n; ++i)
		if(!to[i])
			st.insert(i);
	for(int cnt=n,x; !st.empty(); a[x]=cnt--){
		x=*st.begin();
		st.erase(st.begin());
		for(vector<int>::iterator it=v[x].begin(),ed=v[x].end(); it!=ed; ++it)
			if(--to[*it]==0)
				st.insert(*it);
	}
	for(int i=1; i<=n; ++i)
		printf("%d ",a[i]);
	return 0;
}