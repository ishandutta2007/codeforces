#include <bits/stdc++.h>
using namespace std;
#define int long long
const int MOD=1e9+7;
struct matrix{
	int a[2][2];
	matrix(){memset(a,0,sizeof(a));}
	matrix operator *(matrix m){
		matrix ans;
		for(int i=0;i<2;i++)
			for(int j=0;j<2;j++)
				for(int s=0;s<2;s++)
					ans.a[i][j]=(ans.a[i][j]+a[i][s]*m.a[s][j])%MOD;
		return ans;
	}
};
matrix pow(matrix x,int e){
	matrix ans;
	ans.a[0][0]=ans.a[1][1]=1;
	while(e){
		if(e&1)	ans=ans*x;
		x=x*x;
		e/=2;
	}
	return ans;
}
int x,y,n;
matrix t;
signed main(){
	cin>>x>>y>>n;
	if(n==1)	return cout<<(x+MOD)%MOD<<endl,0;
	if(n==2)	return cout<<(y+MOD)%MOD<<endl,0;
	t.a[0][0]=1;t.a[0][1]=MOD-1;
	t.a[1][0]=1;t.a[1][1]=0;
	t=pow(t,n-2);
	cout<<(t.a[0][0]*y+t.a[0][1]*x+MOD*MOD)%MOD<<endl;
}