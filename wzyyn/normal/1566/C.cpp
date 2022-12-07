#include<bits/stdc++.h>

using namespace std;

const int N=100005;
int n;
char s1[N];
char s2[N];
int f[N];
void solve(){
	scanf("%d",&n);
	scanf("%s",s1+1);
	scanf("%s",s2+1); 
	int p0=-1,p1=-1;
	for (int i=1;i<=n;i++){
		s1[i]=='1'?p1=i:p0=i;
		s2[i]=='1'?p1=i:p0=i;
		f[i]=f[i-1];
		if (p0!=-1) f[i]=max(f[i],f[p0-1]+1);
		if (p0!=-1&&p1!=-1) f[i]=max(f[i],f[min(p0,p1)-1]+2);
	}
	cout<<f[n]<<endl;
}
int main(){
	int T;
	scanf("%d",&T);
	while (T--) solve();
}