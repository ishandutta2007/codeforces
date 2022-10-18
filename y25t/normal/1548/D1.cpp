#include<bits/stdc++.h>
#define ll long long

int n;

int cnt[4];

ll ans;

int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		int x,y;
		scanf("%d%d",&x,&y);
		(x>>=1)&=1;
		(y>>=1)&=1;
		cnt[x<<1|y]++;
	}
	for(int i=0;i<4;i++)
		ans+=1ll*cnt[i]*(cnt[i]-1)/2*(n-cnt[i])+1ll*cnt[i]*(cnt[i]-1)*(cnt[i]-2)/6;
	printf("%lld\n",ans);
}