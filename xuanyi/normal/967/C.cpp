#include <cstdio>
#include <algorithm>
using namespace std;
const int MAXN=100000005,MAXC=100005,INF=0x3f3f3f3f;

int n,m,cl,ce,v,Q;
int l[MAXC],e[MAXC];

int main(){
	scanf("%d%d%d%d%d",&n,&m,&ce,&cl,&v,&Q);
	for (int i=1;i<=ce;i++) scanf("%d",e+i);
	for (int i=1;i<=cl;i++) scanf("%d",l+i);
	scanf("%d",&Q);
	while (Q--){
		int x,y,x_,y_,t,fl=-1,fe=-1,ans=INF;
		scanf("%d%d%d%d",&x,&y,&x_,&y_);
		if (x==x_) ans=abs(y-y_); else{
			if (cl){
				t=upper_bound(l+1,l+1+cl,y)-l;
				if (l[t]>=y&&t<=cl){
					fl=l[t];
					ans=min(ans,(abs(x-x_)+v-1)/v+abs(y-fl)+abs(fl-y_));
				}
				t--;
				if (t>=1&&l[t]<=y){
					fl=l[t];
					ans=min(ans,(abs(x-x_)+v-1)/v+abs(y-fl)+abs(fl-y_));
				}
			}
			if (ce){
				t=upper_bound(e+1,e+1+ce,y)-e;
				if (e[t]>=y&&t<=ce){
					fe=e[t];
					ans=min(ans,abs(x-x_)+abs(y-fe)+abs(fe-y_));
				}
				t--;
				if (t>=1&&e[t]<=y){
					fe=e[t];
					ans=min(ans,abs(x-x_)+abs(y-fe)+abs(fe-y_));
				}
			}
			if (fl!=-1){
				ans=min(ans,(abs(x-x_)+v-1)/v+abs(y-fl)+abs(fl-y_));
			}
		}
		printf("%d\n",ans);
	}
	return 0;
}