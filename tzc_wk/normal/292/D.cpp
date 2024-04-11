#include <bits/stdc++.h>
using namespace std;
int n,m;
class dsu{
	public:
		int p[501];
	protected:
		int s;
	public:
		inline explicit dsu(){
			memset(p,-1,sizeof(p));
			s=0;
		}
		int size(){return s;}
		int find(int n){
			return (~p[n])?p[n]=find(p[n]):n;
		}
		void join(int a,int b){
			int px=find(a),py=find(b);
			if(px==py)	return;
			p[px]=py;
			s++;
		}
};
int x[10005],y[10005];
dsu l[10005],r[10005];
int main(){
	cin>>n>>m;
	for(int i=1;i<=m;i++){
		cin>>x[i]>>y[i];
		l[i]=l[i-1];
		l[i].join(x[i],y[i]);
	}
	for(int i=m;i;i--){
		r[i]=r[i+1];
		r[i].join(x[i],y[i]);
	}
	int QUERY_NUM;
	cin>>QUERY_NUM;
	while(QUERY_NUM--){
		int _l,_r;
		cin>>_l>>_r;
		dsu ans=l[_l-1];
		for(int i=1;i<=n;i++)
			if(~r[_r+1].p[i])
				ans.join(i,r[_r+1].p[i]);
		cout<<n-ans.size()<<endl;
	}
}