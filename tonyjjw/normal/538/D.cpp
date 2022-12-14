//*
#include<stdio.h>
#include<tuple>
#include<algorithm>
#include<vector>
#include<set>
#pragma warning(disable:4996)
#define pb push_back
#define eb emplace_back
#define mt make_tuple
#define mp make_pair
#define MN 50
using namespace std;

int N;
char A[MN][MN+1];
char out[2*MN-1][2*MN];

set<pair<int,int> >S,S2;

int main(){
//	freopen("input.txt","r",stdin),freopen("output.txt","w",stdout);
	scanf("%d",&N);
	for(int i=0;i<N;i++)scanf("%s",A[i]);
	for(int i=0;i<N;i++){
		for(int j=0;j<N;j++){
			if(A[i][j]!='o')continue;
			for(int x=0;x<N;x++){
				for(int y=0;y<N;y++){
					if(A[x][y]!='.')continue;
					S.insert(mp(x-i,y-j));
				}
			}
		}
	}
	for(int i=0;i<N;i++){
		for(int j=0;j<N;j++){
			if(A[i][j]!='x')continue;
			int f=0;
			for(int x=0;x<N;x++){
				for(int y=0;y<N;y++){
					if(A[x][y]!='o')continue;
					if(S.find(mp(i-x,j-y))==S.end()){
						S2.insert(mp(i-x,j-y));
						f=1;
						break;
					}
				}
				if(f)break;
			}
			if(!f){
				puts("NO");
				return 0;
			}
		}
	}
	puts("YES");
	for(int i=0;i<2*N-1;i++)for(int j=0;j<2*N-1;j++)out[i][j]='.';
	out[N-1][N-1]='o';
	for(auto p:S2){
		int x=N-1+p.first;
		int y=N-1+p.second;
		if(x<0 || x>2*N-1 || y<0 || y>2*N-1)continue;
		out[x][y]='x';
	}
	for(int i=0;i<2*N-1;i++)printf("%s\n",out[i]);
	return 0;
}
//*/