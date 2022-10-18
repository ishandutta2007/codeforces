#include<cstdio>
#include<cstring>
#include<algorithm>
#define N 1000005
#define K 20

int n,m,k;
char s[K+10];
int x[N],y[N];

int p[K],q[K];

int a[N],b[N];

int f[1<<K],g[1<<K],cnt[1<<K];

int ans;

int main(){
	scanf("%d%d%d",&n,&m,&k);
	scanf("%s",s);
	for(int i=0;i<k;i++)
		a[n+1]|=(s[i]-'0')<<i;
	scanf("%s",s);
	for(int i=0;i<k;i++)
		b[n+1]|=(s[i]-'0')<<i;
	for(int i=0;i<k;i++)
		q[i]=p[i]=i;
	memset(f,0x3f,sizeof(f));
	memset(g,~0x3f,sizeof(g));
	for(int i=1;i<=n;i++)
		scanf("%d%d",&x[i],&y[i]);
	f[a[n+1]]=g[b[n+1]]=n+1;
	for(int i=n;i;i--){
		x[i]--,y[i]--;
		std::swap(p[x[i]],p[y[i]]);
		q[p[x[i]]]=x[i],q[p[y[i]]]=y[i];
		for(int j=0;j<k;j++){
			a[i]|=((a[n+1]>>q[j])&1)<<j;
			b[i]|=((b[n+1]>>q[j])&1)<<j;
		}
		f[a[i]]=std::min(f[a[i]],i);
		g[b[i]]=std::max(g[b[i]],i);
	}
	for(int l=(1<<k)-1;l>=0;l--)
		for(int i=0;i<k;i++)
			if(!((l>>i)&1)){
				f[l]=std::min(f[l],f[l|(1<<i)]);
				g[l]=std::max(g[l],g[l|(1<<i)]);
			}
	for(int l=0;l<(1<<k);l++){
		cnt[l]=cnt[l>>1]+(l&1);
		if(g[l]-f[l]>=m&&cnt[l]>cnt[ans])
			ans=l;
	}
	printf("%d\n%d %d\n",2*cnt[ans]-cnt[a[n+1]]-cnt[b[n+1]]+k,f[ans],g[ans]-1);
}