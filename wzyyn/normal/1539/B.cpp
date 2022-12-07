#include<bits/stdc++.h>
#define ll long long
using namespace std;

int a[100005];
char s[100005];
int main(){
	int n,Q;
	scanf("%d%d",&n,&Q);
	scanf("%s",s+1);
	for (int i=1;i<=n;i++)
		a[i]=a[i-1]+s[i]-'a'+1;
	while (Q--){
		int l,r;
		scanf("%d%d",&l,&r);
		printf("%d\n",a[r]-a[l-1]);
	}
}