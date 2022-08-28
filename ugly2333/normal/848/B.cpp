//CF 848B
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
vector<pair<int,int> > v1[N*2],v2[N*2];
pair<int,int> st[N],fn[N];
int ans[N],t[N],b[N];
int main()
{
	int n,w,h,i,j,x,y,z,s1,s2;
	scanf("%d%d%d",&n,&w,&h);
	for(i=1;i<=n;i=i+1){
		scanf("%d%d%d",&x,&y,&z);
		ans[i]=i;
		if(x==1){
			st[i]=make_pair(y,0);
			fn[i]=make_pair(y,h);
			v1[y-z+N].push_back(make_pair(y,i));
		}
		else{
			st[i]=make_pair(0,y);
			fn[i]=make_pair(w,y);
			v2[y-z+N].push_back(make_pair(-y,i));
		}
	}
	for(i=5;i<=N+N-5;i=i+1){
		sort(v1[i].begin(),v1[i].end());
		sort(v2[i].begin(),v2[i].end());
		s1=v1[i].size();
		s2=v2[i].size();
		if(!s1||!s2)
			continue;
		for(j=1;j<=s2;j=j+1)
			t[j]=v2[i][j-1].second;
		for(j=s2+1;j<=s2+s1;j=j+1)
			t[j]=v1[i][j-s2-1].second;
		for(j=1;j<=s1;j=j+1)
			b[j]=v1[i][j-1].second;
		for(j=s1+1;j<=s1+s2;j=j+1)
			b[j]=v2[i][j-s1-1].second;
		for(j=1;j<=s1+s2;j=j+1)
			ans[t[j]]=b[j];
	}
	for(i=1;i<=n;i=i+1)
		printf("%d %d\n",fn[ans[i]].first,fn[ans[i]].second);//printf("%d",ans[i]);
	return 0;
}