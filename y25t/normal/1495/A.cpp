#include<cstdio>
#include<cmath>
#include<algorithm>
#define lf long double
#define N 100005

int T;

int n,a[N],_a,b[N],_b;

lf ans;

int main(){
	scanf("%d",&T);
	while(T--){
		scanf("%d",&n);
		_a=_b=0;
		for(int i=1;i<=2*n;i++){
			int x,y;
			scanf("%d%d",&x,&y);
			if(!x)
				a[++_a]=std::abs(y);
			else
				b[++_b]=std::abs(x);
		}
		std::sort(a+1,a+n+1);
		std::sort(b+1,b+n+1);
		ans=0;
		for(int i=1;i<=n;i++)
			ans+=std::sqrt((lf)a[i]*a[i]+(lf)b[i]*b[i]);
		printf("%.10LF\n",ans);
	}
}