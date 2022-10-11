#include <bits/stdc++.h>
#define fr(a, b, c) for(int a = b, __ = c; a < __; a++)
#define dbg(x) cerr << ">>>> " << x << endl;
#define _ << " , " << 

using namespace std;
typedef long long ll;


int dad[102],l[102],r[102];
int fdad(int x){
	if(dad[x]==-1)return x;
	return dad[x]=fdad(dad[x]);
}
void uni(int a,int b){
	a=fdad(a);
	b=fdad(b);
	if(a==b)return;
	dad[a]=b;
}

int main() {
	memset(dad,-1,sizeof dad);
	int n;cin>>n;
	fr(i,1,1+n){
		cin>>l[i]>>r[i];
		if(l[i])uni(i,l[i]);
		if(r[i])uni(i,r[i]);
	}
	fr(i,1,n+1){
		if(!l[i]){
			fr(j,1,n+1){
				if(fdad(i)!=fdad(j)&&r[j]==0){
					l[i]=j;
					r[j]=i;
					uni(i,j);break;
				}
			}
		}
	}	
	fr(i,1,n+1){
		cout<<l[i]<<" "<<r[i]<<endl;
	}
}