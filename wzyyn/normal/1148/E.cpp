#include<bits/stdc++.h>
#define ll long long
#define uint unsigned
#define ull unsigned ll
#define pii pair<int,int>
#define pll pair<ll,ll>
#define PB push_back
#define fi first
#define se second
#define For(i,j,k) for (int i=(int)(j);i<=(int)(k);i++)
#define Rep(i,j,k) for (int i=(int)(j);i>=(int)(k);i--)
#define CLR(a,v) memset(a,v,sizeof(a))
#define CPY(a,b) memcpy(a,b,sizeof(a))
using namespace std;

const int N=300005;
int n,tot;
pii s[N];
int t[N];
struct node{
	int x,y,v;
}ans[N*5];
int q1[N],q2[N];
int main(){
	scanf("%d",&n);
	For(i,1,n) scanf("%d",&s[i].fi),s[i].se=i;
	For(i,1,n) scanf("%d",&t[i]);
	sort(s+1,s+n+1);
	sort(t+1,t+n+1);
	For(i,1,n)
		if (s[i].fi!=t[i])
			if (s[i].fi<t[i])
				q1[++*q1]=i;
			else q2[++*q2]=i;
	for (;(*q1)&&(*q2);){
		int p1=q1[*q1],p2=q2[*q2];
		if (p1>p2) return puts("NO"),0;
		int v=min(t[p1]-s[p1].fi,s[p2].fi-t[p2]);
		ans[++tot]=(node){s[p1].se,s[p2].se,v};
		s[p1].fi+=v; s[p2].fi-=v;
		for (;s[q1[*q1]].fi==t[q1[*q1]]&&(*q1);--(*q1));
		for (;s[q2[*q2]].fi==t[q2[*q2]]&&(*q2);--(*q2));
	}
	if ((*q1)||(*q2)) return puts("NO"),0;
	puts("YES");
	printf("%d\n",tot);
	For(i,1,tot)
		printf("%d %d %d\n",ans[i].x,ans[i].y,ans[i].v);
}
/*
4
1 10 11 20
3 8 15 16
*/