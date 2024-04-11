#include<iostream>
#include<cmath>
#include<cstring>
#include<cstdio>
#include<algorithm>
using namespace std;
char ch[60][60];
int n,m,pd[4],sign;
int main(){
	scanf("%d%d",&n,&m); int ans=0;
	for (int i=1;i<=n;i++) scanf("%s",ch[i]+1);
	for (int i=1;i<n;i++)
		for (int j=1;j<m;j++){
			sign++;
			for (int k=0;k<2;k++)
				for (int k1=0;k1<2;k1++){
					int k3=i+k,k4=j+k1;
					if (ch[k3][k4]=='f') pd[0]=sign;
					if (ch[k3][k4]=='a') pd[1]=sign;
					if (ch[k3][k4]=='c') pd[2]=sign;
					if (ch[k3][k4]=='e') pd[3]=sign;
				}
			int flag=0;
			for (int k=0;k<4;k++) if (pd[k]!=sign){flag=1; break;}
			ans+=1-flag;
		}
	cout<<ans<<endl;
}