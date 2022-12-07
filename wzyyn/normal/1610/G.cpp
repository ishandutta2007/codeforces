#include<bits/stdc++.h>

using namespace std;

const int N=300005;
const int mo1=1000000007;
const int mo2=1000000009;
int n,q[N],nx[N];
char s[N];

struct node{
	int v1,v2;
	int k1,k2;
	node(){}
	node(int x){
		v1=v2=x;
		k1=233; k2=117;
	}
	node(int _v1,int _v2,int _k1,int _k2){
		v1=_v1; v2=_v2;
		k1=_k1; k2=_k2;
	}
	node operator +(const node &a)const{
		node re;
		re.v1=(1ll*v1*a.k1+a.v1)%mo1;
		re.v2=(1ll*v2*a.k2+a.v2)%mo2;
		re.k1=1ll*k1*a.k1%mo1;
		re.k2=1ll*k2*a.k2%mo2;
		return re;
	}
	bool operator ==(const node &a)const{
		return v1==a.v1&&v2==a.v2&&k1==a.k1&&k2==a.k2;
	}
};
node hsh[N][20];
int nxp[N][20];
int nxc[N],tag[N];

int cmp(int x,int y){
	if (hsh[x][19]==hsh[y][19])
		return 0;
	for (int i=18;i>=0;i--)
		if (hsh[x][i]==hsh[y][i]){
			x=nxp[x][i];
			y=nxp[y][i];
		}
	return nxc[x]<nxc[y]?-1:1;
}
int main(){
	scanf("%s",s+1);
	n=strlen(s+1);
	int t=0;
	q[t]=n+1;
	for (int i=n;i>=1;i--)
		if (s[i]==')')
			q[++t]=i,nx[i]=-1;
		else{
			if (t) nx[i]=q[--t];
			else nx[i]=-1;
			q[t]=i;
		}
	nxc[n+1]=0;
	nxp[n+1][0]=n+1;
	hsh[n+1][0]=node(0);
	for (int i=1;i<=19;i++){
		nxp[n+1][i]=n+1;
		hsh[n+1][i]=hsh[n+1][i-1]+hsh[n+1][i-1];
	}
	for (int i=n;i>=1;i--){
		nxp[i][0]=i+1; nxc[i]=s[i];
		hsh[i][0]=node(s[i]);
		for (int j=1;j<=19;j++){
			nxp[i][j]=nxp[nxp[i][j-1]][j-1];
			hsh[i][j]=hsh[i][j-1]+hsh[nxp[i][j-1]][j-1];
		}
		if (nx[i]!=-1){
			if (cmp(nx[i],i)==-1){
				tag[i]=1;
				nxc[i]=nxc[nx[i]];
				for (int j=0;j<=19;j++){
					nxp[i][j]=nxp[nx[i]][j];
					hsh[i][j]=hsh[nx[i]][j];
				}
			}
		}
	}
	int p=1;
	for (;p!=n+1;)
		if (tag[p]) p=nx[p];
		else putchar(s[p++]);
}