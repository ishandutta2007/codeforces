#include<cstdio>
#define ll long long
#define N 100005
#define M 200005

int n;

int prm[M],_prm,vis[M];
inline void sieve(int x){
	for(int i=2;i<=x;i++){
		if(!vis[i]){
			prm[++_prm]=i;
			vis[i]=i;
		}
		for(int j=1;j<=_prm&&i*prm[j]<=x;j++){
			vis[i*prm[j]]=prm[j];
			if(!(i%prm[j]))
				break;
		}
	}
}

int mn[2][M],num[M];

ll ans=1;

int main(){
	sieve(M-5);
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		int a;
		scanf("%d",&a);
		int tmp,cnt=0;
		while(a!=1){
			tmp=vis[a];
			cnt++;
			a/=vis[a];
			if(vis[a]!=tmp){
				if(cnt<mn[0][tmp]||!mn[0][tmp]){
					mn[1][tmp]=mn[0][tmp];
					mn[0][tmp]=cnt;
				}
				else if(cnt<mn[1][tmp]||!mn[1][tmp])
					mn[1][tmp]=cnt;
				num[tmp]++;
				cnt=0;
			}
		}
	}
	for(int i=1;i<=_prm;i++){
		int tmp=(num[prm[i]]<=n-2)?0:mn[num[prm[i]]-n+1][prm[i]];
		while(tmp--)
			ans=1ll*ans*prm[i];
	}
	printf("%I64d",ans);
}