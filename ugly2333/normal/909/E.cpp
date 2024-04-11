//CF 909E
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
int n,m,a[N],s[N];
vector<int> v[N];
queue<int> Q[2];
int main()
{
	int i,j,x,y,h,ans;
	scanf("%d%d",&n,&m);
	for(i=1;i<=n;i=i+1)
		scanf("%d",a+i);
	while(m--){
		scanf("%d%d",&x,&y);
		x++,y++;
		v[y].push_back(x);
		s[x]++;
	}
	m=0;
	for(i=1;i<=n;i=i+1)
		if(!s[i])
			Q[a[i]].push(i),m++;
	j=0;
	ans=0;
	while(m){
		while(!Q[j].empty()){
			x=Q[j].front(),m--;
			Q[j].pop();
			h=v[x].size();
			for(i=0;i<h;i=i+1){
				y=v[x][i];
				s[y]--;
				if(!s[y])
					Q[a[y]].push(y),m++;
			}
		}
		if(j)
			ans++;
		j^=1;
	}
	cout<<ans<<endl;
	return 0;
}