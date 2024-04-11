#include <bits/stdc++.h>
using namespace std;
template <typename T> void read(T &t) {
	t=0; char ch=getchar(); int f=1;
	while ('0'>ch||ch>'9') { if (ch=='-') f=-1; ch=getchar(); }
	do { (t*=10)+=ch-'0';ch=getchar(); } while ('0'<=ch&&ch<='9'); t*=f;
}
const int maxn=(1e6)+10;
int n,a[maxn],b[maxn],d[maxn*2],tot,mx;
pair<int,int> c[maxn*2];
int fa[maxn*2],sz[maxn*2],s[maxn*2];
int s1[maxn*2],s2[maxn*2],ans;
int find(int x) {
	if (x==fa[x]) return x;
	return fa[x]=find(fa[x]);
}
void update(int &s1,int &s2,int s) {
	if (s>s1) s2=s1,s1=s;
	else s2=max(s2,s);
}
int main() {
	//freopen("1.txt","r",stdin);
	read(n);
	for (int i=1;i<=n;i++) {
		read(a[i]); read(b[i]);
		c[++tot]=make_pair(a[i],i*2);
		c[++tot]=make_pair(b[i],i*2+1);
	}
	sort(c+1,c+(tot+1));
	for (int i=1;i<=tot;i++) {
		if (c[i].first!=c[i-1].first) mx++;
		if (c[i].second%2==0) a[c[i].second/2]=mx;
		else b[c[i].second/2]=mx;
		d[mx]=c[i].first;
	}
	for (int i=1;i<=mx;i++) fa[i]=i;
	for (int i=1;i<=n;i++) fa[find(a[i])]=find(b[i]);
	for (int i=1;i<=mx;i++)
		sz[find(i)]++,update(s1[find(i)],s2[find(i)],i);
	for (int i=1;i<=n;i++) s[find(a[i])]++;
	for (int i=1;i<=mx;i++)
	   if (find(i)==i){
            if (s[i]>sz[i]) { printf("-1\n"); return 0; }
			if (s[i]==sz[i]) ans=max(ans,s1[i]);
			else ans=max(ans,s2[i]);                       
        }
    printf("%d\n",d[ans]);
	return 0;
}