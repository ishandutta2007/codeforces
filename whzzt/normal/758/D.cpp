#include "bits/stdc++.h"
using namespace std;
typedef unsigned long long ll;
ll n,ans,mul;char s[105];int l;
int main(){
	cin>>n;scanf("%s",s);
	l=strlen(s);int pos=l-1;mul=1;
	while(pos >= 0){
		int beg; ll c;
		for (int j=0; j<=pos; j++){
			if (pos - j >= 10) continue;
			c=0;
			for (int k=j; k<=pos; k++)
				c=c*10+s[k]-'0';
			if (c<n) {beg=j;break;}
		}
		while (beg<pos&&s[beg]=='0') beg++;
		ans += c*mul; mul*=n; pos=beg-1;
	}
	printf ("%I64d",ans);
	return 0;
}