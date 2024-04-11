#include<stdio.h>
#include<queue>
using namespace std;
const int maxn=100005;
int T,n,m,x,y,z,mx;
int a[maxn],b[maxn],c[maxn];
vector<int>v[maxn];
priority_queue< pair<int,int> >q;
int main(){
	scanf("%d",&T);
	while(T--){
		scanf("%d%d%d",&n,&x,&y);
		for(int i=1;i<=n;i++)
			scanf("%d",&a[i]),v[a[i]].push_back(i);
		int no=0;
		for(int i=1;i<=n+1;i++){
			if(v[i].size()==0)
				no=i;
			else q.push(make_pair(v[i].size(),i));
		}
		for(int i=1;i<=x;i++){
			pair<int,int>x=q.top();
			q.pop(),b[v[x.second].back()]=x.second,v[x.second].pop_back();
			x.first--;
			if(x.first)
				q.push(x);
		}
		m=mx=z=0;
		for(int i=1;i<=n+1;i++){
			mx=max(mx,(int)v[i].size());
			while(v[i].size())
				c[++m]=v[i].back(),v[i].pop_back();
		}
		for(int i=1,j=mx+1;i<=m;i++){
			j=(j-1)%m+1;
			if(z==y-x)
				break;
			if(a[c[i]]!=a[c[j]])
				b[c[i]]=a[c[j]],j=j%m+1,z++;
		}
		if(z==y-x){
			puts("YES");
			for(int i=1;i<=n;i++)
				printf("%d%c",b[i]==0? no:b[i],i==n? '\n':' ');
		}
		else puts("NO");
		while(!q.empty())
			q.pop();
		for(int i=1;i<=n;i++)
			b[i]=0; 
	}
	return 0;
}