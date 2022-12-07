#include<bits/stdc++.h>
#define ll long long
using namespace std;

const int M=125500;
int n,mo,f[2*M];
void UPD(int &x,int y){
	(x+=y)>=mo?x-=mo:233; 
}
int main(){
	scanf("%d%d",&n,&mo);
	int L=0,w=1;
	for (int i=n;i>=1;i--){
		L+=i-1;
		for (int j=M-L;j<=M+L;j++) UPD(f[j],f[j-1]);
		for (int j=M+L;j>=M-L;j--) UPD(f[j],mo-f[j-i]);
		for (int j=M+L;j>=M-L;j--) UPD(f[j],f[j+1]);
		for (int j=M-L;j<=M+L;j++) UPD(f[j],mo-f[j+i]);
		for (int j=1;j<i;j++) f[M-j]=(f[M-j]+1ll*(i-j)*w)%mo;
		w=1ll*w*i%mo;
	}
	int ans=0;
	for (int j=M+1;j<2*M;j++) UPD(ans,f[j]);
	cout<<ans<<endl;
}