#include<bits/stdc++.h>
using namespace std;

const int N=305;
const int K=1005;
const int mo=1000000007;
int n,Q;
int a[N],d[N],e[N][N];
int M[N][N],V[N][N],SV[N][N];
int tr[N][N],VP[K][N],IVP[K][N];
int power(int x,int y){
	int s=1;
	for (;y;y/=2,x=1ll*x*x%mo)
		if (y&1) s=1ll*s*x%mo;
	return s;
}
void init(){
	for (int i=1;i<N;i++){
		VP[0][i]=1; VP[1][i]=i;
		IVP[0][i]=1; IVP[1][i]=power(i,mo-2);
		for (int j=2;j<K;j++){
			VP[j][i]=1ll*VP[j-1][i]*VP[1][i]%mo;
			IVP[j][i]=1ll*IVP[j-1][i]*IVP[1][i]%mo;
		}
	}
}

int t[N][K];
void change(int x,int y,int v){
	for (y++;y<K;y+=y&(-y))
		t[x][y]=(t[x][y]+v)%mo;
		//t[x][y]+=v;
}
int ask(int x,int y){
	long long s=0;
	for (y++;y;y-=y&(-y)) s+=t[x][y];
	return s%mo;
}
void Construct(){
	memset(t,0,sizeof(t));
	for (int i=n;i>=1;i--){
		d[i]=(a[i]>0?0:1ll<<30);
		for (int j=i+1;j<=n;j++)
			if (e[i][j]) d[i]=min(d[i],d[j]+1); 
	}
	for (int i=1;i<=n;i++)
		if (d[i]!=(1<<30))
			for (int j=1;j<=i;j++)
				change(j,d[i],1ll*a[i]*tr[i][j]%mo*IVP[d[i]][j]%mo);
}
int main(){
	init();
	scanf("%d",&n);
	for (int i=1;i<=n;i++)
		scanf("%d",&a[i]);
	for (int i=1;i<=n;i++){
		int x,y;
		scanf("%d",&x);
		while (x--){
			scanf("%d",&y);
			e[i][y]=1;
		}
	}
	for (int i=1;i<=n;i++){
		M[i][i]=i;
		for (int j=1;j<=n;j++)
			if (e[j][i]) M[i][j]=i;
	}
	for (int i=1;i<=n;i++){
		V[i][i]=1;
		for (int j=i-1;j>=1;j--){
			for (int k=j+1;k<=i;k++)
				V[i][j]=(V[i][j]+1ll*V[i][k]*M[k][j])%mo;
			V[i][j]=1ll*(mo-V[i][j])*power(mo+j-i,mo-2)%mo;
		}
		for (int j=1;j<=n;j++)
			SV[i][j]=(SV[i][j-1]+V[i][j])%mo;
	};
	for (int i=1;i<=n;i++){
		tr[i][i]=1;
		for (int j=i-1;j>=1;j--)
			for (int k=j+1;k<=i;k++)
				tr[i][j]=(tr[i][j]+mo-1ll*tr[i][k]*V[k][j]%mo)%mo;
	}
	//cout<<233<<endl;
	Construct();
	scanf("%d",&Q);
	while (Q--){
		int tp,x,y,z;
		scanf("%d%d%d",&tp,&x,&y);
		if (tp==1){
			int ans=0;
			scanf("%d",&z);
			for (int i=y;i<=z;i++)
				if (d[i]>x)	ans=(ans+1ll*mo+a[i])%mo;
			for (int i=1;i<=n;i++)
				ans=(ans+1ll*ask(i,x)*VP[x][i]%mo*(SV[i][z]+mo-SV[i][y-1]))%mo;
			printf("%d\n",(ans%mo+mo)%mo);
		}
		if (tp==2){
			bool fl=(a[x]<=0);
			a[x]+=y;
			if (fl&&a[x]>0) Construct();
			else{
				if (d[x]!=(1<<30))
					for (int i=1;i<=n;i++)
						change(i,d[x],1ll*y*tr[x][i]%mo*IVP[d[x]][i]%mo);
			}
		}
	}
}