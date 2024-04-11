#include <stdio.h>
#include <vector>
#include <cstring>
using namespace std;
const int N=200050;
const int M=2*N*8;
const int inf=2*N;
int min(int a, int b){ return a>b?b:a;}
int x[M],ls[M],rs[M],tsz,root;
void Set(int &c, int ss, int se, int qi, int val)
{
	if(!c) c=++tsz,x[c]=M;
	x[c]=min(x[c],val);
	if(ss==se) return;
	int mid=ss+se>>1;
	if(qi<=mid) Set(ls[c],ss,mid,qi,val);
	else Set(rs[c],mid+1,se,qi,val);
}
int Get(int c, int ss, int se, int qs, int qe)
{
	if(ss>qe || qs>se) return M;
	if(qs<=ss && qe>=se) return x[c];
	int mid=ss+se>>1;
	return min(Get(ls[c],ss,mid,qs,qe),Get(rs[c],mid+1,se,qs,qe));
}
int val[26];
char s[N];
int main()
{
	x[0]=M;
	int n,i;
	for(i=0;i<26;i++) val[i]=2;
	val['a'-'a']=val['e'-'a']=val['i'-'a']=val['o'-'a']=val['u'-'a']=-1;
	scanf("%s",s+1);
	n=strlen(s+1);
	int sol=0,cnt=0,sum=0;
	Set(root,-inf,inf,0,0);
	for(i=1;i<=n;i++)
	{
		if(s[i]>='A' && s[i]<='Z') s[i]-='A',s[i]+='a';
		sum+=val[s[i]-'a'];
		int ans=Get(root,-inf,inf,-sum,inf);
		//printf("ans:%i sum:%i\n",ans,sum);
		if(ans!=M)
		{
			if(sol<i-ans) sol=i-ans,cnt=1;
			else if(sol==i-ans) cnt++;
		}
		Set(root,-inf,inf,-sum,i);
	}
	if(sol==0) printf("No solution\n");
	else printf("%i %i\n",sol,cnt);
	return 0;
}