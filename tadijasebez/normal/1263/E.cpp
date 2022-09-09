#include <bits/stdc++.h>
using namespace std;
const int N=1000050;
const int M=2*N;
int root,tsz,ls[M],rs[M],mn[M],mx[M],lzy[M];
void Add(int &c,int ss,int se,int qs,int qe,int f){
	if(qs>qe || qs>se || ss>qe)return;
	if(!c)c=++tsz;
	if(qs<=ss && qe>=se){mn[c]+=f;mx[c]+=f;lzy[c]+=f;return;}
	int mid=ss+se>>1;
	Add(ls[c],ss,mid,qs,qe,f);
	Add(rs[c],mid+1,se,qs,qe,f);
	mn[c]=min(mn[ls[c]],mn[rs[c]])+lzy[c];
	mx[c]=max(mx[ls[c]],mx[rs[c]])+lzy[c];
}
char s[N];
int val[N],sum;
int main(){
	int n;
	scanf("%i",&n);
	scanf("%s",s+1);
	for(int i=1,cur=1;i<=n;i++){
		if(s[i]=='L')cur=max(1,cur-1);
		else if(s[i]=='R')cur++;
		else if(s[i]=='('){
			Add(root,1,n,1,cur,-1-val[cur]);
			sum+=-1-val[cur];
			val[cur]=-1;
		}else if(s[i]==')'){
			Add(root,1,n,1,cur,1-val[cur]);
			sum+=1-val[cur];
			val[cur]=1;
		}else{
			Add(root,1,n,1,cur,0-val[cur]);
			sum+=0-val[cur];
			val[cur]=0;
		}
		if(mn[root]>=0 && sum==0)printf("%i ",mx[root]);
		else printf("-1 ");
	}
	return 0;
}