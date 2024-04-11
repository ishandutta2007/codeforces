#include<bits/stdc++.h>
#define lf double
#define fr first
#define sc second
#define N 100005

int T;

int n,m;

int a[N];
lf b[N];
std::pair<lf,int> B[N];
std::vector<int> c[N];

int p[N],d[N],e[N],f[N];

int main(){
	scanf("%d",&T);
	while(T--){
		scanf("%d%d",&n,&m);
		for(int i=1;i<=n;i++)
			scanf("%d",&a[i]);
		for(int i=1;i<=m;i++){
			int k;
			scanf("%d",&k);
			c[i].resize(k),b[i]=0;
			for(int j=0;j<k;j++)
				scanf("%d",&c[i][j]),b[i]+=c[i][j];
			b[i]/=k,B[i]={-b[i],i};
		}
		std::sort(a+1,a+n+1,std::greater<int>()),std::sort(B+1,B+m+1);
		for(int i=1;i<=m;i++){
			d[i]=d[i-1]+(-B[i].fr>a[i+1]);
			e[i]=e[i-1]+(-B[i].fr>a[i]);
			f[i]=f[i-1]+(-B[i].fr>a[i-1]);
			p[B[i].sc]=i;
		}
		for(int i=1;i<=m;i++)
			for(auto x:c[i]){
				lf t=(b[i]*(lf)c[i].size()-x)/((lf)c[i].size()-1);
				int o=std::lower_bound(B+1,B+m+1,std::make_pair(-t,i))-B;
				if(o>p[i]){
					if(t>a[o-1]||e[p[i]-1]+f[o-1]-f[p[i]]+e[m]-e[o-1])
						putchar('0');
					else
						putchar('1');
				}
				else{
					if(t>a[o]||e[o-1]+d[p[i]-1]-d[o-1]+e[m]-e[p[i]])
						putchar('0');
					else
						putchar('1');
				}
			}
		puts("");
	}
}