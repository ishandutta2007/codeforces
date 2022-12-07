#include<bits/stdc++.h>
#define ll long long
#define ull unsigned long long
using namespace std;

const int N=200005;
int fl[N],pri[N];
void init(){
	for (int i=2;i<N;i++)
		for (int j=2;j*i<N;j++)
			fl[i*j]=1;
	for (int i=2;i<N;i++)
		if (!fl[i]) pri[++*pri]=i;
}
long long Query(int x,int y){
	printf("? %d %d\n",x,y);
	fflush(stdout);
	long long re;
	scanf("%lld",&re);
	return re;
}
int gcd(int x,int y){
	return y?gcd(y,x%y):x;
}
int Mxpri(long long v){
	int re=1;
	for (int i=1;1ll*pri[i]*pri[i]<=v;++i)
		if (v%pri[i]==0){
			for (;v%pri[i]==0;v/=pri[i]);
			re=max(re,pri[i]);
		}
	re=max(1ll*re,v);
	return re;
}
vector<int> Divi(long long v){
	vector<int> re;
	for (int i=1;1ll*pri[i]*pri[i]<=v;++i)
		for (;v%pri[i]==0;v/=pri[i])
			re.push_back(pri[i]);
	if (v!=1) re.push_back(v);
	return re;
}
int rnd(){
	int x=0;
	for (int i=1;i<=9;i++)
		x=x*10+rand()%10;
	return x;
}
int ans[N],n;
long long a[105][105],q[105][105];
/*
1 5 40 56 24 72 70 30 90 42 63 18
*/
void solve(){
	scanf("%d",&n);
	if (n<100){
		long long mx=0;
		memset(a,0,sizeof(a));
		for (int i=1;i<=n;i++)
			for (int j=i+1;j<=n;j++){
				a[i][j]=a[j][i]=Query(i,j);
				mx=max(mx,a[i][j]);
			}
		int l=1,r=N,m=0;
		while (l<=r){
			int mid=(l+r)/2;
			if (1ll*mid*(mid-1)>=mx)
				m=mid,r=mid-1;
			else l=mid+1;
		}
		//cout<<m<<' '<<mx<<endl;
		for (int i=0;i<n;i++){
			int t=0;
			for (int j=0;j<n;j++)
				if (i!=j) q[i][++t]=1ll*(m-i)*(m-j)/gcd(m-i,m-j);
			sort(q[i]+1,q[i]+n);
		}
		for (int i=1;i<=n;i++){
			sort(a[i]+1,a[i]+n+1);
			for (int j=0;j<n;j++){
				bool flag=0;
				for (int k=1;k<n;k++)
					if (a[i][k+1]!=q[j][k]) flag=1;
				if (!flag) ans[i]=m-j;
			}
		}
	}
	if (100<=n&&n<=10000){
		long long mxv=0,mxp=-1;
		for (int i=1;i+1<=n;i+=2){
			long long v=Query(i,i+1);
			long long pr=Mxpri(v);
			if (pr>mxv) mxv=pr,mxp=i;
		}
		if (Query(mxp,mxp==1?3:1)%mxv==0);
		else ++mxp;
		ans[mxp]=mxv;
		for (int i=1;i<=n;i++)
			if (i!=mxp) ans[i]=Query(mxp,i)/mxv;
	}
	if (n>10000){
		int x,y;
		vector<int> re;
		for (;;){
			x=rnd()%n+1;
			y=rnd()%n+1;
			for (;x==y;x=rnd()%n+1,y=rnd()%n+1);
			re=Divi(Query(x,y));
			if (re.size()==2&&re[0]>=500&&re[1]>=500) break;
		}
		for (int T=1;T<=50;T++){
			int p=rnd()%n+1;
			for (;p==x||p==y;p=rnd()%n+1);
			if (Query(x,p)%re[0]) swap(re[0],re[1]);
		}
		ans[x]=re[0];
		ans[y]=re[1];
		for (int i=1;i<=n;i++)
			if (i!=x&&i!=y){
				ans[i]=Query(x,i)/ans[x];
				if (1ll*ans[i]*ans[x]<N)
					ans[i]=Query(y,i)/ans[y];
			}
	}
	printf("! ");
	for (int i=1;i<=n;i++)
		printf("%d ",ans[i]);
	puts("");
	fflush(stdout);
}
int main(){
	init();
	int T;
	scanf("%d",&T);
	while (T--) solve();
}