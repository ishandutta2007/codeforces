// author: xay5421
// created: Fri Nov 12 14:20:34 2021
#ifdef xay5421
#define D(...) fprintf(stderr,__VA_ARGS__)
#else
#define D(...) ((void)0)
//#define NDEBUG
#endif
#include<bits/stdc++.h>
#define mp make_pair
#define pb push_back
#define eb emplace_back
#define SZ(x) ((int)(x).size())
#define rep(i,a,b) for(int i=(a);i<=(b);++i)
#define per(i,a,b) for(int i=(a);i>=(b);--i)
using namespace std;
char c[15][123];
pair<int,int>pre[52][1024];
int nxt[15][123][52],len[15],dp[52][1024],id[15][123],pos[15][52][2];
int T,n,ans,ansi,ansj;
inline int getid(char c){
	if(c>='a'&&c<='z')return c-'a';
	return c-'A'+26;
}
struct zt{
	int i,j;
	zt(int k1=0,int k2=0):i(k1),j(k2){}
};
bool operator<(const zt a,const zt b){
	int pos1=pos[0][a.i][a.j&1];
	int pos2=pos[0][b.i][b.j&1];
	return pos1>pos2;
}
priority_queue<zt>Q;
void upd(int i,int j,int ndp,pair<int,int>val){
	if(ndp>dp[i][j]){
		if(dp[i][j]==-1)Q.push(zt(i,j));
		dp[i][j]=ndp;
		pre[i][j]=val;
		if(ndp>ans){
			ans=ndp;
			ansi=i;
			ansj=j;
		}
	}
}
int main(){
	scanf("%d",&T);
	while(T--){
		ans=0;
		memset(nxt,-1,sizeof(nxt));
		memset(pos,-1,sizeof(pos));
		memset(dp,-1,sizeof(dp));
		scanf("%d",&n);
		rep(i,0,n-1){
			scanf("%s",c[i]+1);
			len[i]=strlen(c[i]+1);
			per(j,len[i],1){
				memcpy(nxt[i][j],nxt[i][j+1],sizeof(nxt[i][j]));
				nxt[i][j][getid(c[i][j])]=j;
			}
			static int cnt[52];
			memset(cnt,0,sizeof(cnt));
			rep(j,1,len[i]){
				id[i][j]=cnt[getid(c[i][j])];
				pos[i][getid(c[i][j])][cnt[getid(c[i][j])]]=j;
				++cnt[getid(c[i][j])];
			}
		}
		rep(i,0,51){
			int ok=1;
			rep(j,0,n-1){
				if(pos[j][i][0]==-1){
					ok=0;
					break;
				}
			}
			if(ok){
				upd(i,0,1,mp(-1,-1));
			}
		}
		while(!Q.empty()){
			zt u=Q.top();Q.pop();
			rep(i,0,51){
				int st=0,ok=1;
				rep(j,0,n-1){
					int now=pos[j][u.i][(u.j>>j)&1];
					if(nxt[j][now+1][i]==-1){
						ok=0;
						break;
					}
					if(id[j][nxt[j][now+1][i]])st|=1<<j;
				}
				if(ok)upd(i,st,dp[u.i][u.j]+1,mp(u.i,u.j));
			}
		}
		if(ans==0){
			printf("0\n\n");
			continue;
		}
		static char res[123];
		int tmp=ans;
		while(ansi!=-1){
			res[tmp]=(ansi<26?ansi+'a':ansi-26+'A');
			pair<int,int>p=pre[ansi][ansj];
			ansi=p.first;ansj=p.second;--tmp;
		}
		printf("%d\n",ans);
		rep(i,1,ans)printf("%c",res[i]);
		puts("");
	}
	return 0;
}