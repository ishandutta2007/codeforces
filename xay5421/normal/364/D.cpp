#include<set>
#include<cstdio>
#include<cstdlib>
#include<algorithm>
#define int long long
#define rep(i,a,b) for(int i=(a);i<=(b);++i) 
#define per(i,a,b) for(int i=(a);i>=(b);--i)
const int N=1000005;
int n,ans,a[N],d[N],tot[N],sum[N];std::set<int>s;
int brand(){return (rand()<<16)+(rand()<<1)+rand();}
int gcd(int a,int b){while(a^=b^=a^=b%=a,a);return b;}
void calc(int pos){
	*d=0;
	for(int i=1;i*i<=a[pos];++i)if(a[pos]%i==0){d[++*d]=i;if(i*i!=a[pos])d[++*d]=a[pos]/i;}
	std::sort(d+1,d+1+*d);rep(i,1,*d)tot[i]=sum[i]=0;
	rep(i,1,n){
		++tot[std::lower_bound(d+1,d+1+*d,gcd(a[i],a[pos]))-d];
	}
	rep(i,1,*d){
		if(d[i]<=ans)continue;
		rep(j,1,*d)if(d[j]%d[i]==0)sum[i]+=tot[j];
	}
	per(i,*d,1){
		if(d[i]<=ans)break;
		if(sum[i]*2>=n){ans=d[i];break;}
	}
}
signed main(){
	srand(19260817);
	scanf("%I64d",&n);
	rep(i,1,n)scanf("%I64d",a+i);
	for(int i=1,j=1;i<=(n<<1)&&j<=10;++i,++j){
		int pos=brand()%n+1;
		if(s.count(a[pos])){--j;continue;}
		calc(pos),s.insert(a[pos]);
	}
	printf("%I64d\n",ans);
	return 0;
}