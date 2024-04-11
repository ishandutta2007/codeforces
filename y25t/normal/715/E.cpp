#include<cstdio>
#include<algorithm>
#define N 255
#define P 998244353

int fmo(int x){
	return x+((x>>31)&P);
}

int n,p[N],q[N];

int C[N][N],S[N][N],fac[N];
inline void init(){
	for(int i=0;i<=n;i++)
		C[i][0]=1;
	for(int i=1;i<=n;i++)
		for(int j=1;j<=i;j++)
			C[i][j]=fmo(C[i-1][j]+C[i-1][j-1]-P);
	S[0][0]=1;
	for(int i=1;i<=n;i++)
		for(int j=1;j<=i;j++)
			S[i][j]=fmo(S[i-1][j-1]+1ll*(i-1)*S[i-1][j]%P-P);
	fac[0]=1;
	for(int i=1;i<=n;i++)
		fac[i]=1ll*fac[i-1]*i%P;
}

int s[N],t[N];
bool del[N];

int a,b,c,d;

int f[N],ff[N],g[N],gg[N],h[N];

int ans[N];

int main(){
	scanf("%d",&n);
	init();
	for(int i=1;i<=n;i++){
		scanf("%d",&p[i]);
		if(p[i])
			s[p[i]]=i;
	}
	for(int i=1;i<=n;i++){
		scanf("%d",&q[i]);
		if(q[i])
			t[q[i]]=i;
	}
	for(int i=1;i<=n;i++)
		if(t[i]&&s[i]){
			if(t[i]==s[i])
				d++;
			else{
				std::swap(q[t[i]],q[s[i]]);
				del[s[i]]=0;
				t[q[t[i]]]=t[i];
			}
		}
	for(int i=1;i<=n;i++)
		if(p[i]&&!q[i])
			a++;
		else if(!p[i]&&q[i])
			b++;
		else if(!p[i]&&!q[i])
			c++;
	for(int i=0;i<=a;i++)
		for(int j=i;j<=a;j++)
			ff[i]=fmo(ff[i]+1ll*C[a][j]*S[j][i]%P*C[a-j+c][a-j]%P*fac[a-j]%P-P);
	for(int i=0;i<=a;i++)
		for(int j=i;j<=a;j++)
			f[i]=fmo(f[i]+1ll*((i^j)&1?P-1:1)*C[j][i]%P*ff[j]%P-P);
	for(int i=0;i<=b;i++)
		for(int j=i;j<=b;j++)
			gg[i]=fmo(gg[i]+1ll*C[b][j]*S[j][i]%P*C[b-j+c][b-j]%P*fac[b-j]%P-P);
	for(int i=0;i<=b;i++)
		for(int j=i;j<=b;j++)
			g[i]=fmo(g[i]+1ll*((i^j)&1?P-1:1)*C[j][i]%P*gg[j]%P-P);
	for(int i=0;i<=c;i++)
		h[i]=1ll*S[c][i]*fac[c]%P;
	for(int i=0;i<=a;i++)
		for(int j=0;j<=b;j++)
			for(int k=0;k<=c;k++)
				ans[n-d-i-j-k]=fmo(ans[n-d-i-j-k]+1ll*f[i]*g[j]%P*h[k]%P-P);
//	printf("%d %d %d %d\n",a,b,c,d);
	for(int i=0;i<n;i++)
		printf("%d ",ans[i]);
	puts("");
}