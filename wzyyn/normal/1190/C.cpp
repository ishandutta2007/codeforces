#include<bits/stdc++.h>
#define For(i,j,k) for (int i=(int)(j);i<=(int)(k);i++)
#define Rep(i,j,k) for (int i=(int)(j);i>=(int)(k);i--)
#define ll long long
#define uint unsigned
#define ull unsigned ll
#define ldb long double
#define pii pair<int,int>
#define fi first
#define se second
#define PB push_back
using namespace std;
const int N=100005;
char s[N];
int n,k,la[2];
int le[N],ri[N];
int q[N];
int main(){
	scanf("%d%d%s",&n,&k,s+1);
	For(i,1,n) s[i]-='0';
	la[0]=la[1]=1;
	For(i,1,n) la[s[i]^1]=i,le[i]=la[s[i]];
	la[0]=la[1]=n+1;
	Rep(i,n,1) la[s[i]^1]=i,ri[i]=la[s[i]];
	bool sec=1;
	For(op,0,1){
		int cnt=0,L=1,R=k,qL=1,qR=0;
		For(i,1,n) if (s[i]!=op) q[++cnt]=i;
		for (;R<=n;L++,R++){
			for (;qL<=cnt&&q[qL]<L;++qL);
			for (;qR<cnt&&q[qR+1]<=R;++qR);
			if (qL==1&&qR==cnt){
				puts("tokitsukaze");
				return 0;
			}
			int aL=q[qL==1?qR+1:1];
			int aR=q[qR==cnt?qL-1:cnt];
			int vL=(aL!=1?1:min(ri[aL],aR+1));
			int vR=(aR!=n?n:max(le[aR],aL-1));
			if (aR-aL+1>k&&vR-vL+1>k) sec=0;
		}
	}
	if (sec) puts("quailty");
	else puts("once again");
}