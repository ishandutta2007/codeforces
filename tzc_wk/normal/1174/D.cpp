#include <bits/stdc++.h>
using namespace std;
int n,x;
bool mark[1<<18+4];
int pre[1<<18+4];
vector<int> s,a;
int rev(int a,int b){
	int A[18]={0},B[18]={0},C[18]={0},ans=0;
	for(int i=0;i<n;i++){
		A[i]=a>>(n-i-1)&1;
		B[i]=b>>(n-i-1)&1;
		for(int j=0;j<2;j++)	if(A[i]^j==B[i])	C[i]=j;
		ans+=C[i]*(1<<(n-i-1));
	}
	return ans;
}
int main(){
	scanf("%d%d",&n,&x);
	for(int i=0;i<1<<n;i++)	pre[i]=i^x;
	for(int i=0;i<1<<n;i++){
		if(i!=0&&i!=x){
			if(!mark[i]){
				mark[i]=1;
				s.push_back(i);
				mark[pre[i]]=1;
			}
		}
	}
	for(int i=0;i<s.size();i++){
		if(i==0)	a.push_back(s[i]);
		else		a.push_back(rev(s[i-1],s[i]));
	}
	printf("%d\n",a.size());
	for(int i=0;i<a.size();i++){
		printf("%d ",a[i]);
	}
}