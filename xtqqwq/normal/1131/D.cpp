#include<bits/stdc++.h>

using namespace std;

typedef long long ll;

int readint(){
	int x=0,f=1; char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
	return x*f;
}

int n,m,tot;
int f[2005],v[1000005],nxt[1000005],h[2005],du[2005],q[1000005],ans[2005];
char a[1005][1005];

int getf(int v){if(f[v]==v)return v;return f[v]=getf(f[v]);}
void addedge(int x,int y){v[++tot]=y; nxt[tot]=h[x]; h[x]=tot; du[y]++;}

int main(){
	n=readint(); m=readint();
	for(int i=1;i<=n;i++) scanf("%s",a[i]+1);
	for(int i=1;i<=n+m;i++) f[i]=i;
	for(int i=1;i<=n;i++) for(int j=1;j<=m;j++) if(a[i][j]=='=') f[getf(j+n)]=getf(i);
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			if(a[i][j]!='='&&getf(i)==getf(j+n)) return printf("No\n"),0;
			if(a[i][j]=='<') addedge(getf(i),getf(j+n));
			else if(a[i][j]=='>') addedge(getf(j+n),getf(i));
		}
	}
	int front=0,rear=0,num=0;
	for(int i=1;i<=n+m;i++) if(du[i]==0&&getf(i)==i) q[rear++]=i,ans[i]=1;
	for(int i=1;i<=n+m;i++) if(getf(i)==i) num++;
//	for(int i=1;i<=n+m;i++) cout<<"TEST "<<f[i]<<endl;
	for(int i=1;i<=num;i++){
		if(front>=rear) return printf("No\n"),0;
		int t=q[front++];
		for(int p=h[t];p;p=nxt[p]) if(!(--du[v[p]])) q[rear++]=v[p],ans[v[p]]=max(ans[v[p]],ans[t]+1);
	}
	printf("Yes\n");
	for(int i=1;i<=n;i++) printf("%d ",ans[f[i]]);
	printf("\n");
	for(int i=1;i<=m;i++) printf("%d ",ans[f[i+n]]);
	printf("\n");
	return 0;
}