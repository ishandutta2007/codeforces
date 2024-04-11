//CF 220C
#include<iostream>
#include<cstdio>
#include<fstream>
#include<algorithm>
#include<vector>
#include<map>
#include<set>
#include<queue>
#include<cmath>
#include<cstring>
#include<cstdlib>
using namespace std;
typedef long long LL;
const int N = 1e5+15;
int a[N],b[N];
int ida[N],idb[N];
multiset<int> S;
multiset<int>::iterator it;
int main(){
    int n,i,x;
    scanf("%d",&n);
    for(i=1;i<=n;i=i+1){
        scanf("%d",a+i);
        ida[a[i]]=i;
    }
    for(i=1;i<=n;i=i+1){
        scanf("%d",b+i);
        S.insert(i-ida[b[i]]);
    }
    for(i=0;i<n;i=i+1){
    	if(i){
    		S.erase(S.lower_bound(i-ida[b[i]]));
    		S.insert(i-ida[b[i]]+n);
    		//cout<<i-ida[b[i]]<<i-ida[b[i]]+n<<endl;
    	}
    	it=S.lower_bound(i);
    	x=(*it)-i;
    	//cout<<(*it)<<endl;
    	if(it!=S.begin()){
	    	--(it);
	    	//cout<<(*it)<<endl;
	    	x=min(x,i-(*it));
	    }
    	printf("%d\n",x);
   }
    return 0;
}