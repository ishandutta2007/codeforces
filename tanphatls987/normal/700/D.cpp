#include <bits/stdc++.h>

using namespace std;

#define X first 
#define Y second 
#define FOR(i,L,R) for(auto i=(L);i<=(R);i++)
#define REP(i,L,R) for(auto i=(L);i<(R);i++)

typedef pair<int,int> ii;
typedef long long ll;

const int MOD=1e9+7;
const int N=1e5+10,M=350;

vector <ii> imp[M];
ii q[N];
int n,n1,m,a[N];

int ans[N];

map<int,int> ma;
deque <ii> qu1,qu2;

struct linklist{
	ii link[N];
	int h[N],con[N];
	void setlink(int L,int R){
		link[L].Y=R;
		link[R].X=L;
	}
	int next(int x){
		return link[x].Y;
	}
	void reset(){
		memset(h,0,sizeof(h));
		memset(con,0,sizeof(con));
		setlink(0,n+1);
		h[0]=h[n+1]=n1+1;
		// for(int i=0;i<=n+1;i++) cout<<h[i]<<" \n"[i==n+1];
		// for(int i=0;i<=n+1;i++) cout<<link[i].X<<" \n"[i==n+1];
		// for(int i=0;i<=n+1;i++) cout<<link[i].Y<<" \n"[i==n+1];
	}
	void modified(int x,int val){
		h[con[x]]--;
		int pos=con[x]+val;
		if (!h[pos]){
			if (!h[con[x]]){
				setlink(link[con[x]].X,pos);
				setlink(pos,link[con[x]].Y);
			}else{
				if (val==-1){
					setlink(link[con[x]].X,pos);
					setlink(pos,con[x]);
				}else{
					setlink(pos,link[con[x]].Y);
					setlink(con[x],pos);
				}
			}
		}else if (!h[con[x]]) setlink(link[con[x]].X,link[con[x]].Y);
		con[x]+=val;
		h[con[x]]++;
		// for(int i=0;i<=n+1;i++) cout<<h[i]<<" ";cout<<endl;
		// for(int i=0;i<=n+1;i++) cout<<link[i].X<<" ";cout<<endl;
		// for(int i=0;i<=n+1;i++) cout<<link[i].Y<<" ";cout<<endl;
	}
	void modcal(int nx,int add){
		if (!add) return;
		qu2.push_back(ii(nx,add));
	}
	ii getsmallest(){
		while (!qu2.empty()&&qu2.front().X<=qu1.front().X){
			if (qu2.front().X==qu1.front().X){
				ii nfront=qu1.front();
				nfront.Y+=qu2.front().Y;
				qu1.pop_front();
				qu2.pop_front();
				qu1.push_front(nfront);
			}else{
				qu1.push_front(qu2.front());
				qu2.pop_front();
			}
		}
		ii cur=qu1.front();
		qu1.pop_front();
		return cur;
	}
	int cal(int len){
		// for(int i=0;i<=n+1;i++) cout<<h[i]<<" ";cout<<endl;
		// for(int i=0;i<=n+1;i++) cout<<link[i].X<<" ";cout<<endl;
		// for(int i=0;i<=n+1;i++) cout<<link[i].Y<<" ";cout<<endl;
		qu1.clear();
		qu2.clear();
		for(int cur=next(0);cur<=n;cur=next(cur))
			qu1.push_back(ii(cur,h[cur]));
		qu1.push_back(ii(n+1,0));
		int ans=0;
		while (1){
			ii cur=getsmallest();
			// cout<<"Merge "<<cur.X<<" "<<cur.Y<<endl;
			modcal(cur.X*2,cur.Y>>1);
			if (cur.Y&1){
				ii scur=getsmallest();
				if (scur.X>n) break;
				// cout<<"Addin "<<scur.X<<" "<<scur.Y<<'\n';
				modcal(cur.X+scur.X,1);
				ans+=scur.X;
				scur.Y--;
				if (scur.Y) qu1.push_front(scur);
			}
			ans+=cur.Y*cur.X;
		}
		// printf("tick\n");
		return ans;
	}
}mlink;
void prepare(){
	scanf("%d",&n);
	n1=0;
	for(int i=0;i<n;i++) {
		scanf("%d",a+i);
		if (!ma[a[i]]) ma[a[i]]=++n1;
		a[i]=ma[a[i]];
	}
	scanf("%d",&m);
	for(int i=0;i<M;i++) imp[i].push_back(ii(i*M-1,0));
	for(int i=1;i<=m;i++){
		scanf("%d%d",&q[i].X,&q[i].Y);
		q[i].X--;q[i].Y--;
		imp[q[i].X/M].push_back(ii(q[i].Y,i));
	}
	for(int i=0;i<M;i++) sort(imp[i].begin(),imp[i].end());
}


void solve(){
	// for(int i=0;i<imp[0].size();i++) cout<<q[imp[0][i].Y].X<<" "<<q[imp[0][i].Y].Y<<endl;
	for(int cur=0;cur<M;cur++) if (imp[cur].size()>1){
		mlink.reset();
		for(int i=1;i<imp[cur].size();i++){
			int idx=imp[cur][i].Y;
			// cout<<"Ques "<<q[idx].X<<" "<<q[idx].Y<<endl;
			for(int j=imp[cur][i-1].X+1;j<=imp[cur][i].X;j++)
				mlink.modified(a[j],1);
			for(int j=cur*M;j<q[idx].X;j++)
				mlink.modified(a[j],-1);
			ans[idx]=mlink.cal(q[idx].Y-q[idx].X+1);
			for(int j=cur*M;j<q[idx].X;j++)
				mlink.modified(a[j],1);
		}
	}
	for(int i=1;i<=m;i++) printf("%d\n",ans[i]);
}
int main(){
	prepare();
	solve();
}