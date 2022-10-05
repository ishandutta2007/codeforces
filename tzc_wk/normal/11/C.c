#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#define REP(i,a,b) for(i=a;i<b;i++)
#define rep(i,n) REP(i,0,n)

int x,y;
char in[300][300];

int cnt;

void nul(int a,int b,char from,char to){
  int i,j;
  if(a<0||b<0||a>=x||b>=y||in[a][b]!=from) return;
  cnt++; in[a][b]=to;
  REP(i,-1,2) REP(j,-1,2) nul(a+i,b+j,from,to);
}

int is_ok(int i,int j){
  if(i<0||j<0||i>=x||j>=y||in[i][j]!='2') return 0;
  return 1;
}

int main(){
  int i,j,k,l,m,n,len,ok,res;
  int size;

  scanf("%d",&size);
  while(size--){
    scanf("%d%d",&x,&y);
    rep(i,x) scanf("%s",in[i]);
    res=0;

    rep(i,x) rep(j,y) if(in[i][j]=='1'){
      cnt=0; nul(i,j,'1','2');
      if(cnt%4==0){
        len = cnt/4 + 1;

        ok=1;
        rep(k,len) if( !is_ok(i+k,j) ) ok=0;
        rep(k,len) if( !is_ok(i,j+k) ) ok=0;
        rep(k,len) if( !is_ok(i+len-1,j+k) ) ok=0;
        rep(k,len) if( !is_ok(i+k,j+len-1) ) ok=0;
        res += ok;

        ok=1;
        rep(k,len) if( !is_ok(i+k,j+k) ) ok=0;
        rep(k,len) if( !is_ok(i+k,j-k) ) ok=0;
        rep(k,len) if( !is_ok(i+2*len-2-k,j+k) ) ok=0;
        rep(k,len) if( !is_ok(i+2*len-2-k,j-k) ) ok=0;
        res += ok;
      }
      nul(i,j,'2','0');
    }

    printf("%d\n",res);
  }

  return 0;
}