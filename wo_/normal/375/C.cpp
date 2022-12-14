#include<cstdio>
#include<queue>
#include<algorithm>

using namespace std;

const int inf=1e8;

const int di[]={1,0,-1,0};
const int dj[]={0,1,0,-1};

struct State{
	int i,j;
	int mask;
	State(){}
	State(int a,int b,int c):i(a),j(b),mask(c){}
};

char field[25][25];
int N,M;
int dp[25][25][1<<8];
int si,sj;
char ch[30];
int onum;
int oi[8];
int oj[8];
int tval[8];
int tnum;

queue<State> que;

void bfs(int si,int sj){
	for(int i=0;i<25;i++) for(int j=0;j<25;j++) for(int k=0;k<(1<<8);k++){
		dp[i][j][k]=inf;
	}
	que.push(State(si,sj,0));
	dp[si][sj][0]=0;
	while(!que.empty()){
		State cur=que.front();
		que.pop();
		int ci=cur.i;
		int cj=cur.j;
		int cmask=cur.mask;
		int cd=dp[ci][cj][cmask];
		for(int d=0;d<4;d++){
			int ni=ci+di[d];
			int nj=cj+dj[d];
			if(field[ni][nj]!='.') continue;
			int nd=cd+1;
			int nmask=cmask;
			if(ni!=ci){
				for(int o=0;o<onum;o++){
					int i2=oi[o];
					int j2=oj[o];
					int ni2=max(ni,ci);
					if(i2==ni2&&j2<nj){
						nmask^=(1<<o);
					}
				}
			}
			if(dp[ni][nj][nmask]<=nd) continue;
			dp[ni][nj][nmask]=nd;
			que.push(State(ni,nj,nmask));
		}
	}
}

void init(){
	int bnum=0;
	for(int i=0;i<=N+1;i++) field[i][M+2]='\0';
	for(int i=1;i<=N;i++){
		for(int j=1;j<=M;j++){
			if(field[i][j]=='S'){
				si=i;
				sj=j;
				field[i][j]='.';
			}else if('1'<=field[i][j]&&field[i][j]<='8'){
				int id=field[i][j]-'1';
				oi[id]=i;
				oj[id]=j;
			}else if(field[i][j]=='B'){
				oi[tnum+bnum]=i;
				oj[tnum+bnum]=j;
				bnum++;
			}
		}
	}
	onum=tnum+bnum;
}

int solve(){
	bfs(si,sj);
	int ans=0;
	for(int st=0;st<(1<<tnum);st++){
		int tmp=0;
		if(dp[si][sj][st]==inf) continue;
		for(int i=0;i<tnum;i++){
			if((st>>i)&1){
				tmp+=tval[i];
			}
		}
		tmp-=dp[si][sj][st];
		ans=max(ans,tmp);
	}
	return ans;
}

void input(){
	scanf("%d%d",&N,&M);
	for(int i=0;i<=N+1;i++){
		for(int j=0;j<=M+1;j++){
			field[i][j]='#';
		}
	}
	tnum=0;
	for(int i=0;i<N;i++){
		scanf("%s",ch);
		for(int j=0;j<M;j++){
			field[i+1][j+1]=ch[j];
			if('1'<=ch[j]&&ch[j]<='8'){
				tnum++;
			}
		}
	}
	for(int i=0;i<tnum;i++) scanf("%d",tval+i);
}

int main(){
	input();
	init();
	int ans=solve();
	printf("%d\n",ans);
	return 0;
}