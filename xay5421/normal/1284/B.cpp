#include<bits/stdc++.h>
//#define int long long
using namespace std;
template<typename T>void rd(T&x){int f=0,c;while(!isdigit(c=getchar()))f^=!(c^45);x=(c&15);while(isdigit(c=getchar()))x=x*10+(c&15);if(f)x=-x;}
template<typename T>void pt(T x,int c=-1){if(x<0)putchar('-'),x=-x;if(x>9)pt(x/10);putchar(x%10+48);if(c!=-1)putchar(c);}
const int N=100005;
typedef long long ll;
int n,tot,num[N],num2[N];vector<int>a[N];
ll ans;
signed main(){
	rd(n);
	for(int i=1;i<=n;++i){
		int k1;rd(k1);
		a[i].resize(k1);
		for(int j=0;j<k1;++j)rd(a[i][j]);
		bool k2=0;
		for(int j=1;j<k1;++j){
			if(a[i][j]>a[i][j-1]){
				k2=1;
				break;
			}
		}
		if(k2){++tot,--i,--n;continue;}
		num[i]=a[i][k1-1];
		num2[i]=a[i][0];
	}
	sort(num2+1,num2+1+n);
	for(int i=1;i<=n;++i){
		ans+=n-(upper_bound(num2+1,num2+1+n,num[i])-num2)+1;
	}
	ans+=1ll*tot*n+1ll*n*tot+1ll*tot*tot;
	pt(ans,'\n');
	return 0;
}