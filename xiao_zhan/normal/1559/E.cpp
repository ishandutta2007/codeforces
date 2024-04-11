#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define M 998244353

int i,j,k,n,m,t,l[55],r[55],cnt;
int g[100500],f[100500][55],pre[100500][55];
int su(int a,int b){
	a+=b;return (a>=M)?a-M:a;
}

void get(int x){
	//memset(f,0,sizeof(f));
	//memset(pre,0,sizeof(pre));
	int i,j,k,res=0,l1,r1;
	for(i=x;i<=m;i+=x){
		memset(f[i],0,sizeof(f[i]));
		memset(pre[i],0,sizeof(pre[i]));
	}
	for(i=1;i<=n;i++){
		r1=(r[i]/x)*x;
		l1=((l[i]+x-1)/x)*x;
		if(l1>r1){
			return;
		}
		if(i==1){
			for(j=l1;j<=r1;j+=x){
				f[j][i]=1;
			}
		}
		else{
			for(j=x;j<=m;j+=x){
				cnt++;
				if(j<=l1){continue;}
				if(j<=r1+x){
					f[j][i]=pre[j-l1][i-1];
				}
				else{
					f[j][i]=su(pre[j-l1][i-1],M-pre[j-r1-x][i-1]);
				}
			}
		}
		for(j=x;j<=m;j+=x){
			pre[j][i]=su(pre[j-x][i],f[j][i]);
		}
	}
	for(i=x;i<=m;i+=x){
		res=su(res,f[i][n]);
	}
	//cout<<res<<endl;
	g[x]=res;
}

int main(){
	scanf("%d%d",&n,&m);
	for(i=1;i<=n;i++){
		scanf("%d%d",&l[i],&r[i]);
	}
	for(i=1;i<=m;i++){
		get(i);
	}
	for(i=m;i>=1;i--){
		for(j=i+i;j<=m;j+=i){
			g[i]=su(g[i],M-g[j]);
		}
	}
	printf("%d",g[1]);
}