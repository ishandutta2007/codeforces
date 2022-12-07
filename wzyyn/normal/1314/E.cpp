#include<bits/stdc++.h>
#define ll long long
#define ull unsigned ll
#define uint unsigned
#define pii pair<int,int>
#define pll pair<ll,ll>
#define IT iterator
#define PB push_back
#define fi first
#define se second
#define For(i,j,k) for (int i=(int)(j);i<=(int)(k);i++)
#define Rep(i,j,k) for (int i=(int)(j);i>=(int)(k);i--)
#define CLR(a,v) memset(a,v,sizeof(a));
#define CPY(a,b) memcpy(a,b,sizeof(a));
#define debug puts("wzpakking")
#define y1 ysghysgsygsh
using namespace std;
const int mo=998244353;
const int N=2050;
int n,k,ans;
int Sum(vector<int> x){
	int sum=0;
	for (auto i:x) sum+=i;
	return sum;
}
vector<int> work(vector<int> a){
	vector<int> ans;
	reverse(a.begin(),a.end());
	int p=0;
	for (auto i:a){
		++p;
		For(j,1,i) ans.PB(p);
	}
	return ans;
}
bool dfs(vector<int> tmp,int x){
	int p=0,sum=0;
	if (tmp.size()){
		vector<int> v=tmp;
		For(i,1,k-2){
			if (Sum(v)>n) return 0;
			v=work(v);
		}
		reverse(v.begin(),v.end());
		for (auto i:v) sum+=(++p)*i;
		if (sum>n) return 0;
		++ans;
	}
	For(i,x,70) if (sum+i*(i+1)/2<=n){
		vector<int> v=tmp; v.PB(i);
		if (!dfs(v,i)) break;
	}
	return 1;
}
int main(){
	scanf("%d%d",&n,&k);
	if (k>=10) return puts("1"),0;
	if (k==1){
		static int f[N];
		For(i,0,n-1) f[i]=1;
		For(i,1,n) For(j,i,n)
			f[j]=(f[j]+f[j-i])%mo;
		printf("%d\n",f[n]);
		exit(0);
	}
	if (k==2){
		static int f[75][N];
		For(i,0,n-1) f[0][i]=1;
		Rep(i,n,1) For(j,1,70) For(k,0,n-i*j)
			f[j][k+i*j]=(f[j][k+i*j]+f[j-1][k])%mo;
		int ans=0;
		For(i,1,70) ans=(ans+f[i][n])%mo;
		printf("%d\n",ans);
		exit(0);
	}
	vector<int> tmp;
	dfs(tmp,1);
	printf("%d\n",ans);
}
/*
v1 v2 v3 v4
v1*1 v2*2 v3*3 v4*4  
*/