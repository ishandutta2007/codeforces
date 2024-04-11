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

const int N=1000005;
ll a[N],b[N];
char ans[N*5];
int n;
ll sum,top,summ;
void GG(){
	puts("IMPOSSIBLE");
	exit(0);
}
void output1(){
	if (sum>200000)
		printf("BIG\n%lld\n",sum);
	else{
		reverse(ans+1,ans+top+1);
		printf("SMALL\n%lld\n%s",top,ans+1);
	}
	exit(0);
}
void same(){
	int fl=0;
	For(i,1,n) if (a[i]!=b[i]) fl=1;
	if (fl==0) output1();
	For(i,1,n) if (a[i]!=b[n-i+1]) fl=2;
	if (fl!=2){
		if (top<=500000) ans[++top]='R';
		output1();
	}
}
bool increase(){
	For(i,2,n) if (b[i]<=b[i-1]) return 0;
	return 1;
}
void simulate(){
for (;;){
	same();
	//if (b[2]%100==1) cout<<b[1]<<' '<<b[2]<<' '<<b[3]<<' '<<top<<endl;
	if (!increase()){
		ans[++top]='R';
		reverse(b+1,b+n+1);
	}
	if (!increase()) return GG();
	ans[++top]='P'; ++sum;
	Rep(i,n,2) b[i]-=b[i-1];
}
}
void simu(){
for (;;){
	same();
	if (!increase()){
		if (top<=500000) ans[++top]='R';
		reverse(b+1,b+n+1);
	}
	//cout<<b[1]<<' '<<b[2]<<' '<<top<<' '<<sum<<endl;
	if (!increase()) return GG();
	if (max(b[1],b[2])<max(a[1],a[2])) return GG();
	ll T=max(1ll,(b[2]-max(a[1],a[2]))/b[1]); b[2]-=T*b[1];
	for (;T&&sum<=200000;ans[++top]='P',++sum,--T);
	top+=T; sum+=T;
}
}
int main(){
	scanf("%d",&n);
	For(i,1,n) scanf("%lld",&a[i]);
	For(i,1,n) scanf("%lld",&b[i]);
	if (n>=3) simulate();
	else if (n==2) simu();
	else if (a[1]==b[1]) printf("SMALL\n0");
	else GG();
}