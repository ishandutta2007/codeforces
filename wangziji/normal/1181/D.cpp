#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <cstdlib>
#pragma GCC optimize ("O2")
#define int long long
#define INF 10000000
using namespace std;
struct node
{
	int v,id,ans;
}a[500005],b[500005];
inline bool cmp(node x,node y)
{
	return x.v<y.v;
}
inline bool cmp2(node x,node y)
{
	return x.id<y.id;
}
int na;
int ch[500005][2];
int val[500005],dat[500005];
int Size[500005],cnt[500005];
int tot,root;
int New(int v){
	val[++tot]=v;
	dat[tot]=rand();
	Size[tot] = 1;
	cnt[tot] = 1;
	return tot;
	}
void pushup(int id){
	Size[id] = Size[ch[id][0]] + Size[ch[id][1]] + cnt[id];
	}
void build(){
	root = New(-INF),ch[root][1] = New(INF);
	pushup(root);
	}
void Rotate(int &id,int d){
	int temp = ch[id][d ^ 1];
	ch[id][d ^ 1] = ch[temp][d];
	ch[temp][d] = id;
	id = temp;
	pushup(ch[id][d]),pushup(id);
	}
void insert(int &id,int v){
	if(!id){
		id = New(v);
		return ;
		}
	if(v == val[id])cnt[id]++;
	else{
		int d = v < val[id] ? 0 : 1;
		insert(ch[id][d],v);
		if(dat[id] < dat[ch[id][d]])Rotate(id,d ^ 1);
		}
	pushup(id);
	}
int get_val(int id,int rank){
	if(!id)return INF;
	if(rank <= Size[ch[id][0]])return get_val(ch[id][0],rank);
		else if(rank <= Size[ch[id][0]] + cnt[id])return val[id];
	else return get_val(ch[id][1],rank - Size[ch[id][0]] - cnt[id]);
	}
vector <int> v;
signed main() {
	int n,m,q;
	cin >> n >> m >> q;
	for(int i=1;i<=n;i++)
	{
		int t;
		scanf("%lld",&t);
		++a[t].v;
	}
	for(int i=1;i<=q;i++)
		scanf("%lld",&b[i].v);
	for(int i=1;i<=m;i++)
		a[i].id=i;
	for(int i=1;i<=q;i++)
		b[i].id=i,b[i].v-=n;
	sort(a+1,a+m+1,cmp);
	sort(b+1,b+q+1,cmp);
	int cnt=0,x=1;
	int lcnt=0;
	a[m+1].v=a[m].v;
	for(int i=1;i<=m;i++)
	{
		insert(root,a[i].id);
		//v.insert(lower_bound(v.begin(),v.end(),a[i].id),a[i].id);
		cnt+=(i)*(a[i+1].v-a[i].v);
		/*cout << cnt << "***" << i << " " << a[i].v << endl;
		for(int j=0;j<v.Size();j++)
			cout << v[j] << " ";
		cout << endl;*/
		for(;(b[x].v<=cnt||i==m)&&x<=q;++x)
			b[x].ans=get_val(root,((b[x].v-lcnt-1)%i)+1);//v[(b[x].v-lcnt-1)%i];
		lcnt=cnt;
	}
	sort(b+1,b+q+1,cmp2);
	for(int i=1;i<=q;i++)
		printf("%lld\n",b[i].ans);
	return 0;
}