#include<stdio.h>
#include<map>
#include<algorithm>
using namespace std;
const int maxn=200005;
int n1,n2,n3,n4,m1,m2,m3,ans=1e9;
int a[maxn],b[maxn],c[maxn],d[maxn],u[maxn],v[maxn],id1[maxn],id2[maxn],id3[maxn],id4[maxn];
map<int,int>g1[maxn],g2[maxn],g3[maxn];
inline int cmp1(int x,int y){
	return a[x]<a[y];
}
inline int cmp4(int x,int y){
	return d[x]<d[y];
}
inline int cmp3(int x,int y){
	return v[x]<v[y];
}
int main(){
	scanf("%d%d%d%d",&n1,&n2,&n3,&n4);
	for(int i=1;i<=n1;i++)
		scanf("%d",&a[i]),id1[i]=i;
	for(int i=1;i<=n2;i++)
		scanf("%d",&b[i]),id2[i]=i;
	for(int i=1;i<=n3;i++)
		scanf("%d",&c[i]),id3[i]=i;
	for(int i=1;i<=n4;i++)
		scanf("%d",&d[i]),id4[i]=i;
	scanf("%d",&m1);
	for(int i=1,x,y;i<=m1;i++)
		scanf("%d%d",&x,&y),g1[x][y]=1;
	scanf("%d",&m2);
	for(int i=1,x,y;i<=m2;i++)
		scanf("%d%d",&x,&y),g2[x][y]=1;
	scanf("%d",&m3);
	for(int i=1,x,y;i<=m3;i++)
		scanf("%d%d",&x,&y),g3[x][y]=1;
	sort(id1+1,id1+1+n1,cmp1);
	for(int i=1;i<=n2;i++){
		int j=1;
		u[i]=1e9;
		while(j<=n1){
			if(g1[id1[j]].count(i))
				j++;
			else{
				u[i]=a[id1[j]]+b[i];
				break;
			}
		}
	}
	sort(id4+1,id4+1+n4,cmp4);
	for(int i=1;i<=n3;i++){
		int j=1;
		v[i]=1e9;
		while(j<=n4){
			if(g3[i].count(id4[j]))
				j++;
			else{
				v[i]=c[i]+d[id4[j]];
				break;
			}
		}
	}
	sort(id3+1,id3+1+n3,cmp3);
	for(int i=1;i<=n2;i++){
		int j=1;
		while(j<=n3){
			if(g2[i].count(id3[j]))
				j++;
			else{
				ans=min(ans,u[i]+v[id3[j]]);
				break;
			}
		}
	}
	if(ans==1e9)
		puts("-1");
	else printf("%d\n",ans);
	return 0;
}