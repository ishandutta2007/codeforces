#include<bits/stdc++.h>
#define ll long long
#define N 200005

int T;

int n,a[N],b[N];

bool vis[N];

int main(){
	scanf("%d",&T);
	while(T--){
		scanf("%d",&n);
		for(int i=1;i<=n;i++)
			scanf("%d",&a[i]);
		for(int i=1;i<=n;i++)
			scanf("%d",&b[a[i]]);
		for(int i=1;i<=n;i++)
			vis[i]=0;
		int cnt=0;
		for(int i=1;i<=n;i++) if(!vis[i]){
			int tmp=0;
			for(int j=i;!vis[j];j=b[j])
				vis[j]=1,tmp++;
			cnt+=tmp/2;
		}
		ll res=0;
		while(cnt--)
			res+=n-1,n-=2;
		printf("%lld\n",res<<1);
	}
}