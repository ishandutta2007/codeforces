#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
inline int in(){
	int x;
	scanf("%d",&x);
	return x;
}
const int N=105;
int n,m;
char a[N],b[N];
void solve(){
	scanf("%d%d",&n,&m);
	scanf("%s",a+1);
	scanf("%s",b+1);
	for(int i=1;i<m;i++)if(a[n-i+1]!=b[m-i+1]){
		puts("NO");
		return;	
	}
	int f[2];f[0]=f[1]=0;
	for(int i=n-m+1;i>=1;i--)f[a[i]-'0']=1;
	if(!f[b[1]-'0'])puts("NO");
	else puts("YES");
}
int main(){
	int t=in();
	while(t--)solve(); 
	return 0;
}