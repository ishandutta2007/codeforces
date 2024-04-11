#include <bits/stdc++.h>
using namespace std;
#define int long long
int n,m,a,b;
int h[1005][1005],sum[1005][1005];
struct node{
    int pos,x;
} q[1005];
int head,tail;
int s[1005][1005];
priority_queue<pair<int,pair<int,int> >,vector<pair<int,pair<int,int> > >,greater<pair<int,pair<int,int> > > > pq;
vector<pair<int,pair<int,int> > > ans;
bool vis[1005][1005];
inline void work(){
	while(!pq.empty()){
		pair<int,pair<int,int> > p=pq.top();
		pq.pop();
		int val=p.first,x=p.second.first,y=p.second.second;
		if(vis[x][y]||vis[x+a-1][y]||vis[x][y+b-1]||vis[x+a-1][y+b-1])
			continue;
		for(int i=x;i<x+a;i++)
			for(int j=y;j<y+b;j++)
				vis[i][j]=1;
		ans.push_back(p);
	}
}
signed main(){
	cin>>n>>m>>a>>b;
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++)
			scanf("%I64d",&h[i][j]),
			sum[i][j]=sum[i-1][j]+sum[i][j-1]-sum[i-1][j-1]+h[i][j];
    for(int i=1;i<=n;i++){
        head=1;tail=0;
        for(int j=1;j<=m;j++){
            if(head<=tail&&q[head].pos<j-b+1)		head++;
            while(head<=tail&&q[tail].x>h[i][j])	tail--;
            q[++tail].pos=j;
			q[tail].x=h[i][j];
            if(j-b+1>0)	s[i][j-b+1]=q[head].x;
        }
    }
    for(int i=1;i<=m-b+1;i++){
        head=1;tail=0;
        for(int j=1;j<=n;j++){
            if(head<=tail&&q[head].pos<j-a+1)		head++;
            while(head<=tail&&q[tail].x>s[j][i])	tail--;
            q[++tail].pos=j;
			q[tail].x=s[j][i];
            if(j-a+1>0)	s[j-a+1][i]=q[head].x;
        }
    }    
    for(int i=1;i<=n-a+1;i++)
        for(int j=1;j<=m-b+1;j++)
        	pq.push({sum[i+a-1][j+b-1]-sum[i+a-1][j-1]-sum[i-1][j+b-1]+sum[i-1][j-1]-s[i][j]*a*b,{i,j}});
    work();
    cout<<ans.size()<<endl;
    for(int i=0;i<ans.size();i++)
		printf("%I64d %I64d %I64d\n",ans[i].second.first,ans[i].second.second,ans[i].first);
	return 0;
}