#include<bits/stdc++.h>
#define mod 1000000007
using namespace std;
char S[1000005];
int cnt,vis[100051],in[1000005],Map[1000005],In[1000005],VIS[105],qwq[30][100005],w[100005][30],ans[100005],n,q;
struct kkk{
    int son[26],fail,flag,ans;
    void clear(){memset(son,0,sizeof(son)),fail=flag=ans=0;}
}trie[1000005];
queue<int>Q;
void insert(char* s,int num){
    int u=1,len=strlen(s);
    for(int i=0;i<len;i++){
        int v=s[i]-'a';
        if(!trie[u].son[v])trie[u].son[v]=++cnt;
        u=trie[u].son[v];
    }
    if(!trie[u].flag)trie[u].flag=num;
    Map[num]=trie[u].flag;
}
void getFail(){
    for(int i=0;i<26;i++)trie[0].son[i]=1;
    Q.push(1);
    while(!Q.empty()){
        int u=Q.front();Q.pop();
        int Fail=trie[u].fail;
        for(int i=0;i<26;i++){
            int v=trie[u].son[i];
            if(!v){trie[u].son[i]=trie[Fail].son[i];continue;}
            trie[v].fail=trie[Fail].son[i]; in[trie[v].fail]++;
            Q.push(v);
        }
    }
}
string s,t;
inline void Query(int x)
{
    int u=1,len=s.size();
    for(int i=0;i<=cnt;i++) trie[i].ans=0;
    memset(vis,0,sizeof vis);
    for(int i=0;i<len;i++)
    	u=trie[u].son[s[i]-'a'],trie[u].ans++;
    for(int i=1;i<=cnt;i++)
	    if((In[i]=in[i])==0)Q.push(i);
    while(!Q.empty()){
        int u=Q.front();Q.pop();vis[trie[u].flag]=trie[u].ans;
        int v=trie[u].fail;In[v]--;
        trie[v].ans+=trie[u].ans;
        if(In[v]==0)Q.push(v);
    }
    for(int i=1;i<=q;i++) qwq[x][i]=vis[Map[i]];
}
int p[100005];
int main(){
	int mx=0;
	cin >> n >> q >> s >> t;
    cnt=1;
    for(int i=1;i<=q;i++)
	{
    	cin >> p[i];
        scanf("%s",S);
        mx=max(mx,(int)strlen(S));
        insert(S,i);
    }getFail();
    Query(0);
    for(auto X:t) VIS[X-'a'+1]=1;
   // cout << s << "\n" << mx << "\n";
    int QaQ=0;
	for(int i=1;i<=n;i++)
	{
		s=s+t[i-1]+s;
		QaQ=i;
		if(s.size()>=mx) break;
		Query(i);
	}
//	cout << s << " " << QaQ << "\n";
//	Query(1);
	for(int i=1;i<=q;i++)
		if(p[i]<QaQ) ans[i]=qwq[p[i]][i];
	Query(0),s=s+'a'+s;
	for(int i=1;i<=26;i++)
		if(VIS[i])s[s.size()/2]=i+'a'-1,Query(i);
	w[QaQ][0]=1;
	for(int i=QaQ+1;i<=n;i++)
	{
		for(int j=0;j<=26;j++) w[i][j]=w[i-1][j]*2%mod;
		w[i][0]=(w[i][0]+mod-2)%mod,w[i][t[i-1]-'a'+1]=(w[i][t[i-1]-'a'+1]+1)%mod;
	}
//	cout << w[2][0] << " " << w[2][1] << " " << w[2][2] << " " << w[2][3] << " " << w[2][4]<< "\n"; 
//	cout << w[3][0] << " " << w[3][1] << " " << w[3][2] << " " << w[3][3] << " " << w[3][4]<< "\n"; 
	for(int i=1;i<=q;i++)
	{
		if(p[i]<QaQ)
			printf("%d\n",ans[i]);
		else
		{
			int Ans=0;
			for(int j=0;j<=26;j++)
				Ans=(Ans+(long long)w[p[i]][j]*qwq[j][i])%mod;
			printf("%d\n",Ans);
		}
	}
    return 0;
}