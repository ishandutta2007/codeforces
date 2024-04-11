#include<cstdlib>
#include<cstdio>
#include<algorithm>
#define LL long long int 
#define maxn 200005
using namespace std;
LL a[maxn],b[maxn],d[maxn];
LL n,k;
int main(){
	/*freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);*/
	long long int sum=0;
	scanf("%I64d%I64d",&n,&k);
	for(int i=0;i<n;i++){
		scanf("%I64d",&a[i]);
	}
	for(int i=0;i<n;i++){
		scanf("%I64d",&b[i]);
	}
	for(int i=0;i<n;i++){
		d[i]=a[i]-b[i];
		sum+=b[i];
	}
	sort(d,d+n);
	LL cnt=0;
	while(d[cnt]<0){
		cnt++;
	}
	for(int i=0;i<max(k,cnt);i++){
		sum+=d[i];
	}
	printf("%I64d",sum);
	return 0;
}