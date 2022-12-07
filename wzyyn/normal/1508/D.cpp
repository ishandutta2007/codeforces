#include<bits/stdc++.h>
#define For(i,j,k) for (int i=(int)(j);i<=(int)(k);i++)
#define Rep(i,j,k) for (int i=(int)(j);i>=(int)(k);i--)
#define pii pair<int,int>
#define fi first
#define se second
#define PB push_back
#define ll long long
#define ull unsigned long long
#define pll pair<ll,ll> 
#define y1 orzkcz
using namespace std;

const int N=3005;
struct P{
	int x,y;
	P(){}
	P(int _x,int _y){
		x=_x; y=_y;
	}
	P operator +(const P &a)const{
		return P(x+a.x,y+a.y);
	}
	P operator -(const P &a)const{
		return P(x-a.x,y-a.y);
	}
	ll operator *(const P &a)const{
		return 1ll*x*a.y-1ll*y*a.x;
	}
	int pos(){
		return x?x>0:y>0;
	}
}p[N];
int n,lab[N],q[N];
int col[N],fa[N];
vector<pair<int,int> > ans;
int get(int x){
	return x==fa[x]?x:fa[x]=get(fa[x]);
}
bool cmp(int x,int y){
	P d1=p[x]-p[q[1]];
	P d2=p[y]-p[q[1]];
	if (d1.pos()^d2.pos())
		return d1.pos();
	return d1*d2>0;
}
int main(){
	scanf("%d",&n);
	for (int i=1;i<=n;i++)
		scanf("%d%d%d",&p[i].x,&p[i].y,&lab[i]);
	for (int i=1;i<=n;i++)
		if (lab[i]!=i) q[++*q]=i;
	if (!*q){
		puts("0");
		return 0;
	}
	for (int i=2;i<=*q;i++)
		if ((p[q[1]]-p[q[i]]).pos()) swap(q[1],q[i]);
	sort(q+2,q+*q+1,cmp);
	for (int i=1;i<=*q;i++)
		if (!col[q[i]]){
			++*col;
			for (int j=q[i];!col[j];j=lab[j])
				col[j]=*col;
		}
	for (int i=1;i<=*col;i++) fa[i]=i;
	for (int i=2;i<=*q;i++){
		int x=q[i];
		int y=q[(i==*q?2:i+1)];
		//cout<<col[x]<<' '<<col[y]<<endl;
		if (get(col[x])!=get(col[y])){
			ans.push_back(pair<int,int>(x,y));
			fa[get(col[x])]=get(col[y]);
			swap(lab[x],lab[y]);
		}
	}
	for (;lab[q[1]]!=q[1];){
		//cout<<q[1]<<' '<<lab[q[1]]<<endl;
		ans.push_back(pair<int,int>(lab[q[1]],q[1]));
		swap(lab[q[1]],lab[lab[q[1]]]);
		//cout<<q[1]<<' '<<lab[q[1]]<<endl;
	}
	printf("%d\n",ans.size());
	for (auto i:ans)
		printf("%d %d\n",i.first,i.second);
}