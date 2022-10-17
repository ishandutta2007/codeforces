#include <cstdio>
using namespace std;
const int MAXN=100005;
int n,m,cnt,fa[256]; char sa[MAXN],sb[MAXN];
bool vis[256];
inline int getfa(int x){return fa[x]==x?x:fa[x]=getfa(fa[x]);}
int main(){
	for (int i='a';i<='z';i++) fa[i]=i;
	scanf("%d",&n);
	scanf("%s%s",sa,sb);
	for (int i=0;i<n;i++)
	if (sa[i]^sb[i]) fa[getfa(sa[i])]=getfa(sb[i]);
	for (int i='a';i<='z';i++) if (getfa(i)!=i) cnt++;
	printf("%d\n",cnt);
	for (int i='a';i<='z';i++) if (getfa(i)!=i) printf("%c %c\n",i,fa[i]);
	return 0;
}