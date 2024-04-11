#include <bits/stdc++.h>
using namespace std;
template <typename T> void read(T &t) {
	t=0; char ch=getchar(); int f=1;
	while (ch<'0'||ch>'9') { if (ch=='-') f=-1; ch=getchar(); }
	do { (t*=10)+=ch-'0'; ch=getchar(); } while ('0'<=ch&&ch<='9'); t*=f;
}
typedef long long ll;
const int mod=998244353;
int n,m,tot,ch[50][30];
char s[10];
bool op[50];
void insert() {
	int len=strlen(s+1),pos=1;
	for (int i=1;i<=len;i++) {
		int t=s[i]-'a';
		if (ch[pos][t]==0) ch[pos][t]=++tot;
		pos=ch[pos][t];
	}
	op[pos]=1;
}
void update(int &x,int y) { x+=y; if (x>=mod) x-=mod; }
int N,num[50][50];
struct Matrix {
	int d[210][210];
	friend Matrix operator * (Matrix t1,Matrix t2) {
		Matrix res;
		for (int i=1;i<=N;i++)
		for (int j=1;j<=N;j++) {
			res.d[i][j]=0;
			for (int k=1;k<=N;k++)
				update(res.d[i][j],(ll)t1.d[i][k]*t2.d[k][j]%mod);
		}
		return res;
	}
} A,B;
struct node { int id,x,y; };
queue<node> q;
int get(int x,int y) {
	if (x>y) swap(x,y);
	if (!num[x][y]) num[x][y]=++N,q.push((node){N,x,y});
	return num[x][y];
}
int main() {
	//freopen("1.txt","r",stdin);
	read(n),read(m); tot=1;
	for (int i=1;i<=n;i++) {
		scanf("%s",s+1);
		insert();
	}
	int x,y,a,b,now;
	get(1,1);
	while (!q.empty()) {
		now=q.front().id;
		x=q.front().x,y=q.front().y; q.pop();
		for (int i=0;i<26;i++) {
			a=ch[x][i],b=ch[y][i];
			if (!a||!b) continue;
			A.d[now][get(a,b)]++;
			if (op[a]) A.d[now][get(1,b)]++;
			if (op[b]) A.d[now][get(1,a)]++;
			if (op[a]&&op[b]) A.d[now][get(1,1)]++;
		}
	}
	for (int i=1;i<=N;i++) B.d[i][i]=1;
	while (m) {
		if (m&1) B=B*A;
		A=A*A; m>>=1;
	}
	printf("%d\n",B.d[1][1]);
	return 0;
}
/*
  REMEMBER:
  1. Think TWICE, Code ONCE!
  Are there any counterexamples to your algo?
    
  2. Be careful about the BOUNDARIES!
  N=1? P=1? Something about 0?
    
  3. Do not make STUPID MISTAKES!
  Array size? Integer overflow? Time complexity? Memory usage? Precision error?
*/