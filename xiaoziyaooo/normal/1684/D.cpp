#include<bits/stdc++.h>
using namespace std;
const int maxn=500005;
int n,m,T;
long long ans;
int a[maxn],id[maxn],s[maxn];
inline int cmp(int x,int y){
	return a[x]>a[y];
}
int main(){
	scanf("%d",&T);
	while(T--){
		ans=0;
		scanf("%d%d",&n,&m);
		for(int i=1;i<=n;i++)
			scanf("%d",&a[i]),a[i]-=n-i,id[i]=i,s[i]=0;
		sort(id+1,id+1+n,cmp);
		for(int i=1;i<=m;i++)
			s[id[i]]=1;
		int tot=0;
		for(int i=1;i<=n;i++){
			a[i]+=n-i;
			if(s[i]==0)
				ans+=tot+a[i];
			else tot++;
		}
		printf("%lld\n",ans);
	}
	return 0;
}