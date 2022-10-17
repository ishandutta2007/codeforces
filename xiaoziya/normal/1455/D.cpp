#include<bits/stdc++.h>
using namespace std;
const int maxn=500005;
int n,X,T,ans;
int a[maxn],b[maxn];
map<int,int>mp;
int main(){
	scanf("%d",&T);
	while(T--){
		scanf("%d%d",&n,&X),ans=1e9,mp.clear(),mp[X]=1;
		for(int i=1;i<=n;i++)
			scanf("%d",&a[i]),mp[a[i]]=1;
		for(map<int,int>::iterator it=mp.begin();it!=mp.end();it++){
			int x=it->first,f=0,bs=0;
			for(int i=1;i<=n;i++){
				if(f==0&&a[i]==x){
					f=1;
					continue;
				}
				b[++bs]=a[i];
			}
			if(f==1)
				b[++bs]=X;
			else f=1;
			sort(b+1,b+1+bs);
			int tot=0;
			for(int i=1;i<=n;i++){
				if(a[i]<b[i]){
					f=0;
					break;
				}
				tot+=a[i]!=b[i];
			}
			if(f)
				ans=min(ans,tot);
		}
		if(ans==1e9)
			puts("-1");
		else printf("%d\n",ans);
	}
	return 0;
}