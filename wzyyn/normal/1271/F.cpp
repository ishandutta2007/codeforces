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
const int N=10;
int l1[N],l2[N],d[N];
void solve(){
	For(i,1,3) scanf("%d",&l1[i]);
	For(i,1,3) scanf("%d",&l2[i]);
	For(i,1,7) scanf("%d",&d[i]);
	if (d[1]+d[2]+d[3]+d[4]>l1[1]+l2[1]) return puts("-1"),void(0);
	if (d[1]+d[2]+d[5]+d[6]>l1[2]+l2[2]) return puts("-1"),void(0);
	if (d[1]+d[3]+d[5]+d[7]>l1[3]+l2[3]) return puts("-1"),void(0);
	For(v2,0,d[2]) For(v3,0,d[3]){
		int r11=l1[1]-v2-v3,r21=l2[1]-(d[2]-v2)-(d[3]-v3);
		int r12=l1[2]-v2,r22=l2[2]-(d[2]-v2);
		int r13=l1[3]-v3,r23=l2[3]-(d[3]-v3);
		int v5,vv5=0,r5=d[5];
		v5=max(0,min(r5,min(r12-r11,r13-r11))); r12-=v5; r13-=v5; r5-=v5; vv5+=v5;
		v5=max(0,min(r5,min(r22-r21,r23-r21))); r22-=v5; r23-=v5; r5-=v5;
		v5=max(0,min(r5,min(r12,r13))); r12-=v5; r13-=v5; r5-=v5; vv5+=v5;
		v5=max(0,min(r5,min(r22,r23))); r22-=v5; r23-=v5; r5-=v5;
		if (r11<0||r12<0||r13<0||r21<0||r22<0||r23<0||r5) continue;
		int l1=min(r11,min(r12,r13)),l2=min(r21,min(r22,r23));
		if (l1+l2>=d[1]){
			int v1=min(d[1],l1);
			int v4=min(d[4],r11-v1);
			int v6=min(d[6],r12-v1);
			int v7=min(d[7],r13-v1);
			//v5=d[5]-v
			printf("%d %d %d %d %d %d %d\n",v1,v2,v3,v4,vv5,v6,v7);
			return;
		}
	}
	puts("-1");
}
int main(){
	int T;
	scanf("%d",&T);
	while (T--) solve();
}
/*
111
110
101
100
011
010
001
123
*/