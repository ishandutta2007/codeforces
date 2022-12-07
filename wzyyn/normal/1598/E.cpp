#include<bits/stdc++.h>

using namespace std;

const int N=1005;
int n,m,Q,v[N][N];
long long ans;
int F(int s){
	if (s>n+m) return 0;
	int l=max(1,s-n),r=min(m,s-1);
	int pr=0,sum=0;
	for (int i=r;i>=l;i--)
		if (v[s-i][i]){
			if (v[s-i-1][i]) ++pr;
			else pr=0;
			++pr; sum+=pr;
			if (v[s-i][i-1]) sum+=pr;
		}
		else pr=0;
	return sum;
}
int main(){
	scanf("%d%d%d",&n,&m,&Q);
	for (int i=1;i<=n;i++)
		for (int j=1;j<=m;j++)
			v[i][j]=1;
	for (int i=2;i<=n+m;i++)
		ans+=F(i);
	for (int i=1;i<=Q;i++){
		int x,y;
		scanf("%d%d",&x,&y);
		x=n-x+1;
		ans-=F(x+y);
		ans-=F(x+y+1);
		v[x][y]^=1;
		ans+=F(x+y);
		ans+=F(x+y+1);
		cout<<ans<<endl;
	}
}