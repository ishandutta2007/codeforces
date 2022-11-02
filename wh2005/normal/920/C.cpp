#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <ctime>
#include <cstring>
#include <string>
#include <algorithm>
#include <iomanip>
#include <iostream>
#include <vector>
using namespace std;
#define ls(x) x<<1
#define rs(x) x<<1|1
int n,a[200009],pos[200009];
char s[200009];
int sum[200009];
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++) scanf("%d",&a[i]),pos[a[i]]=i;
	scanf("%s",s);
	memset(sum,0,sizeof(sum));
	for(int i=1;i<=n;i++) if(s[i-1]=='1') sum[i]=1;
	for(int i=1;i<=n;i++) sum[i]+=sum[i-1];
	for(int i=1;i<=n;i++){
		int a=pos[i],b=i;
		if(a>b) swap(a,b);
		int p=sum[b-1]-sum[a-1];
		if(p!=b-a){
			printf("NO\n");
			return 0;
		}
	}
	printf("YES\n");
	return 0;
}