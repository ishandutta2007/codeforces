#include<cstdio>
#define N 25005

int n,q,a[N];

int l[N],r[N],pre[N][2],suf[N][2];

int ans;

int main(){
	scanf("%d%d",&n,&q);
	for(int i=1;i<=n;i++)
		scanf("%d",&a[i]);
	a[0]=n+1;
	for(int i=1;i<=n;i++){
		l[i]=i-1,r[i]=i+1;
		pre[i][1]=suf[i][1]=0;
		pre[i][0]=suf[i][0]=n+1;
	}
	while(q--){
		int L,R;
		scanf("%d%d",&L,&R);
		for(int i=L;i<=R;i++){
			while(l[i]>=L){
				int o=a[l[i]]>a[i];
				if((a[l[i]]>a[pre[i][o]])^o){
					ans+=(i==suf[l[i]][o^1])-(i==suf[pre[i][o]][o^1]);
					pre[i][o]=l[i];
				}
				l[i]--;
			}
			while(r[i]<=R){
				int o=a[r[i]]>a[i];
				if((a[r[i]]>a[suf[i][o]])^o){
					ans+=(i==pre[r[i]][o^1])-(i==pre[suf[i][o]][o^1]);
					suf[i][o]=r[i];
				}
				r[i]++;
			}
		}
		printf("%d\n",ans);
	}
}