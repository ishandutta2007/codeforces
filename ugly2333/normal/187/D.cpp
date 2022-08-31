//CF 187D
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
const int N = 111111;
int n,q;
LL l[N],ans[N<<1];
set<pair<int,int> > S;
set<pair<int,int> >::iterator it,itr;
vector<pair<int,int> > v[N<<1];
int main()
{
	int g,r,gr,i,x,y,t;
	scanf("%d%d%d",&n,&g,&r);
	gr=g+r;
	for(i=1;i<=n+1;i=i+1){
		scanf("%d",&x);
		l[i]=l[i-1]+x;
	}
	scanf("%d",&q);
	for(i=1;i<=q;i=i+1){
		scanf("%d",&x);
		ans[i]=l[n+1]+x;
		S.insert(make_pair(x%gr,i));
	}
	for(i=1;i<=n;i=i+1){
		l[i]%=gr;
		t=g-l[i];
		if(t<0)
			t+=gr;
		itr=S.lower_bound(make_pair(t,0));
		for(it=itr;it!=S.end();it++){
			x=(*it).first,y=(*it).second;
			if(r+t>x)
				v[N+i].push_back(make_pair(y,r+t-x));
			else
				break;
		}
		S.erase(itr,it);
		itr=S.begin();
		for(it=itr;it!=S.end();it++){
			x=(*it).first,y=(*it).second;
			if(r+t>x+gr)
				v[N+i].push_back(make_pair(y,r+t-x-gr));
			else
				break;
		}
		S.erase(itr,it);
		S.insert(make_pair((gr-l[i])%gr,N+i));
	}
	for(i=N+n;i>N;i=i-1){
		t=v[i].size();
		while(t--){
			x=v[i][t].first,y=v[i][t].second;
			ans[x]+=ans[i]+y;
		}
	}
	for(i=1;i<=q;i=i+1)
		cout<<ans[i]<<endl;
	return 0;
}