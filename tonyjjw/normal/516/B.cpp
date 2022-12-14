//*
#include<stdio.h>
#include<tuple>
#include<algorithm>
#include<vector>
#include<queue>
#pragma warning(disable:4996)
#define pb push_back
#define eb emplace_back
#define mt make_tuple
#define MN 2000
using namespace std;

int N,M,deg[MN][MN];
char map[MN][MN+1];
int dx[]={0,1,0,-1},dy[]={1,0,-1,0};

queue<tuple<int,int> > que;

void del(int i,int j){
	int ni,nj;
	for(int k=0;k<4;k++){
		ni=i+dx[k],nj=j+dy[k];
		if(ni<0 || ni>=N || nj<0 || nj>=M)continue;
		if(map[ni][nj]=='*')continue;
		deg[ni][nj]--;
		if(deg[ni][nj]==1){
			que.emplace(ni,nj);
		}
	}
}

int main(){
//	freopen("input.txt","r",stdin),freopen("output.txt","w",stdout);
	scanf("%d%d",&N,&M);
	for(int i=0;i<N;i++)scanf("%s",map[i]);
	for(int i=0;i<N;i++){
		for(int j=0;j<M;j++){
			if(map[i][j]=='*')continue;
			for(int k=0;k<4;k++){
				int ni,nj;
				ni=i+dx[k],nj=j+dy[k];
				if(ni<0 || ni>=N || nj<0 || nj>=M)continue;
				if(map[ni][nj]=='*')continue;
				deg[i][j]++;
			}
		}
	}
	int f=0;
	int cnt[2]={0,};
	for(int i=0;i<N;i++){
		for(int j=0;j<M;j++){
			if(map[i][j]=='.' && deg[i][j]==0)f=1;
			if(map[i][j]=='.'){
				cnt[(i+j)&1]++;
			}
		}
	}
	if(f==1 || cnt[0]!=cnt[1]){
		puts("Not unique");
		return 0;
	}
	for(int i=0;i<N;i++){
		for(int j=0;j<M;j++){
			if(deg[i][j]==1){
				que.push(mt(i,j));
			}
		}
	}
	while(!que.empty()){
		int i,j,ni,nj;
		tie(i,j)=que.front();
		que.pop();
		if(deg[i][j]==0)continue;
		for(int k=0;k<4;k++){
			ni=i+dx[k],nj=j+dy[k];
			if(ni<0 || ni>=N || nj<0 || nj>=M)continue;
			if(map[ni][nj]!='.')continue;
			if(k==0){
				map[i][j]='<';
				map[ni][nj]='>';
			}
			if(k==1){
				map[i][j]='^';
				map[ni][nj]='v';
			}
			if(k==2){
				map[ni][nj]='<';
				map[i][j]='>';
			}
			if(k==3){
				map[ni][nj]='^';
				map[i][j]='v';
			}
			break;
		}
		deg[i][j]=deg[ni][nj]=0;
		del(i,j);
		del(ni,nj);
		deg[i][j]=deg[ni][nj]=0;
	}
	for(int i=0;i<N;i++){
		for(int j=0;j<M;j++){
			if(map[i][j]=='.')f=1;
		}
	}
	if(f){
		puts("Not unique");
		return 0;
	}
	for(int i=0;i<N;i++)printf("%s\n",map[i]);
	return 0;
}
//*/