#include<bits/stdc++.h>
using namespace std;
int n,m,cnt,cnt2,f[109][60009];
struct pp{int a,b;}pos[109],neg[109];
bool cmp(pp x,pp y){return x.a<y.a;}
bool cmp2(pp x,pp y){return (x.a+x.b)>(y.a+y.b);}
int main(){
	cnt=cnt2=0;
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++){
		int u,v;scanf("%d%d",&u,&v);
		if(v>=0) pos[++cnt].a=u,pos[cnt].b=v;
		else neg[++cnt2].a=u,neg[cnt2].b=v;
	}
	sort(pos+1,pos+cnt+1,cmp);
	int ans=0;
	for(int i=1;i<=cnt;i++)
		if(m>=pos[i].a) ans++,m+=pos[i].b;
	sort(neg+1,neg+cnt2+1,cmp2);
	memset(f,-1,sizeof(f));
	f[0][m]=ans;int sum=ans;
	for(int i=1;i<=cnt2;i++){
		for(int j=-neg[i].b;j<=m;j++){
			if(f[i-1][j]!=-1){
				if(j>=neg[i].a){
					f[i][j+neg[i].b]=max(f[i][j+neg[i].b],f[i-1][j]+1);	
				}
				f[i][j]=max(f[i][j],f[i-1][j]);
				sum=max(sum,max(f[i][j+neg[i].b],f[i][j]));
			}
		}
	}
	printf("%d\n",sum);
	return 0;
}