#include <stdio.h>
#include <algorithm>
#include <vector>
#include <functional>

using namespace std;

vector<pair<int,int> >g[2];
int res=0,cr=0,q,n,V,x,y,n1,n2,sum[100500];

int main(){
	scanf("%d%d",&n,&V);
	for (int i=0;i<n;i++){
		scanf("%d%d",&x,&y);
		--x;g[x].push_back(make_pair(y,i+1));
	}
	sort(g[0].begin(),g[0].end(),greater<pair<int,int> >());
	sort(g[1].begin(),g[1].end(),greater<pair<int,int> >());
	sum[0]=0;
	for (int i=1;i<=g[0].size();i++)sum[i]=sum[i-1]+g[0][i-1].first;
	for (int i=0;i+i<=V&&i<=g[1].size();i++){
		q=V-i-i;
		if (q>g[0].size())q=g[0].size();
		if (cr+sum[q]>res){res=cr+sum[q];n1=q;n2=i;}
		if (i<g[1].size())cr+=g[1][i].first;
	}
	printf("%d\n",res);
	for (int i=0;i<n1;i++)printf("%d ",g[0][i].second);
	for (int i=0;i<n2;i++)printf("%d ",g[1][i].second);
}