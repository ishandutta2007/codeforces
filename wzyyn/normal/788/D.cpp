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
int x[10005];
int y[10005];
int query(int x,int y){
	printf("0 %d %d\n",x,y);
	fflush(stdout);
	//return min(min(abs(x-233),abs(x+666)),min(abs(y+233),abs(y-666)));
	scanf("%d",&x);
	return x;
}
int main(){
	int bas=0;
	srand(time(NULL));
	For(i,1,8) bas=bas*10+rand()%10;
	if (rand()&1) bas*=-1;
	int px=-1e8,d=1;
	for (;px<=1e8;){
		int dx=query(px,px);
		if (dx==0){
			if (!query(px,bas)) x[++*x]=px;
			if (!query(bas,px)) y[++*y]=px;
			d=1; px++;
			if (px+100<=1e8&&query(px+100,px+100)==101)
				px+=100,d+=100;
		}
		else{
			int dif=min(d,dx);
			px+=dif; d+=dif;
		}
	}
	printf("1 %d %d\n",*x,*y);
	For(i,1,*x) printf("%d ",x[i]); puts("");
	For(i,1,*y) printf("%d ",y[i]); puts("");
}