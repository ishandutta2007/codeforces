#include<bits/stdc++.h>
using namespace std;
#define rep(i,a,b) for(int i=(a);i<=(b);++i)
#define rrep(i,a,b) for(int i=(a);i>=(b);--i)
#define MP make_pair
#define PB push_back
typedef long long LL;
const LL MOD = 1e9+7;
const int N = 300010;

struct dat{
	LL x;
	int id;
}a[N],b[N];
struct dat2{
	int i,j,d;
}c[N];
int n,m;

int main(){
	#ifndef ONLINE_JUDGE
	freopen("test.in","r",stdin);
	#endif
	ios::sync_with_stdio(false);cin.tie(0);
    scanf("%d",&n);
    rep(i,1,n)scanf("%d",&a[i].x),a[i].id=i;
    rep(i,1,n)scanf("%d",&b[i].x),b[i].id=i;
    LL s=0;
    rep(i,1,n)s=s+a[i].x-b[i].x;
    if(s!=0){
    	cout<<"NO\n";
    	return 0;
	}
	sort(a+1,a+n+1,[](dat x,dat y){return x.x<y.x;}); 
	sort(b+1,b+n+1,[](dat x,dat y){return x.x<y.x;});
	queue<dat> small;
	int ia=1,ib=1;
	while(ib<n){
		while(ia<=n&&ib<=n&&a[ia].x==b[ib].x)++ia,++ib; 
		while(ia<=n&&a[ia].x<b[ib].x)small.push(a[ia]),++ia;
		//while(ia<=n&&ib<=n&&a[ia].x==b[ib].x)++ia,++ib; 
		if(ia>n)break;
		if(small.empty()){
			cout<<"NO\n";
    		return 0;
		}
		dat x = small.front();
		small.pop();
		//let x and a[ia] be closer
		c[++m]={x.id,a[ia].id,0};
		if(x.x+a[ia].x>b[ib].x*2){
			c[m].d=b[ib].x-x.x;
			a[ia].x-=c[m].d;
			x.x+=c[m].d;
		}else{
			c[m].d=a[ia].x-b[ib].x;
			a[ia].x-=c[m].d;++ia;
			x.x+=c[m].d;
			small.push(x);
		}
		++ib;
		//cout<<ia<<" "<<a[ia].id<<" "<<c[m].i<<" "<<c[m].j<<" "<<c[m].d<<endl;
	}
	printf("YES\n%d\n",m);
	rep(i,1,m)printf("%d %d %d\n",c[i].i,c[i].j,c[i].d);
	return 0;
}