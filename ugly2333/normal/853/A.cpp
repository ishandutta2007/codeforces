//CF 853A
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
const int N = 333333;
priority_queue<pair<int,int> > Q;
int ans[N];
int main()
{
	int n,k,i,x,y;
	LL s;
	s=0;
	scanf("%d%d",&n,&k);
	for(i=1;i<=n+k;i=i+1){
		if(i<=n){
			scanf("%d",&x);
			Q.push(make_pair(x,i));
		}
		if(i>k){
			x=Q.top().first;
			y=Q.top().second;
			Q.pop();
			s+=(LL)(i-y)*x;
			ans[y]=i;
		}
	}
	cout<<s<<endl;
	for(i=1;i<=n;i=i+1)
		printf("%d ",ans[i]);
	return 0;
}