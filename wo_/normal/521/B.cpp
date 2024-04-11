#include<cstdio>
#include<map>
#include<set>
#include<algorithm>

using namespace std;

const long long mod=1000000009;

long long res[100100];
int N;

int xs[100100],ys[100100];
bool taken[100100];
bool ok[100100];

typedef pair<int,int> P;

map<P,int> ids;

set<int> cands;

int under[100100];

const int dx[]={1,0,-1};

int main(){
	scanf("%d",&N);
	for(int i=0;i<N;i++){
		scanf("%d%d",xs+i,ys+i);
		ids[P(xs[i],ys[i])]=i;
		ok[i]=true;
	}
	for(int i=0;i<N;i++){
		under[i]=0;
		for(int j=0;j<3;j++){
			int nx=xs[i]+dx[j];
			int ny=ys[i]-1;
			if(ids.count(P(nx,ny))==1){
				under[i]++;
			}
		}
		if(under[i]==1){
		for(int j=0;j<3;j++){
			int nx=xs[i]+dx[j];
			int ny=ys[i]-1;
			if(ids.count(P(nx,ny))==1){
		//		under[i]++;
				ok[ids[P(nx,ny)]]=false;
			}
		}
		}
	}
	for(int i=0;i<N;i++){
		if(ok[i]) cands.insert(i);
	}
	for(int c=0;c<N;c++){
		int nxt;
		if(c%2==0) nxt=*cands.rbegin();
		else nxt=*cands.begin();
		cands.erase(nxt);
		res[c]=nxt;
		taken[nxt]=true;
		for(int i=0;i<3;i++){
			int nx=xs[nxt]+dx[i];
			int ny=ys[nxt]+1;
			if(ids.count(P(nx,ny))==0) continue;
			int id=ids[P(nx,ny)];
			if(taken[id]) continue;
			under[id]--;
			if(under[id]==1){
				for(int j=0;j<3;j++){
					int x2=nx+dx[j];
					int y2=ny-1;
					if(ids.count(P(x2,y2))==0) continue;
					int id2=ids[P(x2,y2)];
					if(taken[id2]) continue;
					cands.insert(id2);
					cands.erase(id2);
				}
			}
		}
		if(under[nxt]==1){
			for(int i=0;i<3;i++){
				int nx=xs[nxt]+dx[i];
				int ny=ys[nxt]-1;
				if(ids.count(P(nx,ny))==0) continue;
				int id=ids[P(nx,ny)];
				if(taken[id]) continue;
				bool flg=true;
				for(int j=0;j<3;j++){
					int x2=nx+dx[j];
					int y2=ny+1;
					if(ids.count(P(x2,y2))==0) continue;
					int id2=ids[P(x2,y2)];
					if(taken[id2]) continue;
					if(under[id2]==1) flg=false;
				}
				if(flg) cands.insert(id);
			}
		}
	}
	long long ans=0;
	long long d=1;
	for(int i=N-1;i>=0;i--){
		ans+=d*res[i];
		ans%=mod;
		d*=N;
		d%=mod;
	}
	ans+=mod;
	ans%=mod;
	printf("%d\n",(int)ans);
	return 0;
}