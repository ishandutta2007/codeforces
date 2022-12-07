#include<bits/stdc++.h>

using namespace std;

const int N=100005;
int n,a[2][2],b[2][2];
char s[N],t[N];
void solve(){
	scanf("%d",&n);
	scanf("%s",s+1);
	scanf("%s",t+1);
	a[0][0]=a[0][1]=a[1][0]=a[1][1]=0;
	for (int i=1;i<=n;i++)
		++a[s[i]&1][t[i]&1];
	int ans=(a[0][1]==a[1][0]?2*a[0][1]:1<<30);
	if (a[1][0]){
		b[0][0]=a[1][0]-1; b[0][1]=a[1][1];
		b[1][0]=a[0][0]+1; b[1][1]=a[0][1];
		if (b[0][1]==b[1][0]) ans=min(ans,2*b[0][1]+1);
	}
	if (a[1][1]){
		b[0][0]=a[1][0]; b[0][1]=a[1][1]-1;
		b[1][0]=a[0][0]; b[1][1]=a[0][1]+1;
		if (b[0][1]==b[1][0]) ans=min(ans,2*b[0][1]+1);
	}
	if (ans==1<<30) ans=-1;
	cout<<ans<<endl;
}
int main(){
	int T;
	scanf("%d",&T);
	while (T--) solve();
}