#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef double ld;
#define mp make_pair
#define PI pair<ll,ll>
#define poly vector<ll>
#define mem(a) memset((a),0,sizeof(a))
#define For(i,l,r) for(int i=(int)(l);i<=(int)(r);i++)
#define Rep(i,r,l) for(int i=(int)(r);i>=(int)(l);i--)
#define pb push_back
#define fi first
#define se second
#define SZ(x) ((int)(x.size()))
inline char gc(){
    static char buf[100000],*p1=buf,*p2=buf;
    return p1==p2&&(p2=(p1=buf)+fread(buf,1,100000,stdin),p1==p2)?EOF:*p1++;
}
#define gc getchar
inline ll read(){
	ll x = 0; char ch = gc(); bool positive = 1;
	for (; !isdigit(ch); ch = gc())	if (ch == '-')	positive = 0;
	for (; isdigit(ch); ch = gc())	x = x * 10 + ch - '0';
	return positive ? x : -x;
}
inline void write(ll a){
    if(a<0){
    	a=-a; putchar('-');
	}
    if(a>=10)write(a/10);
    putchar('0'+a%10);
}
inline void writeln(ll a){write(a); puts("");}
inline void wri(ll a){write(a); putchar(' ');}
ll rnd(){
	ull ans=0;
	For(i,0,4)ans=ans<<15^rand();
	return ans%((ull)1<<63);
}
const int N=500005;
PI a[N];
ld d[N],q[N];
pair<ld,int> A[N];
bool vis[N];
int L[N],R[N],bel[N];
ll mul(PI a,PI b){
	return (ll)a.fi*b.se-(ll)a.se*b.fi;
}
int half(PI x){
	return x.se<0||(x.se==0&&x.fi<0);
}
ll dd(PI a){
	return a.fi*a.fi+a.se*a.se;
}
bool cmp(PI A,PI B){
	int X=half(A),Y=half(B);
	return X==Y?(mul(A,B)==0?dd(A)<dd(B):mul(A,B)>0):X<Y;
}
bool cm(PI A,PI B){
	int X=half(A),Y=half(B);
	return X==Y?mul(A,B)>0:X<Y;
}
bool equal(PI a,PI b){
	return cm(a,b)==0&&cm(b,a)==0;
}
int main(){
	#ifdef Brollan
		freopen("1.in","r",stdin);
	#endif
	int n=read(),k=read();
	For(i,1,n){
		a[i].fi=read(); a[i].se=read();
		if(a[i]==mp((ll)0,(ll)0))swap(a[i],a[1]);
	}
	sort(a+2,a+n+1,cmp);
	d[0]=-1; 
	For(i,1,n){
		d[i]=sqrt(a[i].fi*a[i].fi+a[i].se*a[i].se);
	}
	int dq=1; L[1]=R[1]=1;
	for(int i=2;i<=n;i=R[dq]+1){
		dq++;
		R[dq]=i;
		while(R[dq]<n&&equal(a[i],a[R[dq]+1]))R[dq]++;
		For(j,i,R[dq]){L[dq]=i; bel[j]=dq;}
		//cout<<R[dq]<<" "<<i<<endl;
	}
	For(i,1,dq){
		Rep(j,R[i],L[i]){
			A[j]=mp((k-1-(R[i]-j)*2)*d[j],j);
		}
	}
	//For(i,1,n)cout<<a[i].fi<<" "<<a[i].se<<" "<<A[i].fi<<" "<<A[i].se<<endl;
	sort(A+1,A+n+1);
	reverse(A+1,A+n+1);
	ld ans=0;
	For(i,1,k)if(A[i].fi>0||(i==k&&A[i].fi==0)){
	//c/out<<A[i].fi<<endl;
		ans+=A[i].fi;
		vis[A[i].se]=1;
	}else{
		int top=1,jb=0;
		q[1]=d[1];
		For(j,2,n)if(!vis[j]){
			q[++top]=d[j]; jb=R[bel[j]]-j;
			//cout<<j<<" "<<R[bel[j]]<<endl;
		}
		int jj=i-1-jb,L=0,R=top+1; 
		//cout<<jj<<" "<<jb<<endl;
		For(j,i,k){
			if(jb>=jj){
				ans+=q[++L]*(jj-(k-1-jj));
				jj++;
			}else{
				ans+=q[--R]*((k-1-jb)-jb);
				jb++;
			}
			//out<<ans<<" "<<q[L]<<endl;
		}
		break;
	}
	
	printf("%.10f\n",(double)ans);
}