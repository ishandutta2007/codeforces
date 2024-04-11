#include<cstdio>
#include<vector>
#include<algorithm>

using namespace std;

vector<vector<int> > vec;

int N;
int a[100100];

int get(int id){
//	printf("id=%d\n",id);
	if(vec[id].size()==1){
		bool flg=false;
		if(id==0||id==vec.size()-1) flg=true;
		else{
			int p=vec[id-1][vec[id-1].size()-1];
			int n=vec[id+1][0];
			if(n>=p+2) flg=true;
		}
//		if(flg){
//			printf("id=%d,true\n",id);
//		}
		if(flg){
			if(id==0) return vec[0].size()+vec[1].size();
			else if(id==vec.size()-1) return vec[id-1].size()+vec[id].size();
			else return vec[id-1].size()+vec[id].size()+vec[id+1].size();
		}else{
			return -1;
		}
	}
	else{
		int x=-1;
		if(id!=0){
			int p=vec[id-1][vec[id-1].size()-1];
			int n=vec[id][1];
			if(n>=p+2) x=max(x,(int)(vec[id-1].size()+vec[id].size()));
		}
		if(id!=vec.size()-1){
			int p=vec[id][vec[id].size()-2];
			int n=vec[id+1][0];
//			printf("%d&%d\n",p,n);
			if(n>=p+2) x=max(x,(int)(vec[id].size()+vec[id+1].size()));
		}
//		printf("x=%d\n",x);
		return x;
	}
}

int main(){
	scanf("%d",&N);
	for(int i=0;i<N;i++) scanf("%d",a+i);
	int id=0;
	for(;id<N;){
//		printf("id=%d\n",id);
		int cur=id;
		vector<int> tmp;
		tmp.push_back(a[cur]);
		int prev=a[cur];
		int i;
		for(i=cur+1;i<N;i++){
//			printf("i=%d\n",i);
			if(a[i]<=prev) break;
			tmp.push_back(a[i]);
			prev=a[i];
		}
		id=i;
		vec.push_back(tmp);
//		printf("sz=%d\n",tmp.size());
	}
//	printf("end\n");
	if(vec.size()==1){
		printf("%d\n",N);
		return 0;
	}
	int ans=0;
	for(int i=0;i<vec.size();i++){
		ans=max(ans,(int)(vec[i].size()+1));
	}
//	printf("ans=%d\n",ans);
	for(int i=0;i<vec.size();i++){
		int x=get(i);
		ans=max(ans,x);
	}
	printf("%d\n",ans);
	return 0;
}