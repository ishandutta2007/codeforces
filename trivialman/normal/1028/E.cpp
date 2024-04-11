#include<cstdio>
#include<cstring>
#include<iostream>
using namespace std;
#define N 200010
#define LL long long

int n,m,k;
LL b[N],res[N];

int main(){
	scanf("%d",&n);
	
	int start=n+1;
	LL sum=0; 
	for(int i=0;i<n;i++){
		scanf("%d",&b[i]);
		if ((i>0)&&(b[i]>b[i-1]))start=i;
		sum+=b[i];
	}
	if(b[0]>b[n-1])start=0;
	if(start==n+1){
		if(b[0]>0){
			cout<<"NO"<<endl;
			return 0;
		}
		cout<<"YES"<<endl;
		for(int i=0;i<n;i++)printf("1 ");
		return 0;
	}else if(n<=2){
		cout<<"NO"<<endl;
		return 0;
	}
	
	res[start]=b[start];
	int i=start-1;
	if(i==-1)i+=n;
	res[i]=(sum/res[start]+1)*res[start]+b[i];
	while(true){
		i--;
		if(i==-1)i+=n;
		if(i==start)break;
		res[i]=res[(i+1)%n]+b[i];
	}
	cout<<"YES"<<endl;
	for(int i=0;i<n;i++){
		printf("%lld ",res[i]);
	}
	return 0;
}