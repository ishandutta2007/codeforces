#include<bits/stdc++.h>
using namespace std;
int main(){
	int n,k;
	scanf("%i%i",&n,&k);
	char a[n];
	scanf("%s",&a);
	int cnt[27];
	for(int i=0;i<27;i++)cnt[i]=0;
	for(int i=0;i<n;i++)cnt[(int)(a[i]-'a')]++;
	bool ok=1;
	for(int i=0;i<27;i++)if(cnt[i]>k)ok=0;
	if(ok)printf("YES");
	else printf("NO");
}