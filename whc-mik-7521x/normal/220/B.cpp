#include<bits/stdc++.h>
using namespace std;
int n,m,a[100005],sum[100005],b[100005],to[100005],from[100005],cnt[100005][500];
int main(){
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
		if(a[i]>n)a[i]=0;
		sum[a[i]]++;
	}
	for(int i=1;i<=n;i++){
		if(a[i]>sum[a[i]])a[i]=0;
	}
	int con=0;
	for(int i=1;i<=n;i++){
		if(!a[i])continue;
		if(!to[a[i]]){
			to[a[i]]=++con;
			from[con]=a[i];
		}
	}
	for(int i=1;i<=n;i++){
		for(int o=1;o<=con;o++){
			cnt[i][o]=cnt[i-1][o];
		}
		if(a[i]==0)continue;
		cnt[i][to[a[i]]]++;
	}
	while(m--){
		int l,r;
		scanf("%d%d",&l,&r);
		int ans=0;
		for(int o=1;o<=con;o++){
			int s=cnt[r][o]-cnt[l-1][o];
			if(s==from[o])ans++;
		}
		printf("%d\n",ans);
	}
	return 0;
}