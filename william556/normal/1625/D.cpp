#include<bits/stdc++.h>
using namespace std;
inline int in(){
	int x;
	scanf("%d",&x);
	return x;
}
const int N=3e5+5;
int n,k,o;
int a[N];
int rt=1,tot=1;
int ls[N*30],rs[N*30],sz[N*30],id[N*30],dep[N*30];
vector<int> ans;
void ins(int x,int _id){
	int p=rt;
	for(int i=29;i>=0;i--){
		if(x&(1<<i))p=rs[p]?rs[p]:rs[p]=++tot;
		else p=ls[p]?ls[p]:ls[p]=++tot;
		sz[p]++,dep[p]=i-1;
	}
	id[p]=_id;
}
int getid(int p){
	if(dep[p]==-1)return id[p];
	if(sz[ls[p]])return getid(ls[p]);
	else return getid(rs[p]);
}
bool flag;
void dfs(int p,int q){
	if(!p||!q||flag)return;
	int d=dep[p];
	if(d==-1){
		if(!flag){
			flag=1;
			ans.push_back(id[p]);
			ans.push_back(id[q]);
		}
		return;
	}
	if(k&(1<<d)){
		dfs(ls[p],rs[q]);
		dfs(rs[p],ls[q]);
	}else{
		if(ls[p]&&rs[q]){
			ans.push_back(getid(ls[p]));
			ans.push_back(getid(rs[q]));
			flag=1;
			return;
		}
		if(rs[p]&&ls[q]){
			ans.push_back(getid(rs[p]));
			ans.push_back(getid(ls[q]));
			flag=1;
			return;
		}
		dfs(ls[p],ls[q]);
		dfs(rs[p],rs[q]);
	}
}
int main(){
	n=in(),k=in();
	if(k==0){
		cout<<n<<endl;
		for(int i=1;i<=n;i++)printf("%d ",i);
		return 0;
	}
	for(o=0;1<<o+1<=k;o++);
	dep[1]=29;
	for(int i=1;i<=n;i++)a[i]=in(),ins(a[i],i);
	for(int i=1;i<=tot;i++){
		if(dep[i]==o){
			if(sz[ls[i]]&&!sz[rs[i]]){
				ans.push_back(getid(ls[i]));
			}
			if(sz[rs[i]]&&!sz[ls[i]]){
				ans.push_back(getid(rs[i]));
			}
			if(sz[ls[i]]&&sz[rs[i]]){
				flag=0;
				dfs(ls[i],rs[i]);
				if(!flag)ans.push_back(getid(ls[i]));
			}
		}
	}
	if(ans.size()<2)puts("-1");
	else{
		cout<<ans.size()<<endl;
		sort(ans.begin(),ans.end());
		for(int i:ans)printf("%d ",i);
	}
	return 0;
}