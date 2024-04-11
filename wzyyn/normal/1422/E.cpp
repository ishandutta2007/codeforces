#include<bits/stdc++.h>
#define ll long long
#define ull unsigned ll
#define uint unsigned
#define pii pair<int,int>
#define pll pair<ll,ll>
#define IT iterator
#define PB push_back
#define fi first
#define se second
#define For(i,j,k) for (int i=(int)(j);i<=(int)(k);i++)
#define Rep(i,j,k) for (int i=(int)(j);i>=(int)(k);i--)
#define CLR(a,v) memset(a,v,sizeof(a));
#define CPY(a,b) memcpy(a,b,sizeof(a));
#define debug puts("wzpakking")
#define y1 ysghysgsygsh
using namespace std;
const int Bas=19260817+114514;
const int N=100005;
char s[N];
ll pw[50];
struct node{
	int len,v;
	ull Hsh[18];
	node *nxt[18];
	node(){
		For(i,0,17){
			nxt[i]=NULL;
			Hsh[i]=0;
		}
	}
};
node ans[N];
node Expand(node &a,int x){
	node res;
	res.len=a.len+1;
	res.v=x;
	res.Hsh[0]=x;
	res.nxt[0]=&a;
	For(i,1,17)
		if (res.nxt[i-1]->nxt[i-1]!=NULL){
			res.nxt[i]=res.nxt[i-1]->nxt[i-1];
			res.Hsh[i]=res.Hsh[i-1]+pw[i-1]*res.nxt[i-1]->Hsh[i-1];
		}
		else break;
	return res;
}
bool cmp(node a,node b){
	Rep(i,17,0)
		if (a.nxt[i]!=NULL&&b.nxt[i]!=NULL)
			if (a.Hsh[i]!=b.Hsh[i]);
			else a=*(a.nxt[i]),b=*(b.nxt[i]);
	return a.v>b.v;
}
void print(node a){
	printf("%d ",a.len);
	if (a.len<=10){
		node *b=&a;
		for (;b!=NULL&&b->len!=0;b=b->nxt[0])
			printf("%c",char(b->v));
	}
	else{
		node *b=&a;
		for (int i=1;i<=5;i++,b=b->nxt[0])
			printf("%c",char(b->v));
		printf("...");
		Rep(i,17,0){
			if (b->nxt[i]!=NULL) 	
				assert(b->len-b->nxt[i]->len==(1<<i));
			if (b->len-(1<<i)>=2)
				b=b->nxt[i];
		}
		//cout<<b->len<<' '<<b->nxt[0]->len<<endl; 
		for (;b!=NULL&&b->len!=0;b=b->nxt[0])
			printf("%c",char(b->v));
	}
	puts("");
}
int main(){
	scanf("%s",s+1);
	int n=strlen(s+1);
	pw[0]=Bas;
	For(i,1,17) pw[i]=pw[i-1]*pw[i-1];
	for (int i=n;i>=1;i--){
		ans[i]=Expand(ans[i+1],s[i]); 
		if (s[i]==s[i+1])
			if (cmp(ans[i],ans[i+2]))
				ans[i]=ans[i+2];
	}
	For(i,1,n)
		print(ans[i]);
}