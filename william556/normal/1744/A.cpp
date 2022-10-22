// LUOGU_RID: 90774453
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
inline int in(){
	int x;
	scanf("%d",&x);
	return x;
}
const int N=105;
int n,a[N];
char s[N],to[N];
void solve(){
	n=in();
	for(int i=1;i<=n;i++)a[i]=in(),to[a[i]]=0;
	scanf("%s",s+1);
	for(int i=1;i<=n;i++){
		if(!to[a[i]])to[a[i]]=s[i];
		if(s[i]!=to[a[i]]){
			puts("NO");
			return;	
		}
	}
	puts("YES");;
}
int main(){
	int t=in();
	while(t--)solve();
	return 0;
}