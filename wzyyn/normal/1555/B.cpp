#include<bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define For(i,j,k) for (int i=(int)(j);i<=(int)(k);i++)
#define Rep(i,j,k) for (int i=(int)(j);i>=(int)(k);i--)
using namespace std;

void solve(){
	int W,H,x1,y1,x2,y2,w,h,ans=1<<30;
	scanf("%d%d",&W,&H);
	scanf("%d%d%d%d",&x1,&y1,&x2,&y2);
	scanf("%d%d",&w,&h);
	if (x2-x1+w<=W){
		if (x1>=w||W-x2>=w) ans=0;
		else ans=min(w-x1,x2-(W-w));
	}
	if (y2-y1+h<=H){
		if (y1>=h||H-y2>=h) ans=0;
		else ans=min(ans,min(h-y1,y2-(H-h)));
	}
	if (ans==1<<30) printf("-1\n");
	else printf("%d\n",ans);
	
}
int main(){
	int T;
	scanf("%d",&T);
	while (T--) solve();
}