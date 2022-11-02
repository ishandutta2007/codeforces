#include<bits/stdc++.h>
using namespace std;
#define pii pair<int,int>
#define fi first
#define se second
#define mp make_pair
const int N=100005;
set<pii> S;
int a[N],b[N],now[N],n;
int main(){
	for (int i=1;i<=6;i++)scanf("%d",&a[i]);
	scanf("%d",&n);
	for (int i=1;i<=n;i++)scanf("%d",&b[i]);
	sort(b+1,b+n+1);
	sort(a+1,a+6+1);
	for (int i=1;i<=n;i++)now[i]=1,S.insert(mp(-b[i]+a[1],i));
	int ans=1e9,Min=b[1]-a[1];
	while (1){
		ans=min(ans,-(*S.begin()).fi-Min);
		int id=(*S.begin()).se;
		if (now[id]==6)break;
		S.erase(mp(-b[id]+a[now[id]],id));
		now[id]++;
		Min=min(Min,b[id]-a[now[id]]);
		S.insert(mp(-b[id]+a[now[id]],id));
	}
	printf("%d\n",ans);
}