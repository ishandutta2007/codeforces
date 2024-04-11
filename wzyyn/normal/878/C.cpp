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
int n,k;
struct node{
	int v,a[15],b[15];
	bool operator <(const node &tmp)const{
		For(i,1,k) if (b[i]<tmp.a[i]) return 0;
		return 1;
	}
};
set<node> S;
int main(){
	scanf("%d%d",&n,&k);
	For(i,1,n){
		node tmp;
		For(j,1,k){
			scanf("%d",&tmp.a[j]);
			tmp.b[j]=tmp.a[j];
		}
		tmp.v=1;
		set<node>::iterator it;
		for (;;){
			it=S.lower_bound(tmp);
			if (it==S.end()||tmp<(*it)) break;
			tmp.v+=it->v;
			For(j,1,k){
				tmp.a[j]=max(tmp.a[j],it->a[j]);
				tmp.b[j]=min(tmp.b[j],it->b[j]);
			}
			S.erase(it);
		}
		S.insert(tmp);
		//printf("%d %d %d %d\n",tmp.a[1],tmp.a[2],tmp.b[1],tmp.b[2]);
		cout<<S.begin()->v<<endl;
	} 
}