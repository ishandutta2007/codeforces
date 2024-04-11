#include<cstdio>
#include<algorithm>
#define ll long long
#define N 100005

int n,m,d;

int a,b;
ll sa[N],sb[N];

ll ans;

int main(){
	scanf("%d%d%d",&n,&d,&m);
	for(int i=1;i<=n;i++){
		int v;
		scanf("%d",&v);
		if(v>m)
			sa[++a]=v;
		else
			sb[++b]=v;
	}
	std::sort(sa+1,sa+a+1);
	std::sort(sb+1,sb+b+1);
	for(int i=a;i;i--)
		sa[i]+=sa[i+1];
	for(int i=b;i;i--)
		sb[i]+=sb[i+1];
	for(int i=a;i>=0;i--)
		if(i+1ll*i*d>=a&&i+1ll*(i-1)*d<=n)
			ans=std::max(ans,sa[a-i+1]+sb[b-(n-std::max(a,i+(i-1)*d))+1]);
	printf("%I64d\n",ans);
}