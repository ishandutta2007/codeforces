#include<cstdio>
#include<algorithm>
#include<vector>
#define pii std::pair<int,int>
#define mp std::make_pair
#define fir first
#define sec second
#define N 20005

int n,a[N];

int b[N],_b;

inline std::vector<std::vector<int> > sol(int L,int R){
	std::vector<std::vector<int> > res;
	if(L==R)
		return res;
	int mid=(L+R)>>1;
	while(1){
		std::vector<pii> lst;
		for(int i=L;i<=R;i++)
			if(a[i]<=mid){
				int j=i;
				while(j<R&&a[j+1]<=mid)
					j++;
				lst.push_back(mp(i,j));
				i=j;
			}
		if(lst.size()==1&&lst.back().fir==L)
			break;
		std::vector<int> tmp;
		tmp.push_back(R+1);
		while(lst.size()>1){
			auto u=lst.back();
			lst.pop_back();
			auto v=lst.back();
			lst.pop_back();
			tmp.push_back(u.sec+1);
			tmp.push_back(v.sec+1);
			tmp.push_back(v.fir);
		}
		if(lst.size()){
			auto u=lst.back();
			tmp.push_back(u.fir);
		}
		tmp.push_back(L);
		std::vector<int> opt;
		tmp.erase(std::unique(tmp.begin(),tmp.end()),tmp.end());
		_b=L-1;
		for(int i=1;i<(int)tmp.size();i++)
			for(int j=tmp[i];j<tmp[i-1];j++)
				b[++_b]=a[j];
		for(int i=L;i<=R;i++)
			a[i]=b[i];
		std::reverse(tmp.begin(),tmp.end());
		for(int i=0;i<(int)tmp.size()-1;i++)
			opt.push_back(tmp[i+1]-tmp[i]);
		res.push_back(opt);
	}
	auto x=sol(L,mid),y=sol(mid+1,R);
	while(x.size()<y.size()||(x.size()&1)){
		std::vector<int> tmp;
		tmp.push_back(mid-L+1);
		x.push_back(tmp);
	}
	while(y.size()<x.size()){
		std::vector<int> tmp;
		tmp.push_back(R-mid);
		y.push_back(tmp);
	}
	for(int i=0;i<(int)x.size();i++){
		std::vector<int> tmp;
		if(i%2==0){
			for(auto u:x[i])
				tmp.push_back(u);
			for(auto u:y[i])
				tmp.push_back(u);
		}
		else{
			for(auto u:y[i])
				tmp.push_back(u);
			for(auto u:x[i])
				tmp.push_back(u);
		}
		res.push_back(tmp);
	}
//	printf("&%d %d\n",L,R);
//	for(int i=L;i<=R;i++)
//		printf("%d ",a[i]);
//	puts("");
//	printf("%d\n",(int)res.size());
//	for(auto x:res){
//		printf("%d ",(int)x.size());
//		for(auto y:x)
//			printf("%d ",y);
//		puts("");
//	}
	return res;
}

std::vector<std::vector<int> > ans;

int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
		scanf("%d",&a[i]);
	ans=sol(1,n);
	printf("%d\n",(int)ans.size());
	for(auto x:ans){
		printf("%d ",(int)x.size());
		for(auto y:x)
			printf("%d ",y);
		puts("");
	}
}