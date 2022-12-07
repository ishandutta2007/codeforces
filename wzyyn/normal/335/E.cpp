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
int n,h;
char s[25];
int main(){
	scanf("%s%d%d",s,&n,&h);
	if (s[0]=='B') return printf("%d\n",n),0;
	double ans=n;
	For(H,1,h) For(j,1,n-1){
		double res=pow(2,H);
		res-=pow(2,H-1)*(1+(j-1)/(pow(2,H)-1));
		ans+=pow(0.25,H)*pow(1-pow(0.5,H),j-1)*(n-j)*res;
	}
	printf("%.15lf\n",ans);
}