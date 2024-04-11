#include<bits/stdc++.h>
#define ll long long
#define N 200005

int T;

int n,fa[N],l[N],r[N];

ll f[N];

int main(){
	scanf("%d",&T);
	while(T--){
		scanf("%d",&n);
		for(int i=2;i<=n;i++)
			scanf("%d",&fa[i]);
		for(int i=1;i<=n;i++)
			scanf("%d%d",&l[i],&r[i]);
		for(int i=1;i<=n;i++)
			f[i]=0;
		int res=0;
		for(int i=n;i;i--){
			if(l[i]<=f[i])
				f[fa[i]]+=std::min(1ll*r[i],f[i]);
			else
				res++,f[fa[i]]+=r[i];
		}
		printf("%d\n",res);
	}
}