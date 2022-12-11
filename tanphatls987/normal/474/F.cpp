#include <algorithm>
#include <iostream>
#include <fstream>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <deque>
#include <vector>
#include <queue>
#include <map>

using namespace std;

#define X first
#define Y second
#define INPUT freopen(".inp","r",stdin)
#define OUTPUT freopen(".out","w",stdout)
#define FOR(i,l,r) for(int i=l;i<=r;i++)
#define REP(i,l,r) for(int i=l;i<r;i++)
#define FORD(i,l,r) for(int i=l;i>=r;i--)
#define REPD(i,l,r) for(int i=l;i>r;i--)
#define ENDL printf("\n")

typedef long long ll;
typedef pair<int,int> ii;

const int inf=2e9;
const int MOD=1e9+7;
const int N=1e5+10;

map <int,int> r;
struct node{
    int l,r,v;
}a[N<<2];
int v[N],n,x,y,q,val,c2=0;
vector <int> p[N];
int gcd(int x,int y){
    while (y){
        int tmp=y;
        y=x%y,x=tmp;
    }return x;
}
void build(int L,int R,int node){
    //printf("%d %d %d\n",node,L,R);
    a[node].l=L,a[node].r=R;
    if (L==R){
        a[node].v=v[L];
        return;
    }
    build(L,(L+R)/2,node*2);
    build((L+R)/2+1,R,node*2+1);
    a[node].v=gcd(a[node*2].v,a[node*2+1].v);
}
void query(int node){
    if (a[node].l>y||a[node].r<x) return;
    if (a[node].l>=x&&a[node].r<=y){
        val=gcd(val,a[node].v);
        return;
    }
    query(node*2);query(node*2+1);
}
void prepare(){
    scanf("%d",&n);
    FOR(i,1,n){
        scanf("%d",v+i);
        if (r[v[i]]==0) r[v[i]]=++c2;
        p[r[v[i]]].push_back(i);
    }
    build(1,n,1);
}
int main(){
    prepare();
    scanf("%d",&q);
    while (q--){
        scanf("%d%d",&x,&y);
        val=v[x],x++;
        query(1);
        int i=r[val];
        x--;
        if (i==0) printf("%d\n",y-x+1);
        else{
            int R=upper_bound(p[i].begin(),p[i].end(),y)-lower_bound(p[i].begin(),p[i].end(),x);
            printf("%d\n",y-x+1-R);
        }
    }
}