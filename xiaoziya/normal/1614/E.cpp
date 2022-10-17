#include<bits/extc++.h>
using namespace std;
using namespace __gnu_pbds;
tree<int,null_type,less_equal<int>,rb_tree_tag,tree_order_statistics_node_update>s;
int n,t,k,o,pre,st;
inline int get(int o){
	return st+o-s.order_of_key(o+1);
}
inline int query(int o){
	int r=-1;
	for(int i=1<<30;i>>=1;)
		r+=i*(get(r+i)<o);
	return r+1;
}
int main(){
	ios::sync_with_stdio(0);
	cin>>n;
	while(n--){
		cin>>t;
		int a=query(t),b=query(t+1);
		st++,s.insert(a),s.insert(b);
		for(cin>>k;k--;)
			cin>>o,cout<<(pre=get((o+pre)%1000000001))<<"\n";
	}
}
//feaigiaerngleirnheinbienbkien
//feaigiaerngleirnheinbienbkien
//feaigiaerngleirnheinbienbkien
//feaigiaerngleirnheinbienbkien
//feaigiaerngleirnheinbienbkien
//feaigiaerngleirnheinbienbkien
//feaigiaerngleirnheinbienbkien
//feaigiaerngleirnheinbienbkien
//feaigiaerngleirnheinbienbkien
//feaigiaerngleirnheinbienbkien
//feaigiaerngleirnheinbienbkien
//feaigiaerngleirnheinbienbkien
//feaigiaerngleirnheinbienbkien
//feaigiaerngleirnheinbienbkien
//feaigiaerngleirnheinbienbkien
//feaigiaerngleirnheinbienbkien
//feaigiaerngleirnheinbienbkien
//feaigiaerngleirnheinbienbkien
//feaigiaerngleirnheinbienbkien
//feaigiaerngleirnheinbienbkien
//feaigiaerngleirnheinbienbkien
//feaigiaerngleirnheinbienbkien
//feaigiaerngleirnheinbienbkien
//feaigiaerngleirnheinbienbkien
//feaigiaerngleirnheinbienbkien
//feaigiaerngleirnheinbienbkien
//feaigiaerngleirnheinbienbkien
//feaigiaerngleirnheinbienbkien
//feaigiaerngleirnheinbienbkien
//feaigiaerngleirnheinbienbkien
//feaigiaerngleirnheinbienbkien
//feaigiaerngleirnheinbienbkien
//feaigiaerngleirnheinbienbkien
//feaigiaerngleirnheinbienbkien
//feaigiaerngleirnheinbienbkien
//feaigiaerngleirnheinbienbkien
//feaigiaerngleirnheinbienbkien
//feaigiaerngleirnheinbienbkien
//feaigiaerngleirnheinbienbkien
//feaigiaerngleirnheinbienbkien
//feaigiaerngleirnheinbienbkien
//feaigiaerngleirnheinbienbkien
//feaigiaerngleirnheinbienbkien
//feaigiaerngleirnheinbienbkien
//feaigiaerngleirnheinbienbkien
//feaigiaerngleirnheinbienbkien
//feaigiaerngleirnheinbienbkien
//feaigiaerngleirnheinbienbkien
//feaigiaerngleirnheinbienbkien
//feaigiaerngleirnheinbienbkien
//feaigiaerngleirnheinbienbkien
//feaigiaerngleirnheinbienbkien
//feaigiaerngleirnheinbienbkien
//feaigiaerngleirnheinbienbkien
//feaigiaerngleirnheinbienbkien
//feaigiaerngleirnheinbienbkien
//feaigiaerngleirnheinbienbkien
//feaigiaerngleirnheinbienbkien
//feaigiaerngleirnheinbienbkien
//feaigiaerngleirnheinbienbkien
//feaigiaerngleirnheinbienbkien
//feaigiaerngleirnheinbienbkien
//feaigiaerngleirnheinbienbkien
//feaigiaerngleirnheinbienbkien
//feaigiaerngleirnheinbienbkien
//feaigiaerngleirnheinbienbkien
//feaigiaerngleirnheinbienbkien
//feaigiaerngleirnheinbienbkien
//feaigiaerngleirnheinbienbkien
//feaigiaerngleirnheinbienbkien
//feaigiaerngleirnheinbienbkien
//feaigiaerngleirnheinbienbkien