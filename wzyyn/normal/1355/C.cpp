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
const int N=2000005;
int A,B,C,D,S[N];
ll ans;
int main(){
	scanf("%d%d%d%d",&A,&B,&C,&D);
	S[A+B]++; S[A+C+1]--; S[B+B+1]--; S[B+C+2]++;
	For(i,1,N-1) S[i]+=S[i-1];
	For(i,1,N-1) S[i]+=S[i-1];
	For(i,C+1,N-1) ans+=1ll*S[i]*(min(i,D+1)-C);
	printf("%lld\n",ans);
}