#include<bits/stdc++.h>
using namespace std;

const int N=300005;
int Q,a[N],c[N];
int fa[N][20];
int main(){
	scanf("%d%d%d",&Q,&a[1],&c[1]);
	for (int i=2;i<=Q+1;i++){
		int tp,x;
		scanf("%d%d",&tp,&x);
		++x;
		if (tp==1){
			scanf("%d%d",&a[i],&c[i]);
			fa[i][0]=x;
			for (int j=1;j<=18;j++)
				fa[i][j]=fa[fa[i][j-1]][j-1];
		}
		else{
			int w,a1=0;
			long long a2=0;
			scanf("%d",&w);
			for (;a[x]&&w;){
				int p=x;
				for (int i=18;i>=0;i--)
					if (fa[p][i]&&a[fa[p][i]])
						p=fa[p][i];
				int v=min(a[p],w);
				a1+=v; a2+=1ll*c[p]*v;
				a[p]-=v; w-=v;
			}
			printf("%d %lld\n",a1,a2);
		}
		fflush(stdout);
	}
}