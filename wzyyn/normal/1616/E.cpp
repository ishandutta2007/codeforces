#include<bits/stdc++.h>

using namespace std;

const int N=100005;
int n,a[N];
char s[N],t[N];
int nx[N][26],p[26];
void change(int x){
	for (;x<=n;x+=x&(-x)) ++a[x];
}
int ask(int x){
	int s=0;
	for (;x;x-=x&(-x)) s+=a[x];
	return s;
}
void solve(){
	scanf("%d%s%s",&n,s+1,t+1);
	long long ans=1ll<<50;
	for (int i=0;i<=25;i++) nx[n+1][i]=n+1;
	for (int i=n;i>=1;i--){
		for (int j=0;j<=25;j++)
			nx[i][j]=nx[i+1][j];
		nx[i][s[i]-'a']=i;
	}
	for (int i=0;i<=25;i++) p[i]=nx[1][i];
	for (int i=1;i<=n;i++) a[i]=0;
	long long sum=0;
	for (int i=1;i<=n;i++){
		int loc=1<<30;
		for (int j=0;j<t[i]-'a';j++)
			loc=min(loc,p[j]);
		if (loc<=n){
			int d=loc-ask(loc)-1;
			ans=min(ans,sum+d);
		}
		int c=t[i]-'a';
		if (p[c]==n+1) break;
		sum+=p[c]-ask(p[c])-1;
		//cout<<p[c]<<' '<<c<<' '<<sum<<endl;
		change(p[c]);
		p[c]=nx[p[c]+1][c];
	}
	if (ans==(1ll<<50)) ans=-1;
	printf("%lld\n",ans);
}
int main(){
	int T;
	scanf("%d",&T);
	while (T--) solve();
}