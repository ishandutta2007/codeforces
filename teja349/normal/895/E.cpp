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


double seg[412345],lazyadd[412345],lazymul[412345];
double eps=0.0001;
double updatelazymul(int node,int s,int e){
	seg[node]=seg[node]*lazymul[node]+lazyadd[node]*(e-s+1);
	if(s!=e){
		lazymul[2*node]*=lazymul[node];
		lazymul[2*node+1]*=lazymul[node];
		lazyadd[2*node]*=lazymul[node];
		lazyadd[2*node+1]*=lazymul[node];
		lazyadd[2*node]+=lazyadd[node];
		lazyadd[2*node+1]+=lazyadd[node];
	}
	lazymul[node]=1;
	lazyadd[node]=0;
	return 0;
}
//std::ios::sync_with_stdio(false);   
double updatemul(int node,int s,int e,int l,int r,double val){
	if(abs(lazymul[node]-1)>=eps || abs(lazyadd[node])>eps){
		updatelazymul(node,s,e);
	}
	
	if(e<l || r<s){
		return 0;
	}
	if(l<=s && e<=r){
		seg[node]*=val;
		if(s!=e){
			lazymul[2*node]*=val;
			lazyadd[2*node]*=val;
			lazymul[2*node+1]*=val;
			lazyadd[2*node+1]*=val;
		}
		return 0;
	}
	int mid=(s+e)/2;
	updatemul(2*node,s,mid,l,r,val);
	updatemul(2*node+1,mid+1,e,l,r,val);
	seg[node]=seg[2*node]+seg[2*node+1];
	return 0;

}


double updateadd(int node,int s,int e,int l,int r,double val){
	if(abs(lazymul[node]-1)>=eps|| abs(lazyadd[node])>eps){
		updatelazymul(node,s,e);
	}
	
	if(e<l || r<s){
		return 0;
	}
	if(l<=s && e<=r){
		seg[node]+=val*(e-s+1);
		if(s!=e){
			//lazy[2*node]*=val;
			lazyadd[2*node]+=val;
			//lazymul[2*node+1]*=val;
			lazyadd[2*node+1]+=val;
		}
		return 0;
	}
	int mid=(s+e)/2;
	updateadd(2*node,s,mid,l,r,val);
	updateadd(2*node+1,mid+1,e,l,r,val);
	seg[node]=seg[2*node]+seg[2*node+1];
	return 0;



}

double query(int node,int s,int e,int l,int r){
	if(abs(lazymul[node]-1)>=eps|| abs(lazyadd[node])>eps){
		updatelazymul(node,s,e);
	}
	
	if(e<l || r<s){
		return 0;
	}
	if(l<=s && e<=r){
		return seg[node];
	}
	int mid=(s+e)/2;

	double a=query(2*node,s,mid,l,r);
	double b=query(2*node+1,mid+1,e,l,r);
	//cout<<node<<" "<<seg[2*node+1]<<endl;
	return a+b;
}
double a[123456];
int build(int node,int s,int e){
	lazymul[node]=1;
	lazyadd[node]=0;
	if(s==e)
	{
		seg[node]=a[s];
		return 0;
	}
	int mid=(s+e)/2;
	build(2*node,s,mid);
	build(2*node+1,mid+1,e);
	seg[node]=seg[2*node]+seg[2*node+1];
	return 0;
}
int main(){
    std::ios::sync_with_stdio(false);
    int n,q;
    eps*=eps;
    cin>>n>>q;
    int i;
    rep(i,n){
    	cin>>a[i];
    }
    build(1,0,n-1);
    int type,l1,l2,r1,r2,l,r;
    double val1,val2,val;
    //cout<<query(1,0,n-1,1,2)<<endl;
    
    while(q--){
    	cin>>type;
    	if(type==1){
    		cin>>l1>>r1>>l2>>r2;
    		l1--;
    		l2--;
    		r1--;
    		r2--;
    		val1=query(1,0,n-1,l1,r1);
    		val2=query(1,0,n-1,l2,r2);

    		val=(r1-l1)*1.00/(r1-l1+1);
    		//cout<<val<<endl;
    		updatemul(1,0,n-1,l1,r1,val);
    		val=(r2-l2)*1.00/(r2-l2+1);
    		updatemul(1,0,n-1,l2,r2,val);
    		val1/=(r1-l1+1);
    		val1/=(r2-l2+1);
    		val2/=(r1-l1+1);
    		val2/=(r2-l2+1);
    		//cout<<val<<" "<<val<<endl;
    		updateadd(1,0,n-1,l1,r1,val2);
    		updateadd(1,0,n-1,l2,r2,val1);
    		//turn 0;
    	}
    	else{
    		cin>>l>>r;
    		l--;
    		r--;
    		//cout<<"Dadsas"<<endl;
    		cout<<setprecision(20)<<query(1,0,n-1,l,r)<<endl;
    	}
    }
    return 0;  
    
}