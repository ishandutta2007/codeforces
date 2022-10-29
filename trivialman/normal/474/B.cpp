#include<cstdio>
#include<cstring>
#include<iostream>
#include<string>
using namespace std;
#define N 100010
#define MOD 998244353
#define LL long long
#define rep(i,a,b) for(int i=a;i<=b;++i)
#define CL(x) memset(x,0,sizeof(x))

int n,a[N],x,m;

int main(){
	cin>>n;
	CL(a);a[0]=0;
	rep(i,1,n){
		scanf("%d",&x);
		a[i]=a[i-1]+x;
	}
	cin>>m;
	rep(i,1,m){
		scanf("%d",&x);
		int l=1,r=n;
		while(l<r){
			int mid=(l+r)/2;
			if(x>a[mid])l=mid+1;
			else r=mid;
		}
		cout<<l<<endl;
	}
	return 0;
}