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
int n,m;
ll wa,wb,w1,w2;
ll v[105],rem[105];
void check(int a,int b){
	int s1=0,s2=0,s3=0;
	For(i,1,n){
		int rem=v[i]%(a+b);
		if (rem<a) continue;
		if (a<=rem&&rem<b) s1++;
		if (b<=rem&&rem<2*a) s2++;
		if (max(b,2*a)<=rem) s3++;
	}
	if (s1||s3>=2) ++wa,++wb;
	else if (!s3) s2&1?w1+=2:w2+=2;
	else if ((s2+s3)%2==1) w1+=2;
	else ++wa,++wb;
}
/*
!s3
s2%2==1 
s2%2==0&&!s3 
s2%2==0 
*/
void checker(int mm){
	int vl=max(1,mm-m);
	int vr=(mm-1)/2;
	int mx1=0,mx2=0,sum=0;
	For(i,1,n){
		int rem=v[i]%mm;
		if (rem*2>mm){
			if (rem>mx1) mx2=mx1,mx1=rem;
			else mx2=max(mx2,rem);
			sum++;
		}
		if (rem*2<=mm) vl=max(vl,rem+1);
		else vl=max(vl,mm-rem);
	}
	vl=max(vl,mx2/2+1);
	if (vl>vr) return;
	if (sum&1) w1+=(vr-vl+1)*2;
	else w2+=max(0,vr-max(vl,mx1/2+1)+1)*2;
}
int main(){
	scanf("%d%d",&n,&m);
	For(i,1,n) scanf("%lld",&v[i]);
	For(i,1,m){
		int sum=0;
		For(j,1,n) sum+=v[j]/i;
		sum&1?w1++:w2++;
	}
	For(i,2,2*m) checker(i);
	//For(i,1,m) For(j,i+1,m) check(i,j);
	//printf("%lld %lld %lld %lld\n",wa,wb,w1,w2);
	wa=wb=(1ll*m*m-w1-w2)/2;
	printf("%lld %lld %lld %lld\n",wa,wb,w1,w2);
	
	/*w1=w2=wa=wb=0;
	For(i,1,m){
		int sum=0;
		For(j,1,n) sum+=v[j]/i;
		sum&1?w1++:w2++;
	}
	For(i,1,m) For(j,i+1,m) check(i,j);
	printf("%lld %lld %lld %lld\n",wa,wb,w1,w2);*/
}
/*
4 1000
82915 21368 42139 12831
*/