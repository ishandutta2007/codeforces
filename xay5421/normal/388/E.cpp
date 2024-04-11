#include<bits/stdc++.h>
#define rep(i,a,b) for(int i=(a);i<=(b);++i)
#define per(i,a,b) for(int i=(a);i>=(b);--i)
using namespace std;
const int N=1005;
const long double eps=1e-5;
int n,mp[N][N];
bitset<N>can[N];
int sgn(long double x){return fabs(x)<eps?0:x<0?-1:1;}
struct vec{
	long double x,y;
	vec operator-(const vec&k)const{return (vec){x-k.x,y-k.y};}
}xx[N],bb[N];
bool chk(const vec&k1,const vec&k2){
	if(sgn(k1.x)==0&&sgn(k2.x)!=0)return 0;
	if(sgn(k1.y)==0&&sgn(k2.y)!=0)return 0;
	return sgn(k2.x*k1.y-k2.y*k1.x)==0;
}
long double calc(const vec&k1,const vec&k2){
	return sgn(k1.x)!=0?k2.x/k1.x:k2.y/k1.y;
}
long double num[N];
int len;
int main(){
	scanf("%d",&n);
	rep(i,1,n){
		int t1,x1,y1,t2,x2,y2;
		scanf("%d%d%d%d%d%d",&t1,&x1,&y1,&t2,&x2,&y2);
		bb[i]=(vec){x1+1.*(0-t1)/(t2-t1)*(x2-x1),y1+1.*(0-t1)/(t2-t1)*(y2-y1)};
		xx[i]=(vec){1./(t2-t1)*(x2-x1),1./(t2-t1)*(y2-y1)};
	}
	int ans=0;
	rep(i,1,n)rep(j,1,n){
		if(i==j||chk(xx[i]-xx[j],bb[i]-bb[j])){
			can[i][j]=1;
			ans=1;
		}
	}
	rep(i,1,n){
		len=0;
		rep(j,1,n)if(can[i][j]){
			if(j!=i){
				num[++len]=calc(xx[i]-xx[j],bb[i]-bb[j]);
			}
		}
		sort(num+1,num+1+len);
		for(int l=1,r;l<=len;l=r){
			r=l+1;
			while(r<=len&&sgn(num[l]-num[r])==0)++r;
			ans=max(ans,r-l+1);
		}
	}
	rep(i,1,n){
		rep(j,i+1,n){
			auto tmp=can[i]&can[j];
			if((int)tmp.count()>ans){
				for(int k=tmp._Find_first();k<N;k=tmp._Find_next(k)){
					tmp&=can[k];
					if((int)tmp.count()<=ans)break;
				}
				ans=max<int>(ans,tmp.count());
			}
		}
	}
	printf("%d\n",ans);
	return 0;
}