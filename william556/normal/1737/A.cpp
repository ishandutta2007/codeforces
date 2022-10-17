#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
inline int in(){
	int x;
	scanf("%d",&x);
	return x;
}
const int N=1005;
int n,k;
char s[N];
int cnt[26];
void solve(){
	n=in(),k=in();
	scanf("%s",s+1);
	for(int i=0;i<26;i++)cnt[i]=0;
	for(int i=1;i<=n;i++)cnt[s[i]-'a']++;
	for(int i=1;i<=k;i++){
		int m=min(n/k-1,24);
		for(int j=0;j<=m;j++){
			if(!cnt[j]){
				putchar('a'+j);break;
			}else{
				cnt[j]--;	
			}
			if(j==m)putchar('a'+m+1);
		}
		
	}puts("");
}
int main(){
//	freopen("A.in","r",stdin);
//	freopen("A.out","w",stdout);
	int t=in();
	while(t--)solve(); 
	return 0;
}