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
const int N=300050;
const int M=30*N;
int n,a[N];
ll bs[30][2];
namespace Automaton{
	int ch[M][2],T;
	vector<int> v[M];
	void ins(int x,int qq){
		int p=0;
		Rep(i,29,0){
			int b=((x&(1<<i))?1:0);
			if(!ch[p][b])
				ch[p][b]=++T;
			p=ch[p][b];
			v[p].PB(qq);
		}
	}
	void bld(int p){
		sort(v[p].begin(),v[p].end());
		if(ch[p][0])
			bld(ch[p][0]);
		if(ch[p][1])
			bld(ch[p][1]);
	}
	void gao(int p,int d){
		ll L=0,R=0,tot=v[ch[p][0]].size()+v[ch[p][1]].size();
		if(tot==0)
			return;
		if(ch[p][0])
			gao(ch[p][0],d-1);
		if(ch[p][1])
			gao(ch[p][1],d-1);
		For(b,0,1){
			int ptr=0;
			for(int i:v[ch[p][b]]){
				while(ptr<v[ch[p][b^1]].size()&&v[ch[p][b^1]][ptr]<i)
					ptr++;
				(b==0?L:R)+=(v[ch[p][b^1]].size()-ptr);
				//(b==0?L:R)+=ptr;
			}
		}
		//printf("Left: "); for(int i:v[ch[p][0]])printf("%d,",i); puts("");
		//printf("Right: "); for(int i:v[ch[p][1]])printf("%d,",i); puts("");
		//printf("L=%lld   R=%lld\n\n\n",L,R);
		bs[d][0]+=L; bs[d][1]+=R;
	}
};
int main(){
	scanf("%d",&n);
	For(i,1,n) 
		scanf("%d",&a[i]),Automaton::ins(a[i],i);
	//Automaton::bld(0);
	Automaton::gao(0,29);
	ll ans=0; int x=0;
	For(i,0,29){
		ans+=min(bs[i][0],bs[i][1]);
		if(bs[i][0]<bs[i][1])
			x+=(1<<i);
	}
	printf("%lld %d",ans,x);
}