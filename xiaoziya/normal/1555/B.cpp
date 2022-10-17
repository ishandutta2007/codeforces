#include<stdio.h>
int T,w,h,x1,x2,y1,y2,nw,nh;
int min(int a,int b){
	return a<b? a:b;
}
int main(){
	scanf("%d",&T);
	while(T--){
		scanf("%d%d%d%d%d%d%d%d",&w,&h,&x1,&y1,&x2,&y2,&nw,&nh);
		if(x2-x1+nw>w&&y2-y1+nh>h){
			puts("-1");
			continue;
		}
		int ans=1000000000;
		if(nw<=x1||nh<=y1)
			ans=0;
		else{
			if(x2-x1+nw<=w)
				ans=min(ans,nw-x1);
			if(y2-y1+nh<=h)
				ans=min(ans,nh-y1);
		}
		if(nw<=x1||h-nh>=y2)
			ans=0;
		else{
			if(x2-x1+nw<=w)
				ans=min(ans,nw-x1);
			if(y2-y1+nh<=h)
				ans=min(ans,y2-(h-nh));
		}
		if(w-nw>=x2||nh<=y1)
			ans=0;
		else{
			if(x2-x1+nw<=w)
				ans=min(ans,x2-(w-nw));
			if(y2-y1+nh<=h)
				ans=min(ans,nh-y1);
		}
		if(w-nw>=x2||h-nh>=y2)
			ans=0;
		else{
			if(x2-x1+nw<=w)
				ans=min(ans,x2-(w-nw));
			if(y2-y1+nh<=h)
				ans=min(ans,y2-(h-nh));
		}
		printf("%.9lf\n",1.0*ans);
	}
	return 0;
}