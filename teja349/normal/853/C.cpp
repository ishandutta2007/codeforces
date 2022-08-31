//teja349
#include <bits/stdc++.h>
#include <vector>
#include <set>
#include <map>
#include <string>
#include <cstdio>
#include <cstdlib>
#include <climits>
#include <utility>
#include <algorithm>
#include <cmath>
#include <queue>
#include <stack>
#include <iomanip> 
//setbase - cout << setbase (16); cout << 100 << endl; Prints 64
//setfill -   cout << setfill ('x') << setw (5); cout << 77 << endl; prints xxx77
//setprecision - cout << setprecision (14) << f << endl; Prints x.xxxx


using namespace std;
#define f(i,a,b) for(i=a;i<b;i++)
#define rep(i,n) f(i,0,n)
#define fd(i,a,b) for(i=a;i>=b;i--)
#define pb push_back
#define mp make_pair
#define vi vector< int >
#define vl vector< ll >
#define ss second
#define ff first
#define ll long long
#define pii pair< int,int >
#define pll pair< ll,ll >
#define sz(a) a.size()
#define inf (1000*1000*100+5)
#define all(a) a.begin(),a.end()
#define tri pair<int,pii>
#define vii vector<pii>
#define vll vector<pll>
#define viii vector<tri>
#define mod (1000*1000*1000+7)
#define pqueue priority_queue< int >
#define pdqueue priority_queue< int,vi ,greater< int > >

//std::ios::sync_with_stdio(false);  
struct total{
    int l,r,val;
};
int counter=1;
total seg[210005*4*20];
int root[212345];
int build(int s,int e){
    if(s==e){
        seg[counter].val=0;
        seg[counter].l=-1;
        seg[counter++].r=-1;
        return counter-1;
    }
    int mid=(s+e)/2;
    int a=build(s,mid);
    int b=build(mid+1,e);
    seg[counter].l=a;
    seg[counter].r=b;
    seg[counter].val=0;
    counter++;
    return counter-1;
}   
int update(int rot,int s,int e,int pos){
    if(s==e){
       // cout<<s<<"dassda"<<endl;
        seg[counter].val=seg[rot].val+1;
        seg[counter].l=-1;
        seg[counter].r=-1;
        counter++;
        return counter-1;
    }
    int mid=(s+e)/2;
    if(pos<=mid){
        int a=update(seg[rot].l,s,mid,pos);
        seg[counter].l=a;
        seg[counter].r=seg[rot].r;
        seg[counter].val=seg[seg[counter].l].val+seg[seg[counter].r].val;
        counter++;
        return counter-1;
    }
    else{
        int a=update(seg[rot].r,mid+1,e,pos);
        seg[counter].r=a;
        seg[counter].l=seg[rot].l;
        seg[counter].val=seg[seg[counter].l].val+seg[seg[counter].r].val;
        counter++;
        return counter-1;
    }
}
ll n;
int queryseg(int rot,int s,int e,int l,int r){
    if(r<l)
        return 0;
    if(l<=s && e<=r){
        return seg[rot].val;

    }   
    if(e<l || r<s){
        return 0;
    } 
    int mid=(s+e)/2;
    int a=queryseg(seg[rot].l,s,mid,l,r);
    int b=queryseg(seg[rot].r,mid+1,e,l,r);
    return a+b;
}
int queryrec(int d,int u,int l,int r){
    if(d>u || r<l)
        return 0;
    int val;
    //cout<<"Vs";
    val=queryseg(root[u],0,n+10,0,r);
    //cout<<val<<"dasad"<<endl;
    val+=queryseg(root[d-1],0,n+10,0,l-1);
    val-=queryseg(root[d-1],0,n+10,0,r);
    val-=queryseg(root[u],0,n+10,0,l-1);
    return val;
}
int a[312345];

int solve(){
    int l,r,u,d;
    ll ans=0,val;

   // cin>>l>>d>>r>>u;
    scanf("%d%d%d%d",&l,&d,&r,&u);
    //val=queryrec(1,n,1,l-1);
    //cout<<val<<endl;
    //return 0;
    val=queryrec(u+1,n,1,n);
    ans+=val*(val-1);
    val=queryrec(1,d-1,1,n);
    ans+=val*(val-1);
    val=queryrec(1,n,1,l-1);
    //cout<<val<<endl;
    ans+=val*(val-1);
    val=queryrec(1,n,r+1,n);
    ans+=val*(val-1);
    val=queryrec(u+1,n,1,l-1);
    ans-=val*(val-1);
    val=queryrec(u+1,n,r+1,n);
    ans-=val*(val-1);
    val=queryrec(1,d-1,1,l-1);
    ans-=val*(val-1);
    val=queryrec(1,d-1,r+1,n);
    ans-=val*(val-1);
    ans=n*(n-1)-ans;
    ans/=2;
    //cout<<ans<<"\n";
    //ans=inf;
    //?//ans*=inf;
    //ans/=100;
    printf("%lld\n",ans);
    return 0;

}
vii vec;
int main(){
    //std::ios::sync_with_stdio(false); 
    int q,i;
    cin>>n>>q;
    f(i,1,n+1){
        scanf("%d",&a[i]);
        vec.pb(mp(a[i],i));
    }
    sort(vec.begin(),vec.end());
    root[0]=build(0,n+10);
    int haha=1,papa;
    i=0;
    while(haha<=n+10){

        papa=root[haha-1];
        //cout<<vec[i].ff<<endl;
        while(i<vec.size() && vec[i].ff==haha){
            //cout<<"assa"<<endl;
            papa=update(papa,0,n+10,vec[i].ss);
            i++;
        }
        root[haha]=papa;
        haha++;
    }
    rep(i,q){
        solve();
    }

    
}