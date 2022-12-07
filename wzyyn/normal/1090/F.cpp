#include<bits/stdc++.h>
#define ll long long
#define ull unsigned ll
#define uint unsigned
#define pii pair<int,int>
#define pll pair<ll,ll>
#define IT iterator
#define PB push_back
#define fi first
#define se second
#define For(i,j,k) for (int i=(int)(j);i<=(int)(k);i++)
#define Rep(i,j,k) for (int i=(int)(j);i>=(int)(k);i--)
#define CLR(a,v) memset(a,v,sizeof(a));
#define CPY(a,b) memcpy(a,b,sizeof(a));
#define debug puts("wzpakking")
#define y1 ysghysgsygsh
using namespace std;
struct node{
	int x,y,z,v;
	bool operator <(const node &a)const{
		return v<a.v;
	} 
}a[12];
int n,p[105],ans[1005];
void solve(int l){
	int r=l+4,top=0;
	For(i,l,r) For(j,i+1,r) For(k,j+1,r){
		printf("? %d %d %d\n",i,j,k);
		fflush(stdout);
		//a[++top].v=max(p[i],max(p[j],p[k]))+min(p[i],min(p[j],p[k]));
		scanf("%d",&a[++top].v);
		a[top].x=i;
		a[top].y=j;
		a[top].z=k;
	}
	sort(a+1,a+top+1);
	int v13=a[1].v,v35=a[10].v;
	int v14=a[2].v,v25=a[9].v;
	int v15=(1ll*a[4].v+a[5].v+a[6].v+a[7].v-v14-v25)/2;
	int v135=(1ll*v13+v15+v35)/2;
	ans[l]=v135-v35;
	ans[l+2]=v135-v15;
	ans[l+4]=v135-v13;
	ans[l+1]=v25-ans[l+4];
	ans[l+3]=v14-ans[l];
	sort(ans+l,ans+r+1);
	//For(i,l,r) printf("%d ",ans[i]); puts("");
	//For(i,l,r) printf("%d ",p[i]); puts("");
	for (;;){
		bool flag=0;
		For(i,1,10){
			int v=min(min(ans[a[i].x],ans[a[i].y]),ans[a[i].z])+
				  max(max(ans[a[i].x],ans[a[i].y]),ans[a[i].z]);
			if (v!=a[i].v) flag=1;
		}
		if (!flag) break;
		next_permutation(ans+l,ans+r+1);
		//For(i,l,r) printf("%d ",ans[i]); puts("");
	}
}
int main(){
	scanf("%d",&n);
	for (int i=1;i+4<=n;i+=5) solve(i);
	solve(n-4); 
	printf("!");
	For(i,1,n) printf(" %d",ans[i]);
}
/*
1+3
1+4 1+4
1+5 1+5 1+5
2+4
2+5 2+5
3+5 
*/