#include<cstdio>
#include<utility>
#include<algorithm>

using namespace std;

typedef pair<int,int> P;

const int inf=1e9;

P ps[110];
int N;

int vals[330];
int ln;

inline int getId(int x){
	return lower_bound(vals,vals+ln,x)-vals;
}

int left[110][110][330];
int dp[110][330];

void precalc(){
	sort(ps,ps+N);
	for(int i=0;i<N;i++){
		vals[i*3]=ps[i].first-ps[i].second;
		vals[i*3+1]=ps[i].first;
		vals[i*3+2]=ps[i].first+ps[i].second;
	}
	sort(vals,vals+N*3);
	ln=unique(vals,vals+N*3)-vals;
}

void calcLeft(){
	for(int i=0;i<N;i++) for(int j=0;j<N;j++){
		for(int k=0;k<ln;k++){
			left[i][j][k]=inf;
		}
	}
	for(int i=0;i<N;i++){
		int x=getId(ps[i].first+ps[i].second);
		int y=getId(ps[i].first);
		int z=getId(ps[i].first-ps[i].second);
		left[i][i][x]=y;
		left[i][i][y]=z;
	}
	for(int d=1;d<=N-1;d++){
		for(int i=0;i+d<N;i++){
			int j=i+d;
			//rightmost is from i
			int r=getId(ps[i].first+ps[i].second);
			int l=getId(ps[i].first);
			left[i][j][r]=l;
			for(int k=l;k<=r;k++){
				left[i][j][r]=min(left[i][j][r],left[i+1][j][k]);
			}
			int l2=getId(ps[i].first-ps[i].second);
			left[i][j][l]=min(left[i+1][j][l],l2);
			//rightmost is not from i
			for(int k=l;k<ln;k++){
				if(left[i+1][j][k]==inf) continue;
				if(left[i+1][j][k]<=l){
					left[i][j][k]=min(left[i][j][k],min(left[i+1][j][k],l2));
				}else if(left[i+1][j][k]<=r){
					left[i][j][k]=min(left[i][j][k],l);
				}
			}
		}
	}
}

void calcDP(){
	for(int i=0;i<N;i++) for(int j=0;j<ln;j++){
		dp[i][j]=-inf;
	}
	for(int i=0;i<N;i++){
		for(int j=0;j<ln;j++){
			if(left[0][i][j]!=inf){
				dp[i][j]=vals[j]-vals[left[0][i][j]];
			}
			for(int s=0;s<i;s++){
				for(int t=0;t<j;t++){
					if(dp[s][t]==-inf) continue;
					int l=left[s+1][i][j];
					if(l==inf) continue;
					int ad=vals[j]-vals[max(l,t)];
					int res=dp[s][t]+ad;
					dp[i][j]=max(dp[i][j],res);
				}
			}
		}
	}
}

int main(){
	scanf("%d",&N);
	for(int i=0;i<N;i++){
		int a,l;
		scanf("%d%d",&a,&l);
		ps[i]=P(a,l);
	}
	precalc();
	calcLeft();
	calcDP();
	int res=0;
	for(int i=0;i<ln;i++){
		res=max(res,dp[N-1][i]);
	}
	printf("%d\n",res);
	return 0;
}