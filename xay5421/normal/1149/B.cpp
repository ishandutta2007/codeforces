#include<cstdio>
#include<vector>
#define rep(i,a,b) for(int i=((int)a);i<=((int)b);++i)
#define per(i,a,b) for(int i=((int)a);i>=((int)b);--i)
int n,q,nxt[100005][26],f[255][255][255];char s[100005];std::vector<int>wd[3];
int getop(){int ch;while(ch=getchar(),ch!='+'&&ch!='-');return ch;}
int get(){int ch;while(ch=getchar(),ch<'a'||'z'<ch);return ch;}
template<typename T>T min(const T&x,const T&y){return x<y?x:y;}
void pre(){
	rep(i,0,25)nxt[n+1][i]=nxt[n+2][i]=n+1;
	per(i,n,1)
		rep(j,0,25)
			nxt[i][j]=(s[i]=='a'+j?i:nxt[i+1][j]);
}
void calc(int a,int b,int c){
	int&res=f[a][b][c];res=n+1;
	if(a)res=min(res,nxt[f[a-1][b][c]+1][wd[0][a-1]-'a']);
	if(b)res=min(res,nxt[f[a][b-1][c]+1][wd[1][b-1]-'a']);
	if(c)res=min(res,nxt[f[a][b][c-1]+1][wd[2][c-1]-'a']);
}
int main(){
	scanf("%d%d%s",&n,&q,s+1);
	pre();
	while(q--){
		int tp=getop(),x,c;scanf("%d",&x);--x;
		if(tp=='+'){
			c=get();
			wd[x].push_back(c);
			rep(i,x==0?wd[0].size():0,wd[0].size())
				rep(j,x==1?wd[1].size():0,wd[1].size())
					rep(k,x==2?wd[2].size():0,wd[2].size())
						calc(i,j,k);
			puts(f[wd[0].size()][wd[1].size()][wd[2].size()]==n+1?"NO":"YES");
		}
		else{
			wd[x].pop_back();
			puts(f[wd[0].size()][wd[1].size()][wd[2].size()]==n+1?"NO":"YES");
		}
	}
	return 0;
}