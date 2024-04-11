#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define pii pair<int,int>
const int N=1000050;
/*const int M=4*N;
int root[2],tsz,ls[M],rs[M],sz[M];
void Set(int&c,int ss,int se,int qi){
	if(!c)c=++tsz;
	sz[c]++;
	if(ss==se)return;
	int mid=ss+se>>1;
	if(qi<=mid)Set(ls[c],ss,mid,qi);
	else Set(rs[c],mid+1,se,qi);
}
int Get(int c,int ss,int se,int qs,int qe){
	if(qs>qe||qs>se||ss>qe)return 0;
	if(qs<=ss&&qe>=se)return sz[c];
	int mid=ss+se>>1;
	return Get(ls[c],ss,mid,qs,qe)+Get(rs[c],mid+1,se,qs,qe);
}
int Search(int c,int ss,int se,int k){
	if(ss==se)return ss;
	int mid=ss+se>>1;
	if(sz[ls[c]]<k)return Search(rs[c],mid+1,se,k-sz[ls[c]]);
	else return Search(ls[c],ss,mid,k);
}*/
char s[N];
set<pii> st[2];
vector<pii> del[2][N];
int n;
int Search(int t,int ptr,int sz){
	auto it=st[t].lower_bound({ptr+1,-N});
	if(it!=st[t].begin()){
		if(prev(it)->second>=ptr+sz-1)return ptr+sz-1;
	}
	if(it!=st[t].end())return it->first+sz-1;
	return n+1;
}
int main(){
	scanf("%i",&n);
	scanf("%s",s+1);
	int cnt1=0,cnt2=0;
	for(int i=1;i<=n+1;i++){
		if(s[i]=='0'||s[i]=='?'){
			cnt1++;
		}else{
			if(cnt1)st[0].insert({i-cnt1,i-1});
			cnt1=0;
		}
		if(s[i]=='1'||s[i]=='?'){
			cnt2++;
		}else{
			if(cnt2)st[1].insert({i-cnt2,i-1});
			cnt2=0;
		}
		//if(s[i]!='0')Set(root[1],1,n+1,i);
		//if(s[i]!='1')Set(root[0],1,n+1,i);
	}
	for(pii p:st[0])del[0][p.second-p.first+1].pb(p);
	for(pii p:st[1])del[1][p.second-p.first+1].pb(p);
	for(int i=1;i<=n;i++){
		int ptr=0,ans=0;
		while(ptr<=n){
			int ptr1=Search(0,ptr+1,i);//Search(root[0],1,n+1,i+Get(root[0],1,n+1,1,ptr));
			int ptr2=Search(1,ptr+1,i);//Search(root[1],1,n+1,i+Get(root[1],1,n+1,1,ptr));
			ans++;
			ptr=min(ptr1,ptr2);
			//printf("%i ",ptr);
		}
		printf("%i ",ans-1);
		//printf("\n");
		for(pii p:del[0][i])st[0].erase(p);
		for(pii p:del[1][i])st[1].erase(p);
	}
	return 0;
}