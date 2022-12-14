#include<cstdio>
#include<vector>
#include<string>
#include<cstring>
#include<algorithm>

using namespace std;

bool G[440][440];
int N;

bool isVowel[30];
char nxtVowel[30];
char nxtConsonant[30];
char first_V,first_C;

char ch[30];
int L;

char S[220];

int M;

void init_rules(){
	for(int i=0;i<M;i++){
		int pos1,pos2;
		char t1[2];
		char t2[2];
		scanf("%d%s%d%s",&pos1,t1,&pos2,t2);
		pos1--;pos2--;
		int v1=pos1*2+(t1[0]=='V'?0:1);
		int v2=pos2*2+(t2[0]=='V'?0:1);
		G[v1][v2]=true;
		G[v2^1][v1^1]=true;
	}
}

void init_ctypes(){
	scanf("%s",ch);
	L=strlen(ch);
	for(int i=0;i<L;i++){
		isVowel[i]=(ch[i]=='V');
	}
	for(int i=0;i<L;i++){
		nxtVowel[i]=('z'+1);
		nxtConsonant[i]=('z'+1);
		for(int j=i+1;j<L;j++){
			if(isVowel[j]){
				nxtVowel[i]='a'+j;
				break;
			}
		}
		for(int j=i+1;j<L;j++){
			if(!isVowel[j]){
				nxtConsonant[i]='a'+j;
				break;
			}
		}
	}
	first_C=('z'+1);
	first_V=('z'+1);
	for(int i=L-1;i>=0;i--){
		if(isVowel[i]) first_V='a'+i;
		else first_C='a'+i;
	}
}

vector<int> vs;
int ord[440];
bool visited[440];

void dfs(int v){
	visited[v]=true;
	for(int u=0;u<N*2;u++){
		if(!G[v][u]) continue;
		if(visited[u]) continue;
		dfs(u);
	}
	vs.push_back(v);
}

void rdfs(int v,int k){
	ord[v]=k;
	for(int u=0;u<N*2;u++){
		if(!G[u][v]) continue;
		if(ord[u]!=-1) continue;
		rdfs(u,k);
	}
}

void scc(bool debug=false){
	/*for(int i=0;i<N*2;i++){
		for(int j=0;j<N*2;j++){
			printf("%d ",G[i][j]?1:0);
		}
		printf("\n");
	}*/	
	for(int i=0;i<N*2;i++){
		visited[i]=false;
		ord[i]=-1;
	}
	vs.clear();
	for(int i=0;i<N*2;i++){
		if(!visited[i]) dfs(i);
	}
	int k=0;
	for(int i=(int)vs.size()-1;i>=0;i--){
		int v=vs[i];
		if(ord[v]==-1) rdfs(v,k++);
	}
	if(debug){
	for(int i=0;i<N*2;i++){
		printf("%d ",ord[i]);
	}
	printf("\n");
	}
}

bool isValid(){
	scc();
	for(int i=0;i<N;i++){
		int u=i*2;
		int v=i*2+1;
		if(ord[u]==ord[v]) return false;
	}
	return true;
}

void addEdge(int pos,char ch){
	if(isVowel[ch-'a']) G[pos*2+1][pos*2]=true;
	else G[pos*2][pos*2+1]=true;
}

void delEdge(int pos){
	G[pos*2][pos*2+1]=false;
	G[pos*2+1][pos*2]=false;
}

char ans[220];

void solve(){
	for(int i=0;i<N;i++){
		if(isVowel[S[i]-'a']) G[i*2+1][i*2]=true;
		else G[i*2][i*2+1]=true;
	}
	bool flg=isValid();
	if(flg){
		strcpy(ans,S);
		return;
	}
	strcpy(ans,S);
	int lcp=-1;
	for(int i=N-1;i>=0;i--){
		delEdge(i);
		char cands[2];
		cands[0]=nxtConsonant[S[i]-'a'];
		cands[1]=nxtVowel[S[i]-'a'];
		if(cands[0]>cands[1]) swap(cands[0],cands[1]);
		bool suc=false;
		for(int j=0;j<2;j++){
			if(cands[j]>'z') continue;
			addEdge(i,cands[j]);
			bool flg=isValid();
			if(flg){
				suc=true;
				ans[i]=cands[j];
				break;
			}
			delEdge(i);
		}
		if(suc){
			lcp=i;
			break;
		}
	}
	if(lcp==-1){
		ans[0]='\0';
		return;
	}
	for(int i=lcp+1;i<N;i++){
		char cands[2];
		cands[0]=first_C;
		cands[1]=first_V;
		if(cands[0]>cands[1]) swap(cands[0],cands[1]);
		bool suc=false;
		for(int j=0;j<2;j++){
			if(cands[j]>'z') continue;
			addEdge(i,cands[j]);
			bool flg=isValid();
			if(flg){
				suc=true;
				ans[i]=cands[j];
				break;
			}
			delEdge(i);
		}
		if(!suc){
			ans[0]='\0';
			return;
		}
	}
	ans[N]='\0';
	return;
}

void input(){
	init_ctypes();
	scanf("%d%d",&N,&M);
	init_rules();
	scanf("%s",S);
}

int main(){
	input();
	solve();
	if(ans[0]=='\0'){
		printf("-1\n");
	}else{
		printf("%s\n",ans);
	}
	return 0;
}