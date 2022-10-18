#include<bits/stdc++.h>
#define ll long long
#define pii std::pair<int,int>
#define fr first
#define sc second
#define N 1000005

inline void chk(pii &x,pii y){
	x=std::min(x,y);
}

int n;
ll a[3][N];

int pre[3][N],nxt[3][N];

pii f[2][N];

int main(){
	scanf("%d",&n);
	for(int o=0;o<3;o++){
		for(int i=1;i<=n;i++)
			if(o==2)
				a[o][i]=a[0][i]+a[1][i];
			else
				scanf("%lld",&a[o][i]),a[o][i]+=a[o][i-1];
		std::unordered_map<ll,int> mp;
		mp.reserve(n);
		pre[o][0]=-1;
		for(int i=1;i<=n;i++){
			mp[a[o][i-1]]=i-1;
			pre[o][i]=std::max(pre[o][i-1],mp.count(a[o][i])?mp[a[o][i]]:-1);
		}
		mp.clear(),mp.reserve(n);
		nxt[o][n]=n+1;
		for(int i=n-1;~i;i--){
			mp[a[o][i+1]]=i+1;
			nxt[o][i]=std::min(nxt[o][i+1],mp.count(a[o][i])?mp[a[o][i]]:n+1);
		}
	}
	for(int i=0;i<=n;i++){
		chk(f[0][i],pii(f[1][i].fr,i)),chk(f[1][i],pii(f[0][i].fr,i));
		if(i==n)
			break;
		for(int o=0;o<2;o++){
			chk(f[o][i+1],f[o][i]);
			int j=f[o][i].sc,x=nxt[o][i],y=nxt[o^1][j];
			if(x<y)
				chk(f[o][x],pii(f[o][i].fr-1,j));
			else if(y<x)
				chk(f[o^1][y],pii(f[o][i].fr-1,i));
			else{
				chk(f[o][x],pii(f[o][i].fr-2,y));
				chk(f[o^1][y],pii(f[o][i].fr-2,x));
			}
			chk(f[o][nxt[2][i]],pii(f[o][i].fr-1,nxt[2][i]));
		}
	}
	printf("%d\n",-f[0][n].fr);
}