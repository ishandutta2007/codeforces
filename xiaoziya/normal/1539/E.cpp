#include<stdio.h>
#include<set>
using namespace std;
const int maxn=100005;
int n,m;
int k[maxn],la[maxn],ra[maxn],lb[maxn],rb[maxn],rec[maxn][2],ans[maxn];
set< pair<int,int> >s0,s1;
void out(int p,int t){
	if(p==0)
		return ;
	int lst=rec[p][t];
	for(int i=lst+1;i<=p;i++)
		ans[i]=t;
	out(lst,t^1);
}
int main(){
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)
		scanf("%d%d%d%d%d",&k[i],&la[i],&ra[i],&lb[i],&rb[i]);
	if(la[1]<=k[1]&&k[1]<=ra[1]&&lb[1]<=0&&0<=rb[1])
		s0.insert(make_pair(0,0));
	if(lb[1]<=k[1]&&k[1]<=rb[1]&&la[1]<=0&&0<=ra[1])
		s1.insert(make_pair(0,0));
	for(int i=2;i<=n;i++){
		int e0=s0.empty(),e1=s1.empty();
		if(la[i]<=k[i]&&k[i]<=ra[i]){
			if(!e1)
				s0.insert(make_pair(k[i-1],i-1));
			while(!s0.empty()&&s0.begin()->first<lb[i])
				s0.erase(s0.begin());
			while(!s0.empty()&&s0.rbegin()->first>rb[i])
				s0.erase(--s0.end());
		}
		else s0.clear();
		if(lb[i]<=k[i]&&k[i]<=rb[i]){
			if(!e0)
				s1.insert(make_pair(k[i-1],i-1));
			while(!s1.empty()&&s1.begin()->first<la[i])
				s1.erase(s1.begin());
			while(!s1.empty()&&s1.rbegin()->first>ra[i])
				s1.erase(--s1.end());
		}
		else s1.clear();
		if(!s0.empty())
			rec[i][0]=s0.begin()->second;
		if(!s1.empty())
			rec[i][1]=s1.begin()->second;
	}
	if(s0.empty()&&s1.empty()){
		puts("No");
		return 0;
	}
	if(!s0.empty())
		out(n,0);
	else out(n,1);
	puts("Yes");
	for(int i=1;i<=n;i++)
		printf("%d%c",ans[i],i==n? '\n':' ');
	return 0;
}