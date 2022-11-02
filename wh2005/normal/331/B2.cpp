#include<bits/stdc++.h>
using namespace std;
const int N = 3e5+9;
int n,m,a[N],p[N];

struct treearray{
	int tr[N];
	int lowbit(int x){return x&(-x);}
	void add(int x,int d){while(x<=n){tr[x]+=d;x+=lowbit(x);}return ;}
	int sum(int x){int a=0;while(x){a+=tr[x];x-=lowbit(x);}return a;}
	int val(int l,int r){return sum(r)-sum(l-1);}
}t;
void del(int x){
	if(x<n&&p[x]>p[x+1]&&p[x+1]!=-1) t.add(x,-1);
	if(x>1&&p[x-1]>p[x]) t.add(x-1,-1);
	return ;
}
void ins(int x,int d){
	if(x<n&&d>p[x+1]&&p[x+1]!=-1) t.add(x,1);
	if(x>1&&p[x-1]>d&&p[x-1]!=-1) t.add(x-1,1);
	return ;
}

int main(){
	scanf("%d",&n); 
	for(int i=1;i<=n;i++) scanf("%d",&a[i]);
	for(int i=1;i<=n;i++) p[a[i]]=i;
	for(int i=1;i<n;i++) if(p[i]>p[i+1]) t.add(i,1);
	scanf("%d",&m);
	for(int i=1;i<=m;i++){
		int op,l,r;scanf("%d%d%d",&op,&l,&r);
		if(op==1){printf("%d\n",t.val(l,r-1)+1);}
		if(op==2){
			del(a[l]);p[a[l]]=-1;
			del(a[r]);p[a[r]]=-1;
			p[a[l]]=r;
			ins(a[l],r);
			p[a[r]]=l;
			ins(a[r],l);
			swap(a[l],a[r]);
		}
	}
	return 0;
}