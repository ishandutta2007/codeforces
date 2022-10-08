#include<bits/stdc++.h>

using namespace std;

const int N=305,P=1E9+7;
typedef long long ll;
int n,a[N],ans,c[N<<1][N<<1],b[N],m,f[N][N],s,fac[N];
map<int,int> dat;

int main(){
	scanf("%d",&n);
	fac[0]=1;
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
		for(int w=2;w*w<=a[i];w++)while(a[i]%(w*w)==0)a[i]/=w*w;
		dat[a[i]]++;
		fac[i]=(ll)fac[i-1]*i%P;
	}
	for(int i=0;i<=2*n;i++)for(int j=c[i][0]=1;j<=i;j++){
		c[i][j]=(c[i-1][j-1]+c[i-1][j])%P;
	}
	for(auto it:dat)b[++m]=it.second;
	f[0][0]=ans=1;
	for(int i=0;i<m;i++){
		for(int j=0;j<=n;j++)if(f[i][j]){
			for(int k=1;k<=b[i+1];k++){
				for(int l=0,lm=min(j,k);l<=lm;l++){
					f[i+1][j+b[i+1]-k-l]=(f[i+1][j+b[i+1]-k-l]+
					(ll)f[i][j]*c[j][l]%P*c[s+1-j][k-l]%P*c[b[i+1]-1][k-1]%P)%P;
				}
			}
		}
		s+=b[i+1];
		ans=(ll)ans*fac[b[i+1]]%P;
	}
	ans=(ll)ans*f[m][0]%P;
	printf("%d\n",ans);
	return 0;
}