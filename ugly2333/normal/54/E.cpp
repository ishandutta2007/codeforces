//CF 54E
#include<iostream>
#include<cstdio>
#include<fstream>
#include<algorithm>
#include<vector>
#include<map>
#include<set>
#include<queue>
#include<cmath>
#include<cstring>
#include<cstdlib>
using namespace std;
typedef long long LL;
typedef double DB;
const int N = 111111;
LL ABS(LL x){
	if(x<0)
		return -x;
	return x;
}
struct pt{
	LL x;
	LL y;
	pt(LL X=0,LL Y=0){
		x=X,y=Y;
	}
}a[N];
pt operator-(pt p,pt q){
	return pt(p.x-q.x,p.y-q.y);
}
LL operator*(pt p,pt q){
	return p.x*q.x+p.y*q.y;
}
LL operator%(pt p,pt q){
	return p.x*q.y-p.y*q.x;
}
DB D(pt p){
	return sqrt(p.x*p.x+p.y*p.y);
}
LL S(pt p,pt q,pt r){
	return ABS((p-r)%(q-r));
}
int n;
int main()
{
	int i,j,x,y;
	LL s;
	DB ans=1e18,t,h;
	scanf("%d",&n);
	for(i=1;i<=n;i=i+1){
		scanf("%d%d",&x,&y);
		a[i]=pt(x,y);
		a[n+i]=a[i];
	}
	a[0]=a[n];
	s=0;
	i=n+1;
	for(j=1;j<=n;j=j+1){
		while((a[i-1]-a[i])*(a[j+1]-a[j])<0){
			i--;
			s+=S(a[i],a[i+1],a[j]);
		}
		while((a[i]-a[i+1])*(a[j+1]-a[j])>0){
			s-=S(a[i],a[i+1],a[j]);
			i++;
		}
		h=D(a[i]-a[j]);
		t=(DB)S(a[i],a[j],a[j+1])/D(a[j]-a[j+1]);
		h=sqrt(h*h-t*t);
		ans=min(ans,h*t-s);
		s+=S(a[i],a[j],a[j+1]);
	}
	a[0]=a[1];
	reverse(a+1,a+n+n+1);
	s=0;
	i=n+1;
	for(j=1;j<=n;j=j+1){
		while((a[i-1]-a[i])*(a[j+1]-a[j])<0){
			i--;
			s+=S(a[i],a[i+1],a[j]);
		}
		while((a[i]-a[i+1])*(a[j+1]-a[j])>0){
			s-=S(a[i],a[i+1],a[j]);
			i++;
		}
		h=D(a[i]-a[j]);
		t=(DB)S(a[i],a[j],a[j+1])/D(a[j]-a[j+1]);
		h=sqrt(h*h-t*t);
		ans=min(ans,h*t-s);
		s+=S(a[i],a[j],a[j+1]);
	}
	printf("%.18lf",ans/2);
	return 0;
}