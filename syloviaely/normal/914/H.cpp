#include <bits/stdc++.h>
using namespace std;
int n,D,mo;
long long C[210][210],T[210][210],f[210][210],g[210][210],fpre[210][210],gpre[210][210];
struct atom{
	long long way,tot;
};
atom operator + (atom k1,atom k2){
	return (atom){(k1.way+k2.way)%mo,(k1.tot+k2.tot)%mo};
}
atom calc1(){
	long long way=0,tot=0;
	for (int d=2;d<=D;d++){
		way=(way+f[n][d])%mo;
		tot=(tot+g[n][d])%mo;
	}
	return (atom){way,tot};
}
atom calc2(){
	long long way=0,tot=0;
	for (int d1=1;d1<=D;d1++)
		for (int d2=2;d1+d2<=D;d2++)
			for (int i=1;i<=n;i++){
				int rem=n-i+1;
				long long num=1ll*f[i][d1]*f[rem][d2]%mo;
				way=(way+num)%mo;
				tot=(tot+1ll*f[i][d1]*g[rem][d2]%mo+1ll*f[rem][d2]*g[i][d1])%mo;	
			}
	return (atom){way,tot};
}
atom calcrem(){
	long long way=0,tot=0;
	for (int d=1;d<=D;d++){
		way=(way+f[n][d])%mo;
		tot=(tot+g[n][d])%mo;
	}
	return (atom){way,tot};
}
int main(){
	scanf("%d%d%d",&n,&D,&mo);
	for (int i=0;i<=n;i++){
		C[i][0]=1;
		for (int j=1;j<=i;j++) C[i][j]=(1ll*C[i-1][j-1]+C[i-1][j])%mo;
	}
	memset(f,0x00,sizeof f);
	memset(g,0x00,sizeof g);
	f[1][0]=1; 
	for (int i=0;i<=n;i++) fpre[1][i]=1;
	for (int i=2;i<=n;i++){
		for (int d=1;d<=n;d++)
			for (int j=1;j<i;j++){
				f[i][d]=(f[i][d]+1ll*f[i-j][d-1]*C[i-2][j-1]%mo*fpre[j][D-1])%mo;
				g[i][d]=(g[i][d]+1ll*g[i-j][d-1]*C[i-2][j-1]%mo*fpre[j][D-1]%mo+1ll*gpre[j][D-1]*C[i-2][j-1]%mo*f[i-j][d-1]%mo+1ll*j*f[i-j][d-1]%mo*C[i-2][j-1]%mo*fpre[j][D-1])%mo;
			//	if (i==3&&d==2) cout<<"fa "<<j<<" "<<g[i-j][d-1]<<" "<<f[i-j][d-1]<<" "<<g[i][d]<<endl;
			}
		for (int d=1;d<=n;d++){
			fpre[i][d]=(f[i][d]+fpre[i][d-1])%mo;
			gpre[i][d]=(g[i][d]+gpre[i][d-1])%mo;
		}
		//for (int d=0;d<=n;d++) cout<<g[i][d]<<" "; cout<<endl;
	}
	/*for (int i=1;i<=n;i++){
		for (int j=0;j<=n;j++) cout<<f[i][j]<<" "; cout<<endl;} cout<<endl;
	for (int i=1;i<=n;i++){
		for (int j=0;j<=n;j++) cout<<g[i][j]<<" "; cout<<endl;} cout<<endl;
	for (int i=1;i<=n;i++){
		for (int j=0;j<=n;j++) cout<<fpre[i][j]<<" "; cout<<endl;}
	for (int i=1;i<=n;i++){
		for (int j=0;j<=n;j++) cout<<gpre[i][j]<<" "; cout<<endl;}*/
	atom ans=calc1();
	//cout<<ans.way<<" "<<ans.tot<<endl;
	ans=ans+calc2();
	//cout<<ans.way<<" "<<ans.tot<<endl;
	ans=ans+calcrem();
	//cout<<ans.way<<" "<<ans.tot<<endl;
	ans.tot=(ans.tot-1ll*ans.way*(n-1))%mo;
	ans.tot=0;
	long long tot=n*(n-1)*2*ans.way%mo;
	tot=(tot-ans.tot*2)%mo;
	tot=(tot+mo)%mo;
	cout<<tot<<endl;
}