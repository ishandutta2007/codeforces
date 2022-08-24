#include<iostream>
#include<cmath>
#include<cstring>
#include<algorithm>
#include<cstdio>
using namespace std;
char ch[110000];
int n,w,mo=1e9+7,num;
int quick(int k1,int k2){
	int k3=1;
	while (k2){
		if (k2&1) k3=1ll*k3*k1%mo; k1=1ll*k1*k1%mo; k2>>=1;
	}
	return k3;
}
int main(){
	scanf("%d",&n); int ans=0;
	scanf("%s",ch+1);
	num=0; w=0;
	for (int i=1;i<=n;i++) if (ch[i]=='A') num++; 
	if (ans<num){ans=num; w=1;} else if (ans==num) w++;
	num=0;
	for (int i=1;i<=n;i++) if (ch[i]=='C') num++; 
	if (ans<num){ans=num; w=1;} else if (ans==num) w++; 
	num=0;
	for (int i=1;i<=n;i++) if (ch[i]=='G') num++;
	if (ans<num){ans=num; w=1;} else if (ans==num) w++;
	num=0;
	for (int i=1;i<=n;i++) if (ch[i]=='T') num++; 
	if (ans<num){ans=num; w=1;} else if (ans==num) w++;
	cout<<quick(w,n)<<endl;
	return 0;
}