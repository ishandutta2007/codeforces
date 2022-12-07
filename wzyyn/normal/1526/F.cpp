#include<bits/stdc++.h>
using namespace std;

const int N=100005;
int p[N],d[N],ans[N];
int n;
int Query(int x,int y,int z){
	assert(x!=y&&x!=z&&y!=z);
	#ifdef zyy
		int v1=abs(p[x]-p[y]);
		int v2=abs(p[x]-p[z]);
		int v3=abs(p[y]-p[z]);
		if (v1>v2) swap(v1,v2);
		if (v1>v3) swap(v1,v3);
		if (v2>v3) swap(v2,v3);
		return v2;
	#endif
	cout<<"? "<<x<<' '<<y<<' '<<z<<endl;
	fflush(stdout);
	cin>>x;
	assert(x!=-1);
	return x;
}
void solve(){
	scanf("%d",&n);
	#ifdef zyy
		for (int i=1;i<=n;i++) p[i]=i;
		random_shuffle(p+1,p+n+1);
		if (p[1]>p[2])
			for (int i=1;i<=n;i++)
				p[i]=n-p[i]+1;
	#endif
	int p1,p2;
	for (int i=1;i<=13;i++)
		for (int j=i+1;j<=13;j++)
			for (int k=j+1;k<=13;k++)
				if (Query(i,j,k)<=(n-4)/6){
					p1=i,p2=j;
					break;
				}
	int mx=0;
	d[p1]=d[p2]=0;
	for (int i=1;i<=n;i++)
		if (i!=p1&&i!=p2){
			d[i]=Query(p1,p2,i);
			mx=max(mx,d[i]);
		}
	int pp1=-1,pp2=-1;
	for (int i=1;i<=n;i++)
		if (d[i]==mx) pp1=i;
	for (int i=1;i<=n;i++)
		if (d[i]==mx-1){
			if (Query(p1,pp1,i)==mx-1) pp2=i;
			if (Query(p2,pp1,i)==mx-1) pp2=i;
		}
	ans[pp1]=1; ans[pp2]=2;
	for (int i=1;i<=n;i++)
		if (i!=pp1&&i!=pp2)
			ans[i]=Query(pp1,pp2,i)+2;
	if (ans[1]>ans[2])
		for (int i=1;i<=n;i++)
			ans[i]=n-ans[i]+1;
	printf("!");
	for (int i=1;i<=n;i++)
		printf(" %d",ans[i]);
	puts("");
	fflush(stdout);
	#ifdef zyy
		for (int i=1;i<=n;i++){
			printf(" %d",p[i]);
			assert(ans[i]==p[i]);
		}
		return;
	#endif
	scanf("%d",&n);
	assert(n==1);
}
int main(){
	int T;
	scanf("%d",&T);
	while (T--) solve();
}
/*
if I know a+b 
*/