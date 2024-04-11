#include<iostream>
#include<algorithm>
#include<cmath>
#include<vector>
using namespace std;

const int maxn=100007;
vector<int > a,b,c,d;
int n;

struct arr{
	int pos,val,idx;
	friend bool operator<(arr x,arr y){
		if (x.val<y.val){
			return true;
		}
		else{
			if (x.val>y.val){
				return false;
			}
			else{
				return x.idx<y.idx; 
			}
		}
	}
};

vector<int> cut_prod(vector<arr> u){
	int ret=0,n=u.size();
	vector<int> ans;
	ans.clear();
	ans.push_back(0);
	for (int i=0;i<n;++i){
		ret+=u[i].idx;
		if (ret==0){
			ans.push_back(i+1);
		}
	}
	return ans;
}

bool work(vector<int> a,vector<int> b,vector<int> c,vector<int> d){
	int n=a.size();
	bool check=true;
	if (n==1) return true;
	vector<arr> tmp;
	tmp.clear();
	for (int i=0;i<n;++i){
		arr tmp0;
		tmp0.pos=i;
		tmp0.val=a[i];
		tmp0.idx=1;
		tmp.push_back(tmp0);
		tmp0.pos=i;
		tmp0.val=c[i];
		tmp0.idx=-1;
		tmp.push_back(tmp0);
	}
	sort(tmp.begin(),tmp.end());
	vector<int> ans=cut_prod(tmp);
	int u=ans.size();
	if (u>2){
		for (int i=1;i<u;++i){
			vector<int> aa,bb,cc,dd;
			aa.clear(),bb.clear(),cc.clear(),dd.clear();
			for (int j=ans[i-1];j<ans[i];++j){
				if (tmp[j].idx==1){
					aa.push_back(a[tmp[j].pos]);
					bb.push_back(b[tmp[j].pos]);
					cc.push_back(c[tmp[j].pos]);
					dd.push_back(d[tmp[j].pos]);
				}
			}
			check=check&work(aa,bb,cc,dd);
		}
		return check;
	}
	else{
		vector<arr> tmp;
		tmp.clear();
		for (int i=0;i<n;++i){
			arr tmp0;
			tmp0.pos=i;
			tmp0.val=b[i];
			tmp0.idx=1;
			tmp.push_back(tmp0);
			tmp0.pos=i;
			tmp0.val=d[i];
			tmp0.idx=-1;
			tmp.push_back(tmp0);
		}
		sort(tmp.begin(),tmp.end());
		vector<int> ans=cut_prod(tmp);
		u=ans.size();
		if (u>2){
			for (int i=1;i<u;++i){
				vector<int> aa,bb,cc,dd;
				aa.clear(),bb.clear(),cc.clear(),dd.clear();
				for (int j=ans[i-1];j<ans[i];++j){
					if (tmp[j].idx==1){
						aa.push_back(a[tmp[j].pos]);
						bb.push_back(b[tmp[j].pos]);
						cc.push_back(c[tmp[j].pos]);
						dd.push_back(d[tmp[j].pos]);
					}
				}
				check=check&work(aa,bb,cc,dd);
			}
			return check;
		}
		else{
			return false;
		}
	}
} 
int main(){
	scanf("%d",&n);
	for (int i=1;i<=n;++i){
		int u,v,w,x;
		scanf("%d%d%d%d",&u,&v,&w,&x);
		a.push_back(u);
		b.push_back(v);
		c.push_back(w);
		d.push_back(x); 
	}
	if(work(a,b,c,d)){
		printf("yes");
	}
	else{
		printf("no");
	}
	return 0;
}