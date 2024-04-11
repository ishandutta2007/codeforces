#include<bits/stdc++.h>
using namespace std;
const int N=200005;
int T,n;
char s[N],a[N],b[N];
int main(){
	scanf("%d",&T);
	while (T--){
		scanf("%d",&n);
		scanf("%s",s+1);
		int cnt=0;
		for (int i=1;i<=n;i++)
			if (s[i]=='1')cnt++;
		if (cnt%2!=0||s[1]!='1'||s[n]!='1'){
			puts("NO");
			continue;
		}
		int flag=0;cnt/=2;
		for (int i=1;i<=n;i++)
			if (s[i]=='1'){
				if (cnt>0){
					a[i]=b[i]='(';
					cnt--;
				}
				else a[i]=b[i]=')';
			}
			else {
				if (flag){
					a[i]=')';
					b[i]='(';
				}
				else {
					a[i]='(';
					b[i]=')';
				}
				flag^=1;
			}
		a[n+1]=b[n+1]=0;
		puts("YES");
		puts(a+1);
		puts(b+1);
	}
}