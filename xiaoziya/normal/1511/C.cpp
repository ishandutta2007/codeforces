#include<bits/stdc++.h>
#define lowbit(x) (x&-x)
using namespace std;
const int maxn=600005;
int n,m,T,ans,flg;
int a[maxn],lst[maxn],t[maxn];
void update(int x,int v){
	for(int i=x;i<=n+m;i+=lowbit(i))
		t[i]+=v;
}
int query(int x){
	int res=0;
	for(int i=x;i;i-=lowbit(i))
		res+=t[i];
	return res;
}
int main(){
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)
		scanf("%d",&a[i]);
	for(int i=n;i>=1;i--)
		lst[a[i]]=m+i,update(m+i,1);
	int tot=m+1;
	for(int i=1,x;i<=m;i++){
		scanf("%d",&x);
		printf("%d%c",query(lst[x]),i==m? '\n':' ');
		update(lst[x],-1),lst[x]=--tot,update(lst[x],1);
	}
	return 0;
}