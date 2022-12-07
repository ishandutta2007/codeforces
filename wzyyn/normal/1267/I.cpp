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
int n,q1[505],q2[505];
bool cmp(int x,int y){
	if (x==2*n+1||y==2*n+1) return 0;
	printf("? %d %d\n",x,y);
	fflush(stdout);
	char s[10];
	scanf("%s",s+1);
	return s[1]=='<';
}
void solve(){
	scanf("%d",&n);
	int v1=(n+1)/2,v2=n+1-v1;
	*q1=0; *q2=0;
	For(i,1,v1) q1[++*q1]=i;
	For(i,1,v2) q2[++*q2]=i+v1;
	For(i,1,v1) For(j,i+1,v1)
		if (cmp(q1[j],q1[i])) swap(q1[i],q1[j]);
	For(i,1,v2) For(j,i+1,v2)
		if (cmp(q2[j],q2[i])) swap(q2[i],q2[j]);
	For(i,n+2,2*n+1)
		if (cmp(q1[1],q2[1])){
			q1[1]=i;
			For(j,1,v1-1)
				if (cmp(q1[j+1],q1[j]))
					swap(q1[j+1],q1[j]);
				else break;
		}
		else{
			q2[1]=i;
			For(j,1,v2-1)
				if (cmp(q2[j+1],q2[j]))
					swap(q2[j+1],q2[j]);
				else break;
		}
	puts("!");
	fflush(stdout);
}
int main(){
	int T;
	scanf("%d",&T);
	while (T--) solve();
}
/*
6 3 2 4 1 5
*/