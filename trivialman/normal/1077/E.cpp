#include<cstdio>
#include<cstring>
#include<iostream>
#include<string>
#include<algorithm>
using namespace std;
#define N 300000
#define MOD 998244353
#define LL long long
#define rep(i,a,b) for(int i=a;i<=b;++i)
#define CL(x) memset(x,0,sizeof(x))

int n,k,a[N],cnt[N],b[N],m,ans=0;

int main(){
	CL(cnt);CL(b);
	scanf("%d",&n);
	rep(i,1,n)scanf("%d",&a[i]);
	sort(a+1,a+n+1);
	
	cnt[1]=1;m=1;
	rep(i,2,n){
		if(a[i]==a[i-1])++cnt[m];
		else cnt[++m]=1;
	}
	sort(cnt+1,cnt+m+1);
	
	rep(i,1,20){
		int x=cnt[m],j=m-1;
		for(;m-j<i;--j){
			x=min(x/2,cnt[j]);
		}
		if(x>0){
			int tot=0;
			for(j=1;j<=i;++j){
				tot+=x;x*=2;
			}
			if(tot>ans)ans=tot;
		}
	}
	cout<<ans<<endl;
	return 0;
}