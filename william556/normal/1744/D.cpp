// LUOGU_RID: 90774356
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
inline int in(){
	int x;
	scanf("%d",&x);
	return x;
}
const int N=2e5+5;
int n,a[N],m;
void solve(){
	n=m=in();
	for(int i=1;i<=n;i++){
		int x=in();
		while(x%2==0)x>>=1,m--;	
	}
	if(m<0){puts("0");return;}
	int ans=0;
	for(int i=1;i<=n;i++){
		a[i]=0;
		int x=i;
		while(x%2==0)a[i]++,x/=2;	
	}
	sort(a+1,a+n+1,greater<int>());
	for(int i=1;i<=n&&m>0;i++){
		ans++;m-=a[i];		
	}
	if(m>0)puts("-1");
	else printf("%d\n",ans);
}
int main(){
//	freopen("in.txt","r",stdin);
	int t=in();
	while(t--)solve();;
	return 0;
}