//CF 1037E
#include<iostream>
#include<cstdio>
#include<fstream>
#include<algorithm>
#include<vector>
#include<map>
#include<set>
#include<queue>
#include<bitset>
#include<cmath>
#include<cstring>
#include<cstdlib>
using namespace std;
typedef long long LL;
typedef double DB;
const int N = 222222;
int n,m,k,s,a[N],b[N],x[N],y[N],ans[N];
vector<int> v[N];
queue<int> q;
int main()
{
	int i,j,t,ii;
	scanf("%d%d%d",&n,&m,&k);
	for(i=1;i<=m;i=i+1){
		scanf("%d%d",x+i,y+i);
		v[x[i]].push_back(y[i]);
		v[y[i]].push_back(x[i]);
		b[x[i]]++,b[y[i]]++;
	}
	for(i=1;i<=n;i=i+1)
		a[i]=1;
	for(i=1;i<=n;i=i+1)
		if(b[i]<k)
			q.push(i);
	while(!q.empty()){
		i=q.front();
		q.pop();
		a[i]=0;
		for(j=v[i].size();j--;){
			t=v[i][j];
			if(a[t]&&b[t]==k)
				q.push(t);
			b[t]--;
		}
	}
	for(i=1;i<=n;i=i+1)
		s+=a[i];
	for(i=m;i;i=i-1){
		ans[i]=s;
		v[x[i]].pop_back();
		v[y[i]].pop_back();
		if(!a[x[i]]||!a[y[i]])
			continue;
		b[x[i]]--,b[y[i]]--;
		if(a[x[i]]&&b[x[i]]==k-1)
			q.push(x[i]);
		if(a[y[i]]&&b[y[i]]==k-1)
			q.push(y[i]);
		while(!q.empty()){
			ii=q.front();
			q.pop();
			//cout<<i<<ii<<endl;
			a[ii]=0;
			s--;
			for(j=v[ii].size();j--;){
				t=v[ii][j];
				if(a[t]&&b[t]==k)
					q.push(t);
				//cout<<ii<<b[t]<<t<<endl;
				b[t]--;
			}
		}
	}
	for(i=1;i<=m;i=i+1)
		cout<<ans[i]<<endl;
	return 0;
}