#include<bits/stdc++.h>
using namespace std;
inline void Max(int &a,int b){if(a<b)a=b;}
const int N=5000;
int n,m,c;
char s[N];
int tot,ch[N][20],fail[N],v[N];
void insert(char *s){
	int p=0;
	for(int i=1;s[i];i++){
		int c=s[i]-'a';
		if(!ch[p][c])ch[p][c]=++tot;
		p=ch[p][c];
	}
	v[p]+=c;
}
void build(){
	queue<int> q;
	for(int i=0;i<12;i++)if(ch[0][i])q.push(ch[0][i]);
	while(q.size()){
		int i=q.front();q.pop();
		v[i]+=v[fail[i]];
		for(int c=0;c<12;c++){
			if(!ch[i][c])ch[i][c]=ch[fail[i]][c];
			else fail[ch[i][c]]=ch[fail[i]][c],q.push(ch[i][c]);
		}
	}
}
void init(){
	static bool mark[N];
	static char res[30];
	for(int i=0;i<12;i++)mark[i]=0;
	for(int i=0;i<30;i++)res[i]=0;
	int p=15;res[p]=s[1];
	for(int i=2;i<=m;i++){
		if(res[p-1]==s[i])p--;
		else if(res[p+1]==s[i])p++;
		else if(!res[p+1]&&!mark[s[i]-'a'])res[++p]=s[i];
		else if(!res[p-1]&&!mark[s[i]-'a'])res[--p]=s[i];
		else return;
		mark[s[i]-'a']=1;
	}
	static char t[20];int tp=0;
	for(int i=0;i<20;i++)t[i]=0;
	for(int i=0;i<30;i++)if(res[i])t[++tp]=res[i];
	insert(t);
	if(tp>1){
		reverse(t+1,t+tp+1);
		insert(t);
	}
}
int f[N][N],g[N][N],h[N][N];
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%d",&c);
		scanf("%s",s+1);
		m=strlen(s+1);
		init();
	}
	build();
	memset(f,-1,sizeof(f));
	f[0][0]=0;
	for(int s=0;s<1<<12;s++){
		for(int j=0;j<=tot;j++){
			if(f[s][j]<0)continue;
			for(int i=0;i<12;i++){
				if(s>>i&1)continue;
				int now=f[s][j]+v[ch[j][i]];
				if(now>f[s|1<<i][ch[j][i]]){
					f[s|1<<i][ch[j][i]]=now;
					g[s|1<<i][ch[j][i]]=j;
					h[s|1<<i][ch[j][i]]=i;
				}
			}
		}
	}
	int id=0;
	for(int i=1;i<=tot;i++)
		if(f[4095][i]>f[4095][id])id=i;
	for(int s=4095;s;){
		printf("%c",'a'+h[s][id]);
		int x=h[s][id];
		id=g[s][id],s^=1<<x;
	}
	puts("");
	return 0;
}