#include <cstdio>

int n,h,a,b,k;

template <typename T>
inline void read(T &x){
	int fl=0,ch;
	while (ch=getchar(),ch<48 || 57<ch) fl^=!(ch^45); x=(ch&15);
	while (ch=getchar(),47<ch && ch<58) x=(x<<1)+(x<<3)+(ch&15);
	if (fl) x=-x;
}

inline int abs_(int x){
	if (x<0) return -x;
	return x;
}

int main(){
	read(n),read(h),read(a),read(b),read(k);
	for (int i=1,ta,fa,tb,fb,ans;i<=k;i++){
		read(ta),read(fa),read(tb),read(fb);
		if (ta==tb) ans=abs_(fa-fb);
		else if (fa>b && fb>b){
			ans=fa-b+fb-b+abs_(ta-tb);
		} else if (fa<a && fb<a){
			ans=a-fa+a-fb+abs_(ta-tb);
		} else{
			ans=abs_(fa-fb)+abs_(ta-tb); 
		}
		printf("%d\n",ans);
	}
	return 0;
}