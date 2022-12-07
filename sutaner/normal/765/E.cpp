#include<set>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<stack>
#define maxn 200005
using namespace std;
int n,root;
set<int> geo[maxn];
int vis[maxn],exi[maxn],size[maxn];
int f=1,cnt=0,cha=0;
/*set<int> DFS(int x,int depth){
	if(geo[x].size()==1&&x!=root){
		set<int> cal;
		cal.insert(0);
		return cal;
	}
	vis[x]=true;
	set<int> cal,k;
	for(int i=0;i<geo[x].size();i++){
		if(vis[geo[x][i]])continue;
		k=DFS(geo[x][i],depth+1);
		if(k.size()>2||f==-1){f=-1;k.clear();return k;}
		for(set<int>::iterator it=k.begin();it!=k.end();it++){
			if(*it+1!=depth)
				cal.insert(*it+1);
		}
		if(cal.size()>2||f==-1){f=-1;cal.clear();return cal;}
	}
	return cal;
}*/
int DFS(int x){
	vis[x]=cnt;
	set<int> cal;
	stack<int> ans;
	int f=0;
	for(set<int>::iterator it=geo[x].begin();it!=geo[x].end();it++){
		if(vis[*it]==cnt||exi[*it]==0)continue;
		f=1;
		int k=DFS(*it);
		if(k==-1)continue;
		if(cal.count(k+1)){
			cha=1;
			exi[*it]=0;
			ans.push(*it);
			continue;
		}
		cal.insert(k+1);
	}
	while(!ans.empty()){
		geo[x].erase(ans.top());
		ans.pop();
	}
	if(f==0){
		return 0;
	}
	if(cal.size()==1){
		return *cal.begin();
	} 
	return -1;
}
int DFS2(int x){
	vis[x]=cnt;
	int k=0;
	for(set<int>::iterator it=geo[x].begin();it!=geo[x].end();it++){
		if(vis[*it]==cnt)continue;
		if(exi[*it]==0)return -1;
		k=DFS2(*it);
		if(k==-1)return -1;
	}
	return k+1;
}
int main(){
	/*freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);*/
	scanf("%d",&n);
	int u,v;
	for(int i=0;i<n-1;i++){
		scanf("%d%d",&u,&v);
		geo[u].insert(v);
		geo[v].insert(u);
	}
	for(int i=1;i<=n;i++)
		exi[i]=1;
	for(;;){
		int max1=0,max2;
		for(int j=1;j<=n;j++){
			if(exi[j]==0)continue;
			int op=geo[j].size();
			if(max1<op){
				max1=op;
				max2=j;
			}
		}
		if(max1<=2){
			cnt++;
			for(int j=1;j<=n;j++){
				if(exi[j]==0||vis[j]==cnt||geo[j].size()!=1)continue;
				int out=DFS2(j);
				if(out!=-1){
					out--;
					while(out!=0&&out%2==0)out=out/2;
					printf("%d",out);
					return 0;
				}
			}
		}else{
			cnt++;
			DFS(max2);
			if(cha==0){
				printf("-1");
				return 0;
			}
		}
		cha=0;
	}
	/*set<int> k=DFS(root,0);
	if(k.size()>1||f==-1)
		printf("-1");
	else {	
	    int sum=0;
		for(set<int>::iterator it=k.begin();it!=k.end();it++){
			sum+=*it;
		}
		printf("%d",sum);
	}*/
	return 0;
}