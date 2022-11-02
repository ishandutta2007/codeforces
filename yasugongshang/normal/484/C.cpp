#include<bits/stdc++.h>
using namespace std;
#define ll long long
inline char gc(){
	static char buf[100000],*p1=buf,*p2=buf;
	return p1==p2&&(p2=(p1=buf)+fread(buf,1,100000,stdin),p1==p2)?EOF:*p1++;
}
#define gc getchar
#define ld long double
inline ll read(){
	ll x=0;char ch=gc();bool positive=1;
	for(;!isdigit(ch);ch=gc())if(ch=='-')positive=0;
	for(;isdigit(ch);ch=gc())x=x*10+ch-'0';
	return positive?x:-x;
}
inline void write(int x){
	if(x<0) putchar('-'),x=-x;
	if(x>=10) write(x/10);
	putchar(x%10+'0');
}
const int N=1000005,K=20;
int n,m,f[N][K];
char s[N],Alb[N];
int main(){
	scanf("%s",s);
	n=strlen(s);
	m=read();
	while(m--){
		int k=read(),d=read(),dq=-1;
		for(int i=0;i<d;i++)for(int j=i;j<k;j+=d)f[j][0]=dq++;
		for(int j=1;j<K;j++){
			for(register int i=0;i<k;i++){
				if(f[i][j-1]!=-1)f[i][j]=f[f[i][j-1]][j-1]; else f[i][j]=-1;
			}
		}
		for(int i=0;i<n;i++){
			if(i<k){
				int t=i,zt=0;
				for(register int j=K-1;j>=0;j--)if(f[t][j]!=-1&&zt+(1<<j)<=n-k+1){
					zt+=1<<j; t=f[t][j];
				}
				//cout<<(zt==n-k+1?n-k+t:zt)<<" "<<zt<<" "<<t<<endl;
				if(zt==n-k+1)Alb[n-k+t+1]=s[i]; else Alb[zt]=s[i];
			}else{
				int t=k-1,zt=0;
				for(register int j=K-1;j>=0;j--)if(f[t][j]!=-1&&zt+(1<<j)<=n-i){
					zt+=1<<j; t=f[t][j];
				}
				if(zt==n-i)Alb[n-k+t+1]=s[i]; else Alb[zt+i-k+1]=s[i];
			}
		}
		for(int j=0;j<n;j++)s[j]=Alb[j];
		printf("%s\n",s);
	}
}
/*
012345
021345
023145
023415
4->3->0
*/