#include <bits/stdc++.h>
using namespace std;
const int N=100050;
int a[N];
struct Triple{ int x,y,z;Triple(int a=0, int b=0, int c=0){ x=a,y=b,z=c;}};
vector<Triple> ans;
void Flip(int x, int y, int z)
{
	a[x]^=1;a[y]^=1;a[z]^=1;
	ans.push_back(Triple(x,y,z));
}
void Flip(int x, int z)
{
	int dif=z-x;
	if(dif&1) printf("???\n");
	Flip(x,x+dif/2,z);
}
const int L=11;
const int M=1<<L;
int go[M];
bool was[M];
void BFS(int l, int r)
{
	int i,j,state=0;
    for(i=0;i<=r-l;i++) if(a[l+i]) state+=1<<i;
    queue<int> q;
	q.push(0);was[0]=1;
	while(q.size())
	{
        int mask=q.front();
        q.pop();
        for(j=1;j<=5;j++)
		{
			for(i=0;i+j*2<=r-l;i++)
			{
				int tmp=mask;
				tmp^=(1<<i);
				tmp^=(1<<(i+j));
				tmp^=(1<<(i+2*j));
				if(!was[tmp]) q.push(tmp),go[tmp]=mask,was[tmp]=1;
			}
		}
	}
	if(!was[state])
	{
		printf("NO\n");
		exit(0);
	}
	while(state)
	{
        int nxt=state^go[state];
        vector<int> tmp;
        for(i=0;i<=r-l;i++) if((nxt>>i)&1) tmp.push_back(i);
        ans.push_back(Triple(tmp[0]+l,tmp[1]+l,tmp[2]+l));
        state=go[state];
	}
}
void Solve(int l, int r)
{
	if(r-l<=10){ BFS(l,r);return;}
	if(a[l]==0){ Solve(l+1,r);return;}
	if(a[r]==0){ Solve(l,r-1);return;}
    if(a[l]==1 && a[l+1]==1 && a[l+2]==1){ Flip(l,l+1,l+2);Solve(l+1,r);return;}
    if(a[l]==1 && a[l+1]==0 && a[l+2]==1){ Flip(l,l+2,l+4);Solve(l+1,r);return;}
    if(a[l]==1 && a[l+1]==0 && a[l+2]==0){ Flip(l,l+3,l+6);Solve(l+1,r);return;}
    if(a[r]==1 && a[r-1]==1 && a[r-2]==1){ Flip(r-2,r-1,r);Solve(l,r-1);return;}
    if(a[r]==1 && a[r-1]==0 && a[r-2]==1){ Flip(r-4,r-2,r);Solve(l,r-1);return;}
    if(a[r]==1 && a[r-1]==0 && a[r-2]==0){ Flip(r-6,r-3,r);Solve(l,r-1);return;}
    if((r-l+1)&1){ Flip(l,r);Flip(l+1,r-1);Solve(l,r);return;}
	else{ Flip(l,r-1);Flip(l+1,r);Solve(l,r);return;}
}
int main()
{
	int n,i;
	scanf("%i",&n);
	for(i=1;i<=n;i++) scanf("%i",&a[i]);
	Solve(1,n);
	printf("YES\n");
	printf("%i\n",ans.size());
	for(Triple t:ans) printf("%i %i %i\n",t.x,t.y,t.z);
	return 0;
}