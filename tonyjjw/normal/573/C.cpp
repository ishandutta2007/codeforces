#include<stdio.h>
#include<vector>
#include<stdlib.h>
#pragma warning(disable:4996)
#define MN 100000
using namespace std;

int N;
vector<int> E[MN];
int side[MN];
int chain[MN];
int line[MN];

int V[MN];
bool ans=true;

int rand32(){
	return (rand()<<16)+rand();
}

void dfs(int n){
	V[n]=1;
	vector<int> ch;
	for(int t:E[n])if(!V[t]){
		dfs(t);
		ch.push_back(t);
	}
	if(ch.empty()){
		line[n]=chain[n]=side[n]=1;
		return;
	}
	if(ch.size()==1 && line[ch[0]])line[n]=1;
	if(ch.size()==2 && line[ch[0]] && line[ch[1]])chain[n]=1;
	chain[n]|=line[n];

	int cnt=0;
	for(int p:ch){
		if(chain[p])cnt++;
	}
	if(cnt+1>=ch.size()){
		side[n]=1;
		for(int p:ch){
			if(!chain[p] && !side[p])side[n]=0;
		}
	}
	bool tmp=true;
	if(cnt+2>=ch.size()){
		int sp;
		for(int p:ch){
			if(!chain[p] && !side[p]){
				tmp=false;
				sp=p;
			}
		}
		if(tmp==true)return;

		if(ch.size()>3){
			ans=false;
			return;
		}
		
		for(int p:ch){
			if(p!=sp && !line[p])ans=false;
		}
	}
	else ans=false;
}

int main(){
//	freopen("input.txt","r",stdin),freopen("output.txt","w",stdout);
	scanf("%d",&N);
	for(int i=0;i<N-1;i++){
		int a,b;
		scanf("%d%d",&a,&b),--a,--b;
		E[a].push_back(b),E[b].push_back(a);
	}
	for(int cc=20;cc>=0;cc--){
		for(int i=0;i<N;i++)V[i]=0,line[i]=side[i]=chain[i]=0;
		int n=rand32()%N;
		dfs(n);
		if(ans==true){
			puts("Yes");
			return 0;
		}
	}
	puts("No");
	return 0;
}