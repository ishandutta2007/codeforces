#include<bits/stdc++.h>
using namespace std;

const int N=305;
const int mo=998244353;
vector<int> e[N];
int n,C;
int f[N][N*2];

void Merge(int* f,int* g){
	static int S1[N*2],S2[N*2];
	static int p1[N*2],p2[N*2];
	for (int i=0;i<=C*2+1;i++) S1[i]=f[i],f[i]=0;
	for (int i=1;i<=C*2+1;i++) S2[i]=g[i-1];
	p1[0]=S1[0]; p2[0]=S2[0];
	for (int i=1;i<=C*2+1;i++){
		p1[i]=(p1[i-1]+S1[i])%mo;
		p2[i]=(p2[i-1]+S2[i])%mo;
	}
	
	for (int i=0;i<=C;i++){
		f[i]=(f[i]+1ll*S1[i]*S2[i])%mo;
		f[i]=(f[i]+1ll*S1[i]*(p2[2*C+1-i]+mo-p2[i]))%mo;
		f[i]=(f[i]+1ll*S2[i]*(p1[2*C+1-i]+mo-p1[i]))%mo;
		/*i+j<=C*2+1 min(i,j)*/
	}
	for (int i=C+1;i<=2*C;i++){
		f[i]=(f[i]+1ll*S1[i]*S2[i])%mo;
		f[i]=(f[i]+1ll*S1[i]*(p2[i-1]+mo-p2[2*C+1-i]))%mo;
		f[i]=(f[i]+1ll*S2[i]*(p1[i-1]+mo-p1[2*C+1-i]))%mo;
		/*i+j>=C*2+2 max(i,j)*/
	}
}
void dfs(int x,int fa){
	for (auto i:e[x])
		if (i!=fa) dfs(i,x);
	
	f[x][C+1]=1;
	f[x][0]=1;
	for (auto i:e[x])
		if (i!=fa)
			Merge(f[x],f[i]);
	
}
int Calc(){
	memset(f,0,sizeof(f));
	dfs(1,0);
	int s=0;
	for (int i=0;i<=C;i++)
		s=(s+f[1][i])%mo;
	return s;
}
int main(){
	scanf("%d",&n);
	for (int i=1;i<n;i++){
		int x,y;
		scanf("%d%d",&x,&y);
		e[x].push_back(y);
	}
	int ans=n-1;
	for (C=1;C<n;C++){
		int val=Calc();
		//cout<<"DEBUG "<<val<<' '<<C<<endl;
		for (int j=1;j<=n;j++)
			val=1ll*val*(mo+1)/2%mo;
		ans=(ans+mo-val)%mo;
	}
	cout<<ans<<endl;
}

/*
f[i][j]:ij
if[i][300]
j
*/