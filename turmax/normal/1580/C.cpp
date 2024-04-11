#pragma GCC optimize("O3","Ofast","unroll-loops")
#pragma GCC target("avx2")
#include <bits/stdc++.h>

using namespace std;
const int maxn=4e5+4309;
const int maxn1=2e5+5;
const int sq=1200;
static int t[maxn];
static int z[sq][sq];
int n=maxn;
int sum (int r)
{
	int result = 0;
	for (; r >= 0; r = (r & (r+1)) - 1)
		result += t[r];
	return result;
}

void inc (int i, int delta)
{
	for (; i < n; i = (i | (i+1)))
		t[i] += delta;
}

int sum (int l, int r)
{
	return sum (r) - sum (l-1);
}

/*void init (vector<int> a)
{
	init ((int) a.size());
	for (unsigned i = 0; i < a.size(); i++)
		inc (i, a[i]);
}*/
void pl1(int val,int x,int y)
{
    if((x+y)<sq)
    {
        int l=((val+x)%(x+y));int r=(val+x+y)%(x+y); 
        int o=(x+y);
        while(l!=r)
        {
            z[o][l]++;
            ++l;
            if(l==o) l=0;
        }
        return;
    }
    x=min(x,maxn1);y=min(y,maxn1-x);
    while(val<maxn1)
    {
        inc(val+x,1);
        //cout<<val+x<<" val2 "<<endl;
        inc(val+x+y,-1);
        val+=(x+y);
    }
}
void mi1(int val,int x,int y)
{
    if((x+y)<sq)
    {
    int l=((val+x)%(x+y));int r=(val+x+y)%(x+y); 
        int o=(x+y);
        while(l!=r)
        {
            z[o][l]--;
            ++l;
            if(l==o) l=0;
        }
        return;
    }
    x=min(x,maxn1);y=min(y,maxn1-x);
    while(val<maxn1)
    {
        inc(val+x,-1);
        //cout<<val+x<<" val2 "<<endl;
        inc(val+x+y,1);
        val+=(x+y);
    }
}
int get(int t)
{
    int ans=sum(t);
    for(int i=1;i<sq;++i)
    {
        ans+=z[i][t%i];
    }
    return ans;
}
int32_t main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int n,m;
    cin>>n>>m;
    pair <int,int> a[n];
    for(int i=0;i<n;++i) {cin>>a[i].first>>a[i].second;}
    int cnt[n]={0};
    int r=0;
    for(int i=0;i<m;++i)
    {
        int typ,pos;
        cin>>typ>>pos;
        pos--;
        if(typ==1)
        {
            cnt[pos]=i;
            ++r;
            pl1(i,a[pos].first,a[pos].second);
        }
        else
        {
            --r;
            mi1(cnt[pos],a[pos].first,a[pos].second);
        }
        cout<<get(i)<<'\n';
    }
    return 0;
}