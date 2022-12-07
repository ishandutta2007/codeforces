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
const int N=(1<<20)+5;
int n,m;
char s[55][25];
ll B[N];
double f[N];
int cnt[N],sum[N];
int main(){
	scanf("%d",&n);
	For(i,1,n) scanf("%s",s[i]);
	m=strlen(s[1]);
	For(i,1,n) For(j,i+1,n){
		int S=0;
		For(k,0,m-1)
			if (s[i][k]==s[j][k])
				S|=1<<k;
		B[S]|=(1ll<<i)|(1ll<<j);
	}
	For(i,0,m-1) For(j,0,(1<<m)-1)
		if (j&(1<<i)) B[j^(1<<i)]|=B[j];
	For(i,0,(1<<m)-1){
		cnt[i]=cnt[i/2]+(i&1);
		For(j,1,n) if (B[i]&(1ll<<j)) sum[i]++;
		sum[i]=n-sum[i];
	}
	f[(1<<m)-1]=0;
	Rep(i,(1<<m)-2,0){
		int S1=0;
		For(j,0,m-1)
			if (i&(1<<j));
			else{
				f[i]+=f[i|(1<<j)];
				f[i]+=(cnt[i]+1)*(sum[i|(1<<j)]-sum[i]);
				S1++;
			}
		f[i]/=S1;
		//cout<<sum[i]<<' '<<cnt[i]<<' '<<f[i]<<' '<<i<<endl;
	}
	printf("%.10lf\n",f[0]/n);
}