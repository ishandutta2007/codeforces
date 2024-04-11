#include <bits/stdc++.h>
using namespace std;
template <typename T> void read(T &t) {
	t=0; char ch=getchar(); int f=1;
	while ('0'>ch||ch>'9') { if (ch=='-') f=-1; ch=getchar(); }
	do {(t*=10)+=ch-'0';ch=getchar();} while ('0'<=ch&&ch<='9'); t*=f;
}
typedef long long ll;
const int maxn=(1e6)+10;
int n,len,cnt[30],tmp;
char s[maxn];
ll ans;
map<int,int> m;
int main() {
	//freopen("1.txt","r",stdin);
	read(n);
    for (int i=1;i<=n;i++) {
    	scanf("%s",s+1);
    	len=strlen(s+1);
    	memset(cnt,0,sizeof(cnt));
    	for (int j=1;j<=len;j++) cnt[s[j]-'a'+1]++;
    	tmp=0;
    	for (int j=1;j<=26;j++)
    		tmp+=(cnt[j]%2)*(1<<(j-1));
    	ans+=m[tmp];
    	for (int j=1;j<=26;j++)
    		ans+=m[tmp^(1<<(j-1))];
    	m[tmp]++;
    }
    printf("%lld\n",ans);
    return 0;
}