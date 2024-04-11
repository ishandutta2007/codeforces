#include<cstdio>
#include<cstring>
#include<iostream>
#include<string>
using namespace std;
#define N 200010
#define MOD 998244353
#define LL long long
#define rep(i,a,b) for(int i=a;i<=b;++i)
#define CL(x) memset(x,0,sizeof(x))

LL n,a[N],ans[N],res=0;
LL sum0=0;

int main(){
	scanf("%d",&n);
	rep(i,1,n)scanf("%d",&a[i]);
	LL max1=0,max2=0;
	rep(i,1,n){
		if(a[i]>=max1){
			max2=max1;max1=a[i];
		}else if(a[i]>=max2){
			max2=a[i];
		}
		sum0+=a[i];
	}
	LL poss1=sum0-max1-max1;
	if(poss1!=max1||max1==max2){
		rep(i,1,n){
			if(a[i]==poss1&&(a[i]!=max1||max1==max2)){
				++res;ans[res]=i;
			}
		}
	}
	//cout<<poss1<<endl;
	if(max1!=max2&&sum0==max1+max2+max2){
		rep(i,1,n){
			if(a[i]==max1)ans[++res]=i;
		}
	}
	cout<<res<<endl;
	rep(i,1,res)cout<<ans[i]<<" ";
	cout<<endl;
	return 0;
}