#include<cstdio>
#include<cstring>
const int N=300005;
typedef long long ll;
int n,mx=0;char s[N];ll ans;
int main(){
	scanf("%s",s+1);n=strlen(s+1);
	for(int i=1;i<=n;++i){
		for(int j=1;i-j*2>mx;++j){
			if(i-j>0&&i-j*2>0&&i-j*2>mx&&s[i]==s[i-j]&&s[i-j]==s[i-2*j]){
				mx=i-j*2;
				break;
			}
		}
		ans+=mx;
	}
	printf("%I64d\n",ans);
	return 0;
}