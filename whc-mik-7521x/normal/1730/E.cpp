#include<bits/stdc++.h>
using namespace std;
const int N=1e6+10;
vector<int>pos[N],fac[N];
int t,n,a[N],ll[N],lg[N],rl[N],rg[N],stk[N],tp,cnt[N];
int main(){
	for(int i=1;i<=1e6;i++){
		for(int o=i;o<=1e6;o+=i)fac[o].push_back(i);
	}
	scanf("%d",&t);
	while(t--){
		memset(cnt,0,sizeof cnt);
		for(int i=1;i<N;i++)pos[i].clear();
		scanf("%d",&n);
		for(int i=0;i<n;i++)scanf("%d",&a[i]),pos[a[i]].push_back(i);
		stk[tp=0]=-1;
		for(int i=0;i<n;i++){
			while(tp&&a[stk[tp]]>=a[i])tp--;
			ll[i]=stk[tp];
			stk[++tp]=i;
		}
		tp=0;
		for(int i=0;i<n;i++){
			while(tp&&a[stk[tp]]<a[i])tp--;
			lg[i]=stk[tp];
			stk[++tp]=i;
		}
		stk[tp=0]=n;
		for(int i=n-1;i>=0;i--){
			while(tp&&a[stk[tp]]>=a[i])tp--;
			rl[i]=stk[tp];
			stk[++tp]=i;
		}
		tp=0;
		for(int i=n-1;i>=0;i--){
			while(tp&&a[stk[tp]]<=a[i])tp--;
			rg[i]=stk[tp];
			stk[++tp]=i;
		}
		long long ans=0;
		for(int i=0;i<n;i++){
			for(int x:fac[a[i]]){
				if(cnt[x]>=1){
					int o=pos[x][cnt[x]-1];
					if(o>lg[i]&&rl[o]>i){
						ans+=(o-max(lg[i],ll[o]))*1ll*(min(rg[i],rl[o])-i);
					}
				}
				if(cnt[x]<(int)pos[x].size()){
					int o=pos[x][cnt[x]];
					if(o<rg[i]&&ll[o]<i){
						ans+=(i-max(lg[i],max(ll[o],(cnt[x]>=1?pos[x][cnt[x]-1]:-1))))*1ll*(min(rg[i],rl[o])-o);
					}
				}
			}
			cnt[a[i]]++;
		}
		printf("%lld\n",ans);
	}
	return 0;
}