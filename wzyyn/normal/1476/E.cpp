#include<bits/stdc++.h>
#define For(i,j,k) for (int i=(int)(j);i<=(int)(k);i++)
#define Rep(i,j,k) for (int i=(int)(j);i>=(int)(k);i--)
#define pii pair<int,int>
#define fi first
#define se second
#define PB push_back
#define ll long long
using namespace std;

const int N=27*27*27*27+5;
int n,m,k,op[N],id[N];
int ind[N],q[N];
vector<int> e[N];
void topo(){
	int h=0,t=0;
	For(i,1,n) if (!ind[i]) q[++t]=i;
	while (h!=t){
		int x=q[++h];
		for (auto i:e[x])
			if (!--ind[i]) q[++t]=i;
	}
	if (t!=n){
		puts("NO");
		exit(0);
	}
}
int Idx(string s,int S){
	int id=0;
	For(i,0,k-1)
		if (S&(1<<i)) id=id*27+26;
		else if (s[i]=='_') id=id*27+26;
		else id=id*27+s[i]-'a';
	return id;
}
int main(){
	scanf("%d%d%d",&n,&m,&k);
	For(i,1,n){
		string s;
		cin>>s;
		id[i]=Idx(s,0);
		op[Idx(s,0)]=i;
	}
	For(i,1,m){
		string s;
		int x;
		cin>>s;
		scanf("%d",&x);
		bool flg=0;
		For(j,0,(1<<k)-1){
			int p=Idx(s,j);
			if (p==id[x]) flg=1;
			else if (op[p]) ++ind[op[p]],e[x].PB(op[p]);
		}
		if (!flg) return puts("NO"),0; 
	}
	topo();
	puts("YES");
	For(i,1,n) printf("%d ",q[i]);
}