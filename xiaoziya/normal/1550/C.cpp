#include<stdio.h>
#include<map>
#include<algorithm>
#define lowbit(x) x&-x
using namespace std;
const int maxn=200005;
int T,n,tot;
int a[maxn],b[maxn],t[maxn][4];
map<int,int>mp;
inline int max(int a,int b){
	return a>b? a:b;
}
void update(int x,int v,int id){
	for(int i=x;i<=n;i+=lowbit(i))
		t[i][id]=max(t[i][id],v);
}
int query(int x,int id){
	int res=0;
	for(int i=x;i;i-=lowbit(i))
		res=max(res,t[i][id]);
	return res;
}
int main(){
	scanf("%d",&T);
	while(T--){
		scanf("%d",&n);
		for(int i=1;i<=n;i++)
			scanf("%d",&a[i]),b[i]=a[i];
		sort(b+1,b+1+n);
		for(int i=1;i<=n;i++)
			if(i==1||b[i]!=b[i-1])
				tot++,mp[b[i]]=tot;
		for(int i=1;i<=n;i++)
			a[i]=mp[a[i]];
		long long all=1ll*(n+1)*n/2ll,bad=0;
		for(int i=1,lst=0;i<=n;i++){
			int cnt=0,posup=query(a[i],1),posdown=query(tot-a[i]+1,3);
			int pup=query(a[i],0),pdown=query(tot-a[i]+1,2);
			update(a[i],i,0),update(tot-a[i]+1,i,2);
			update(a[i],pup,1),update(tot-a[i]+1,pdown,3);
			lst=max(lst,max(posup,posdown)),bad+=lst;
		}
		printf("%lld\n",all-bad);
		tot=0,mp.clear();
		for(int i=1;i<=n;i++)
			t[i][0]=t[i][1]=t[i][2]=t[i][3]=0;
	}
	return 0;
}