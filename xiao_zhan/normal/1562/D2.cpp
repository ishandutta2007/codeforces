#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define N 600005
int i,j,k,t,n,m,f[300500],q,l,r;
char s[300500],c;
set<int> st[2005000];

int main(){
	ios::sync_with_stdio(0);
	scanf("%d",&t);
	while(t--){
		scanf("%d%d",&n,&q);
		for(i=1;i<=n;i++){
			c=getchar();
			if(c=='+'||c=='-'){s[i]=c;}
			else{i--;}
		}
		for(i=1;i<=n;i++){
			if(i&1){
				if(s[i]=='+'){f[i]=f[i-1]+1;}
				else{f[i]=f[i-1]-1;}
			}
			else{
				if(s[i]=='+'){f[i]=f[i-1]-1;}
				else{f[i]=f[i-1]+1;}
			}
		}
		for(i=1;i<=n;i++){
			st[N+f[i]+f[i-1]].insert(i);
		}
		while(q--){
			scanf("%d%d",&l,&r);
			if((r-l+1)&1){
				puts("1");
				k=*st[N+f[r]+f[l-1]].lower_bound(l);
				printf("%d\n",k);
				continue;
			}
			else{
				if(f[r]==f[l-1]){
					puts("0");
					continue;
				}
				else{
					puts("2");
					printf("%d ",r);r--;
					k=*st[N+f[r]+f[l-1]].lower_bound(l);
					printf("%d\n",k);
					continue;
				}
			}
		}
		for(i=1;i<=n;i++){
			st[N+f[i]+f[i-1]].clear();
		}
	}
}