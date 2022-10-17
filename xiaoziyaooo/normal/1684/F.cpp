#include<bits/stdc++.h>
using namespace std;
const int maxn=500005;
int n,m,k,T,ans,tot,mn,mx;
int a[maxn],b[maxn];
set<int>s[maxn];
vector<int>tmp[maxn];
struct seg{
	int l,r;
}u[maxn],v[maxn];
inline int cmp(seg a,seg b){
	return a.l<b.l||(a.l==b.l&&a.r>b.r);
}
map<int,int>mp;
int main(){
	scanf("%d",&T);
	while(T--){
		scanf("%d%d",&n,&m),mn=n,mx=k=0,ans=1e9,tot=0,mp.clear();
		for(int i=1;i<=n;i++)
			scanf("%d",&a[i]),b[i]=a[i];
		for(int i=1;i<=m;i++)
			scanf("%d%d",&u[i].l,&u[i].r);
		sort(b+1,b+1+n),sort(u+1,u+1+m,cmp);
		for(int i=1;i<=n;i++)
			if(i==1||b[i]!=b[i-1])
				mp[b[i]]=++tot;
		for(int i=1;i<=n;i++)
			a[i]=mp[a[i]];
		int maxx=0;
		for(int i=1;i<=m;i++){
			if(u[i].r>maxx)
				v[++k]=u[i];
			maxx=max(maxx,u[i].r);
		}
		int lst=0,x=1,y=0;
		for(int i=1,lst=0;i<=k;i++){
			int qx=v[i].l,qy=v[i].r;
			while(y<qy)
				y++,s[a[y]].insert(y);
			while(x<qx)
				s[a[x]].erase(x),x++;
			lst++;
			while(lst<=y){
				if(s[a[lst]].size()>1){
					set<int>::iterator it=s[a[lst]].end();
					it--;
					tmp[(*s[a[lst]].begin())+1].push_back(*it);
					it--,mx=max(mx,*it);
					it=s[a[lst]].begin(),it++,mn=min(mn,*it);
				}
				lst++;
			}
			if(lst>y)
				lst=y;
		}
		if(mx!=0){
			for(int i=1;i<=mn;i++){
				for(int j=0;j<tmp[i].size();j++)
					mx=max(mx,tmp[i][j]);
				ans=min(ans,mx-i+1);
			}
			printf("%d\n",ans);
		}
		else puts("0");
		for(int i=0;i<=n+5;i++)
			s[i].clear(),tmp[i].clear();
	}
	return 0;
}