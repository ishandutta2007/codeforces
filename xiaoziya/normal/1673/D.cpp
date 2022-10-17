#include<bits/stdc++.h>
using namespace std;
const int maxn=500005,mod=1000000007;
int T,b,q,y,c,r,z,R,p0,ans;
map<int,int>C;
void solve(int x){
	if(x%p0==0)
		ans=(ans+1ll*(R/x)*(R/x))%mod;
}
int main(){
	scanf("%d",&T);
	while(T--){
		scanf("%d%d%d%d%d%d",&b,&q,&y,&c,&r,&z),p0=R=r,ans=0,C.clear();
		long long Bed=b+1ll*(y-1)*q,Ced=c+1ll*(z-1)*r;
		if((c-b)%q||c<b||Ced>Bed||r%q){
			puts("0");
			continue;
		}
		for(int i=2;i*i<=r;i++)
			if(r%i==0){
				int tot=0;
				while(r%i==0)
					r/=i,tot++;
				C[i]=tot;
			}
		if(r>1)
			C[r]=1;
		for(int i=2;i*i<=q;i++)
			if(q%i==0){
				int tot=0;
				while(q%i==0)
					q/=i,tot++;
				if(tot==C[i])
					for(int j=1;j<=C[i];j++)
						p0/=i;
			}
		if(q>1&&C[q]==1)
			p0/=q;
		if(c-R<b||Ced+R>Bed){
			puts("-1");
			continue;
		}
		for(int i=1;i*i<=R;i++)
			if(R%i==0){
				solve(i);
				if(i*i!=R)
					solve(R/i);
			}
		printf("%d\n",ans);
	}
	return 0;
}