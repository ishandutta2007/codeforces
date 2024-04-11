#include<bits/stdc++.h>
using namespace std;
const int N=1025;
int n,k,a[N],tot;
vector<int> v[N];
char s[2];
int ask(int x){
	printf("? %d\n",x);
	fflush(stdout);
	scanf("%s",s);
	if (s[0]=='N')return 1;
	return 0;
}
void R(){
	puts("R");
	fflush(stdout);
}
int main(){
	scanf("%d%d",&n,&k);
	if (k==1){
		for (int i=1;i<=n;i++)a[i]=1;
		for (int i=1;i<=n;i++)
			for (int j=i+1;j<=n;j++){
				ask(j);
				a[i]&=ask(i);
				R();
			}
		int ans=0;
		for (int i=1;i<=n;i++)ans+=a[i];
		printf("! %d\n",ans);
		fflush(stdout);
		return 0;
	}
	k/=2;
	for (int i=1;i<=n;i+=k<<1,tot+=2){
		for (int j=0;j<k<<1;j++)
			if (ask(i+j))
				if (j<k)a[i+j]=1,v[tot].push_back(i+j);
				else a[i+j]=1,v[tot+1].push_back(i+j);
		R();
	}
	for (int i=tot-2;i>=0;i--){
		for (int j=tot-1;j>i+1;j-=2){
			for (int k:v[j])if (a[k])ask(k);
			for (int k:v[i])if (a[k])a[k]&=ask(k);
			for (int k:v[j-1])if (a[k])a[k]&=ask(k);
			R();
		}
	}
	int ans=0;
	for (int i=1;i<=n;i++)ans+=a[i];
	printf("! %d\n",ans);
	fflush(stdout);
	return 0;
}