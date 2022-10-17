#include <vector>
#include <cstdio>
#include <cstring>
using namespace std;
const int MAXN=200005;

int n,ans,Head,Tail,nxt[MAXN];
char s[MAXN];
bool vis[MAXN];

int get_number(int x,int total){
	if (nxt[x]==x) return total;
	return get_number(nxt[x],total+1);
}

void get_each_number(int x){
	vis[x]=1;
	printf(" %d",x);
	if (nxt[x]==x){
		return;
	}
	get_each_number(nxt[x]);
}

int main(){
	scanf("%s",s+1);
	n=strlen(s+1);
	for (int i=1;i<=n;i++) nxt[i]=i;
	Head=1;
	for (int i=1;i<=n;i++){
		if (s[i]=='1'){
			while (s[Head]!='0'&&Head<i) Head++;
			if (Head!=i) nxt[Head++]=i;
			else{
				printf("-1\n");
				return 0;
			}
		}
	}
	Tail=n;
	for (int i=n;i>=1;i--){
		if (s[i]=='1'){
			while (s[Tail]!='0'&&Tail>i) Tail--;
			if (Tail!=i) nxt[i]=Tail--;
			else{
				printf("-1\n");
				return 0;
			}
		}
	}
	for (int i=1;i<=n;i++) if (nxt[i]==i) ans++;
	printf("%d\n",ans);
	for (int i=1;i<=n;i++){
		if (!vis[i]){
			printf("%d",get_number(i,1));
			get_each_number(i);
			putchar('\n');
		}
	}
	return 0;
}