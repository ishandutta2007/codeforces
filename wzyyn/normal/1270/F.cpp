#include<bits/stdc++.h>
#define ll long long
#define ull unsigned ll
#define uint unsigned
#define pii pair<int,int>
#define pll pair<ll,ll>
#define IT iterator
#define PB push_back
#define fi first
#define se second
#define For(i,j,k) for (int i=(int)(j);i<=(int)(k);i++)
#define Rep(i,j,k) for (int i=(int)(j);i>=(int)(k);i--)
#define CLR(a,v) memset(a,v,sizeof(a));
#define CPY(a,b) memcpy(a,b,sizeof(a));
#define debug puts("wzpakking")
#define y1 ysghysgsygsh
using namespace std;
const int N=200005;
int n,q[N];
char s[N];
ll S[N],ans;
int main(){
	scanf("%s",s+1);
	n=strlen(s+1);
	int B=min(n,100);
	For(i,0,B){
		For(j,1,n) S[j]=(S[j-1]+(s[j]=='1'?i:-1));
		sort(S,S+n+1);
		int la=1;
		//For(j,1,n) printf("%lld",S[j]); puts("");
		For(j,1,n){
			if (S[j]==S[j-1])
				ans+=la,la++;
			else la=1;
		}
	}
	q[++*q]=0;
	For(i,1,n)
		if (s[i]=='1')
			q[++*q]=i;
	q[++*q]=n+1;
	For(l,1,n/B){
		memset(S,0,sizeof(S));
		For(i,2,(*q)-l){
			int v=q[i+l-1]-q[i]+1;
			int vl=q[i]-q[i-1]-1,vr=q[i+l]-q[i+l-1]-1;
			//printf("%d %d %d %d\n",l,v,vl,vr);
			S[v]++; S[v+vl+1]--; S[v+vr+1]--; S[v+vl+vr+2]++;
		}
		//For(i,1,n) printf("%d ",S[i]); puts("");
		For(i,1,n) S[i]+=S[i-1];
		//For(i,1,n) printf("%d ",S[i]); puts("");
		For(i,1,n) S[i]+=S[i-1];
		//For(i,1,n) printf("%d ",S[i]); puts("");
		for (int i=l*(B+2);i<=n;i+=l) ans+=S[i];
		//printf("%lld")
	}
	printf("%lld\n",ans);
}