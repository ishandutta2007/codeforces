#include<stdio.h>
#include<vector>
#include<iostream>
using namespace std;
const int maxn=55,maxs=1<<23;
int n,ans,tot,U;
int a[maxn][maxn],f[maxs],dsu[maxn];
unsigned long long res[maxs];
long long S[maxn],val[maxn],pos[maxn],sp[maxs],sv[maxs];
vector<int>v[maxn];
string s;
int find(int x){
	return dsu[x]==x? x:dsu[x]=find(dsu[x]);
}
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
		dsu[i]=i;
	for(int i=1;i<=n;i++){
		cin>>s;
		for(int j=1;j<=n;j++){
			a[i][j]=s[j-1]=='-'? 0:(s[j-1]=='A'? 1:(s[j-1]=='O'? 2:3));
			if(a[i][j]==1)
				dsu[find(i)]=find(j);
			if(a[i][j]==3)
				S[i]|=(1ll<<(j-1));
		}
	}
	for(int i=1;i<=n;i++)
		v[find(i)].push_back(i);
	for(int i=1;i<=n;i++)
		if(dsu[i]==i){
			if(v[i].size()==1)
				ans++;
			else{
				tot++;
				for(int j=0;j<v[i].size();j++)
					pos[tot]|=(1ll<<(v[i][j]-1)),val[tot]|=S[v[i][j]],ans++;
			}
		}
	if(tot==0){
		printf("%d\n",ans-1);
		return 0;
	}
	U=1<<tot;
	for(int i=1;i<U;i++){
		int j=i&-i,k=__builtin_ctz(j)+1;
		sp[i]=sp[i^j]|pos[k],sv[i]=sv[i^j]|val[k];
		if((sp[i]&sv[i])==0)
			f[i]=1;
	}
	for(int len=2;len<=U;len<<=1)
		for(int i=0,now=len/2;i<U;i+=len)
			for(int j=0;j<now;j++)
				f[i+j+now]+=f[i+j];
	for(int i=0;i<U;i++)
		res[i]=1;
	for(int k=1;k<=n;k++){
		unsigned long long hsh=0;
		for(int i=0;i<U;i++){
			res[i]*=f[i];
			if(__builtin_parity((U-1)^i))
				hsh-=res[i];
			else hsh+=res[i];
		}
		if(hsh>0){
			printf("%d\n",k+ans-1);
			return 0;
		}
	}
	puts("-1");
	return 0;
}