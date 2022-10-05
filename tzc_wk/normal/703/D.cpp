#include <bits/stdc++.h>
using namespace std;
typedef vector<pair<int,int> >::iterator vit;
#define lowbit(a)	(a&(-a))
#define LiuYuHan ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
const int N=1000000+5;
map<int,int> s;
vector<pair<int,int> > queries[N];
int n,m,l,r,ss,g,a[N],ans[N],sum[N];
//BIT code area begins here
int Tree[N];
void add(int x,int v){
    for(int i=x;i<=N;i+=lowbit(i))	Tree[i]^=v;
} 
int q(int x){
    int sum=0;
    for(int i=x;i;i-=lowbit(i))	sum^=Tree[i];
    return sum;
}
//BIT code area ends here
int main(){
    LiuYuHan
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        sum[i]=sum[i-1]^a[i];
    }
    cin>>m;
    for(int i=1;i<=m;i++){
        cin>>l>>r;
        queries[r].push_back(make_pair(l, i));
    }
    for(int i=1;i<=n;i++){
        ss=s[a[i]];
        if(ss!=0)	add(ss, a[i]);
        add(i,a[i]);
        s[a[i]]=i;
        for(vit it=queries[i].begin();it!=queries[i].end();it++){
            l=(*it).first;
            r=i;
            g=q(r)^q(l - 1);
            ans[(*it).second]=sum[l-1]^sum[r]^g;
        }
    }
    for(int i=1;i<=m;i++)	cout<<ans[i]<<"\n";
}