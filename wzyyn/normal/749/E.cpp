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
#define CLR(a,v) memset(a,v,sizeof(a));
#define CPY(a,b) memcpy(a,b,sizeof(a));
#define debug puts("wzpakking")
#define y1 ysghysgsygsh
using namespace std;
const int N=100005;
int n,a[N];
double ans,ans1,t[N];
void change(int x,int v){
	for (;x<=n;x+=x&(-x)) t[x]+=v;
}
double ask(int x){
	double s=0;
	for (;x;x-=x&(-x)) s+=t[x];
	return s;
}
int main(){
	scanf("%d",&n);
	For(i,1,n) scanf("%d",&a[i]);
	For(i,1,n) ans+=i-1-ask(a[i]),change(a[i],1);
	For(i,1,n) t[i]=0;
	For(i,1,n) ans1+=1.0*(n-i+1)*(2*ask(a[i])-1.0*i*(i-1)/2),change(a[i],i);
	printf("%.15lf\n",ans+ans1/n/(n+1));
	//cout<<ans1<<' '<<ans<<endl;
}