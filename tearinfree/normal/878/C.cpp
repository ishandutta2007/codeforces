#include <bits/stdc++.h>
using namespace std;

int n,k,arr[10];
class datat{
public:
	int max_val[10],min_val[10],c;
	datat() {c=0;}
	void init(int *arr) {
		for(int i=0;i<k;i++) max_val[i]=min_val[i]=arr[i];
		c=1;
	}
	bool cango(const datat &rhs)const {
		for(int i=0;i<k;i++) {
			if(max_val[i]>rhs.min_val[i]) return true;
		}
		return false;
	}
	void print() const{
		for(int i=0;i<k;i++) printf("%d ",max_val[i]);
		for(int i=0;i<k;i++) printf("%d ",min_val[i]);
		puts("");
	}
	datat operator+(const datat &rhs)const {
		datat res;
		for(int i=0;i<k;i++) {
			res.max_val[i]=max(max_val[i],rhs.max_val[i]);
			res.min_val[i]=min(min_val[i],rhs.min_val[i]);
		}
		res.c=c+rhs.c;
		return res;
	}
};
struct comp{
	bool operator()(const datat &a,const datat &b)const{
		return a.max_val[0]<b.max_val[0];
	}
};

set<datat,comp> tr;
int main() {
	scanf("%d%d",&n,&k);
	for(int i=0;i<n;i++) {
		for(int j=0;j<k;j++) scanf("%d",arr+j);
		
		datat cur;
		cur.init(arr);
		
		while(!tr.empty()) {
			auto it=tr.lower_bound(cur);
			if(it!=tr.begin()) {
				it--;
				if(cur.cango(*it) && it->cango(cur)) {
					cur=cur+*it;
					tr.erase(it);
					continue;
				}
			}

			it=tr.lower_bound(cur);
			if(it!=tr.end() && cur.cango(*it) && it->cango(cur)) {
				cur=cur+*it;
				tr.erase(it);
				continue;
			}
			break;
		}
		tr.insert(cur);

		auto it=tr.end();
		it--;
		printf("%d\n",it->c);
	}
	return 0;
}