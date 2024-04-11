#include "bits/stdc++.h"

using namespace std;

typedef long long LL;

const int maxn=400007;

int cnt=1;

LL par_sum[20][maxn];
int par[20][maxn];
int w[maxn];

int main(){
	w[0]=0x7fffffff;
	int chr,cnt=1,last=0,Q;
	cin>>Q;
	for (int i=0;i<=20;++i){
		par_sum[i][1]=1e16;
	}
	while (Q--){
		LL p,q;
		scanf("%d%lld%lld",&chr,&p,&q);
		p^=last;
		q^=last;
		if (chr==1){
			w[++cnt]=q;
			if (w[p]>=q){
				par[0][cnt]=p;
			}
			else{
				int from=p;
				for (int i=19;i>-1;--i){
					if (w[par[i][from]]<q){
						from=par[i][from];
					}
				}
				par[0][cnt]=par[0][from];
			}
			par_sum[0][cnt]=((par[0][cnt])?w[par[0][cnt]]:1e16);
			for (int i=1;i<=19;++i){
				par[i][cnt]=par[i-1][par[i-1][cnt]];
				par_sum[i][cnt]=((par[i][cnt])?par_sum[i-1][cnt]+par_sum[i-1][par[i-1][cnt]]:1e16);
			}
		}
		else{
			int ans=1;
			if (w[p]>q){
				cout<<0<<endl;
				last=0;
			}
			else{
			    q-=w[p];
			    for (int i=19;i>-1;--i){
			    	if (par_sum[i][p]<=q){
			    		q-=par_sum[i][p];
			    		ans+=(1<<i);
			    		p=par[i][p]; 
			    	}
			    }
			    printf("%d\n",ans);
			    last=ans;
			}
		}
	}
	return 0;
}