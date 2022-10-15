#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;

const int maxn=10000000;
int s[maxn+7],a[maxn+7];
char v[maxn+7];
int n;

int main(){
	memset(a,0,sizeof(s));
	scanf("%d",&n);
	for (int i=1;i<=n;++i){
		scanf("%d",&a[i]);
	}
	scanf("%s",&v); 
	for (int i=1;i<n;++i){
		s[i]=s[i-1]+v[i-1]-'0';
	}
	for (int i=1;i<=n;++i){
		if (abs(a[i]-i)!=abs(s[a[i]-1]-s[i-1])){
			printf("NO");
			return 0;
		}
	}
	printf("YES");
	return 0;
}