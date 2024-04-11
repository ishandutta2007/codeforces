#define _USE_MATH_DEFINES
#include<bits/stdc++.h>
using namespace std;
const int maxn=262144;
struct cp{
    long double r,i;
    cp(long double _r=0,long double _i=0):
        r(_r),i(_i){}
    cp operator+(cp x){return cp(r+x.r,i+x.i);}
    cp operator-(cp x){return cp(r-x.r,i-x.i);}
    cp operator*(cp x){return cp(r*x.r-i*x.i,r*x.i+i*x.r);}
};
cp a[maxn],b[maxn],A[maxn],x,y,c[maxn];
int n, m, k, dig[maxn], cnt[maxn];
int rev[maxn],N,L;
void FFT(cp a[],int flag){
    for(int i=0;i<N;i++)A[i]=a[rev[i]];
    for(int i=0;i<N;i++)a[i]=A[i];
    for(int i=2;i<=N;i<<=1){
        cp wn(cos(2*M_PI/i),flag*sin(2*M_PI/i));
        for(int k=0;k<N;k+=i){
            cp w(1,0);
            for(int j=k;j<k+i/2;j++){
                x=a[j];
                y=a[j+i/2]*w;
                a[j]=x+y;
                a[j+i/2]=x-y;
                w=w*wn;
            }
        }
    }
    if(flag==-1)for(int i=0;i<N;i++)a[i].r/=N;
}

struct cmp {
	inline bool operator()(const vector<int> &a, const vector<int> &b) const {
		return a.size()>b.size();
	}
};

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> n >> m >> k;
    k=min(n-k, k);
   	for(int i=0; i<n; ++i) {
		int ai;
		cin >> ai;
		++cnt[ai];
	}
	priority_queue<vector<int>, vector<vector<int>>, cmp> pq;
	for(int i=1; i<=m; ++i)
		pq.push(vector<int>(min(cnt[i], k)+1, 1));
	while(pq.size()>1) {
		vector<int> va, vb, vc;
		va=pq.top();
		pq.pop();
		vb=pq.top();
		pq.pop();
		for(N=1,L=0;N<va.size()+vb.size()-1;N<<=1,L++);
	    for(int i=0;i<N;i++){
	        int len=0;
	        for(int t=i;t;t>>=1)dig[len++]=t&1;
	        rev[i]=0;
	        for(int j=0;j<L;j++)rev[i]=(rev[i]<<1)|(dig[j]&(j<len));
	    }
	    for(int i=0; i<N; ++i)
	    	a[i]=cp(i<va.size()?va[i]:0), b[i]=cp(i<vb.size()?vb[i]:0);
	    FFT(a,1);FFT(b,1);
	    for(int i=0;i<N;i++)c[i]=a[i]*b[i];
	    FFT(c,-1);
	    vc=vector<int>(min(N, k+1));
	    for(int i=0; i<min(N, k+1); ++i)
	    	vc[i]=(long long)(c[i].r+0.5)%1009;
		pq.push(vc);
	}
	cout << pq.top()[k];
}