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
vi vec(12345);
vii vec1;
int n;
int baba[12345][20];
int faf[12345],gg[12345];
int comp(pii a,pii b){
	if(a.ff!=b.ff)
		return a.ff>b.ff;
	return a.ss>b.ss;
} 
int precomp(){
	int i,j;
	rep(i,n){
		baba[i][0]=vec[i]-vec[i+1];
	}
	f(j,1,19){
		rep(i,n){
			if((i+(1<<(j-1)))<n){
				baba[i][j]=max(baba[i][j-1],baba[i+(1<<(j-1))][j-1]);
			}
		}
	}
	return 0;
}
int findmax(int i,int j){
	int val=log2(j-i+1);
	//val=ceil(val);
	return max(baba[i][val],baba[j-(1<<val)+1][val]);
}
int siz,siz1,siz2,sizz,sizz1,sizz2,coord,flag=0;
int calc(){
	flag=0;
	sizz1=sizz/2;
	if(sizz%2)
		sizz1++;
	sizz2=(2*sizz);
	sizz1=max(sizz1,siz1);
	sizz2=min(siz2,sizz2);
	if(sizz1>sizz2)
		return 0;
	sizz1+=coord;
	sizz2+=coord;
	if(sizz1>=n)
		return 0;
	flag=1;
	return findmax(sizz1,min(sizz2,n-1));
}
int calc1(){
	sizz1=sizz/2;
	if(sizz%2)
		sizz1++;
	sizz2=(2*sizz);
	sizz1=max(sizz1,siz1);
	sizz2=min(siz2,sizz2);
	if(sizz1>sizz2)
		return 0;
	sizz1+=coord;
	sizz2+=coord;
	int i,wow=-1,gag;
	f(i,sizz1,min(sizz2+1,n)){
		if(wow<baba[i][0]){
			wow=baba[i][0];
			gag=i;
		}
	}
	f(i,coord+1,gag+1){
		gg[i]=3;
	}
	f(i,gag+1,n){
		gg[i]=-1;
	}
	rep(i,n){
		faf[vec1[i].ss]=gg[i];
	}
	rep(i,n){
		cout<<faf[i]<<" ";
	}
	exit(0);
}
int a[12345];
int main(){
    std::ios::sync_with_stdio(false);
	
	cin>>n;
	//int val=log2(1);
	//cout<<val<<endl;
	int i;
	rep(i,n){
		cin>>a[i];
		vec1.pb(mp(a[i],i));
	}  
	sort(vec1.begin(),vec1.end(),comp);
	rep(i,n){
		vec[i]=vec1[i].ff;
	}
	vec[n]=0;
	precomp();
	tri ans;
	tri maxi;
	ans.ff=-1;
	ans.ss.ff=0;
	ans.ss.ss=0;
	maxi=ans;
	int j;
	int rem1,rem2,coco;
	rep(i,n-2){
		siz = i+1;
		ans.ff = vec[i]-vec[i+1];
		siz1=siz/2;
		if(siz%2)
			siz1++;
		siz2=2*siz;
		f(j,siz1,siz2+1){
			if(j+i>=n-1){
				break;
			}
			ans.ss.ff=vec[j+i]-vec[j+i+1];
			sizz=j;
			coord=i+j;
			flag=0;
			ans.ss.ss=calc();

			if(flag==1){
				if(maxi<ans){
					maxi=ans;
					rem1=siz;
					rem2=sizz;
					coco=coord;
				}
				
			}
		}
	}
	siz=rem1;
	siz1=siz/2;
	if(siz%2)
		siz1++;
	siz2=2*siz;
	sizz=rem2;
	coord=coco;
	rep(i,siz){
		gg[i]=1;
	}
	f(i,siz,coord+1){
		gg[i]=2;
	}
	//cout<<baba[n-1][0]<<endl;
	calc1();
    return 0;  
    
}