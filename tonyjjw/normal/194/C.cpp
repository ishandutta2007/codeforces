#include<stdio.h>

int N,M;

char map[51][51];
int dx[]={1,0,0,-1},dy[]={0,1,-1,0};
int v[51][51];

void dfs(int x,int y){
	int k,ddx,ddy;
	v[x][y]=1;
	for(k=0;k<4;k++){
    	ddx=x+dx[k],ddy=y+dy[k];
    	if(ddx<0 || ddy<0 || ddx>=N || ddy>=M)continue;
    	if(map[ddx][ddy]!='#')continue;
    	if(v[ddx][ddy])continue;
    	dfs(ddx,ddy);
	}
}

int main(){
	int i,j,k=0,l;
//	freopen("input","r",stdin);
	scanf("%d%d",&N,&M);
	for(i=0;i<N;i++)scanf("%s",map[i]);
	for(i=0;i<N;i++){
    	for(j=0;j<M;j++){
        	if(map[i][j]=='#')k++;
    	}
	}
	if(k<=2){
    	puts("-1");
    	return 0;
	}
	for(i=0;i<N;i++){
    	for(j=0;j<M;j++){
        	if(map[i][j]=='#'){
            	map[i][j]='.';
            	for(k=0;k<N;k++)for(l=0;l<M;l++)v[k][l]=0;
            	for(k=0;k<N;k++){
                	for(l=0;l<M;l++){
                    	if(map[k][l]=='#')break;
                	}
                	if(l<M)break;
            	}
            	if(k==N){
                	break;
            	}
            	dfs(k,l);
            	for(k=0;k<N;k++){
                	for(l=0;l<M;l++){
                    	if(map[k][l]=='#' && !v[k][l])break;
                	}
                	if(l<M)break;
            	}
            	if(k<N){
                	break;
            	}
            	map[i][j]='#';
        	}
    	}
    	if(j<M)break;
	}
	if(i<N){
    	puts("1");
    	return 0;
	}
	puts("2");
	return 0;
}