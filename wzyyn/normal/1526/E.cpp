#include<bits/stdc++.h>
using namespace std;

const int N=200005;
const int mo=998244353;
int n,k;
int a[N],p[N];
int power(int x,int y){
	int s=1;
	for (;y;y/=2,x=1ll*x*x%mo)
		if (y&1) s=1ll*s*x%mo;
	return s;
}
int main(){
	scanf("%d%d",&n,&k);
	for (int i=1;i<=n;i++){
		scanf("%d",&p[i]);
		a[++p[i]]=i;
	}
	int Ds=1;
	for (int i=1;i<n;i++)
		if (a[p[i]+1]>a[p[i+1]+1])
			Ds++;
	//cout<<Ds<<endl;
	if (Ds>k) puts("0");
	else{
		int ans=1;
		int x=n+(k-Ds),y=(k-Ds);
		for (int i=1;i<=y;i++)
			ans=1ll*ans*(x+1-i)%mo*power(i,mo-2)%mo;
		cout<<ans<<endl;
	}
}