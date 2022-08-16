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
struct node{
	int l;
	int r;
	int val;
};
int counter=0,n;
node seg[52345*70];
vector<vi> vec(52345);
int a[52345],root[52345];
int dp[36000][57];

int build(int s,int e){
	if(s==e){
		//cout<<"dsa";
		seg[counter].val=0;
		seg[counter].l=-1;
		seg[counter].r=-1;
		counter++;
		return counter-1;
	}

	int mid=(s+e)/2;
	int aa=build(s,mid);
	int bb=build(mid+1,e);
	seg[counter].val=0;
	seg[counter].l=aa;
	seg[counter].r=bb;
	counter++;
	return counter-1;
}
int update(int s,int e,int rot,int pos,int vali){
	//cout<<"Sas;";
	if(s==e){
		seg[counter].val=seg[rot].val+vali;
		seg[counter].l=-1;
		seg[counter].r=-1;
		counter++;
		return counter-1;
	}
	int mid=(s+e)/2;
	if(pos<=mid){
		//seg[counter].r=seg[rot].r;
			
		int lol=update(s,mid,seg[rot].l,pos,vali);
		seg[counter].l=lol;
		seg[counter].r=seg[rot].r;
		seg[counter].val=seg[seg[counter].l].val+seg[seg[counter].r].val;
		counter++;
		return counter-1;
	}	
	else{
		int lol=update(mid+1,e,seg[rot].r,pos,vali);
		seg[counter].r=lol;
		seg[counter].l=seg[rot].l;
		seg[counter].val=seg[seg[counter].l].val+seg[seg[counter].r].val;
		counter++;
		return counter-1;
	}
	return 0;
}
//vector< vector<int>> mapi(35020,vi (3000,-1));
int query(int s,int e,int rot,int l,int r){
	if(e<l || r<s){
		return 0;
	}
	if(l<=s && e<=r){
		return seg[rot].val;
	}
	int mid=(s+e)/2;
	int sumi=0;
	sumi+=query(s,mid,seg[rot].l,l,r);
	sumi+=query(mid+1,e,seg[rot].r,l,r);
	return sumi;
}
int previ[100000];
int compute(int k,int st,int en,int l,int r){
	int mid=(st+en)/2,i;
	if(st>en){
		return 0;
	}
	dp[mid][k]=-100000;
	int l1=max(mid,l);
	i=l1;
	int ans;
	if(l1<=r){
		ans=query(1,n,root[i],mid,i);
		dp[mid][k]=ans+dp[l1+1][k-1];
	}
	//dp[mid][k]=query(1,n,root[i],mid,i);
	int rem=l1;
	
	f(i,l1+1,r+1){

		if(previ[i]<mid){
			ans++;
		}
		//cout<<i<<" "<<mid<<" "<<ans<<endl;
		if(dp[mid][k]<ans+dp[i+1][k-1]){
			rem=i;
			dp[mid][k]=ans+dp[i+1][k-1];
		}

	}
	//cout<<mid<<" "<<rem<<" "<<dp[mid][k]<<endl;
	//return 0;	
	compute(k,st,mid-1,l,rem);
	compute(k,mid+1,en,rem,r);
	return 0;
}
int main(){
   // std::ios::sync_with_stdio(false);
    int k;
    cin>>n>>k;
    int i;
    f(i,1,n+1){
    	scanf("%d",&a[i]);
    }
    root[0]=build(1,n);
    f(i,1,n+1){
    	vec[a[i]].pb(i);
    	int lol=vec[a[i]].size();
    	if(lol>1){
    		//cout<<i<<endl;
    		int val=update(1,n,root[i-1],vec[a[i]][lol-2],-1);


    		root[i]=update(1,n,val,i,1);
    		previ[i]=vec[a[i]][lol-2];
    	}
    	else{
    		root[i]=update(1,n,root[i-1],i,1);
    		previ[i]=-1;
    	}
    }

    set<int>seti;
    fd(i,n,1){
    	seti.insert(a[i]);

    	dp[i][1]=seti.size();
    }
    //return 0;
    f(i,2,k+1){
    	dp[n+1][i-1]=-100000;
    	compute(i,1,n,1,n);
    	//return 0;
    }
    cout<<dp[1][k]<<endl;


    return 0;      

}