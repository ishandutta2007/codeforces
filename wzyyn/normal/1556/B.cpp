#include<bits/stdc++.h>
#define ll long long
#define ull unsigned long long
using namespace std;

int n,a[100005];
long long Mat(int x,int y){
	long long re=0;
	int s[2]={0,0};
	for (int i=1;i<=n;i++){
		++s[(i&1)?x:y];
		--s[a[i]&1];
		re+=abs(s[0]);
	}
	return s[0]||s[1]?(1ll<<60):re;
}
void solve(){
	scanf("%d",&n);
	for (int i=1;i<=n;i++) scanf("%d",&a[i]);
	long long ans=min(Mat(0,1),Mat(1,0));
	if (ans==1ll<<60) ans=-1;
	printf("%lld\n",ans);
}
int main(){
	int T;
	scanf("%d",&T);
	while (T--) solve();
}