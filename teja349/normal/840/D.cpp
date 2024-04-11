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
#define inf (1000*1000*1000+5)
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
total seg[300005*4*20];
int root[312345];
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
int query1(int rot1,int rot2,int s,int e,int reqd){
    //cout<<s<<" "<<e<<endl;
    //cout<<seg[seg[rot1].l].val-seg[seg[rot2].l].val<<endl;
    if(s==e){
        return s;
    }
    
    int mid=(s+e)/2;
    if(seg[seg[rot1].l].val-seg[seg[rot2].l].val>=reqd){

        return query1(seg[rot1].l,seg[rot2].l,s,mid,reqd);
    }
    else{
        //cout<<"sad"<<endl;
        reqd-=seg[seg[rot1].l].val-seg[seg[rot2].l].val;
        return query1(seg[rot1].r,seg[rot2].r,mid+1,e,reqd);
    }

}
int query2(int rot,int s,int e,int elem){
    if(s==e){
        return seg[rot].val;
    }
    int mid=(s+e)/2;
    if(elem<=mid){
        return query2(seg[rot].l,s,mid,elem);
    }
    else{
        return query2(seg[rot].r,mid+1,e,elem);
    }
}
int a[312345];
int main(){
    int n,q,i,l,r,k;
    scanf("%d%d",&n,&q);
    root[0]=build(0,n+10);
    f(i,1,n+1){
         scanf("%d",&a[i]);
        root[i]=update(root[i-1],0,n+10,a[i]);
    }
    //int q;
    while(q--){
         scanf("%d%d%d",&l,&r,&k);
        //l--;
        //r--;
        int total=(r-l+1)/k;
        // if(total==0){
        //     f(i,l,r+1){
        //         mini=min(ans,a[i]);
        //     }
        //     cout<<mini<<endl;
        //     continue;
        // }
        total++;
        //cout<<total<<endl;
        int lol=total,flag=1;
        while(lol<=r-l+1 && flag){
            int val=query1(root[r],root[l-1],0,n+10,lol);
            //cout<<lol<<" "<<val<<endl;
            if(query2(root[r],0,n+10,val)-query2(root[l-1],0,n+10,val)>=total)
            {
                printf("%d\n",val);
                flag=0;
            }
            
            lol+=total;

        }
        if(flag){
            printf("%d\n",-1);
        }



    }
}