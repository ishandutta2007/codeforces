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

const int N=100005;
const int M=2005;
const int B=505;
int n,Q,t1,t2,a[N],ans[N];
int q[N],qq[N],loc[N],S[N],cnt[N],t;
struct node{
	int x,y,z,k,id;
}q1[N],ch[N];
bool cmp(node x,node y){
	if (x.x/M!=y.x/M) return x.x<y.x;
	if (x.y/M!=y.y/M) return x.y<y.y;
	return x.z<y.z;
}
void ins(int x){
	int &s=cnt[x];
	if (!--S[s]) q[loc[s]]=q[t--],loc[q[loc[s]]]=loc[s];
	++s; 
	if (!(S[s]++)) q[++t]=s,loc[s]=t;
}
void del(int x){
	int &s=cnt[x];
	if (!--S[s]) q[loc[s]]=q[t--],loc[q[loc[s]]]=loc[s];
	--s; 
	if (!(S[s]++)) q[++t]=s,loc[s]=t;
}
int Query(int x){
	For(i,1,t) qq[i]=q[i];
	sort(qq+1,qq+t+1);
	int s=0,ans=1<<30,l=1;
	For(i,1,t){
		s+=S[qq[i]];
		for (;s-S[qq[l]]>=x;s-=S[qq[l++]]);
		if (s>=x) ans=min(ans,qq[i]-qq[l]);
	}
	if (ans==1<<30) ans=-1;
	return ans;
}
int main(){
	scanf("%d%d",&n,&Q);
	For(i,1,n) scanf("%d",&a[i]);
	For(i,1,Q){
		int tp,l,r,v;
		scanf("%d%d%d",&tp,&l,&r);
		if (tp==1){
			scanf("%d",&v);
			q1[++t1]=(node){l,r,t2,v,i};
		}
		else{
			ch[++t2]=(node){l,a[l],r,0,0};
			a[l]=r; ans[i]=-2;
		}
	}
	t=0; S[0]=1<<30;
	int l=1,r=0,p=t2;
	sort(q1+1,q1+t1+1,cmp);
	For(i,1,t1){
		for (;r<q1[i].y;ins(a[++r]));
		for (;l>q1[i].x;ins(a[--l]));
		for (;r>q1[i].y;del(a[r--]));
		for (;l<q1[i].x;del(a[l++]));
		for (;p>q1[i].z;){
			if (l<=ch[p].x&&ch[p].x<=r) del(ch[p].z);
			a[ch[p].x]=ch[p].y;
			if (l<=ch[p].x&&ch[p].x<=r) ins(ch[p].y);
			--p;
		}
		for (;p<q1[i].z;){
			++p;
			if (l<=ch[p].x&&ch[p].x<=r) del(ch[p].y);
			a[ch[p].x]=ch[p].z;
			if (l<=ch[p].x&&ch[p].x<=r) ins(ch[p].z);
		}
		//For(i,1,t) cout<<q[i]<<' '<<S[q[i]]<<endl;
		//cout<<"DEBUG "<<q1[i].k<<' '<<q1[i].id<<' '<<l<<' '<<r<<' '<<cnt[1]<<' '<<cnt[2]<<' '<<cnt[3]<<endl;
		ans[q1[i].id]=Query(q1[i].k);
	}
	For(i,1,Q)
		if (ans[i]!=-2)
			printf("%d\n",ans[i]);
}