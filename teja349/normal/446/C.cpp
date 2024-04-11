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
#define mod (1000*1000*1000+9)
#define pqueue priority_queue< int >
#define pdqueue priority_queue< int,vi ,greater< int > >

//std::ios::sync_with_stdio(false);   
int a[312345],seg[4*300000+29];
int mat[300045][3][3];
pii lazy[4*300000+29];
int build(int node,int s,int e){
	if(s==e){
		seg[node]=a[s];
		return 0;
	}	
	int mid=(s+e)/2;
	build(2*node,s,mid);
	build(2*node+1,mid+1,e);
	seg[node]=seg[2*node]+seg[2*node+1];
	if(seg[node]>=mod)
		seg[node]-=mod;
	return 0;
}
pii updatelazy(int node,int s,int e){
	//cout<<"lol"<<lazy[node].ff<<" "<<lazy[node].ss<<" "<<e<<endl;
	pii haha;
	int mid=(s+e)/2;
	ll val=1LL * lazy[node].ff * mat[(e-s+1)][0][1];
	val%=mod;
	val+=1LL * lazy[node].ss * mat[(e-s+1)][0][2];
	val%=mod;
	//cout<<val<<" sas"<<endl;
	seg[node]+=val;
	if(seg[node]>=mod){
		seg[node]-=mod;
	}
	mid++;
	mid-=s;
	if(s==e){
		return haha;
	}

	val=1LL * lazy[node].ff * mat[mid][1][1] + 1LL * lazy[node].ss * mat[mid][1][2];
	val%=mod;
	haha.ff=val;
	val=1LL * lazy[node].ff * mat[mid][2][1] + 1LL * lazy[node].ss * mat[mid][2][2];
	val%=mod;
	haha.ss=val;
	return haha;
}	
pii getval(int l,int s){
	s-=l;
	if(s==0){
		return mp(1,0);
	}
	pii haha;
	haha.ff=mat[s][1][1];
	haha.ss=mat[s][2][1];
	return haha;


}
int add(pii &a,pii b){
	a.ff+=b.ff;
	if(a.ff>=mod){
		a.ff-=mod;
	}
	a.ss+=b.ss;
	if(a.ss>=mod){
		a.ss-=mod;
	}
	return 0;
}
int query(int node,int s,int e,int l ,int r){
	pii haha;
	if(lazy[node]!=mp(0,0)){

		haha=updatelazy(node,s,e);
		//cout<<haha.ff<<" "<<haha.ss<<" "<<s<<" "<<e<<endl;
		if(s!=e){
			add(lazy[2*node],lazy[node]);
			add(lazy[2*node+1],haha);
			lazy[node]=mp(0,0);
		}
		else{
			lazy[node]=mp(0,0);
		}

	}
	if(l>e || r<s){
		return 0;
	}
	if(l<=s && e<=r){
		return seg[node];
	}
	int mid=(s+e)/2;
	int aa=query(2*node,s,mid,l,r);
	int ab=query(2*node+1,mid+1,e,l,r);
	if(aa+ab>=mod){
		return (aa+ab-mod);
	}
	else{
		return (aa+ab);
	}
	return 0;
}

int update(int node,int s,int e,int l ,int r){
	pii haha;
	//cout<<"yoo"<<endl;
	if(lazy[node]!=mp(0,0)){
		haha=updatelazy(node,s,e);
		//cout<<haha.ff<<" "<<haha.ss<<" "<<s<<" "<<e<<endl;
		if(s!=e){
			add(lazy[2*node],lazy[node]);
			add(lazy[2*node+1],haha);
			lazy[node]=mp(0,0);
		}
		else{
			lazy[node]=mp(0,0);
		}

	}
	if(l>e || r<s){
		return 0;
	}
	if(l<=s && e<=r){
		
		haha=getval(l,s);

		
		add(lazy[node],haha);
		if(lazy[node]!=mp(0,0)){
		haha=updatelazy(node,s,e);
			//cout<<haha.ff<<" "<<haha.ss<<" "<<s<<" "<<e<<endl;
			if(s!=e){
				add(lazy[2*node],lazy[node]);
				add(lazy[2*node+1],haha);
				lazy[node]=mp(0,0);
			}
			else{
				lazy[node]=mp(0,0);
			}

		}
		return 0;
	}
	int mid=(s+e)/2;
	update(2*node,s,mid,l,r);
	update(2*node+1,mid+1,e,l,r);
	seg[node]=seg[2*node]+seg[2*node+1];
	if(seg[node]>=mod)
		seg[node]-=mod;
	return 0;

}
int pre(int n){
	ll base[3][3]={0};
	base[0][0]=base[0][1]=base[1][1]=base[1][2]=base[2][1]=1;
	int i,j,p,q,r,k;
	rep(i,3){
		rep(j,3){
			mat[1][i][j]=base[i][j];
		}
	}
	ll lol[3][3]={0};
	f(i,2,n+10){
		rep(p,3){
			rep(q,3){
				rep(r,3){
					lol[p][q]+=base[p][r]*mat[i-1][r][q];
					lol[p][q]%=mod;
				}
			}
		}
		rep(p,3){
			rep(q,3){
				mat[i][p][q]=lol[p][q];
				lol[p][q]=0;
			}
		}
	}
	return 0;
}
int main(){
    std::ios::sync_with_stdio(false);
    int n,m,i,t,l,r;
    cin>>n>>m;
    pre(n);
    rep(i,n){
    	cin>>a[i];
    }
    rep(i,4*n+12){
    	lazy[i]=mp(0,0);
    	seg[i]=0;
    }
    build(1,0,n-1);
    while(m--){
    	cin>>t>>l>>r;
    	l--;
    	r--;
    	if(t==1){
    		update(1,0,n-1,l,r);

    	}
    	else{
    		cout<<query(1,0,n-1,l,r)<<endl;
    	}
    }
    return 0;
}