#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;

const int maxn=3000007;

int a[maxn],b[maxn],n;
int u[maxn*5],v[maxn*5],cnt=0;
void swap1(int i,int j){
	u[cnt]=i;
	v[cnt++]=j;
	int tmp=a[i];
	a[i]=a[j];
	a[j]=tmp;
	b[a[i]]=i;
	b[a[j]]=j;
}

int main(){
	scanf("%d",&n);
	for (int i=1;i<=n;++i){
		scanf("%d",&a[i]);
		b[a[i]]=i;
	}
	for (int i=1;i<=n/2;++i){
		if (b[i]<=n/2){
			swap1(b[i],n);
			swap1(n,i);
		}
		else{
			if (b[i]==n){
				swap1(n,i);
			}
			else{
				int tmp=b[i];
				swap1(b[i],1);
				swap1(1,n);
				swap1(1,tmp);
				swap1(n,i);
			}
		}
		if (b[i+n/2]>n/2){
			if (b[i+n/2]==i+n/2){
				continue;
			}
			int tmp=b[i+n/2];
			swap1(b[i+n/2],1);
			swap1(i+n/2,1);
			swap1(1,tmp);
		}
		else{
			int tmp=b[i+n/2];
			swap1(tmp,n);
			swap1(n,1);
			swap1(1,i+n/2);
			swap1(1,n);
		}
	}
	printf("%d\n",cnt);
	for (int i=0;i<cnt;++i){
		printf("%d %d\n",u[i],v[i]);
	}
	return 0;
}