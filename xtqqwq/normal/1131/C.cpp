#include<bits/stdc++.h>

using namespace std;

typedef long long ll;

int readint(){
	int x=0,f=1; char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
	return x*f;
}

int n,ansx,ansy,tmpx,tmpy,bc,ac;
int a[105],d[105][105],prex[105][105],prey[105][105],aa[105],bb[105];

int main(){
	n=readint();
	for(int i=1;i<=n;i++) a[i]=readint();
	sort(a+1,a+n+1);
	memset(d,0x3f,sizeof(d));
	d[0][0]=1<<30;
	for(int i=0;i<=n;i++){
		for(int j=0;j<=i;j++){
			if(i==j) continue;
			if(d[i-1][j]!=0x3f3f3f3f&&min(d[i-1][j],a[i]-a[i-1])<d[i][j]) prex[i][j]=i-1,prey[i][j]=j,d[i][j]=min(d[i-1][j],a[i]-a[i-1]);
			if(d[i][j-1]!=0x3f3f3f3f&&min(d[i][j-1],a[j]-a[j-1])<d[i][j]) prex[i][j]=i,prey[i][j]=j-1,d[i][j]=min(d[i][j-1],a[j]-a[j-1]);
		}
	}
	for(int i=1;i<n;i++) d[n][i]+=a[n]-a[i],d[i][n]+=a[n]-a[i];
	int ans=1<<30;
	for(int i=1;i<n;i++) if(d[n][i]<ans) ans=d[n][i],ansx=n,ansy=i;
	for(int i=1;i<n;i++) if(d[i][n]<ans) ans=d[i][n],ansx=i,ansy=n;
//	cout<<ans<<endl;
	for(int i=n;i>=1;i--){
		if(prex[ansx][ansy]==ansx) bb[++bc]=i;
		else aa[++ac]=i;
		tmpx=prex[ansx][ansy],tmpy=prey[ansx][ansy];
//		cout<<ansx<<' '<<ansy<<' '<<prex[ansx][ansy]<<' '<<prey[ansx][ansy]<<endl;
		ansx=tmpx,ansy=tmpy;
	}
	for(int i=ac;i>=1;i--) cout<<a[aa[i]]<<' ';
	for(int i=1;i<=bc;i++) cout<<a[bb[i]]<<' ';
	cout<<endl;
	return 0;
}