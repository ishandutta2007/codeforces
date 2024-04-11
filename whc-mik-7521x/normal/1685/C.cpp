#include<bits/stdc++.h>
using namespace std;
const int N=1e5+10;
int t,n;
char s[N<<1];
int per[N<<1];
int main(){
    scanf("%d",&t);
	while(t--){
		scanf("%d%s",&n,s);
		per[0]=0;
		for(int i=0;i<n<<1;i++){
			per[i+1]=per[i]+(s[i]=='('?1:-1);
		}
		int nl=-1,nr=-1;
		int mxi=0;
		for(int i=0;i<=n<<1;i++){
			if(per[i]<0){
				if(nl==-1)nl=i;
				nr=i;
			}
			if(per[mxi]<per[i])mxi=i;
		}
		if(nl==-1)puts("0");
        else{
            int lmi=0,rmi=n<<1;
            for(int i=0;i<nl;i++)if(per[lmi]<per[i])lmi=i;
            for(int i=nr+1;i<=n<<1;i++)if(per[rmi]<per[i])rmi=i;
            if(per[lmi]+per[rmi]>=per[mxi])printf("1\n%d %d\n",lmi+1,rmi);
            else printf("2\n%d %d\n%d %d\n",lmi+1,mxi,mxi+1,rmi);
        }
	}
}