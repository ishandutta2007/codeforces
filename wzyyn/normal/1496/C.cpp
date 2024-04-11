#include<bits/stdc++.h>
#define For(i,j,k) for (int i=(int)(j);i<=(int)(k);i++)
#define Rep(i,j,k) for (int i=(int)(j);i>=(int)(k);i--)
using namespace std;

int n,q1[200005],q2[200005];
void solve(){
	scanf("%d",&n);
	*q1=*q2=0;
	For(i,1,2*n){
		int x,y;
		scanf("%d%d",&x,&y);
		if (!x) q1[++*q1]=abs(y);
		else q2[++*q2]=abs(x); 
	}
	sort(q1+1,q1+*q1+1);
	sort(q2+1,q2+*q2+1);
	double ans=0;
	For(i,1,n) ans+=sqrt(1ll*q1[i]*q1[i]+1ll*q2[i]*q2[i]);
	printf("%.10lf\n",ans);
} 
int main(){
	int T;
	scanf("%d",&T);
	while (T--) solve();
}