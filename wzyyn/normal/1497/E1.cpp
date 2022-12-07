#include<bits/stdc++.h>
#define For(i,j,k) for (int i=(int)(j);i<=(int)(k);i++)
#define Rep(i,j,k) for (int i=(int)(j);i>=(int)(k);i--)
#define double long double
using namespace std;

int f[10250000];
void init(){
	For(i,0,10000000) f[i]=i;
	For(i,2,3200)
		for (int j=i*i;j<=10000000;j+=i*i)
			for (;f[j]%(i*i)==0;f[j]/=i*i);
}
bool vi[10250000];
int q[200005],n,k;

void solve(){
	scanf("%d%d",&n,&k);
	int t=0,ans=1;
	For(i,1,n){
		int x;
		scanf("%d",&x);
		x=f[x];
		if (!vi[x]){
			q[++t]=x;
			vi[x]=1;
		}
		else{
			for (;t;--t) vi[q[t]]=0;
			q[++t]=x; vi[x]=1; ++ans;
		}
	}
	for (;t;--t) vi[q[t]]=0;
	cout<<ans<<endl;
}
int main(){
	init();
	int T;
	scanf("%d",&T);
	while (T--) solve();
}