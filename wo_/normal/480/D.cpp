#include<cstdio>
#include<vector>
#include<cstring>
#include<algorithm>

using namespace std;
/*
struct Task{
	int to,val,weight,stren,id;
	Task(){}
	Task(int a,int b,int c,int d,int e){
		to=a,val=b,weight=c,stren=d,id=e;
	}
};

bool operator<(const Task &t1,const Task &t2){
	return t1.to<t2.to;
}

vector<int> tasks[2000];

int dp[550][2020],dp2[550][2020];

*/

const int inf=1001001001;

typedef pair<int,int> P;
typedef pair<P,int> PP;

int in[550],out[550];
vector<PP> pps;
int val[550],w[550],stren[550];

int c_in[550],c_out[550];
P ps[2020];

int dp1[550][2020],dp2[550][2020];

int f1(int id,int weight){
	if(weight<w[id]) return -inf;
	if(dp1[id][weight]!=-1) return dp1[id][weight];
	int S=min(stren[id],weight-w[id]);
	for(int i=c_in[id];i<=c_out[id];i++){
		dp2[id][i]=0;
	}
	for(int i=c_in[id]+1;i<c_out[id];i++){
		dp2[id][i]=max(dp2[id][i],dp2[id][i-1]);
		if(ps[i]!=P(-1,-1)&&ps[i].first<c_out[id]){
			int tmp=f1(ps[i].second,S);
			dp2[id][ps[i].first]=max(dp2[id][ps[i].first],dp2[id][i]+tmp+val[ps[i].second]);
		}
	}
	dp2[id][c_out[id]]=max(dp2[id][c_out[id]],dp2[id][c_out[id]-1]);
	dp1[id][weight]=dp2[id][c_out[id]];
	return dp2[id][c_out[id]];
}

int main(){
	int N,S;
	scanf("%d%d",&N,&S);
	for(int i=0;i<N;i++){
		scanf("%d%d%d%d%d",in+i,out+i,w+i,stren+i,val+i);
		pps.push_back(PP(P(in[i]*2+1,-out[i]),i));
		pps.push_back(PP(P(out[i]*2,-in[i]),i));
	}
	stren[N]=S;
	val[N]=0;
	w[N]=0;
	in[N]=-1;
	out[N]=N*2;
	pps.push_back(PP(P(in[N]*2+1,-out[N]),N));
	pps.push_back(PP(P(out[N]*2,-in[N]),N));
	sort(pps.begin(),pps.end());
	int c=0;
	for(int i=0;i<pps.size();i++){
		int id=pps[i].second;
		int a=pps[i].first.first,b=pps[i].first.second;
		b*=-1;
		a/=2;
		if(a<b){
			c_in[id]=c;
			c++;
		}else{
			c_out[id]=c;
			c++;
		}
	}
	for(int i=0;i<2000;i++) ps[i]=P(-1,-1);
	for(int i=0;i<=N;i++){
		int a=c_in[i],b=c_out[i];
		ps[a]=P(b,i);
//		printf("%d %d %d\n",i,a,b);
	}
	memset(dp1,-1,sizeof(dp1));
	memset(dp2,-1,sizeof(dp2));
	int ans=f1(N,S);
	printf("%d\n",ans);
	return 0;
}