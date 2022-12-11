#include<bits/stdc++.h>
using namespace std;
int t,cnt[200005],ans[200005],draw[200005],star[200005],re[200005];
int main(){
	scanf("%d\n",&t);
	while(t--){
		memset(cnt,0,sizeof cnt);
		memset(ans,0,sizeof ans);
		memset(star,0,sizeof star);
		memset(draw,0,sizeof draw);
		memset(re,0,sizeof re);
		int n,k,x[200005],tot=0;
		scanf("%d%d",&n,&k);
		for(int i=1;i<=n;i++)scanf("%d",&x[i]),cnt[x[i]]++;
		for(int i=1;i<=n;i++){
			if(cnt[x[i]]>=k){
				draw[x[i]]++;
				if(draw[x[i]]<=k)ans[i]=draw[x[i]];
			}
			else{
				if(star[x[i]])re[++star[x[i]]]=i;
				else{
					star[x[i]]=tot;
					tot+=cnt[x[i]];
					re[++star[x[i]]]=i;
				}
			}
		}
		int tim=tot/k;
		tim=tim*k;
		for(int i=1;i<=tim;i++){
			ans[re[i]]=(i-1)%k+1;
		}
		for(int i=1;i<=n;i++)printf("%d ",ans[i]);
		puts("");
	} 
	return 0;
}