#include<bits/stdc++.h>
#define ll long long
#define ull unsigned ll
#define uint unsigned
#define pii pair<int,int>
#define pll pair<ll,ll>
#define IT iterator
#define PB push_back
#define fi first
#define se second
#define For(i,j,k) for (int i=(int)(j);i<=(int)(k);i++)
#define Rep(i,j,k) for (int i=(int)(j);i>=(int)(k);i--)
#define UPD(x,y) (((x)+=(y))>=mo?x-=mo:233)
#define CLR(a,v) memset(a,v,sizeof(a));
#define CPY(a,b) memcpy(a,b,sizeof(a));
#define debug puts("wzpakking")
using namespace std;
const int N=10005;
int n,q[N],h,t,ans[N];
ll a[N];
vector<int> vec0,vec1;
bool cmp(int x,int y){
	return a[x]>a[y];
}
ll Query(int i,int j,int k,int tp){
	printf("%d %d %d %d\n",tp,i,j,k);
	fflush(stdout);
	ll ans;
	scanf("%lld",&ans);
	return ans;
}
int main(){
	scanf("%d",&n);
	For(i,3,n){
		if (Query(1,2,i,2)==-1) vec0.PB(i);
		else vec1.PB(i);
		a[i]=Query(1,2,i,1);
	}
	sort(vec0.begin(),vec0.end(),cmp);
	sort(vec1.begin(),vec1.end(),cmp);
	ans[++*ans]=1;
	h=n+1,t=n;
	if (vec0.size()){
		q[++t]=vec0[0];
		For(i,1,vec0.size()-1)
			if (Query(1,vec0[0],vec0[i],2)==1)
				q[++t]=vec0[i];
			else q[--h]=vec0[i];
	}
	For(i,h,t) ans[++*ans]=q[i];
	ans[++*ans]=2;
	h=n+1,t=n;
	if (vec1.size()){
		q[++t]=vec1[0];
		For(i,1,vec1.size()-1)
			if (Query(1,vec1[0],vec1[i],2)==1)
				q[++t]=vec1[i];
			else q[--h]=vec1[i];
	}
	For(i,h,t) ans[++*ans]=q[i];
	printf("0 ");
	For(i,1,*ans)
		printf("%d ",ans[i]);
}