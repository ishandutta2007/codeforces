#include <bits/stdc++.h>
using namespace std;

const int MN = 1e5+5;
int n, x[MN], y[MN], i, p, a=1, b=2;
pair<int,int> v1, v2, v3;

long long cr(pair<int,int> a,pair<int,int> b){
	return 1LL*a.first*b.second-1LL*a.second*b.first;
}

int main(){
	for(scanf("%d",&n),i=1;i<=n;i++)
		scanf("%d%d",&x[i],&y[i]);
	for(i=3;i<=n;i++){
		bool a1=0, a2=0;
		v1={x[i]-x[a],y[i]-y[a]};
		v2={x[b]-x[a],y[b]-y[a]};
		if(cr(v1,v2)) a1=1;
		v1={x[i]-x[b],y[i]-y[b]};
		v2={x[a]-x[b],y[a]-y[b]};
		if(cr(v1,v2)) a2=1;
		if(!a1&&!a2){
			if(x[i]>x[a]&&x[i]<x[b]||y[i]>y[a]&&y[i]<y[b]) a=i;
			else if(x[i]>x[b]&&x[i]<x[a]||y[i]>y[b]&&y[i]<y[a]) b=i;
		}
		if(a1&&a2){p=i; break;}
	}
	for(i++;i<=n;i++){
		bool a1=0, a2=0;
		bool o1=0, o2=0;
		v1={x[p]-x[a],y[p]-y[a]};
		v2={x[i]-x[a],y[i]-y[a]};
		v3={x[b]-x[a],y[b]-y[a]};
		if(cr(v2,v3)) o1=1;
		if(cr(v1,v2)>=0&&cr(v2,v3)>=0) a1=1;
		else if(cr(v1,v2)<=0&&cr(v2,v3)<=0) a1=1;
		v1={x[p]-x[b],y[p]-y[b]};
		v2={x[i]-x[b],y[i]-y[b]};
		v3={x[a]-x[b],y[a]-y[b]};
		if(cr(v2,v3)) o2=1;
		if(!o1&&!o2){
			if(x[i]>x[a]&&x[i]<x[b]||y[i]>y[a]&&y[i]<y[b]) a=i;
			else if(x[i]>x[b]&&x[i]<x[a]||y[i]>y[b]&&y[i]<y[a]) b=i;
		}
		else if(cr(v1,v2)>=0&&cr(v2,v3)>=0) a2=1;
		else if(cr(v1,v2)<=0&&cr(v2,v3)<=0) a2=1;
		if(a1&&a2) p=i;
	}
	printf("%d %d %d\n",a,b,p);
	return 0;
}