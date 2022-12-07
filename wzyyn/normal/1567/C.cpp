#include<bits/stdc++.h>
#define ll long long
#define ull unsigned ll
using namespace std;
int a[20],b[20],n;
long long ans;

void dfs(int x){
	if (x<=2){
		long long sum=1;
		for (int i=1;i<=*a;i++)
			if (b[i]==-233) sum*=a[i]+1;
			else if (b[i]>=0&&b[i]<=9) sum*=b[i]+1; 
			else if (b[i]>=10&&b[i]<=18) sum*=19-b[i];
			else sum=0;
		ans+=sum;
		return;
	}
	b[x-2]=a[x-2];    dfs(x-1); b[x-2]=-233; 
	b[x-2]=a[x-2]+10; b[x]--; dfs(x-1); b[x-2]=-233; b[x]++;
}
void solve(){
	scanf("%d",&n);
	*a=0;
	for (;n;a[++*a]=n%10,n/=10);
	for (int i=1;i<=*a;i++) b[i]=-233;
	ans=0;
	b[*a]=a[*a];
	b[(*a)-1]=a[(*a)-1];
	dfs(*a);
	cout<<ans-2<<endl;
}
int main(){
	int T;
	scanf("%d",&T);
	while (T--) solve();
}