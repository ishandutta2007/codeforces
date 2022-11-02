#include <bits/stdc++.h>
using namespace std;
typedef long long lli;
typedef pair<int,int> ip;

int q,n;
lli s,cur;
char str[100100];

int main() {
	scanf("%lld%d",&s,&q);
	while(q--) {
		scanf("%lld",&cur);
		scanf("%s",str);
		n=strlen(str);
		for(int i=0;i<n;i++) {
			lli t=1;
			while(cur%(t<<1)==0) t<<=1;
			
			if(str[i]=='U') {
				if((t<<1)>s) continue;
				cur^=t;
				cur|=(t<<1);
			}
			else if(str[i]=='L') {
				if(t==1) continue;
				cur^=t;
				cur|=(t>>1);
			}
			else {
				if(t==1) continue;
				cur|=(t>>1);
			}
		}
		printf("%lld\n",cur);
	}
	return 0;
}