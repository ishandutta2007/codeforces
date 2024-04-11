#include<bits/stdc++.h>
#define For(i,j,k) for (int i=(int)(j);i<=(int)(k);i++)
#define Rep(i,j,k) for (int i=(int)(j);i>=(int)(k);i--)
#define pii pair<int,int>
#define fi first
#define se second
#define PB push_back
#define ll long long
#define ull unsigned long long
#define pll pair<ll,ll> 
#define y1 orzkcz
using namespace std;
int Reflect(int x){
	int c1=x/10,c2=x%10;
	if (c1==0||c1==1||c1==8);
	else if (c1==2||c1==5) c1=7-c1;
	else return -1;
	if (c2==0||c2==1||c2==8);
	else if (c2==2||c2==5) c2=7-c2;
	else return -1;
	return c2*10+c1;
}
void solve(){
	int H,M,x,y;
	scanf("%d%d",&H,&M);
	scanf("%d:%d",&x,&y);
	//cout<<H<<' '<<M<<' '<<x<<' '<<y<<endl;
	for (;;){
		int ry=Reflect(x);
		int rx=Reflect(y);
		if (rx>=0&&rx<H&&ry>=0&&ry<M)
			return printf("%02d:%02d\n",x,y),void(0);
		if ((++y)==M){
			y=0;
			if ((++x)==H)
				x=0;
		}
	}
}
int main(){
	int T;
	scanf("%d",&T);
	while (T--) solve(); 
}