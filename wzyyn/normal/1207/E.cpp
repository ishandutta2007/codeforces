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
#define y1 hfjskghsdjkfg
using namespace std;
int x,y;
int main(){
	printf("? ");
	For(i,1,100) printf("%d ",i*128);
	puts(""); fflush(stdout);
	scanf("%d",&x);
	printf("? ");
	For(i,1,100) printf("%d ",i);
	puts(""); fflush(stdout);
	scanf("%d",&y);
	printf("! %d\n",((y>>7)<<7)+(x&127));
	fflush(stdout);
}