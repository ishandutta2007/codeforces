#include<cstdio>
#include<algorithm>
#define N 100005

int n,a[N];

int l[N],r[N],mx[N];

struct node{
	int x,y;
	inline void ins(int d){
		if(d>x){
			y=x;
			x=d;
		}
		else if(d>y)
			y=d;
	}
	inline int mx(int d=-1){
		return d==x?y:x;
	}
}s;

int ans;

int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
		scanf("%d",&a[i]);
	a[0]=a[n+1]=N;
	for(int i=1;i<=n;i++)
		l[i]=a[i]>a[i-1]?l[i-1]+1:0;
	for(int i=n;i;i--)
		r[i]=a[i]>a[i+1]?r[i+1]+1:0;
	for(int i=1;i<=n;i++){
		if(r[i]<l[i])
			std::swap(l[i],r[i]);
		mx[i]=std::max(l[i],r[i]);
		s.ins(mx[i]);
	}
	for(int i=1;i<=n;i++)
		if(l[i]&&r[i]&&((l[i]==r[i]&&l[i]%2==0))&&mx[i]>s.mx(mx[i]))
			ans++;
	printf("%d\n",ans);
}