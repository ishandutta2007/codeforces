#include<cstdio>
#include<algorithm>
#define rep(i,a,b) for(int i=(a);i<=(b);++i) 
const int N=5005;
int n,a[N],t[N],p[N],q[N],posp[N],sum;
void fix(int i,int j){
	int k=posp[t[i]^q[i]];
	if(k==i)return;
	if(k==j){
		std::swap(posp[p[i]],posp[p[j]]);
		std::swap(p[i],p[j]);
		return;
	}
	std::swap(posp[p[i]],posp[p[k]]);
	std::swap(p[i],p[k]),std::swap(q[j],q[k]);
	fix(k,j);
}
int main(){
	scanf("%d",&n);n=1<<n;
	rep(i,0,n-1)scanf("%d",a+i),p[i]=q[i]=posp[i]=i,sum^=a[i];
	if(sum!=0)return 0&puts("Fou");
	rep(i,0,n-1){
		if(a[i]!=t[i]){
			int dt=a[i]^t[i];
			t[i]^=dt,t[i+1]^=dt;
			fix(i,i+1);
		}
	}
	puts("Shi");
	rep(i,0,n-1)printf("%d ",p[i]);puts("");
	rep(i,0,n-1)printf("%d ",q[i]);puts(""); 
	return 0;
}