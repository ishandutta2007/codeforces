#include<iostream>
#include<algorithm>
#include<cmath>
#include<cstring>
using namespace std;

const int maxn=1000007;

struct arr{
	int k,p;
	friend bool operator<(arr x,arr y){
		return x.k<y.k;
	}
}a[maxn];

int n,M;
int b[maxn];

bool check(int k){
	int j=0;
	for (int i=1;i<=n;++i){
		if (i==k) continue;
		b[++j]=a[i].k;
	}
	sort(b+1,b+n);
	if (n==2) return true;
	int t=b[2]-b[1];
	for (int i=1;i<n-1;++i){
		if (b[i+1]-b[i]!=t) return false;
	} 
	return true;
}

int main(){
	scanf("%d",&n);
	if (n==1){
		printf("%d\n",1);
		return 0;
	}
	for (int i=1;i<=n;++i){
		scanf("%d",&a[i].k);
		a[i].p=i;
	}
	sort(a+1,a+n+1);
	if (check(1)){
		printf("%d",a[1].p);
		return 0;
	}
	if (check(2)){
		printf("%d",a[2].p);
		return 0;
	}
	int k=a[2].k-a[1].k,u=-1;
	for (int i=1;i<n;++i){
		if (a[i+1].k-a[i].k!=k){
			if (u!=-1){
				printf("-1");
				return 0;
			}
			if (i+2<=n&&a[i+2].k-a[i].k!=k){
				printf("-1");
				return 0;
			}
			u=a[i+1].p;
			i++;
		}
	}
	printf("%d\n",max(1,u));
	return 0;
}