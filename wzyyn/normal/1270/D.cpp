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
int n,k,m,type=0,a[505];
void init(){
	For(i,1,n) a[i]=i;
	random_shuffle(a+1,a+n+1);
	m=rand()%k+1;
	printf("%d\n",m);
	For(i,1,n) printf("%d ",a[i]); puts("");
}
pii Query(int *b){
	if (type==0){
		printf("? ");
		For(i,1,k) printf("%d ",b[i]);
		puts("");
		fflush(stdout);
		int x,y;
		scanf("%d%d",&x,&y);
		return pii(x,y);
	}
	else{
		static int c[105];
		For(i,1,k) c[i]=b[i];
		For(i,1,k) For(j,i+1,k)
			if (a[c[i]]>a[c[j]])
				swap(c[i],c[j]);
		return pii(c[m],a[c[m]]);
	}
}
int b[505],c[505],vis[505];
int main(){
	scanf("%d%d",&n,&k);
	if (type==1) init();
	For(i,1,k) b[i]=i;
	pii tmp=Query(b);
	For(i,k+1,n){
		int pos=0;
		//printf("%d\n",tmp.fi);
		For(j,1,k) if (b[j]==tmp.fi) pos=j;
		b[pos]=i;
		pii tmpp=Query(b);
		if (tmpp.se>tmp.se) b[pos]=tmp.fi;
		else tmp=tmpp;
	}
	int sum=0,poss=0,ans=1;
	//For(j,1,k) printf("%d ",b[j]); puts("");
	//printf("%d %d\n",tmp.fi,tmp.se);
	For(j,1,k) vis[b[j]]=1;
	For(j,1,n) if (!vis[j]) poss=j;
	For(j,1,k) if (b[j]!=tmp.fi){
		int val=b[j]; b[j]=poss;
		if (Query(b).se!=tmp.se) ++ans;
		b[j]=val;
	}
	printf("! %d\n",ans);
	return 0;
}