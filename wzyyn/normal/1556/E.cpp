#include<bits/stdc++.h>
#define ll long long
#define ull unsigned long long
using namespace std;

const int N=100005;
int n,Q,a[N],b[N],lg[N];
ll s[N],mx[N][18],mn[N][18];
ll Qmn(int x,int y){
	int k=lg[y-x+1];
	return min(mn[x][k],mn[y-(1<<k)+1][k]);
}
ll Qmx(int x,int y){
	int k=lg[y-x+1];
	return max(mx[x][k],mx[y-(1<<k)+1][k]);
}
int main(){
	scanf("%d%d",&n,&Q);
	for (int i=1;i<=n;i++)
		scanf("%d",&a[i]);
	for (int i=1;i<=n;i++)
		scanf("%d",&b[i]);
	for (int i=1;i<=n;i++){
		s[i]=s[i-1]-a[i]+b[i];
		mn[i][0]=mx[i][0]=s[i];
	}
	for (int i=2;i<=n;i++)
		lg[i]=lg[i/2]+1;
	for (int i=1;i<=16;i++)
		for (int j=1;j+(1<<i)-1<=n;j++){
			mn[j][i]=min(mn[j][i-1],mn[j+(1<<(i-1))][i-1]);
			mx[j][i]=max(mx[j][i-1],mx[j+(1<<(i-1))][i-1]);
		}
	while (Q--){
		int l,r;
		scanf("%d%d",&l,&r);
		if (s[l-1]!=s[r]) puts("-1");
		else{
			ll v1=Qmn(l,r),v2=Qmx(l,r);
			//cout<<v1<<' '<<v2<<endl;
			if (v1!=s[r]) puts("-1");
			else printf("%lld\n",v2-s[r]);
		}
	}
}