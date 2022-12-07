#include<bits/stdc++.h>
using namespace std;

const int N=10005;
const int M=100005;
const int mo=1000000007;
int n,c[N],S[N],f[N],X;
int q[M],id[M],ans[M],Q;
bool cmp(int x,int y){
	return q[x]<=q[y];
}
int Calc(int X){
	memset(f,0,sizeof(f)); 
	f[0]=1;
	for (int i=1;i<=n;i++){
		for (int j=1;j<N;j++)
			f[j]=(f[j]+f[j-1])%mo;
		for (int j=N-1;j>=c[i]+1;j--)
			f[j]=(f[j]+mo-f[j-c[i]-1])%mo; 
		int s=i*X+S[i];
		for (int j=0;j<N&&j<s;j++)
			f[j]=0;
	}
	int ans=0;
	for (int j=0;j<N;j++)
		ans=(ans+f[j])%mo;
	return ans;
}
int main(){
	scanf("%d",&n);
	for (int i=1;i<=n;i++)
		scanf("%d",&c[i]);
	for (int i=1;i<n;i++)
		scanf("%d",&S[i+1]);
	for (int i=1;i<=n;i++)
		S[i]+=S[i-1];
	for (int i=1;i<=n;i++)
		S[i]+=S[i-1];
	scanf("%d",&Q);
	for (int i=1;i<=Q;i++){
		scanf("%d",&q[i]);
		id[i]=i;
	}
	sort(id+1,id+Q+1,cmp);
	ans[id[1]]=Calc(q[id[1]]);
	for (int i=2;i<=Q;i++)
		if (q[id[i]]==q[id[i-1]])
			ans[id[i]]=ans[id[i-1]];
		else if (n*q[id[i]]+S[n]<0)
			ans[id[i]]=ans[id[i-1]];
		else if (n*q[id[i]]+S[n]>n*100)
			ans[id[i]]=0;
		else ans[id[i]]=Calc(q[id[i]]);
	for (int i=1;i<=Q;i++)
		printf("%d\n",ans[i]);
}