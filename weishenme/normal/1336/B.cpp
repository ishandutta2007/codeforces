#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll ans;
int T,a[3][100005];
ll sqr(int x){
	return (ll)x*x;
}
void solve(int A,int B,int C){
	for (int i=1,j=1,k=1;i<=a[A][0];i++){
		while (k<=a[C][0]&&a[A][i]>a[C][k])k++;
		while (j<=a[B][0]&&a[A][i]+a[C][k]>a[B][j]*2)j++;
		if (j<=a[B][0]&&k<=a[C][0])ans=min(ans,sqr(a[A][i]-a[B][j])+sqr(a[B][j]-a[C][k])+sqr(a[C][k]-a[A][i]));
		if (j>1&&k<=a[C][0])ans=min(ans,sqr(a[A][i]-a[B][j-1])+sqr(a[B][j-1]-a[C][k])+sqr(a[C][k]-a[A][i]));
	}
}
int main(){
	scanf("%d",&T);
	while (T--){
		scanf("%d%d%d",&a[0][0],&a[1][0],&a[2][0]);
		for (int i=0;i<=2;i++)
			for (int j=1;j<=a[i][0];j++)scanf("%d",&a[i][j]);
		for (int i=0;i<=2;i++)sort(a[i]+1,a[i]+a[i][0]+1);
		ans=6e18;
		solve(0,1,2);solve(0,2,1);solve(1,0,2);solve(1,2,0);solve(2,0,1);solve(2,1,0);
		printf("%lld\n",ans);
	}
}