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
//cout.precision(x)  cout<<fixed<<val;  // prints x digits after decimal in val

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

/////////////////////////////////
/////////   FFT    //////////////
/////////////////////////////////

int N=(1<<20);
int K=20;
struct base{
	double x, y;
	base(double xx, double yy){
		x = xx;
		y = yy;
	}
	base(double xx){
		x = xx;
		y = 0;
	}
	base(){
		x = 0;
		y = 0;
	}

	base operator + (const base &o){
		return base(x+o.x, y+o.y);
	}
	base operator - (const base &o){
		return base(x - o.x, y - o.y);
	}
	base operator = (const base &o){
		x=o.x;
		y=o.y;
		return *this;
	}
	base operator * (const base &o){
		return base(x*o.x - y*o.y, y*o.x + x*o.y);
	}
	base operator * (const double &num){
		return base(x*num, y*num);
	}
	base operator / (const double &num){
		return base(x/num, y/num);	
	}
	double norm(const base &o){
		return (o.x*o.x + o.y*o.y);
	}

	base operator / (const base &o){
		double val = norm(o);
		return base((x*o.x+y*o.y)/val, (y*o.x - x*o.y)/val);
	}

};

const long double pi = atan(1.0)*4.0;
base a[(1<<20)+3],b[(1<<20)+3];
ll res[(1<<20)+3];
int rev[(1<<20)+3];

void pre(){
	int i,j,ans;
	rep(i,N){
		ans=0;
		rep(j,K){
			if(i&(1<<j)){
				ans+=(1<<(K-j-1));
			}
		}
		rev[i] = ans; 
	}
}

void fft(base a[],bool inv){
	int i,j,gap;
	rep(i,N){
		if(rev[i]>i){
			swap(a[i],a[rev[i]]);
		}
	}
	for(gap = 1; gap < N; gap *= 2){
		base w(cos(pi/gap), sin(pi/gap) * (inv ? -1 : 1));
		for(i = 0; i < N; i += 2*gap){
			base cur(1,0);
			rep(j,gap){
				base u = a[i+j];
				base v = a[i+j+gap]*cur;
				a[i+j] = u+v;
				a[i+j+gap] = u-v;
				cur = cur*w;
			}
		}
	}
}

void multiply(base a[],base b[]){
	int i;
	pre();
	fft(a,0);
	fft(b,0);
	rep(i,N){
		a[i] = a[i]*b[i];
	}
	fft(a,1);
	rep(i,N){
		res[i]=(ll)((a[i].x)/N +0.5);
	}
}
char arr[4]={ 'A', 'T', 'G','C'};
int result[(1<<19)+3],haha[(1<<19)+3];
int main(){
    std::ios::sync_with_stdio(false);
    int k;
    cin>>k;
    cin>>k;
    cin>>k;
    string s,t;
    cin>>s>>t;
    int n=s.length();
    K=0;
    while((1<<K)<n) K++;
    K++;
    N=(1<<K);
    int i,j;

    rep(j,4){
    	rep(i,N){
    		a[i]=base();
    		b[i]=base();
    	}
    	rep(i,s.length()){
    		if(s[i]==arr[j]){
    			haha[i]=1;
    			//a[i]=base(1);
    		}
    		else{
    			haha[i]=0; 
    		}
    	}
    	int previ=-inf;
    	rep(i,s.length()){
    		if(haha[i]){
    			previ=i;
    			a[i]=base(1);
    		}
    		else if(i-previ<=k){
    			a[i]=base(1);
    		}
    	}
    	previ=inf;
    	fd(i,s.length()-1,0){
    		if(haha[i]){
    			previ=i;
    			a[i]=base(1);
    		}
    		else if(previ-i<=k){
    			a[i]=base(1);
    		}
    	}

    	rep(i,t.length()){
    		if(t[i]==arr[j])
    			b[t.length()-i-1]=base(1);
    	}
    	multiply(a,b);
    	f(i,t.length()-1,s.length()){
    		result[i]+=res[i];
    	}
    }
    int cnt=0;
    rep(i,s.length()){
    	if(result[i]>=t.length())
    		cnt++;
    }
    cout<<cnt<<endl;
    return 0;   
}