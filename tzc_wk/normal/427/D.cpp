#include <bits/stdc++.h>
using namespace std;
int n,m,tot;
char s[5005],t[5005],x[15005];
int z[15005],ans=INT_MAX;
inline void Z_algorithm(){
	memset(z,0,sizeof(z));
	int l=0,r=0;
	for(int i=1;i<tot;i++){
		if(i<=r)	z[i]=min(z[i-l],r-i);
		while(i+z[i]<tot&&x[z[i]]==x[i+z[i]])	z[i]++;
		if(i+z[i]>r){
			l=i;
			r=i+z[i];
		}
	}
}
int main(){
	scanf("%s%s",s+1,t+1);
	n=strlen(s+1),m=strlen(t+1);
	for(int i=1;i<=n;i++){
		memset(x,0,sizeof(x));tot=0;
		for(int j=i;j<=n;j++)	x[tot++]=s[j];
		x[tot++]='$';
		for(int j=1;j<=n;j++)	x[tot++]=s[j];
		x[tot++]='#';
		for(int j=1;j<=m;j++)	x[tot++]=t[j];
		Z_algorithm();
//		for(int i=1;i<=tot;i++)	cout<<z[i]<<" ";cout<<endl;
		z[n+1]=0;
		int f=0,g=0,idx=-1;
		bool good=false;
		for(int j=1;j<tot;j++){
			if(z[j]>f){
				g=f;
				f=z[j];
				idx=j;
				good=1;
			}
			else if(z[j]==f)	good=0;
			else if(z[j]>g)		g=z[j];
		}
		if(good&&idx>2*n-i+1)	ans=min(ans,g+1);
	}
	if(ans==INT_MAX)	puts("-1");
	else				cout<<ans<<endl;
}