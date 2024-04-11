#include <bits/stdc++.h>
using namespace std;
#define FOR(i,a,b)	for(int i=a;i<b;++i)
#define REP(i,n)	FOR(i,0,n)
int t,m;
int a[128],id=1;
int main(){
	#ifdef LocalHost
	freopen("x.in","r",stdin);
	freopen("x.out","w",stdout);
	#endif
	cin>>t>>m;
	REP(i,t){
		string q;
		cin>>q;
		switch(q[0])
		{
			case 'a':
				{
				int k;
				bool ok=false;
				cin>>k;
				for(int i=0;i+k<=m;++i){
					int j=0;
					for(j=0;j<k && a[i+j]==0;++j);
					if(j==k){
						ok=true;
						REP(j,k)a[i+j]=id;
						break;
					}
				}
				if(ok)cout<<id++<<endl;
				else puts("NULL");
				break;
				}
			case 'e':
				{
				bool ok=false;
				int x;
				cin>>x;
				if (x > 0) {
					REP(i,m)if(a[i]==x)ok=true,a[i]=0;
				}
				if(!ok)puts("ILLEGAL_ERASE_ARGUMENT");
				break;
				}
			case 'd':
				for(int i=remove(a,a+m,0)-a;i<m;++i)a[i]=0;
				break;
		}
	}
	return 0;
}