#include<bits/stdc++.h>
using namespace std;
#define rep(i,j,k) for(int i=(j);i<=(k);i++)
#define per(i,j,k) for(int i=(j);i>=(k);i--)
#define ll long long
#define arr array<int8_t,13>
set<tuple<arr,int,int>>p;
set<arr>s2,s1;
int n,m,k,e[15][15];
ll as,ct[15],tt=1;
void dfs(arr a,int x,int y)
{
    if(x<y)
        swap(x,y);
    a[x]=y;
	if(p.count(make_tuple(a,x,y)))
        return;
	p.insert(make_tuple(a,x,y));
    bool v[13]={};
	rep(i,1,n)
        if(a[i])
            v[i]=v[a[i]]=1;
	if(*min_element(v+1,v+n+1))
    {
        if(e[x][y])
            s1.insert(a);
        return;
    }
	rep(i,1,n)
        if(e[x][i]&&!v[i])
            rep(j,1,n)
                if(i!=j&&e[y][j]&&!v[j])
                    dfs(a,i,j);
}
void sol(arr a,int x)
{
	while(x<=n&&a[x])
        x++;
	if(x>n)
    {
        rep(i,1,n)
        if(a[a[i]])
            a[i]=a[a[i]];
                s2.insert(a);
        return;
    }
	vector<int>v;
    rep(i,x+1,n)
        if(!a[i])
            v.push_back(i);
	int l=v.size(); 
	rep(s,0,(1<<l)-1)
    {   
        arr nw=a;
		rep(i,0,l-1)
            if(s>>i&1)
                nw[v[i]]=x;
		sol(nw,x+1);
	}
}
int main()
{
    scanf("%d%d%d",&n,&m,&k); int x,y;
	rep(i,1,n)e[0][i]=e[i][0]=1;
	rep(i,1,m)
        scanf("%d%d",&x,&y),e[x][y]=e[y][x]=1;
	dfs(arr(),0,0);
	for(arr y:s1)
        sol(y,1);
	for(arr a:s2)
    {
        int tt=0;
		rep(i,1,n)
            if(!a[i])
                tt++;
        ct[tt]++;
	}
	rep(i,1,n/2)
    {
        tt=tt*(k-i+1);
		as+=tt*ct[i];
	}
    printf("%lld\n",as);
    return 0;
}