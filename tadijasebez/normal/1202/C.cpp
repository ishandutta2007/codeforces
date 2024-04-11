#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int N=400050;
const int M=4*2*N;
int root[4],tsz,ls[M],rs[M],mx[M],lzy[M];
void Add(int &c,int ss,int se,int qs,int qe,int f){
	if(qs>qe || qs>se || ss>qe)return;
	if(!c)c=++tsz,lzy[c]=0,mx[c]=0,ls[c]=rs[c]=0;
	if(qs<=ss && qe>=se){lzy[c]+=f;mx[c]+=f;return;}
	int mid=ss+se>>1;
	Add(ls[c],ss,mid,qs,qe,f);
	Add(rs[c],mid+1,se,qs,qe,f);
	mx[c]=max(mx[ls[c]],mx[rs[c]])+lzy[c];
}
ll Get(){return (ll)(mx[root[0]]+mx[root[1]]+1)*(mx[root[2]]+mx[root[3]]+1);}
void cl(){root[0]=root[1]=root[2]=root[3]=tsz=0;}
char s[N];
int gt(char c){
	if(c=='W')return 0;
	if(c=='S')return 1;
	if(c=='A')return 2;
	if(c=='D')return 3;
}
int ft(char c){return gt(c)^1;}
void run(){
	cl();
	scanf("%s",s+1);
	int n=strlen(s+1);
	for(int i=1;i<=n;i++)
		Add(root[gt(s[i])],0,n*2+2,0,i*2,1),
		Add(root[ft(s[i])],0,n*2+2,0,i*2,-1);
	ll ans=Get();
	for(int i=1;i<=2*n+1;i+=2){
		for(char c:{'W','A','S','D'})
			Add(root[gt(c)],0,n*2+2,0,i,1),
			Add(root[ft(c)],0,n*2+2,0,i,-1),
			ans=min(ans,Get()),
			Add(root[gt(c)],0,n*2+2,0,i,-1),
			Add(root[ft(c)],0,n*2+2,0,i,1);
	}
	printf("%lld\n",ans);
}
int main(){
	int t;
	scanf("%i",&t);
	while(t--)run();
	return 0;
}