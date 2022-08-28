//CF 884D
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
priority_queue<LL> Q;
int main()
{
	int n,i,s,x;
	LL ans,t;
	scanf("%d",&n);
	for(i=1;i<=n;i=i+1){
		scanf("%d",&x);
		Q.push(-x);
	}
	ans=0;
	s=n;
	if(n%2==0)
		Q.push(0),s++;
	//cout<<ans<<endl;
	while(s>1){
		t=Q.top();
		Q.pop();
		t+=Q.top();
		Q.pop();
		t+=Q.top();
		Q.pop();
		Q.push(t);
		ans+=t;
		s-=2;
	}
	cout<<-ans<<endl;
	return 0;
}