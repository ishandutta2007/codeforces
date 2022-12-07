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
const int N=500005;
vector<int> vec[N];
int fa[N],fav[N],v[N];
int s0[N],s1[N],ban[N];
int n,k,ans;
char s[N];
int get(int x){
	if (x==fa[x]) return x;
	int y=fa[x];
	fa[x]=get(fa[x]);
	v[x]=v[y]^fav[x];
	fav[x]=v[x]^v[fa[x]];
	return fa[x];
}
int main(){
	scanf("%d%d",&n,&k);
	scanf("%s",s+1);
	For(i,1,n) s[i]^=1;
	For(i,1,k){
		int x;
		scanf("%d",&x);
		For(j,1,x){
			int y;
			scanf("%d",&y);
			vec[y].PB(i);
		}
	}
	For(i,1,k) fa[i]=i,fav[i]=0,v[i]=0,ban[i]=-1;
	For(i,1,k) s0[i]=0,s1[i]=1;
	For(i,1,n){
		if (!vec[i].size())
			assert(s[i]=='0');
		else if (vec[i].size()==1){
			int x=vec[i][0],p=get(x);
			if (ban[p]==-1){
				ans-=min(s0[p],s1[p]);
				ban[p]=(s[i]-'0')^v[x];
				//cout<<"BAN "<<ban[p]<<endl;
				ans+=(ban[p]?s1[p]:s0[p]);
			}
			else
				assert(!((s[i]-'0')^v[x]^ban[p]));
		}
		else{
			int x=vec[i][0],y=vec[i][1];
			int p1=get(x),p2=get(y);
			if (p1==p2) assert(!(v[x]^v[y]^(s[i]-'0')));
			else{
				if (ban[p1]==-1)
					ans-=min(s0[p1],s1[p1]);
				else ans-=(ban[p1]?s1[p1]:s0[p1]);
				
				if (ban[p2]==-1)
					ans-=min(s0[p2],s1[p2]);
				else ans-=(ban[p2]?s1[p2]:s0[p2]);
				
				if (v[x]^v[y]^(s[i]-'0')){
					swap(s0[p2],s1[p2]);
					if (ban[p2]!=-1) ban[p2]^=1;
				}
				fav[p2]=v[x]^v[y]^(s[i]-'0'); fa[p2]=p1;
				s0[p1]+=s0[p2]; s1[p1]+=s1[p2];
				if (ban[p2]!=-1){
					if (ban[p1]==-1) ban[p1]=ban[p2];
					else assert(ban[p1]==ban[p2]);
				}
				
				//cout<<p1<<' '<<s0[p1]<<' '<<
				if (ban[p1]==-1)
					ans+=min(s0[p1],s1[p1]);
				else ans+=(ban[p1]?s1[p1]:s0[p1]);
			}
		}
		printf("%d\n",ans);
	}
}