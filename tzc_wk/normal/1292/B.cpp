#include <bits/stdc++.h>
using namespace std;
#define fi			first
#define se			second
#define fz(i,a,b)	for(int i=a;i<=b;i++)
#define fd(i,a,b)	for(int i=a;i>=b;i--)
#define put(x)		putchar(x)
#define eoln        put('\n')
#define space		put(' ')
#define int long long
inline int read(){
	int x=0,neg=1;char c=getchar();
	while(!isdigit(c)){
		if(c=='-')	neg=-1;
		c=getchar();
	}
	while(isdigit(c))	x=x*10+c-'0',c=getchar();
	return x*neg;
}
inline void print(int x){
	if(x<0){
		putchar('-');
		print(abs(x));
		return;
	}
	if(x<=9)	putchar(x+'0');
	else{
		print(x/10);
		putchar(x%10+'0');
	}
}
int x[105],y[105];
int ax,ay,bx,by;
int sx,sy,t,cntx,cnty,ans = 0;
int dist(int i,int j){
	return abs(x[j]-x[i]) + abs(y[j]-y[i]);
}
signed main(){
	cin>>x[0]>>y[0]>>ax>>ay>>bx>>by>>sx>>sy>>t;
	for(cntx=1;x[cntx-1]<=4e16;++cntx)
		x[cntx]=ax*x[cntx-1]+bx;
	for(cnty=1;y[cnty-1]<=4e16;++cnty)
		y[cnty]=ay*y[cnty-1]+by;
	for(int i=0;i<cntx&&i<cnty;i++){
		int sum=abs(sx-x[i])+abs(sy-y[i]);
		if(sum>t)	continue;
		for(int j=i-1;j>=0;j--){
			sum+=dist(j+1,j);
			if(sum>t){
				ans=max(ans,i-j);
				break;
			}
		}
		if(sum>t) continue;
		int p=0;
		for(int j=i+1;;j++){
			sum+=dist(j,p);
			if(sum>t){
				ans=max(ans,j);
				break;
			}
			p=j;
		}
	}
	cout<<ans<<endl;
}